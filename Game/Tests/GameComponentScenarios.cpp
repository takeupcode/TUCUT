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
#include "../GameManager.h"

using namespace std;
using namespace TUCUT;

SCENARIO( GameComponent, "Construction/Normal", "unit,game", "GameComponent can be constructed." )
{
    std::string token = "moveable";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameComp = pGameMgr->getGameComponent<Game::GameComponent>(token);
}

SCENARIO( GameComponent, "Operation/Normal", "unit,game", "GameComponent can get shared pointer." )
{
    std::string token = "moveable";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameComp = pGameMgr->getGameComponent<Game::GameComponent>(token);
    
    auto sharedPtr = gameComp->getSharedGameComponent();
    
    VERIFY_EQUAL(3, static_cast<int>(sharedPtr.use_count()));
    VERIFY_SAMEPTR(gameComp.get(), sharedPtr.get());
}
