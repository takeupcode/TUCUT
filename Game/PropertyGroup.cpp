//
//  PropertyGroup.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 7/31/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "PropertyGroup.h"

namespace TUCUT {
namespace Game {

bool PropertyGroup::addValue (const std::string & valueName, const std::string & value, bool readOnly)
{
    auto result = mValues.insert(std::make_pair(valueName, PropertyValue::createStringPropertyValue(value, readOnly)));
    
    return result.second;
}

bool PropertyGroup::addValue (const std::string & valueName, const char * value, bool readOnly)
{
    auto result = mValues.insert(std::make_pair(valueName, PropertyValue::createStringPropertyValue(value, readOnly)));
    
    return result.second;
}

bool PropertyGroup::addValue (const std::string & valueName, int value, bool readOnly)
{
    auto result = mValues.insert(std::make_pair(valueName, PropertyValue::createIntegerPropertyValue(value, readOnly)));
    
    return result.second;
}

bool PropertyGroup::addValue (const std::string & valueName, double value, bool readOnly)
{
    auto result = mValues.insert(std::make_pair(valueName, PropertyValue::createFloatingPropertyValue(value, readOnly)));
    
    return result.second;
}

bool PropertyGroup::addValue (const std::string & valueName, bool value, bool readOnly)
{
    auto result = mValues.insert(std::make_pair(valueName, PropertyValue::createBooleanPropertyValue(value, readOnly)));
    
    return result.second;
}

void PropertyGroup::deleteValue (const std::string & valueName)
{
    mValues.erase(valueName);
}

PropertyValue * PropertyGroup::getValue (const std::string & valueName)
{
    auto valueMapResult = mValues.find(valueName);
    if (valueMapResult == mValues.end())
    {
        return nullptr;
    }
    
    return valueMapResult->second.get();
}
    
} // namespace Game
} // namespace TUCUT
