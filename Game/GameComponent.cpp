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
    for (const auto & token: mActionTokens)
    {
        pGameMgr->getOrCreateGameAction(token);
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

std::vector<std::string> GameComponent::getStrings (int objectId, int propertyId) const
{
    GameManager * pGameMgr = GameManager::instance();
    auto gameObj = pGameMgr->getGameObject<GameObject>(objectId);
    
    return getStrings(gameObj, propertyId);
}

std::vector<std::string> GameComponent::getStrings (const std::shared_ptr<GameObject> & object, int propertyId) const
{
    return std::vector<std::string>();
}

std::vector<int> GameComponent::getIntegers (int objectId, int propertyId) const
{
    GameManager * pGameMgr = GameManager::instance();
    auto gameObj = pGameMgr->getGameObject<GameObject>(objectId);
    
    return getIntegers(gameObj, propertyId);
}

std::vector<int> GameComponent::getIntegers (const std::shared_ptr<GameObject> & object, int propertyId) const
{
    return std::vector<int>();
}

std::vector<double> GameComponent::getFloatings (int objectId, int propertyId) const
{
    GameManager * pGameMgr = GameManager::instance();
    auto gameObj = pGameMgr->getGameObject<GameObject>(objectId);
    
    return getFloatings(gameObj, propertyId);
}

std::vector<double> GameComponent::getFloatings (const std::shared_ptr<GameObject> & object, int propertyId) const
{
    return std::vector<double>();
}

std::vector<bool> GameComponent::getBooleans (int objectId, int propertyId) const
{
    GameManager * pGameMgr = GameManager::instance();
    auto gameObj = pGameMgr->getGameObject<GameObject>(objectId);
    
    return getBooleans(gameObj, propertyId);
}

std::vector<bool> GameComponent::getBooleans (const std::shared_ptr<GameObject> & object, int propertyId) const
{
    return std::vector<bool>();
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

void GameComponent::setStrings (int objectId, int propertyId, const std::vector<std::string> & value) const
{
    GameManager * pGameMgr = GameManager::instance();
    auto gameObj = pGameMgr->getGameObject<GameObject>(objectId);
    
    setStrings(gameObj, propertyId, value);
}

void GameComponent::setStrings (const std::shared_ptr<GameObject> & object, int propertyId, const std::vector<std::string> & value) const
{ }

void GameComponent::setIntegers (int objectId, int propertyId, const std::vector<int> & value) const
{
    GameManager * pGameMgr = GameManager::instance();
    auto gameObj = pGameMgr->getGameObject<GameObject>(objectId);
    
    setIntegers(gameObj, propertyId, value);
}

void GameComponent::setIntegers (const std::shared_ptr<GameObject> & object, int propertyId, const std::vector<int> & value) const
{ }

void GameComponent::setFloatings (int objectId, int propertyId, const std::vector<double> & value) const
{
    GameManager * pGameMgr = GameManager::instance();
    auto gameObj = pGameMgr->getGameObject<GameObject>(objectId);
    
    setFloatings(gameObj, propertyId, value);
}

void GameComponent::setFloatings (const std::shared_ptr<GameObject> & object, int propertyId, const std::vector<double> & value) const
{ }

void GameComponent::setBooleans (int objectId, int propertyId, const std::vector<bool> & value) const
{
    GameManager * pGameMgr = GameManager::instance();
    auto gameObj = pGameMgr->getGameObject<GameObject>(objectId);
    
    setBooleans(gameObj, propertyId, value);
}

void GameComponent::setBooleans (const std::shared_ptr<GameObject> & object, int propertyId, const std::vector<bool> & value) const
{ }

} // namespace Game
} // namespace TUCUT
