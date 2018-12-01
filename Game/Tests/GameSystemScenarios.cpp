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
#include "TestActionSystem.h"

using namespace std;
using namespace TUCUT;

SCENARIO( GameSystem, "Construction/Normal", "unit,game", "GameSystem can be constructed." )
{
    std::string token = "render";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameSys = pGameMgr->getOrCreateGameSystem<Game::GameSystem>(token);
}

SCENARIO( GameSystem, "Operation/Normal", "unit,game", "GameSystem can get shared pointer." )
{
    std::string token = "render";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameSys = pGameMgr->getOrCreateGameSystem<Game::GameSystem>(token);

    auto sharedPtr = gameSys->getSharedGameSystem();
    
    VERIFY_EQUAL(3, static_cast<int>(sharedPtr.use_count()));
    VERIFY_SAMEPTR(gameSys.get(), sharedPtr.get());
}

SCENARIO( GameSystem, "Construction/Normal", "unit,game", "Derived GameSystem can be constructed." )
{
    std::string token = "testAction";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameSys = pGameMgr->getOrCreateGameSystem<Test::TestActionSystem>(token);
}

SCENARIO( GameSystem, "Operation/Normal", "unit,game", "Derived GameSystem can get shared pointer." )
{
    std::string token = "testAction";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameSys = pGameMgr->getOrCreateGameSystem<Test::TestActionSystem>(token);

    auto sharedPtr = gameSys->getSharedTestActionSystem();
    
    VERIFY_EQUAL(3, static_cast<int>(sharedPtr.use_count()));
    VERIFY_SAMEPTR(gameSys.get(), sharedPtr.get());
    
    VERIFY_FALSE(gameSys->notified());
    VERIFY_EQUAL(0, gameSys->objectId());
    VERIFY_EQUAL(0, gameSys->actionId());
    VERIFY_FALSE(sharedPtr->notified());
    VERIFY_EQUAL(0, sharedPtr->objectId());
    VERIFY_EQUAL(0, sharedPtr->actionId());
}

SCENARIO( GameSystem, "Operation/Normal", "unit,game", "Derived GameSystem is notified of action." )
{
    std::string tokenSystem = "actionSystem";
    std::string tokenComp = "player";
    std::string tokenAction = "moveAction";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameSys = pGameMgr->getOrCreateGameSystem<Test::TestActionSystem>(tokenSystem);
    auto gameComp = pGameMgr->getOrCreateGameComponent<Game::GameComponent>(tokenComp);
    auto gameActionId = pGameMgr->getOrCreateGameAction(tokenAction);
    
    pGameMgr->queueGameAction(gameComp->identity(), gameActionId);
    pGameMgr->update();
    
    VERIFY_TRUE(gameSys->notified());
    VERIFY_EQUAL(gameComp->identity(), gameSys->objectId());
    VERIFY_EQUAL(gameActionId, gameSys->actionId());
    
    // Make sure actions only get handled once.
    gameSys->reset();
    pGameMgr->update();
    
    VERIFY_FALSE(gameSys->notified());
    VERIFY_EQUAL(0, gameSys->objectId());
    VERIFY_EQUAL(0, gameSys->actionId());
}

SCENARIO( GameSystem, "Operation/Normal", "unit,game", "GameSystem adds objects." )
{
    std::string tokenSystem = "actionSystem";
    std::string tokenComp = "player";
    std::string tokenObject = "object";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameSys = pGameMgr->getOrCreateGameSystem<Test::TestActionSystem>(tokenSystem);
    auto gameComp = pGameMgr->getOrCreateGameComponent<Game::GameComponent>(tokenComp);
    auto gameObj = pGameMgr->createGameObject<Game::GameObject>(tokenObject);
    
    VERIFY_FALSE(gameSys->hasGameObject(gameObj->identity()));
    
    // The object needs to be modified in order to trigger the addition to the system.
    gameObj->addGameComponent(gameComp);
    
    VERIFY_TRUE(gameSys->hasGameObject(gameObj->identity()));
    
    // Since the base GameSystem class has no required components, the object should stay in the system.
    gameObj->removeGameComponent(gameComp);
    
    VERIFY_TRUE(gameSys->hasGameObject(gameObj->identity()));
}
