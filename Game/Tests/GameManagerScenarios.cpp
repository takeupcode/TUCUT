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
    
    auto result = pGameMgr->hasGameObject(gameObj1->identity());
    VERIFY_TRUE(result);
    
    result = pGameMgr->hasGameObject(123456);
    VERIFY_FALSE(result);

    auto gameObj2 = pGameMgr->getGameObject<Game::GameObject>(gameObj1->identity());
    VERIFY_TRUE(gameObj2 != nullptr);
    
    pGameMgr->removeGameObject(gameObj1->identity());
    
    result = pGameMgr->hasGameObject(gameObj1->identity());
    VERIFY_FALSE(result);

    auto gameObj3 = pGameMgr->getGameObject<Game::GameObject>(gameObj1->identity());
    VERIFY_TRUE(gameObj3 == nullptr);
}

SCENARIO( GameManager, "Operation/Corner", "unit,game", "GameManager knows invalid GameObject identities." )
{
    std::string token = "token1";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameObj1 = pGameMgr->createGameObject<Game::GameObject>(token);
    VERIFY_TRUE(gameObj1 != nullptr);
    
    auto gameObj2 = pGameMgr->getGameObject<Game::GameObject>(0);
    VERIFY_TRUE(gameObj2 == nullptr);
    
    auto gameObj3 = pGameMgr->getGameObject<Game::GameObject>(-1);
    VERIFY_TRUE(gameObj3 == nullptr);
    
    pGameMgr->removeGameObject(0);
    pGameMgr->removeGameObject(-1);
    
    auto result = pGameMgr->hasGameObject(0);
    VERIFY_FALSE(result);
    
    result = pGameMgr->hasGameObject(-1);
    VERIFY_FALSE(result);

    auto gameObj4 = pGameMgr->getGameObject<Game::GameObject>(gameObj1->identity());
    VERIFY_TRUE(gameObj4 != nullptr);
    
    result = pGameMgr->hasGameObject(gameObj4->identity());
    VERIFY_TRUE(result);
}

SCENARIO( GameManager, "Operation/Normal", "unit,game", "GameManager can add GameComponents." )
{
    std::string token1 = "token1";
    std::string token2 = "token2";
    Game::GameManager * pGameMgr = Game::GameManager::instance();

    auto result = pGameMgr->hasGameComponent(token1);
    VERIFY_FALSE(result);

    auto gameComp1 = pGameMgr->getOrCreateGameComponent<Game::GameComponent>(token1);
    VERIFY_TRUE(gameComp1 != nullptr);
    
    auto gameCompId = pGameMgr->getGameComponentId(token1);
    VERIFY_EQUAL(gameComp1->identity(), gameCompId);

    result = pGameMgr->hasGameComponent(gameComp1->identity());
    VERIFY_TRUE(result);
    
    result = pGameMgr->hasGameComponent(token1);
    VERIFY_TRUE(result);

    auto gameComp2 = pGameMgr->getOrCreateGameComponent<Game::GameComponent>(token2);
    VERIFY_TRUE(gameComp2 != nullptr);
    
    auto gameComp3 = pGameMgr->getOrCreateGameComponent<Game::GameComponent>(token1);
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
    
    auto gameComp1 = pGameMgr->getOrCreateGameComponent<Game::GameComponent>(token);
    VERIFY_TRUE(gameComp1 != nullptr);
    
    auto gameComp2 = pGameMgr->getGameComponent<Game::GameComponent>(static_cast<int>(0));
    VERIFY_TRUE(gameComp2 == nullptr);
    
    auto gameComp3 = pGameMgr->getGameComponent<Game::GameComponent>(-1);
    VERIFY_TRUE(gameComp3 == nullptr);
    
    auto gameCompId = pGameMgr->getGameComponentId("unknown");
    VERIFY_EQUAL(0, gameCompId);

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
    
    pGameMgr->removeGameObject(100);
    VERIFY_FALSE(subscriber->notified());
    VERIFY_EQUAL(0, subscriber->id());

    pGameMgr->removeGameObject(gameObj->identity());
    VERIFY_TRUE(subscriber->notified());
    VERIFY_EQUAL(Game::GameManager::GameObjectRemovingEventId, subscriber->id());

    pGameMgr->gameObjectCreated()->disconnect("test");
    pGameMgr->gameObjectRemoving()->disconnect("test");
}

SCENARIO( GameManager, "Operation/Normal", "unit,game", "GameManager can add actions." )
{
    std::string token1 = "token1";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto result = pGameMgr->hasGameAction(token1);
    VERIFY_FALSE(result);
    
    auto gameActionId = pGameMgr->getOrCreateGameAction(token1);
    VERIFY_TRUE(gameActionId != 0);
    
    auto gameActionId2 = pGameMgr->getGameActionId(token1);
    VERIFY_EQUAL(gameActionId, gameActionId2);

    result = pGameMgr->hasGameAction(gameActionId);
    VERIFY_TRUE(result);
    
    result = pGameMgr->hasGameAction(token1);
    VERIFY_TRUE(result);
    
    auto gameActionToken = pGameMgr->getGameAction(10);
    VERIFY_TRUE(gameActionToken.empty());
    
    result = pGameMgr->hasGameAction(10);
    VERIFY_FALSE(result);
}

