//
//  PropertyContainer.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 7/31/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "PropertyContainer.h"

namespace TUCUT {
namespace Game {

PropertyContainer::PropertyContainer ()
: mGroups(new GroupMap())
{ }

PropertyContainer::PropertyContainer (const PropertyContainer & src)
: mGroups(new GroupMap())
{
    for (const auto & groupPair: *src.mGroups)
    {
        auto result = mGroups->try_emplace(groupPair.first, groupPair.second->clone());
        if (!result.second)
        {
            throw std::runtime_error("Unable to copy PropertyGroup");
        }
    }
}

PropertyContainer::PropertyContainer (PropertyContainer && src)
: mGroups(src.mGroups.release())
{ }

PropertyContainer & PropertyContainer::operator = (const PropertyContainer & rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    
    mGroups->clear();
    for (const auto & groupPair: *rhs.mGroups)
    {
        auto result = mGroups->try_emplace(groupPair.first, groupPair.second->clone());
        if (!result.second)
        {
            throw std::runtime_error("Unable to copy PropertyGroup");
        }
    }
    
    return *this;
}

PropertyContainer & PropertyContainer::operator = (PropertyContainer && rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    
    mGroups = std::move(rhs.mGroups);
    
    return *this;
}

PropertyGroup * PropertyContainer::addGroup (const std::string & groupName)
{
    auto result = mGroups->try_emplace(groupName, std::make_unique<PropertyGroup>());
    
    auto & group = result.first->second;
    return group.get();
}

void PropertyContainer::deleteGroup (const std::string & groupName)
{
    mGroups->erase(groupName);
}

PropertyGroup * PropertyContainer::getGroup (const std::string & groupName)
{
    auto groupMapResult = mGroups->find(groupName);
    if (groupMapResult == mGroups->end())
    {
        return nullptr;
    }
    
    return groupMapResult->second.get();
}

const PropertyGroup * PropertyContainer::getGroup (const std::string & groupName) const
{
    auto groupMapResult = mGroups->find(groupName);
    if (groupMapResult == mGroups->end())
    {
        return nullptr;
    }
    
    return groupMapResult->second.get();
}

PropertyValue * PropertyContainer::getValue (const std::string & groupName, const std::string & valueName)
{
    auto group = getGroup(groupName);
    if (!group)
    {
        return nullptr;
    }
    
    return group->getValue(valueName);
}

const PropertyValue * PropertyContainer::getValue (const std::string & groupName, const std::string & valueName) const
{
    auto group = getGroup(groupName);
    if (!group)
    {
        return nullptr;
    }
    
    return group->getValue(valueName);
}

} // namespace Game
} // namespace TUCUT
