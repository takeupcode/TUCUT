//
//  PropertyContainer.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 7/31/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_PropertyContainer_h
#define TUCUT_Game_PropertyContainer_h

#include <string>
#include <unordered_map>
#include <vector>

#include "PropertyGroup.h"

namespace TUCUT {
namespace Game {

class PropertyContainer
{
public:
    PropertyContainer ();
    
    PropertyContainer (const PropertyContainer & src);

    PropertyContainer (PropertyContainer && src);
    
    virtual ~PropertyContainer () = default;
    
    PropertyContainer & operator = (const PropertyContainer & rhs);
    PropertyContainer & operator = (PropertyContainer && rhs);

    PropertyGroup * addGroup (const std::string & groupName);
    
    void removeGroup (const std::string & groupName);

    bool hasGroup (const std::string & groupName) const
    {
        auto groupMapResult = mGroups->find(groupName);
        if (groupMapResult == mGroups->end())
        {
            return false;
        }
        
        return true;
    }

    bool hasAllGroups (const std::vector<std::string> & groupNames) const
    {
        for (const auto & groupName: groupNames)
        {
            auto groupMapResult = mGroups->find(groupName);
            if (groupMapResult == mGroups->end())
            {
                return false;
            }
        }
        
        return true;
    }

    PropertyGroup * getGroup (const std::string & groupName);

    const PropertyGroup * getGroup (const std::string & groupName) const;

    PropertyValue * getValue (const std::string & groupName, const std::string & valueName);

    const PropertyValue * getValue (const std::string & groupName, const std::string & valueName) const;

private:
    using GroupMap = std::unordered_map<std::string, std::unique_ptr<PropertyGroup>>;
    
    std::unique_ptr<GroupMap> mGroups;
};
    
} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_PropertyContainer_h
