//
//  PropertyValue.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 7/31/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "PropertyValue.h"

#include <stdexcept>

namespace TUCUT {
namespace Game {

std::unique_ptr<PropertyValue> PropertyValue::createStringPropertyValue (const std::string & value, bool readOnly)
{
    return std::unique_ptr<PropertyValue>(new StringPropertyValue(value, readOnly));
}

std::unique_ptr<PropertyValue> PropertyValue::createIntegerPropertyValue (int value, bool readOnly)
{
    return std::unique_ptr<PropertyValue>(new IntegerPropertyValue(value, readOnly));
}

std::unique_ptr<PropertyValue> PropertyValue::createFloatingPropertyValue (double value, bool readOnly)
{
    return std::unique_ptr<PropertyValue>(new FloatingPropertyValue(value, readOnly));
}

std::unique_ptr<PropertyValue> PropertyValue::createBooleanPropertyValue (bool value, bool readOnly)
{
    return std::unique_ptr<PropertyValue>(new BooleanPropertyValue(value, readOnly));
}

std::string PropertyValue::getString () const
{
    throw std::runtime_error("Wrong type of PropertyValue");
}

int PropertyValue::getInteger () const
{
    throw std::runtime_error("Wrong type of PropertyValue");
}

double PropertyValue::getFloating () const
{
    throw std::runtime_error("Wrong type of PropertyValue");
}

bool PropertyValue::getBoolean () const
{
    throw std::runtime_error("Wrong type of PropertyValue");
}

void PropertyValue::setString (const std::string &)
{
    throw std::runtime_error("Wrong type of PropertyValue");
}

void PropertyValue::setInteger (int)
{
    throw std::runtime_error("Wrong type of PropertyValue");
}

void PropertyValue::setFloating (double)
{
    throw std::runtime_error("Wrong type of PropertyValue");
}

void PropertyValue::setBoolean (bool)
{
    throw std::runtime_error("Wrong type of PropertyValue");
}
    
} // namespace Game
} // namespace TUCUT
