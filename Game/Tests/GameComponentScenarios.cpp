//
//  GameComponentScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 11/19/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../GameComponent.h"

using namespace std;
using namespace TUCUT;

SCENARIO( GameComponent, "Construction/Normal", "unit,game", "GameComponent can be constructed." )
{
    auto gameComp = Game::GameComponent::createSharedGameComponent("moveable", 1);
}

SCENARIO( GameComponent, "Operation/Normal", "unit,game", "GameComponent can get shared pointer." )
{
    auto gameComp = Game::GameComponent::createSharedGameComponent("moveable", 1);
    
    auto sharedPtr = gameComp->getSharedGameComponent();
    
    VERIFY_EQUAL(2, static_cast<int>(sharedPtr.use_count()));
    VERIFY_SAMEPTR(gameComp.get(), sharedPtr.get());
}
