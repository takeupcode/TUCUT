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
    
    group.removeValue("test1");
    value1 = group.getValue("test1");
    VERIFY_TRUE(value1 == nullptr);
}

SCENARIO( PropertyGroup, "Construction/Normal", "unit,game", "PropertyGroup can be copied." )
{
    auto group1 = Game::PropertyGroup();
    
    auto result = group1.addValue("test1", "abc");
    VERIFY_TRUE(result);
    result = group1.addValue("test2", 5);
    VERIFY_TRUE(result);
    result = group1.addValue("test3", 1.5);
    VERIFY_TRUE(result);
    result = group1.addValue("test4", true);
    VERIFY_TRUE(result);
    
    auto group2 = Game::PropertyGroup();
    
    result = group2.addValue("test5", "def");
    VERIFY_TRUE(result);
    result = group2.addValue("test6", 6);
    VERIFY_TRUE(result);
    result = group2.addValue("test7", 2.5);
    VERIFY_TRUE(result);
    result = group2.addValue("test8", false);
    VERIFY_TRUE(result);
    
    Game::PropertyGroup group3(group1);
    auto value1 = group3.getValue("test1");
    auto value2 = group3.getValue("test2");
    auto value3 = group3.getValue("test3");
    auto value4 = group3.getValue("test4");
    
    VERIFY_TRUE(value1 != nullptr);
    VERIFY_TRUE(value2 != nullptr);
    VERIFY_TRUE(value3 != nullptr);
    VERIFY_TRUE(value4 != nullptr);
    
    VERIFY_EQUAL("abc", value1->getString());
    VERIFY_EQUAL(5, value2->getInteger());
    VERIFY_EQUAL(1.5, value3->getFloating());
    VERIFY_EQUAL(true, value4->getBoolean());

    group3 = group2;
    auto value5 = group3.getValue("test5");
    auto value6 = group3.getValue("test6");
    auto value7 = group3.getValue("test7");
    auto value8 = group3.getValue("test8");
    
    VERIFY_TRUE(value5 != nullptr);
    VERIFY_TRUE(value6 != nullptr);
    VERIFY_TRUE(value7 != nullptr);
    VERIFY_TRUE(value8 != nullptr);
    
    VERIFY_EQUAL("def", value5->getString());
    VERIFY_EQUAL(6, value6->getInteger());
    VERIFY_EQUAL(2.5, value7->getFloating());
    VERIFY_EQUAL(false, value8->getBoolean());
}
