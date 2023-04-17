//  PropertyContainer.h
//  TUCUT/ECS (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-07-31.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_ECS_PropertyContainer_h
#define TUCUT_ECS_PropertyContainer_h

#include "PropertyGroup.h"

#include <string>
#include <unordered_map>
#include <vector>

namespace TUCUT::ECS
{
  class PropertyContainer
  {
  public:
    PropertyContainer ();

    PropertyContainer (PropertyContainer const & src);

    PropertyContainer (PropertyContainer && src);

    virtual ~PropertyContainer () = default;

    PropertyContainer & operator = (
      PropertyContainer const & rhs);
    PropertyContainer & operator = (PropertyContainer && rhs);

    PropertyGroup * addGroup (std::string const & groupName);

    void removeGroup (std::string const & groupName);

    bool hasGroup (std::string const & groupName) const
    {
      return mGroups->contains(groupName);
    }

    bool hasAllGroups (
      std::vector<std::string> const & groupNames) const
    {
      for (const auto & groupName: groupNames)
      {
        if (not mGroups->contains(groupName))
        {
          return false;
        }
      }

      return true;
    }

    PropertyGroup * getGroup (std::string const & groupName);

    PropertyGroup const * getGroup (
      std::string const & groupName) const;

    PropertyValue * getValue (
      std::string const & groupName,
      std::string const & valueName);

    PropertyValue const * getValue (
      std::string const & groupName,
      std::string const & valueName) const;

  private:
    using GroupMap = std::unordered_map<
      std::string, std::unique_ptr<PropertyGroup>>;

    std::unique_ptr<GroupMap> mGroups;
  };
} // namespace TUCUT::ECS

#endif // TUCUT_ECS_PropertyContainer_h
