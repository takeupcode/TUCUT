//
//  PropertyContainerScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 8/19/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../PropertyContainer.h"

using namespace std;
using namespace TUCUT;

SCENARIO( PropertyContainer, "Construction/Normal", "unit,game", "PropertyContainer can be constructed." )
{
    auto container = Game::PropertyContainer();
}

SCENARIO( PropertyContainer, "Construction/Normal", "unit,game", "PropertyContainer can be copied." )
{
    auto container1 = Game::PropertyContainer();
    
    auto group1 = container1.addGroup("test1");
    VERIFY_TRUE(group1 != nullptr);
    auto group2 = container1.addGroup("test2");
    VERIFY_TRUE(group2 != nullptr);

    auto result = group1->addValue("testValue1", "abc");
    VERIFY_TRUE(result);
    
    auto container2 = Game::PropertyContainer();
    
    auto group3 = container2.addGroup("test3");
    VERIFY_TRUE(group3 != nullptr);
    auto group4 = container2.addGroup("test4");
    VERIFY_TRUE(group4 != nullptr);
    
    result = group3->addValue("testValue3", "def");
    VERIFY_TRUE(result);
    
    Game::PropertyContainer container3(container1);
    
    auto group5 = container3.getGroup("test1");
    VERIFY_TRUE(group5 != nullptr);
    auto group6 = container3.getGroup("test2");
    VERIFY_TRUE(group6 != nullptr);

    auto value1 = container3.getValue("test1", "testValue1");
    VERIFY_TRUE(value1 != nullptr);
    VERIFY_EQUAL("abc", value1->getString());
    
    container3 = container2;
    
    auto group7 = container3.getGroup("test3");
    VERIFY_TRUE(group7 != nullptr);
    auto group8 = container3.getGroup("test4");
    VERIFY_TRUE(group8 != nullptr);
    
    auto value2 = container3.getValue("test3", "testValue3");
    VERIFY_TRUE(value2 != nullptr);
    VERIFY_EQUAL("def", value2->getString());
}

SCENARIO( PropertyContainer, "Operation/Normal", "unit,game", "PropertyContainer can add and delete groups." )
{
    auto container = Game::PropertyContainer();
    
    auto group = container.getGroup("test1");
    VERIFY_TRUE(group == nullptr);
    
    group = container.addGroup("test1");
    VERIFY_TRUE(group != nullptr);
    
    auto result = group->addValue("testValue1", "abc");
    VERIFY_TRUE(result);
    
    auto group2 = container.getGroup("test1");
    VERIFY_SAMEPTR(group, group2);
    
    auto value = container.getValue("test1", "testValue1");
    VERIFY_TRUE(value != nullptr);
    VERIFY_EQUAL("abc", value->getString());
    
    container.deleteGroup("test1");
    group = container.getGroup("test1");
    VERIFY_TRUE(group == nullptr);
}

SCENARIO( PropertyContainer, "Operation/Normal", "unit,game", "PropertyContainer knows groups." )
{
    auto container = Game::PropertyContainer();
    
    auto group = container.addGroup("test1");
    VERIFY_TRUE(group != nullptr);
    group = container.addGroup("test2");
    VERIFY_TRUE(group != nullptr);
    
    auto result = container.hasGroup("test1");
    VERIFY_TRUE(result);
    
    result = container.hasGroup("test2");
    VERIFY_TRUE(result);
    
    result = container.hasGroup("test3");
    VERIFY_FALSE(result);
    
    result = container.hasAllGroups({"test1"});
    VERIFY_TRUE(result);
    
    result = container.hasAllGroups({"test2"});
    VERIFY_TRUE(result);
    
    result = container.hasAllGroups({"test3"});
    VERIFY_FALSE(result);
    
    result = container.hasAllGroups({"test1", "test2"});
    VERIFY_TRUE(result);
    
    result = container.hasAllGroups({"test1", "test2", "test3"});
    VERIFY_FALSE(result);
}
