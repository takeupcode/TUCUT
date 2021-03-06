//
//  GameObjectScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 8/19/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../GameComponent.h"
#include "../GameObject.h"
#include "../GameManager.h"
#include "GameManagerSubscriber.h"
#include "TestSimpleComponent.h"

using namespace std;
using namespace TUCUT;

SCENARIO( GameObject, "Construction/Normal", "unit,game", "GameObject can be constructed." )
{
    std::string token = "character";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameObj = pGameMgr->createGameObject<Game::GameObject>(token);
}

SCENARIO( GameObject, "Operation/Normal", "unit,game", "GameObject can get shared pointer." )
{
    std::string token = "character";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameObj = pGameMgr->createGameObject<Game::GameObject>(token);
    
    auto sharedPtr = gameObj->getSharedGameObject();
    
    VERIFY_SAMEPTR(gameObj.get(), sharedPtr.get());
}

SCENARIO( GameObject, "Operation/Normal", "unit,game", "GameObject has properties." )
{
    std::string token = "character";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameObj = pGameMgr->createGameObject<Game::GameObject>(token);
    
    auto & properties = gameObj->properties();
    auto group = properties.getGroup("not found");
    
    VERIFY_TRUE(group == nullptr);
}

SCENARIO( GameObject, "Operation/Normal", "unit,game", "GameObject can add and remove components." )
{
    std::string token = "character";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameObj = pGameMgr->createGameObject<Game::GameObject>(token);

    auto gameComp1 = pGameMgr->getOrCreateGameComponent<Game::GameComponent>("moveable");
    auto gameComp2 = pGameMgr->getOrCreateGameComponent<Game::GameComponent>("drawable");
    auto gameComp3 = pGameMgr->getOrCreateGameComponent<Game::GameComponent>("controllable");

    auto result = gameObj->addGameComponent(1);
    VERIFY_TRUE(result);

    result = gameObj->addGameComponent(gameComp2);
    VERIFY_TRUE(result);

    result = gameObj->hasGameComponent(gameComp2);
    VERIFY_TRUE(result);

    result = gameObj->hasGameComponent(0);
    VERIFY_FALSE(result);

    result = gameObj->hasGameComponent(gameComp3);
    VERIFY_FALSE(result);

    gameObj->removeGameComponent(gameComp2);
    result = gameObj->hasGameComponent(gameComp2);
    VERIFY_FALSE(result);

    gameObj->removeGameComponent(4);
    result = gameObj->hasGameComponent(4);
    VERIFY_FALSE(result);

    gameObj->removeGameComponent(400);
    result = gameObj->hasGameComponent(400);
    VERIFY_FALSE(result);
}

SCENARIO( GameObject, "Operation/Normal", "unit,game", "GameObject notifies component changes." )
{
    std::string token = "character";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    std::shared_ptr<Test::GameManagerSubscriber> subscriber(new Test::GameManagerSubscriber());
    pGameMgr->gameObjectComponentChanged()->connect("test", subscriber);
    
    VERIFY_FALSE(subscriber->notified());
    VERIFY_EQUAL(0, subscriber->id());

    auto gameObj = pGameMgr->createGameObject<Game::GameObject>(token);
    
    auto gameComp1 = pGameMgr->getOrCreateGameComponent<Game::GameComponent>("moveable");
    auto gameComp2 = pGameMgr->getOrCreateGameComponent<Game::GameComponent>("drawable");

    auto result = gameObj->addGameComponent(gameComp1->identity());
    VERIFY_TRUE(result);
    VERIFY_TRUE(subscriber->notified());
    VERIFY_EQUAL(Game::GameManager::GameObjectComponentEventId, subscriber->id());
    subscriber->reset();

    gameObj->removeGameComponent(gameComp1);
    VERIFY_TRUE(subscriber->notified());
    VERIFY_EQUAL(Game::GameManager::GameObjectComponentEventId, subscriber->id());
    subscriber->reset();
    
    pGameMgr->removeGameObject(gameObj->identity());
    
    result = gameObj->addGameComponent(gameComp2->identity());
    VERIFY_TRUE(result);
    VERIFY_FALSE(subscriber->notified());
    VERIFY_EQUAL(0, subscriber->id());
    
    pGameMgr->gameObjectComponentChanged()->disconnect("test");
}

