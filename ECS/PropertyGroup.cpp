//  PropertyGroup.cpp
//  TUCUT/ECS (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-07-31.
//  Copyright © Take Up Code, Inc.
//
#include "PropertyGroup.h"

#include <stdexcept>

PropertyGroup::PropertyGroup ()
: mValues(new ValueMap())
{ }

PropertyGroup::PropertyGroup (PropertyGroup const & src)
: mValues(new ValueMap())
{
  for (auto const & valuePair: *src.mValues)
  {
    auto result = mValues->try_emplace(
      valuePair.first, valuePair.second->clone());
    if (not result.second)
    {
      throw std::runtime_error("Unable to copy PropertyValue");
    }
  }
}

PropertyGroup::PropertyGroup (PropertyGroup && src)
: mValues(src.mValues.release())
{ }

PropertyGroup & PropertyGroup::operator = (
  PropertyGroup const & rhs)
{
  if (this == &rhs)
  {
    return *this;
  }

  mValues->clear();
  for (auto const & valuePair: *rhs.mValues)
  {
    auto result = mValues->try_emplace(
      valuePair.first, valuePair.second->clone());
    if (not result.second)
    {
      throw std::runtime_error("Unable to copy PropertyValue");
    }
  }

  return *this;
}

PropertyGroup & PropertyGroup::operator = (PropertyGroup && rhs)
{
  if (this == &rhs)
  {
    return *this;
  }

  mValues = std::move(rhs.mValues);

  return *this;
}

std::unique_ptr<PropertyGroup> PropertyGroup::clone () const
{
  return std::unique_ptr<PropertyGroup>(
    new PropertyGroup(*this));
}

bool PropertyGroup::addValue (std::string const & valueName,
  std::string const & value, bool readOnly)
{
  auto result = mValues->try_emplace(valueName,
    PropertyValue::createStringPropertyValue(value,
      readOnly));

  return result.second;
}

bool PropertyGroup::addValue (std::string const & valueName,
  char const * value, bool readOnly)
{
  auto result = mValues->try_emplace(valueName,
    PropertyValue::createStringPropertyValue(value,
      readOnly));

  return result.second;
}

bool PropertyGroup::addValue (std::string const & valueName,
  int value, bool readOnly)
{
  auto result = mValues->try_emplace(valueName,
    PropertyValue::createIntegerPropertyValue(value,
      readOnly));

  return result.second;
}

bool PropertyGroup::addValue (std::string const & valueName,
  double value, bool readOnly)
{
  auto result = mValues->try_emplace(valueName,
    PropertyValue::createFloatingPropertyValue(value,
      readOnly));

  return result.second;
}

bool PropertyGroup::addValue (std::string const & valueName,
  bool value, bool readOnly)
{
  auto result = mValues->try_emplace(valueName,
    PropertyValue::createBooleanPropertyValue(value,
      readOnly));

  return result.second;
}

void PropertyGroup::removeValue (std::string const & valueName)
{
  mValues->erase(valueName);
}

PropertyValue * PropertyGroup::getValue (
  std::string const & valueName)
{
  auto valueMapResult = mValues->find(valueName);
  if (valueMapResult == mValues->end())
  {
    return nullptr;
  }

  return valueMapResult->second.get();
}

PropertyValue const * PropertyGroup::getValue (
  std::string const & valueName) const
{
  auto valueMapResult = mValues->find(valueName);
  if (valueMapResult == mValues->end())
  {
    return nullptr;
  }

  return valueMapResult->second.get();
}
