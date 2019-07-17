//
//  PropertyValueScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 8/19/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../PropertyValue.h"

using namespace std;
using namespace TUCUT;

SCENARIO( PropertyValue, "Construction/Normal", "unit,game", "PropertyValue can be constructed." )
{
    auto stringValue = Game::PropertyValue::createStringPropertyValue();
    auto integerValue = Game::PropertyValue::createIntegerPropertyValue();
    auto floatingValue = Game::PropertyValue::createFloatingPropertyValue();
    auto booleanValue = Game::PropertyValue::createBooleanPropertyValue();

    VERIFY_EQUAL("", stringValue->getString());
    VERIFY_EQUAL(0, integerValue->getInteger());
    VERIFY_EQUAL(0.0, floatingValue->getFloating());
    VERIFY_EQUAL(false, booleanValue->getBoolean());
    
    VERIFY_TRUE(stringValue->isString());
    VERIFY_FALSE(stringValue->isInteger());
    VERIFY_FALSE(stringValue->isFloating());
    VERIFY_FALSE(stringValue->isBoolean());
    
    VERIFY_FALSE(integerValue->isString());
    VERIFY_TRUE(integerValue->isInteger());
    VERIFY_FALSE(integerValue->isFloating());
    VERIFY_FALSE(integerValue->isBoolean());
    
    VERIFY_FALSE(floatingValue->isString());
    VERIFY_FALSE(floatingValue->isInteger());
    VERIFY_TRUE(floatingValue->isFloating());
    VERIFY_FALSE(floatingValue->isBoolean());
    
    VERIFY_FALSE(booleanValue->isString());
    VERIFY_FALSE(booleanValue->isInteger());
    VERIFY_FALSE(booleanValue->isFloating());
    VERIFY_TRUE(booleanValue->isBoolean());
}

SCENARIO( PropertyValue, "Construction/Normal", "unit,game", "PropertyValue can be constructed with values." )
{
    auto stringValue = Game::PropertyValue::createStringPropertyValue("test", true);
    auto integerValue = Game::PropertyValue::createIntegerPropertyValue(5, true);
    auto floatingValue = Game::PropertyValue::createFloatingPropertyValue(1.5, true);
    auto booleanValue = Game::PropertyValue::createBooleanPropertyValue(true, true);
    
    VERIFY_EQUAL("test", stringValue->getString());
    VERIFY_EQUAL(5, integerValue->getInteger());
    VERIFY_EQUAL(1.5, floatingValue->getFloating());
    VERIFY_EQUAL(true, booleanValue->getBoolean());
    
    stringValue->setString("abc");
    integerValue->setInteger(10);
    floatingValue->setFloating(3.5);
    booleanValue->setBoolean(false);
    
    VERIFY_EQUAL("test", stringValue->getString());
    VERIFY_EQUAL(5, integerValue->getInteger());
    VERIFY_EQUAL(1.5, floatingValue->getFloating());
    VERIFY_EQUAL(true, booleanValue->getBoolean());
}

SCENARIO( PropertyValue, "Construction/Normal", "unit,game", "PropertyValue can be cloned." )
{
    auto stringValue = Game::PropertyValue::createStringPropertyValue("test", true);
    auto integerValue = Game::PropertyValue::createIntegerPropertyValue(5, true);
    auto floatingValue = Game::PropertyValue::createFloatingPropertyValue(1.5, true);
    auto booleanValue = Game::PropertyValue::createBooleanPropertyValue(true, true);
    
    VERIFY_EQUAL("test", stringValue->getString());
    VERIFY_EQUAL(5, integerValue->getInteger());
    VERIFY_EQUAL(1.5, floatingValue->getFloating());
    VERIFY_EQUAL(true, booleanValue->getBoolean());
    
    auto stringValue2 = stringValue->clone();
    auto integerValue2 = integerValue->clone();
    auto floatingValue2 = floatingValue->clone();
    auto booleanValue2 = booleanValue->clone();
    
    VERIFY_EQUAL("test", stringValue2->getString());
    VERIFY_EQUAL(5, integerValue2->getInteger());
    VERIFY_EQUAL(1.5, floatingValue2->getFloating());
    VERIFY_EQUAL(true, booleanValue2->getBoolean());
}

SCENARIO( PropertyValue, "Operation/Normal", "unit,game", "PropertyValue can change values." )
{
    auto stringValue = Game::PropertyValue::createStringPropertyValue();
    auto integerValue = Game::PropertyValue::createIntegerPropertyValue();
    auto floatingValue = Game::PropertyValue::createFloatingPropertyValue();
    auto booleanValue = Game::PropertyValue::createBooleanPropertyValue();
    
    stringValue->setString("abc");
    integerValue->setInteger(10);
    floatingValue->setFloating(3.5);
    booleanValue->setBoolean(true);
    
    VERIFY_EQUAL("abc", stringValue->getString());
    VERIFY_EQUAL(10, integerValue->getInteger());
    VERIFY_EQUAL(3.5, floatingValue->getFloating());
    VERIFY_EQUAL(true, booleanValue->getBoolean());
}
