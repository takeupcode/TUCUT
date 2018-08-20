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
    auto gameObj = Game::GameObject::createSharedGameObject();
}

SCENARIO( GameObject, "Operation/Normal", "unit,game", "GameObject can get shared pointer." )
{
    auto gameObj = Game::GameObject::createSharedGameObject();
    
    auto sharedPtr = gameObj->getSharedGameObject();
    
    VERIFY_EQUAL(2, static_cast<int>(sharedPtr.use_count()));
    VERIFY_EQUAL(gameObj.get(), sharedPtr.get());
}

SCENARIO( GameObject, "Operation/Normal", "unit,game", "GameObject has properties." )
{
    auto gameObj = Game::GameObject::createSharedGameObject();
    
    auto & properties = gameObj->properties();
}
