//
//  ConfigInfo.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 1/9/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "ConfigInfo.h"

#include <vector>
#include <stdexcept>

#include "../File/FileManager.h"

namespace TUCUT {
namespace Config {

void ConfigInfo::load (const std::string & fileName)
{
    auto parseLine = [this] (std::string && line)
    {
        for (char c: line)
        {
            if (!parseChar(c))
            {
                return;
            }
        }
    };
    
    initializeCurrentItem();
    File::FileManager::processLines(fileName, parseLine);
    addCurrentItem();
}
    
std::vector<std::string> ConfigInfo::getItemTypes ()
{
    std::vector<std::string> result;
    
    result.reserve(mConfigMap.size());
    for (auto const & iter: mConfigMap)
    {
        result.push_back(iter.first);
    }
    
    return result;
}

std::vector<std::string> ConfigInfo::getItemIds (const std::string & type)
{
    std::vector<std::string> result;
    
    auto configMapResult = mConfigMap.find(type);
    if (configMapResult == mConfigMap.end())
    {
        return result;
    }
    
    result.reserve(configMapResult->second.size());
    for (auto const & iter: configMapResult->second)
    {
        result.push_back(iter.first);
    }
    
    return result;
}

std::vector<std::string> ConfigInfo::getItemPropertyNames (const std::string & type, const std::string & id)
{
    std::vector<std::string> result;
    
    auto configMapResult = mConfigMap.find(type);
    if (configMapResult == mConfigMap.end())
    {
        return result;
    }
    
    auto itemMapResult = configMapResult->second.find(id);
    if (itemMapResult == configMapResult->second.end())
    {
        return result;
    }
    
    result.reserve(itemMapResult->second.mProperties.size());
    for (auto const & iter: itemMapResult->second.mProperties)
    {
        result.push_back(iter.first);
    }
    
    return result;
}

void ConfigInfo::addCurrentItem ()
{
    if (mCurrentItemName.empty() || mCurrentItemId.empty())
    {
        return;
    }
    
    auto configMapResult = mConfigMap.find(mCurrentItemName);
    if (configMapResult == mConfigMap.end())
    {
        auto newItemMapResult = mConfigMap.insert(std::make_pair(mCurrentItemName, ItemMap{}));
        if (!newItemMapResult.second)
        {
            return;
        }
        configMapResult = newItemMapResult.first;
    }

    configMapResult->second.insert(std::make_pair(mCurrentItemId, mCurrentItem));
}

void ConfigInfo::initializeCurrentItem ()
{
    mCurrentItemName.clear();
    mCurrentItemId.clear();
    mCurrentPropertyName.clear();
    mCurrentBuffer.clear();
    mParseState = ParseState::itemStartOrPropertyName;
    mCurrentItem.clearProperties();
}

bool ConfigInfo::parseChar (char c)
{
    const auto parseError = "Could not parse config file.";
    
    switch (mParseState)
    {
        case ParseState::itemStartOrPropertyName:
            if (c == '#')
            {
                return false;
            }
            else if (c == ':')
            {
                if (mCurrentBuffer == "item")
                {
                    addCurrentItem();
                    initializeCurrentItem();
                    mParseState = ParseState::propertyName;
                }
                else
                {
                    throw std::logic_error(parseError);
                }
                
                mCurrentBuffer.clear();
            }
            else if (c == '=')
            {
                if (!mCurrentBuffer.empty())
                {
                    mCurrentPropertyName = mCurrentBuffer;
                    mParseState = ParseState::propertyValueBegin;
                }
                else
                {
                    throw std::logic_error(parseError);
                }
                
                mCurrentBuffer.clear();
            }
            else if (c != ' ' && c != '\t')
            {
                mCurrentBuffer += c;
            }
            break;
            
        case ParseState::propertyName:
            if (c == '#')
            {
                return false;
            }
            else if (c == '=')
            {
                if (!mCurrentBuffer.empty())
                {
                    if (mCurrentItemName.empty())
                    {
                        mCurrentItemName = mCurrentBuffer;
                    }
                    else
                    {
                        mCurrentPropertyName = mCurrentBuffer;
                    }
                    mParseState = ParseState::propertyValueBegin;
                }
                else
                {
                    throw std::logic_error(parseError);
                }
                
                mCurrentBuffer.clear();
            }
            else if (c != ' ' && c != '\t')
            {
                mCurrentBuffer += c;
            }
            break;
            
        case ParseState::propertyValueBegin:
            if (c == '#')
            {
                return false;
            }
            else if (c == '"')
            {
                mParseState = ParseState::propertyValue;
            }
            else if (c != ' ' && c != '\t')
            {
                throw std::logic_error(parseError);
            }
            break;
            
        case ParseState::propertyValue:
            if (c == '"')
            {
                if (!mCurrentBuffer.empty())
                {
                    if (mCurrentItemId.empty())
                    {
                        mCurrentItemId = mCurrentBuffer;
                    }
                    else
                    {
                        mCurrentItem.addProperty(mCurrentPropertyName, mCurrentBuffer);
                    }
                    mParseState = ParseState::propertyMultiValueOrEnd;
                }
                else
                {
                    throw std::logic_error(parseError);
                }
                
                mCurrentBuffer.clear();
            }
            else
            {
                mCurrentBuffer += c;
            }
            break;
            
        case ParseState::propertyMultiValueOrEnd:
            if (c == '#')
            {
                return false;
            }
            else if (c == ',')
            {
                mParseState = ParseState::propertyValueBegin;
            }
            else if (c == ';')
            {
                mParseState = ParseState::itemStartOrPropertyName;
            }
            else if (c != ' ' && c != '\t')
            {
                throw std::logic_error(parseError);
            }
            break;
    }
    
    return true;
}

} // namespace Config
} // namespace TUCUT
