//
//  PropertyGroup.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 7/31/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "PropertyGroup.h"

#include <stdexcept>

namespace TUCUT {
namespace Game {

PropertyGroup::PropertyGroup ()
: mValues(new ValueMap())
{ }

PropertyGroup::PropertyGroup (const PropertyGroup & src)
: mValues(new ValueMap())
{
    for (const auto & valuePair: *src.mValues)
    {
        auto result = mValues->try_emplace(valuePair.first, valuePair.second->clone());
        if (!result.second)
        {
            throw std::runtime_error("Unable to copy PropertyValue");
        }
    }
}
    
PropertyGroup::PropertyGroup (PropertyGroup && src)
: mValues(src.mValues.release())
{ }

PropertyGroup & PropertyGroup::operator = (const PropertyGroup & rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    
    mValues->clear();
    for (const auto & valuePair: *rhs.mValues)
    {
        auto result = mValues->try_emplace(valuePair.first, valuePair.second->clone());
        if (!result.second)
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
    return std::unique_ptr<PropertyGroup>(new PropertyGroup(*this));
}
    
bool PropertyGroup::addValue (const std::string & valueName, const std::string & value, bool readOnly)
{
    auto result = mValues->try_emplace(valueName, PropertyValue::createStringPropertyValue(value, readOnly));
    
    return result.second;
}

bool PropertyGroup::addValue (const std::string & valueName, const char * value, bool readOnly)
{
    auto result = mValues->try_emplace(valueName, PropertyValue::createStringPropertyValue(value, readOnly));
    
    return result.second;
}

bool PropertyGroup::addValue (const std::string & valueName, int value, bool readOnly)
{
    auto result = mValues->try_emplace(valueName, PropertyValue::createIntegerPropertyValue(value, readOnly));
    
    return result.second;
}

bool PropertyGroup::addValue (const std::string & valueName, double value, bool readOnly)
{
    auto result = mValues->try_emplace(valueName, PropertyValue::createFloatingPropertyValue(value, readOnly));
    
    return result.second;
}

bool PropertyGroup::addValue (const std::string & valueName, bool value, bool readOnly)
{
    auto result = mValues->try_emplace(valueName, PropertyValue::createBooleanPropertyValue(value, readOnly));
    
    return result.second;
}

void PropertyGroup::deleteValue (const std::string & valueName)
{
    mValues->erase(valueName);
}

PropertyValue * PropertyGroup::getValue (const std::string & valueName)
{
    auto valueMapResult = mValues->find(valueName);
    if (valueMapResult == mValues->end())
    {
        return nullptr;
    }
    
    return valueMapResult->second.get();
}

const PropertyValue * PropertyGroup::getValue (const std::string & valueName) const
{
    auto valueMapResult = mValues->find(valueName);
    if (valueMapResult == mValues->end())
    {
        return nullptr;
    }
    
    return valueMapResult->second.get();
}

} // namespace Game
} // namespace TUCUT
