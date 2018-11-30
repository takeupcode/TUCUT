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
#include "../GameObject.h"
#include "../GameManager.h"
#include "TestSimpleComponent.h"
#include "TestDependentComponent.h"

using namespace std;
using namespace TUCUT;

SCENARIO( GameComponent, "Construction/Normal", "unit,game", "GameComponent can be constructed." )
{
    std::string token = "moveable";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameComp = pGameMgr->getOrCreateGameComponent<Game::GameComponent>(token);
}

SCENARIO( GameComponent, "Operation/Normal", "unit,game", "GameComponent can get shared pointer." )
{
    std::string token = "moveable";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameComp = pGameMgr->getOrCreateGameComponent<Game::GameComponent>(token);
    
    auto sharedPtr = gameComp->getSharedGameComponent();
    
    VERIFY_EQUAL(3, static_cast<int>(sharedPtr.use_count()));
    VERIFY_SAMEPTR(gameComp.get(), sharedPtr.get());
}

SCENARIO( GameComponent, "Operation/Normal", "unit,game", "Game components know dependencies." )
{
    std::string tokenCompSimple = "SimpleComponent";
    std::string tokenCompDependent = "DependentComponent";
    std::string tokenObject = "object1";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameCompDependent = pGameMgr->getOrCreateGameComponent<Test::TestDependentComponent>(tokenCompDependent);
    auto gameObj = pGameMgr->createGameObject<Game::GameObject>(tokenObject);
    
    // Make sure requirements are not met when no component has been added.
    // Simple component doesn't even exist yet.
    auto result = gameCompDependent->hasRequiredComponents(gameObj->identity());
    VERIFY_FALSE(result);
    
    result = gameCompDependent->hasRequiredComponents(gameObj);
    VERIFY_FALSE(result);
    
    gameObj->addGameComponent(gameCompDependent);
    
    // Make sure requirements are not met when only dependent component has been added.
    result = gameCompDependent->hasRequiredComponents(gameObj->identity());
    VERIFY_FALSE(result);
    
    result = gameCompDependent->hasRequiredComponents(gameObj);
    VERIFY_FALSE(result);
    
    auto gameCompSimple = pGameMgr->getOrCreateGameComponent<Test::TestSimpleComponent>(tokenCompSimple);
    
    // Make sure requirements are not met when simple component has been created but not added.
    result = gameCompDependent->hasRequiredComponents(gameObj->identity());
    VERIFY_FALSE(result);
    
    result = gameCompDependent->hasRequiredComponents(gameObj);
    VERIFY_FALSE(result);
    
    gameObj->addGameComponent(gameCompSimple->identity());
    
    // Make sure all requirements are now met.
    result = gameCompDependent->hasRequiredComponents(gameObj->identity());
    VERIFY_TRUE(result);
    
    result = gameCompDependent->hasRequiredComponents(gameObj);
    VERIFY_TRUE(result);
    
    result = gameCompSimple->hasRequiredComponents(gameObj->identity());
    VERIFY_TRUE(result);
    
    result = gameCompSimple->hasRequiredComponents(gameObj);
    VERIFY_TRUE(result);
    
    // Make sure requirement check works for nonexistent objects.
    result = gameCompDependent->hasRequiredComponents(0);
    VERIFY_FALSE(result);
    
    result = gameCompSimple->hasRequiredComponents(-1);
    VERIFY_FALSE(result);
    
    pGameMgr->removeGameObject(gameObj->identity());
    
    // Make sure all requirements are not met for removed objects.
    result = gameCompDependent->hasRequiredComponents(gameObj->identity());
    VERIFY_FALSE(result);
    
    result = gameCompDependent->hasRequiredComponents(gameObj);
    VERIFY_FALSE(result);
    
    result = gameCompSimple->hasRequiredComponents(gameObj->identity());
    VERIFY_FALSE(result);
    
    result = gameCompSimple->hasRequiredComponents(gameObj);
    VERIFY_FALSE(result);
}
