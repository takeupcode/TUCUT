//
//  GameManagerScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 8/19/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../GameManager.h"

using namespace std;
using namespace TUCUT;

SCENARIO( GameManager, "Construction/Singleton", "unit,game", "GameManager instances are the same." )
{
    Game::GameManager * pGameMgr1 = Game::GameManager::instance();
    Game::GameManager * pGameMgr2 = Game::GameManager::instance();
    
    VERIFY_TRUE(pGameMgr1 != nullptr);
    VERIFY_SAMEPTR(pGameMgr1, pGameMgr2);
}

SCENARIO( GameManager, "Operation/Normal", "unit,game", "GameManager can add and remove GameObjects." )
{
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameObj1 = pGameMgr->getGameObject(1);
    VERIFY_TRUE(gameObj1 == nullptr);
    
    auto gameObj2 = pGameMgr->createGameObject("character");
    VERIFY_TRUE(gameObj2 != nullptr);
    
    auto gameObj3 = pGameMgr->getGameObject(gameObj2->identity());
    VERIFY_TRUE(gameObj3 != nullptr);
    
    VERIFY_EQUAL(3, static_cast<int>(gameObj2.use_count()));
    VERIFY_EQUAL(3, static_cast<int>(gameObj3.use_count()));
}
