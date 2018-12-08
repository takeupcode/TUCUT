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

PropertyValue * GameComponent::getPropertyValue (int objectId, int propertyId) const
{
    GameManager * pGameMgr = GameManager::instance();
    auto gameObj = pGameMgr->getGameObject<GameObject>(objectId);
    
    return getPropertyValue(gameObj, propertyId);
}

PropertyValue * GameComponent::getPropertyValue (const std::shared_ptr<GameObject> & object, int propertyId) const
{
    return nullptr;
}

} // namespace Game
} // namespace TUCUT