SCENARIO( GameManager, "Operation/Corner", "unit,game", "GameManager knows invalid action identities." )
{
    std::string token = "";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    bool exceptionThrown = false;
    try
    {
        pGameMgr->getOrCreateGameAction(token);
    } catch (const std::runtime_error &)
    {
        exceptionThrown = true;
    }
    VERIFY_TRUE(exceptionThrown);
    
    auto gameActionToken = pGameMgr->getGameAction(static_cast<int>(0));
    VERIFY_TRUE(gameActionToken.empty());

    gameActionToken = pGameMgr->getGameAction(-1);
    VERIFY_TRUE(gameActionToken.empty());
    
    auto gameActionId = pGameMgr->getGameActionId("unknown");
    VERIFY_EQUAL(0, gameActionId);

    auto result = pGameMgr->hasGameAction(0);
    VERIFY_FALSE(result);
    
    result = pGameMgr->hasGameAction(-1);
    VERIFY_FALSE(result);
}

SCENARIO( GameManager, "Operation/Normal", "unit,game", "GameManager can add GameSystems." )
{
    std::string token1 = "token1";
    std::string token2 = "token2";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto result = pGameMgr->hasGameSystem(token1);
    VERIFY_FALSE(result);
    
    auto gameSys1 = pGameMgr->getOrCreateGameSystem<Game::GameSystem>(token1);
    VERIFY_TRUE(gameSys1 != nullptr);
    
    auto gameSysId = pGameMgr->getGameSystemId(token1);
    VERIFY_EQUAL(gameSys1->identity(), gameSysId);

    result = pGameMgr->hasGameSystem(gameSys1->identity());
    VERIFY_TRUE(result);
    
    result = pGameMgr->hasGameSystem(token1);
    VERIFY_TRUE(result);
    
    auto gameSys2 = pGameMgr->getOrCreateGameSystem<Game::GameSystem>(token2);
    VERIFY_TRUE(gameSys2 != nullptr);
    
    auto gameSys3 = pGameMgr->getOrCreateGameSystem<Game::GameSystem>(token1);
    VERIFY_TRUE(gameSys3 != nullptr);
    
    VERIFY_EQUAL(3, static_cast<int>(gameSys1.use_count()));
    VERIFY_EQUAL(2, static_cast<int>(gameSys2.use_count()));
    
    auto gameSys4 = pGameMgr->getGameSystem<Game::GameSystem>(10);
    VERIFY_TRUE(gameSys4 == nullptr);
    
    result = pGameMgr->hasGameSystem(10);
    VERIFY_FALSE(result);
    
    auto gameSys5 = pGameMgr->getGameSystem<Game::GameSystem>(gameSys1->identity());
    VERIFY_TRUE(gameSys5 != nullptr);
}

SCENARIO( GameManager, "Operation/Corner", "unit,game", "GameManager knows invalid GameSystem identities." )
{
    std::string token = "state";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameSys1 = pGameMgr->getOrCreateGameSystem<Game::GameSystem>(token);
    VERIFY_TRUE(gameSys1 != nullptr);
    
    auto gameSys2 = pGameMgr->getGameSystem<Game::GameSystem>(static_cast<int>(0));
    VERIFY_TRUE(gameSys2 == nullptr);
    
    auto gameSys3 = pGameMgr->getGameSystem<Game::GameSystem>(-1);
    VERIFY_TRUE(gameSys3 == nullptr);
    
    auto gameSysId = pGameMgr->getGameSystemId("unknown");
    VERIFY_EQUAL(0, gameSysId);

    auto result = pGameMgr->hasGameSystem(0);
    VERIFY_FALSE(result);
    
    result = pGameMgr->hasGameSystem(-1);
    VERIFY_FALSE(result);
    
    auto gameSys4 = pGameMgr->getGameSystem<Game::GameSystem>(gameSys1->identity());
    VERIFY_TRUE(gameSys4 != nullptr);
}

SCENARIO( GameManager, "Operation/Normal", "unit,game", "GameManager can add abilities." )
{
    std::string token1 = "token1";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto result = pGameMgr->hasGameAbility(token1);
    VERIFY_FALSE(result);
    
    auto gameAbilityId = pGameMgr->getOrCreateGameAbility(token1);
    VERIFY_TRUE(gameAbilityId != 0);
    
    auto gameAbilityId2 = pGameMgr->getGameAbilityId(token1);
    VERIFY_EQUAL(gameAbilityId, gameAbilityId2);
    
    result = pGameMgr->hasGameAbility(gameAbilityId);
    VERIFY_TRUE(result);
    
    result = pGameMgr->hasGameAbility(token1);
    VERIFY_TRUE(result);
    
    auto gameAbilityToken = pGameMgr->getGameAbility(10);
    VERIFY_TRUE(gameAbilityToken.empty());
    
    result = pGameMgr->hasGameAbility(10);
    VERIFY_FALSE(result);
}

SCENARIO( GameManager, "Operation/Corner", "unit,game", "GameManager knows invalid ability identities." )
{
    std::string token = "";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    bool exceptionThrown = false;
    try
    {
        pGameMgr->getOrCreateGameAbility(token);
    } catch (const std::runtime_error &)
    {
        exceptionThrown = true;
    }
    VERIFY_TRUE(exceptionThrown);
    
    auto gameAbilityToken = pGameMgr->getGameAbility(static_cast<int>(0));
    VERIFY_TRUE(gameAbilityToken.empty());
    
    gameAbilityToken = pGameMgr->getGameAbility(-1);
    VERIFY_TRUE(gameAbilityToken.empty());
    
    auto gameAbilityId = pGameMgr->getGameAbilityId("unknown");
    VERIFY_EQUAL(0, gameAbilityId);
    
    auto result = pGameMgr->hasGameAbility(0);
    VERIFY_FALSE(result);
    
    result = pGameMgr->hasGameAbility(-1);
    VERIFY_FALSE(result);
}
