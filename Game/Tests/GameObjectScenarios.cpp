//
//  GameObjectScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 8/19/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../GameObject.h"

using namespace std;
using namespace TUCUT;

SCENARIO( GameObject, "Construction/Normal", "unit,game", "GameObject can be constructed." )
{
    auto gameObj = Game::GameObject::createSharedGameObject("character", 1);
}

SCENARIO( GameObject, "Operation/Normal", "unit,game", "GameObject can get shared pointer." )
{
    auto gameObj = Game::GameObject::createSharedGameObject("character", 1);
    
    auto sharedPtr = gameObj->getSharedGameObject();
    
    VERIFY_EQUAL(2, static_cast<int>(sharedPtr.use_count()));
    VERIFY_SAMEPTR(gameObj.get(), sharedPtr.get());
}

SCENARIO( GameObject, "Operation/Normal", "unit,game", "GameObject has properties." )
{
    auto gameObj = Game::GameObject::createSharedGameObject("character", 1);
    
    auto & properties = gameObj->properties();
    auto group = properties.getGroup("not found");
    
    VERIFY_TRUE(group == nullptr);
}

SCENARIO( GameObject, "Operation/Normal", "unit,game", "GameObject can add and remove components." )
{
    auto gameObj = Game::GameObject::createSharedGameObject("character", 1);

    auto gameComp1 = Game::GameComponent::createSharedGameComponent("moveable", 1);
    auto gameComp2 = Game::GameComponent::createSharedGameComponent("drawable", 3);
    auto gameComp3 = Game::GameComponent::createSharedGameComponent("controllable", 10);

    auto result = gameObj->addGameComponent(1);
    VERIFY_TRUE(result);

    result = gameObj->addGameComponent(gameComp2);
    VERIFY_TRUE(result);

    result = gameObj->hasGameComponent(gameComp2);
    VERIFY_TRUE(result);

    result = gameObj->hasGameComponent(2);
    VERIFY_FALSE(result);

    result = gameObj->hasGameComponent(gameComp3);
    VERIFY_FALSE(result);

    gameObj->removeGameComponent(gameComp2);
    result = gameObj->hasGameComponent(gameComp2);
    VERIFY_FALSE(result);
}
