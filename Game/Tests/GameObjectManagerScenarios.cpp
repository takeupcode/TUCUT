//
//  GameObjectManagerScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 8/19/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../GameObjectManager.h"

using namespace std;
using namespace TUCUT;

SCENARIO( GameObjectManager, "Construction/Singleton", "unit,game", "GameObjectManager instances are the same." )
{
    Game::GameObjectManager * pGameObjectMgr1 = Game::GameObjectManager::instance();
    Game::GameObjectManager * pGameObjectMgr2 = Game::GameObjectManager::instance();
    
    VERIFY_TRUE(pGameObjectMgr1 != nullptr);
    VERIFY_SAMEPTR(pGameObjectMgr1, pGameObjectMgr2);
}

SCENARIO( GameObjectManager, "Operation/Normal", "unit,game", "GameObjectManager can add and remove GameObjects." )
{
    Game::GameObjectManager * pGameObjectMgr = Game::GameObjectManager::instance();
    
    auto gameObj = pGameObjectMgr->getGameObject("test");
    VERIFY_TRUE(gameObj == nullptr);
    
    bool result = pGameObjectMgr->addGameObject("test", Game::GameObject::createSharedGameObject());
    VERIFY_TRUE(result);
    
    gameObj = pGameObjectMgr->getGameObject("test");
    VERIFY_TRUE(gameObj != nullptr);
    
    result = pGameObjectMgr->addGameObject("test", Game::GameObject::createSharedGameObject());
    VERIFY_FALSE(result);
    
    pGameObjectMgr->removeGameObject("test");
    result = pGameObjectMgr->addGameObject("test", Game::GameObject::createSharedGameObject());
    VERIFY_TRUE(result);
    
    auto gameObj2 = pGameObjectMgr->getGameObject("test");
    VERIFY_TRUE(gameObj != nullptr);
    
    VERIFY_EQUAL(1, static_cast<int>(gameObj.use_count()));
    VERIFY_EQUAL(2, static_cast<int>(gameObj2.use_count()));
}
