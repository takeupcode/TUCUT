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
#include "TestSimpleComponent.h"
#include "TestDependentComponent.h"
#include "TestSimpleSystem.h"
#include "TestDependentSystem.h"

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
    
    auto gameSys = pGameMgr->getOrCreateGameSystem<Test::TestSimpleSystem>(token);
}

SCENARIO( GameSystem, "Operation/Normal", "unit,game", "Derived GameSystem can get shared pointer." )
{
    std::string token = "testAction";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameSys = pGameMgr->getOrCreateGameSystem<Test::TestSimpleSystem>(token);

    auto sharedPtr = gameSys->getSharedTestSimpleSystem();
    
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
    
    auto gameSys = pGameMgr->getOrCreateGameSystem<Test::TestSimpleSystem>(tokenSystem);
    auto gameComp = pGameMgr->getOrCreateGameComponent<Game::GameComponent>(tokenComp);
    auto gameActionId = pGameMgr->getOrCreateGameAction(tokenAction);
    
    pGameMgr->queueGameAction(gameComp->identity(), gameActionId);
    pGameMgr->update(Game::TimeResolution(5));
    
    VERIFY_TRUE(gameSys->notified());
    VERIFY_EQUAL(gameComp->identity(), gameSys->objectId());
    VERIFY_EQUAL(gameActionId, gameSys->actionId());
    
    // Make sure actions only get handled once.
    gameSys->reset();
    pGameMgr->update(Game::TimeResolution(5));
    
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
    
    auto gameSys = pGameMgr->getOrCreateGameSystem<Test::TestSimpleSystem>(tokenSystem);
    auto gameComp = pGameMgr->getOrCreateGameComponent<Game::GameComponent>(tokenComp);
    auto gameObj = pGameMgr->createGameObject<Game::GameObject>(tokenObject);
    
    // Since the simple system class has no required abilities, it should be added right away.
    VERIFY_TRUE(gameSys->hasGameObject(gameObj->identity()));
    
    gameObj->addGameComponent(gameComp);
    
    // Since the simple system class has no required abilities, the object should stay in the system.
    VERIFY_TRUE(gameSys->hasGameObject(gameObj->identity()));
    
    gameObj->removeGameComponent(gameComp);
    
    // Since the simple system class has no required abilities, the object should stay in the system.
    VERIFY_TRUE(gameSys->hasGameObject(gameObj->identity()));

    pGameMgr->removeGameObject(gameObj->identity());
    
    VERIFY_FALSE(gameSys->hasGameObject(gameObj->identity()));
}

SCENARIO( GameSystem, "Operation/Normal", "unit,game", "Derived GameSystem adds objects." )
{
    std::string tokenSystem = "DependentSystem";
    std::string tokenCompSimple = "SimpleComponent";
    std::string tokenCompDependent = "DependentComponent";
    std::string tokenObject = "object";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameSys = pGameMgr->getOrCreateGameSystem<Test::TestDependentSystem>(tokenSystem);
    auto gameCompSimple = pGameMgr->getOrCreateGameComponent<Test::TestSimpleComponent>(tokenCompSimple);
    auto gameCompDependent = pGameMgr->getOrCreateGameComponent<Test::TestDependentComponent>(tokenCompDependent);
    auto gameObj = pGameMgr->createGameObject<Game::GameObject>(tokenObject);
    
    VERIFY_FALSE(gameSys->hasGameObject(gameObj->identity()));
    
    gameObj->addGameComponent(gameCompDependent);
    
    // The system depends on the Ability1 and Ability2 abilities.
    VERIFY_FALSE(gameSys->hasGameObject(gameObj->identity()));
    
    gameObj->addGameComponent(gameCompSimple);
    
    VERIFY_TRUE(gameSys->hasGameObject(gameObj->identity()));

    gameObj->removeGameComponent(gameCompSimple);

    VERIFY_FALSE(gameSys->hasGameObject(gameObj->identity()));
}
