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
#include "GameManagerSubscriber.h"

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

    auto gameObj1 = pGameMgr->createGameObject<Game::GameObject>(token);
    VERIFY_TRUE(gameObj1 != nullptr);
    
    auto result = pGameMgr->hasGameObject(token, gameObj1->identity());
    VERIFY_TRUE(result);
    
    result = pGameMgr->hasGameObject("unknown", gameObj1->identity());
    VERIFY_FALSE(result);
    
    result = pGameMgr->hasGameObject(token, 123456);
    VERIFY_FALSE(result);

    auto gameObj2 = pGameMgr->getGameObject<Game::GameObject>(token, gameObj1->identity());
    VERIFY_TRUE(gameObj2 != nullptr);
    
    VERIFY_EQUAL(3, static_cast<int>(gameObj1.use_count()));
    VERIFY_EQUAL(3, static_cast<int>(gameObj2.use_count()));
    
    pGameMgr->removeGameObject(token, gameObj1->identity());
    
    result = pGameMgr->hasGameObject(token, gameObj1->identity());
    VERIFY_FALSE(result);

    auto gameObj3 = pGameMgr->getGameObject<Game::GameObject>(token, gameObj1->identity());
    VERIFY_TRUE(gameObj3 == nullptr);
    
    VERIFY_EQUAL(2, static_cast<int>(gameObj1.use_count()));
    VERIFY_EQUAL(2, static_cast<int>(gameObj2.use_count()));
}

SCENARIO( GameManager, "Operation/Corner", "unit,game", "GameManager knows invalid GameObject identities." )
{
    std::string token = "token1";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameObj1 = pGameMgr->createGameObject<Game::GameObject>(token);
    VERIFY_TRUE(gameObj1 != nullptr);
    
    auto gameObj2 = pGameMgr->getGameObject<Game::GameObject>(token, 0);
    VERIFY_TRUE(gameObj2 == nullptr);
    
    auto gameObj3 = pGameMgr->getGameObject<Game::GameObject>(token, -1);
    VERIFY_TRUE(gameObj3 == nullptr);
    
    pGameMgr->removeGameObject(token, 0);
    pGameMgr->removeGameObject(token, -1);
    
    auto result = pGameMgr->hasGameObject(token, 0);
    VERIFY_FALSE(result);
    
    result = pGameMgr->hasGameObject(token, -1);
    VERIFY_FALSE(result);

    auto gameObj4 = pGameMgr->getGameObject<Game::GameObject>(token, gameObj1->identity());
    VERIFY_TRUE(gameObj4 != nullptr);
    
    result = pGameMgr->hasGameObject(token, gameObj4->identity());
    VERIFY_TRUE(result);
}

SCENARIO( GameManager, "Operation/Normal", "unit,game", "GameManager can add GameComponents." )
{
    std::string token1 = "token1";
    std::string token2 = "token2";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto result = pGameMgr->hasGameComponent(token1);
    VERIFY_FALSE(result);

    auto gameComp1 = pGameMgr->getGameComponent<Game::GameComponent>(token1);
    VERIFY_TRUE(gameComp1 != nullptr);
    
    result = pGameMgr->hasGameComponent(gameComp1->identity());
    VERIFY_TRUE(result);
    
    result = pGameMgr->hasGameComponent(token1);
    VERIFY_TRUE(result);

    auto gameComp2 = pGameMgr->getGameComponent<Game::GameComponent>(token2);
    VERIFY_TRUE(gameComp2 != nullptr);
    
    auto gameComp3 = pGameMgr->getGameComponent<Game::GameComponent>(token1);
    VERIFY_TRUE(gameComp3 != nullptr);

    VERIFY_EQUAL(3, static_cast<int>(gameComp1.use_count()));
    VERIFY_EQUAL(2, static_cast<int>(gameComp2.use_count()));
    
    auto gameComp4 = pGameMgr->getGameComponent<Game::GameComponent>(10);
    VERIFY_TRUE(gameComp4 == nullptr);
    
    result = pGameMgr->hasGameComponent(10);
    VERIFY_FALSE(result);

    auto gameComp5 = pGameMgr->getGameComponent<Game::GameComponent>(gameComp1->identity());
    VERIFY_TRUE(gameComp5 != nullptr);
}

SCENARIO( GameManager, "Operation/Corner", "unit,game", "GameManager knows invalid GameComponent identities." )
{
    std::string token = "state";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameComp1 = pGameMgr->getGameComponent<Game::GameComponent>(token);
    VERIFY_TRUE(gameComp1 != nullptr);
    
    auto gameComp2 = pGameMgr->getGameComponent<Game::GameComponent>(0);
    VERIFY_TRUE(gameComp2 == nullptr);
    
    auto gameComp3 = pGameMgr->getGameComponent<Game::GameComponent>(-1);
    VERIFY_TRUE(gameComp3 == nullptr);
    
    auto result = pGameMgr->hasGameComponent(0);
    VERIFY_FALSE(result);
    
    result = pGameMgr->hasGameComponent(-1);
    VERIFY_FALSE(result);

    auto gameComp4 = pGameMgr->getGameComponent<Game::GameComponent>(gameComp1->identity());
    VERIFY_TRUE(gameComp4 != nullptr);
}

SCENARIO( GameManager, "Operation/Normal", "unit,game", "GameManager notifies new and removing component." )
{
    std::string token = "character";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    std::shared_ptr<Test::GameManagerSubscriber> subscriber(new Test::GameManagerSubscriber());
    pGameMgr->gameObjectCreated()->connect("test", subscriber);
    pGameMgr->gameObjectRemoving()->connect("test", subscriber);

    VERIFY_FALSE(subscriber->notified());
    VERIFY_EQUAL(0, subscriber->id());
    
    auto gameObj = pGameMgr->createGameObject<Game::GameObject>(token);
    VERIFY_TRUE(gameObj != nullptr);
    VERIFY_TRUE(subscriber->notified());
    VERIFY_EQUAL(Game::GameManager::GameObjectCreatedEventId, subscriber->id());
    subscriber->reset();
    
    pGameMgr->removeGameObject(gameObj->token(), 100);
    VERIFY_FALSE(subscriber->notified());
    VERIFY_EQUAL(0, subscriber->id());
    
    pGameMgr->removeGameObject("unknown", gameObj->identity());
    VERIFY_FALSE(subscriber->notified());
    VERIFY_EQUAL(0, subscriber->id());

    pGameMgr->removeGameObject(gameObj->token(), gameObj->identity());
    VERIFY_TRUE(subscriber->notified());
    VERIFY_EQUAL(Game::GameManager::GameObjectRemovingEventId, subscriber->id());

    pGameMgr->gameObjectCreated()->disconnect("test");
    pGameMgr->gameObjectRemoving()->disconnect("test");
}
