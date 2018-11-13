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

SCENARIO( GameManager, "Operation/Corner", "unit,game", "GameManager cannot add GameObjects without registering token." )
{
    std::string token = "unknown";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameObj = pGameMgr->createGameObject(token);
    VERIFY_TRUE(gameObj == nullptr);
}

SCENARIO( GameManager, "Operation/Normal", "unit,game", "GameManager can add and remove GameObjects." )
{
    std::string token = "token1";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    bool tokenResult = pGameMgr->registerGameObjectToken(token);
    VERIFY_TRUE(tokenResult);

    auto gameObj2 = pGameMgr->createGameObject(token);
    VERIFY_TRUE(gameObj2 != nullptr);
    
    auto gameObj3 = pGameMgr->getGameObject(token, gameObj2->identity());
    VERIFY_TRUE(gameObj3 != nullptr);
    
    VERIFY_EQUAL(3, static_cast<int>(gameObj2.use_count()));
    VERIFY_EQUAL(3, static_cast<int>(gameObj3.use_count()));
    
    pGameMgr->removeGameObject(token, gameObj2->identity());
    
    auto gameObj4 = pGameMgr->getGameObject(token, gameObj2->identity());
    VERIFY_TRUE(gameObj4 == nullptr);
    
    VERIFY_EQUAL(2, static_cast<int>(gameObj2.use_count()));
    VERIFY_EQUAL(2, static_cast<int>(gameObj3.use_count()));
}
