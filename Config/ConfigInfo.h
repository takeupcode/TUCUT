//
//  ConfigInfo.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 1/9/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Config_ConfigInfo_h
#define TUCUT_Config_ConfigInfo_h

#include <string>
#include <vector>
#include <unordered_map>

namespace TUCUT {
namespace Config {

class ConfigInfo
{
public:
    class Item
    {
    public:
        void addProperty (const std::string & name, const std::string & value)
        {
            auto result = mProperties.find(name);
            if (result == mProperties.end())
            {
                mProperties.insert(std::make_pair(name, std::vector<std::string>{value}));
            }
            else
            {
                result->second.push_back(value);
            }
        }
        
        void addProperty (const std::string & name, std::string && value)
        {
            auto result = mProperties.find(name);
            if (result == mProperties.end())
            {
                mProperties.insert(std::make_pair(name, std::vector<std::string>{std::move(value)}));
            }
            else
            {
                result->second.push_back(std::move(value));
            }
        }
        
        void clearProperties ()
        {
            mProperties.clear();
        }

        size_t getPropertySize (const std::string & name) const
        {
            auto result = mProperties.find(name);
            if (result == mProperties.end())
            {
                return 0;
            }
            
            return result->second.size();
        }

        std::string getProperty (const std::string & name, size_t n) const
        {
            auto result = mProperties.find(name);
            return result->second[n];
        }

    private:
        friend class ConfigInfo;
        
        std::unordered_map<std::string, std::vector<std::string>> mProperties;
    };
    
    void load (const std::string & fileName);
    
    std::vector<std::string> getItemTypes ();
    
    std::vector<std::string> getItemIds (const std::string & type);
    
    std::vector<std::string> getItemPropertyNames (const std::string & type, const std::string & id);

    size_t getPropertySize (const std::string & type, const std::string & id, const std::string & name) const
    {
        auto configMapResult = mConfigMap.find(type);
        if (configMapResult == mConfigMap.end())
        {
            return 0;
        }
        
        auto itemMapResult = configMapResult->second.find(id);
        if (itemMapResult == configMapResult->second.end())
        {
            return 0;
        }
        
        return itemMapResult->second.getPropertySize(name);
    }

    std::string getProperty (const std::string & type, const std::string & id, const std::string & name, size_t n) const
    {
        auto configMapResult = mConfigMap.find(type);
        auto itemMapResult = configMapResult->second.find(id);
        return itemMapResult->second.getProperty(name, n);
    }

private:
    using ItemMap = std::unordered_map<std::string, Item>;
    using ConfigMap = std::unordered_map<std::string, ItemMap>;

    enum class ParseState
    {
        itemStartOrPropertyName,    // up to : or =
        propertyName,               // up to =, also used for item name
        propertyValueBegin,         // starts with "
        propertyValue,              // up to ", also used for item id
        propertyMultiValueOrEnd     // up to , or ;
    };
    
    bool parseChar (char c);
    
    void addCurrentItem ();
    
    void initializeCurrentItem ();

    std::string mCurrentItemName;
    std::string mCurrentItemId;
    std::string mCurrentPropertyName;
    std::string mCurrentBuffer;
    ParseState mParseState;
    Item mCurrentItem;
    ConfigMap mConfigMap;
};
    
} // namespace Config
} // namespace TUCUT

#endif // TUCUT_Config_ConfigInfo_h
