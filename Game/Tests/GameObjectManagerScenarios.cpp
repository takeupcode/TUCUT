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
    
    auto gameObj1 = pGameObjectMgr->getGameObject(1);
    VERIFY_TRUE(gameObj1 == nullptr);
    
    auto gameObj2 = pGameObjectMgr->createGameObject("character");
    VERIFY_TRUE(gameObj2 != nullptr);
    
    auto gameObj3 = pGameObjectMgr->getGameObject(gameObj2->identity());
    VERIFY_TRUE(gameObj3 != nullptr);
    
    VERIFY_EQUAL(3, static_cast<int>(gameObj2.use_count()));
    VERIFY_EQUAL(3, static_cast<int>(gameObj3.use_count()));
}
