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
    VERIFY_TRUE(group != nullptr);
    VERIFY_EQUAL(group, group2);
    
    auto value = container.getValue("test1", "testValue1");
    VERIFY_TRUE(value != nullptr);
    VERIFY_EQUAL("abc", value->getString());
    
    container.deleteGroup("test1");
    group = container.getGroup("test1");
    VERIFY_TRUE(group == nullptr);
}
