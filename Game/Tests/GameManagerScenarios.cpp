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
    std::string token = "token1";
    Game::GameManager * pGameMgr = Game::GameManager::instance();

    auto gameObj2 = pGameMgr->createGameObject<Game::GameObject>(token);
    VERIFY_TRUE(gameObj2 != nullptr);
    
    auto gameObj3 = pGameMgr->getGameObject<Game::GameObject>(token, gameObj2->identity());
    VERIFY_TRUE(gameObj3 != nullptr);
    
    VERIFY_EQUAL(3, static_cast<int>(gameObj2.use_count()));
    VERIFY_EQUAL(3, static_cast<int>(gameObj3.use_count()));
    
    pGameMgr->removeGameObject(token, gameObj2->identity());
    
    auto gameObj4 = pGameMgr->getGameObject<Game::GameObject>(token, gameObj2->identity());
    VERIFY_TRUE(gameObj4 == nullptr);
    
    VERIFY_EQUAL(2, static_cast<int>(gameObj2.use_count()));
    VERIFY_EQUAL(2, static_cast<int>(gameObj3.use_count()));
}

SCENARIO( GameManager, "Operation/Normal", "unit,game", "GameManager can add GameComponents." )
{
    std::string token1 = "token1";
    std::string token2 = "token2";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameComp1 = pGameMgr->getGameComponent<Game::GameComponent>(token1);
    VERIFY_TRUE(gameComp1 != nullptr);
    
    auto gameComp2 = pGameMgr->getGameComponent<Game::GameComponent>(token2);
    VERIFY_TRUE(gameComp2 != nullptr);
    
    auto gameComp3 = pGameMgr->getGameComponent<Game::GameComponent>(token1);
    VERIFY_TRUE(gameComp3 != nullptr);

    VERIFY_EQUAL(3, static_cast<int>(gameComp1.use_count()));
    VERIFY_EQUAL(2, static_cast<int>(gameComp2.use_count()));
    
    auto gameComp4 = pGameMgr->getGameComponent<Game::GameComponent>(10);
    VERIFY_TRUE(gameComp4 == nullptr);
    
    auto gameComp5 = pGameMgr->getGameComponent<Game::GameComponent>(gameComp1->identity());
    VERIFY_TRUE(gameComp5 != nullptr);
}
