//
//  GameComponent.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/15/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "GameComponent.h"
#include "GameManager.h"

namespace TUCUT {
namespace Game {

const std::string GameComponent::defaultToken = "GameComponent";

void GameComponent::initialize ()
{
    Game::GameManager * pGameMgr = Game::GameManager::instance();
    for (const auto & token: mAbilityTokens)
    {
        pGameMgr->getOrCreateGameAbility(token);
    }
}

std::shared_ptr<GameComponent> GameComponent::getSharedGameComponent ()
{
    return shared_from_this();
}
    
void GameComponent::addDefaultProperties (int objectId) const
{
    GameManager * pGameMgr = GameManager::instance();
    auto gameObj = pGameMgr->getGameObject<GameObject>(objectId);
    
    return addDefaultProperties(gameObj);
}

void GameComponent::addDefaultProperties (const std::shared_ptr<GameObject> & object) const
{ }
    
void GameComponent::removeProperties (int objectId) const
{
    GameManager * pGameMgr = GameManager::instance();
    auto gameObj = pGameMgr->getGameObject<GameObject>(objectId);
    
    return removeProperties(gameObj);
}

void GameComponent::removeProperties (const std::shared_ptr<GameObject> & object) const
{ }

std::string GameComponent::getString (int objectId, int propertyId) const
{
    GameManager * pGameMgr = GameManager::instance();
    auto gameObj = pGameMgr->getGameObject<GameObject>(objectId);
    
    return getString(gameObj, propertyId);
}
    
std::string GameComponent::getString (const std::shared_ptr<GameObject> & object, int propertyId) const
{
    return "";
}
    
int GameComponent::getInteger (int objectId, int propertyId) const
{
    GameManager * pGameMgr = GameManager::instance();
    auto gameObj = pGameMgr->getGameObject<GameObject>(objectId);
    
    return getInteger(gameObj, propertyId);
}
    
int GameComponent::getInteger (const std::shared_ptr<GameObject> & object, int propertyId) const
{
    return 0;
}
    
double GameComponent::getFloating (int objectId, int propertyId) const
{
    GameManager * pGameMgr = GameManager::instance();
    auto gameObj = pGameMgr->getGameObject<GameObject>(objectId);
    
    return getFloating(gameObj, propertyId);
}
    
double GameComponent::getFloating (const std::shared_ptr<GameObject> & object, int propertyId) const
{
    return 0;
}
    
bool GameComponent::getBoolean (int objectId, int propertyId) const
{
    GameManager * pGameMgr = GameManager::instance();
    auto gameObj = pGameMgr->getGameObject<GameObject>(objectId);
    
    return getBoolean(gameObj, propertyId);
}
    
bool GameComponent::getBoolean (const std::shared_ptr<GameObject> & object, int propertyId) const
{
    return false;
}
    
void GameComponent::setString (int objectId, int propertyId, const std::string & value) const
{
    GameManager * pGameMgr = GameManager::instance();
    auto gameObj = pGameMgr->getGameObject<GameObject>(objectId);
    
    setString(gameObj, propertyId, value);
}
    
void GameComponent::setString (const std::shared_ptr<GameObject> & object, int propertyId, const std::string & value) const
{ }
    
void GameComponent::setInteger (int objectId, int propertyId, int value) const
{
    GameManager * pGameMgr = GameManager::instance();
    auto gameObj = pGameMgr->getGameObject<GameObject>(objectId);
    
    setInteger(gameObj, propertyId, value);
}
    
void GameComponent::setInteger (const std::shared_ptr<GameObject> & object, int propertyId, int value) const
{ }
    
void GameComponent::setFloating (int objectId, int propertyId, double value) const
{
    GameManager * pGameMgr = GameManager::instance();
    auto gameObj = pGameMgr->getGameObject<GameObject>(objectId);
    
    setFloating(gameObj, propertyId, value);
}
    
void GameComponent::setFloating (const std::shared_ptr<GameObject> & object, int propertyId, double value) const
{ }
    
void GameComponent::setBoolean (int objectId, int propertyId, bool value) const
{
    GameManager * pGameMgr = GameManager::instance();
    auto gameObj = pGameMgr->getGameObject<GameObject>(objectId);
    
    setBoolean(gameObj, propertyId, value);
}
    
void GameComponent::setBoolean (const std::shared_ptr<GameObject> & object, int propertyId, bool value) const
{ }

} // namespace Game
} // namespace TUCUT
