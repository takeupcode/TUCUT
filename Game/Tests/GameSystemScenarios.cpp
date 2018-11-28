//
//  GameSystemScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 11/28/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../GameSystem.h"
#include "../GameManager.h"

using namespace std;
using namespace TUCUT;

SCENARIO( GameSystem, "Construction/Normal", "unit,game", "GameSystem can be constructed." )
{
    std::string token = "render";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameSys = pGameMgr->getGameSystem<Game::GameSystem>(token);
}

SCENARIO( GameSystem, "Operation/Normal", "unit,game", "GameSystem can get shared pointer." )
{
    std::string token = "render";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameSys = pGameMgr->getGameSystem<Game::GameSystem>(token);

    auto sharedPtr = gameSys->getSharedGameSystem();
    
    VERIFY_EQUAL(3, static_cast<int>(sharedPtr.use_count()));
    VERIFY_SAMEPTR(gameSys.get(), sharedPtr.get());
}
