//  PropertyContainer.cpp
//  TUCUT/ECS (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-07-31.
//  Copyright © Take Up Code, Inc.
//
#include "PropertyContainer.h"

PropertyContainer::PropertyContainer ()
: mGroups(new GroupMap())
{ }

PropertyContainer::PropertyContainer (
  PropertyContainer const & src)
: mGroups(new GroupMap())
{
  for (auto const & groupPair: *src.mGroups)
  {
    auto result = mGroups->try_emplace(groupPair.first,
      groupPair.second->clone());
    if (not result.second)
    {
      throw std::runtime_error("Unable to copy PropertyGroup");
    }
  }
}

PropertyContainer::PropertyContainer (PropertyContainer && src)
: mGroups(src.mGroups.release())
{ }

PropertyContainer & PropertyContainer::operator = (
  PropertyContainer const & rhs)
{
  if (this == &rhs)
  {
    return *this;
  }

  mGroups->clear();
  for (auto const & groupPair: *rhs.mGroups)
  {
    auto result = mGroups->try_emplace(
      groupPair.first, groupPair.second->clone());
    if (not result.second)
    {
      throw std::runtime_error("Unable to copy PropertyGroup");
    }
  }

  return *this;
}

PropertyContainer & PropertyContainer::operator = (
  PropertyContainer && rhs)
{
  if (this == &rhs)
  {
    return *this;
  }

  mGroups = std::move(rhs.mGroups);

  return *this;
}

PropertyGroup * PropertyContainer::addGroup (
  std::string const & groupName)
{
  auto result = mGroups->try_emplace(
    groupName, std::make_unique<PropertyGroup>());

  auto & group = result.first->second;
  return group.get();
}

void PropertyContainer::removeGroup (
  std::string const & groupName)
{
  mGroups->erase(groupName);
}

PropertyGroup * PropertyContainer::getGroup (
  std::string const & groupName)
{
  auto groupMapResult = mGroups->find(groupName);
  if (groupMapResult == mGroups->end())
  {
    return nullptr;
  }

  return groupMapResult->second.get();
}

PropertyGroup const * PropertyContainer::getGroup (
  std::string const & groupName) const
{
  auto groupMapResult = mGroups->find(groupName);
  if (groupMapResult == mGroups->end())
  {
    return nullptr;
  }

  return groupMapResult->second.get();
}

PropertyValue * PropertyContainer::getValue (
  std::string const & groupName,
  std::string const & valueName)
{
  auto group = getGroup(groupName);
  if (not group)
  {
    return nullptr;
  }

  return group->getValue(valueName);
}

PropertyValue const * PropertyContainer::getValue (
  std::string const & groupName,
  std::string const & valueName) const
{
  auto group = getGroup(groupName);
  if (not group)
  {
    return nullptr;
  }

  return group->getValue(valueName);
}
