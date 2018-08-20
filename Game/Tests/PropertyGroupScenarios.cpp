//
//  PropertyGroupScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 8/19/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../PropertyGroup.h"

using namespace std;
using namespace TUCUT;

SCENARIO( PropertyGroup, "Construction/Normal", "unit,game", "PropertyGroup can be constructed." )
{
    auto group = Game::PropertyGroup();
}

SCENARIO( PropertyGroup, "Operation/Normal", "unit,game", "PropertyGroup can add and delete values." )
{
    auto group = Game::PropertyGroup();
    
    auto value1 = group.getValue("test1");
    VERIFY_TRUE(value1 == nullptr);

    auto result = group.addValue("test1", "abc");
    VERIFY_TRUE(result);
    
    result = group.addValue("test1", "def");
    VERIFY_FALSE(result);
    
    result = group.addValue("test2", 5);
    VERIFY_TRUE(result);
    result = group.addValue("test3", 1.5);
    VERIFY_TRUE(result);
    result = group.addValue("test4", true);
    VERIFY_TRUE(result);

    value1 = group.getValue("test1");
    auto value2 = group.getValue("test2");
    auto value3 = group.getValue("test3");
    auto value4 = group.getValue("test4");

    VERIFY_TRUE(value1 != nullptr);
    VERIFY_TRUE(value2 != nullptr);
    VERIFY_TRUE(value3 != nullptr);
    VERIFY_TRUE(value4 != nullptr);

    VERIFY_EQUAL("abc", value1->getString());
    VERIFY_EQUAL(5, value2->getInteger());
    VERIFY_EQUAL(1.5, value3->getFloating());
    VERIFY_EQUAL(true, value4->getBoolean());
    
    group.deleteValue("test1");
    value1 = group.getValue("test1");
    VERIFY_TRUE(value1 == nullptr);
}