SCENARIO( GameObject, "Operation/Corner", "unit,game", "GameObject knows invalid component identities." )
{
    std::string token = "character";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameObj = pGameMgr->createGameObject<Game::GameObject>(token);
    
    auto gameComp1 = pGameMgr->getOrCreateGameComponent<Game::GameComponent>("moveable");
    
    auto result = gameObj->addGameComponent(gameComp1);
    VERIFY_TRUE(result);
    
    result = gameObj->addGameComponent(0);
    VERIFY_FALSE(result);
    
    result = gameObj->addGameComponent(-1);
    VERIFY_FALSE(result);

    result = gameObj->hasGameComponent(0);
    VERIFY_FALSE(result);
    
    result = gameObj->hasGameComponent(-1);
    VERIFY_FALSE(result);
    
    gameObj->removeGameComponent(0);
    
    gameObj->removeGameComponent(-1);
    
    result = gameObj->hasGameComponent(gameComp1);
    VERIFY_TRUE(result);
}

SCENARIO( GameObject, "Operation/Normal", "unit,game", "GameObject knows abilities." )
{
    std::string compAbility = "Ability1";
    std::string token = "character";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameObj = pGameMgr->createGameObject<Game::GameObject>(token);
    
    auto gameComp1 = pGameMgr->getOrCreateGameComponent<Game::GameComponent>("moveable");
    auto gameComp2 = pGameMgr->getOrCreateGameComponent<Test::TestSimpleComponent>("simplecomponent");
    
    auto result = gameObj->addGameComponent(gameComp1);
    VERIFY_TRUE(result);
    
    result = gameObj->hasGameAbility(compAbility);
    VERIFY_FALSE(result);
    
    result = gameObj->addGameComponent(gameComp2);
    VERIFY_TRUE(result);
    
    result = gameObj->hasGameAbility(compAbility);
    VERIFY_TRUE(result);
    
    gameObj->removeGameComponent(gameComp2);
    
    result = gameObj->hasGameAbility(compAbility);
    VERIFY_FALSE(result);
}

SCENARIO( GameObject, "Operation/Normal", "unit,game", "GameObject knows which components provide abilities." )
{
    std::string compAbility = "Ability1";
    std::string token = "character";
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    
    auto gameObj = pGameMgr->createGameObject<Game::GameObject>(token);
    
    auto gameComp1 = pGameMgr->getOrCreateGameComponent<Test::TestSimpleComponent>("simplecomponent1");
    auto gameComp2 = pGameMgr->getOrCreateGameComponent<Test::TestSimpleComponent>("simplecomponent2");
    auto compAbilityId = pGameMgr->getGameAbilityId(compAbility);

    auto result = gameObj->addGameComponent(gameComp1);
    VERIFY_TRUE(result);
    
    auto sharedPtr = gameObj->getGameComponentFromAbility(compAbilityId);
    VERIFY_TRUE(sharedPtr != nullptr);
    VERIFY_EQUAL(gameComp1->identity(), sharedPtr->identity());

    result = gameObj->addGameComponent(gameComp2);
    VERIFY_TRUE(result);
    
    sharedPtr = gameObj->getGameComponentFromAbility(compAbility);
    VERIFY_TRUE(sharedPtr != nullptr);
    VERIFY_EQUAL(gameComp2->identity(), sharedPtr->identity());
    
    gameObj->removeGameComponent(gameComp2);
    
    sharedPtr = gameObj->getGameComponentFromAbility(compAbility);
    VERIFY_TRUE(sharedPtr != nullptr);
    VERIFY_EQUAL(gameComp1->identity(), sharedPtr->identity());

    result = gameObj->addGameComponent(gameComp2);
    gameObj->removeGameComponent(gameComp1);
    
    sharedPtr = gameObj->getGameComponentFromAbility(compAbility);
    VERIFY_TRUE(sharedPtr != nullptr);
    VERIFY_EQUAL(gameComp2->identity(), sharedPtr->identity());
}
