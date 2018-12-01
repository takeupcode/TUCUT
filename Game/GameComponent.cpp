//
//  GameComponent.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/15/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "GameComponent.h"
#include "GameObject.h"
#include "GameManager.h"

namespace TUCUT {
namespace Game {
    
void GameComponent::initialize ()
{ }

std::shared_ptr<GameComponent> GameComponent::getSharedGameComponent ()
{
    return shared_from_this();
}

bool GameComponent::hasRequiredComponents (int objectId) const
{
    GameManager * pGameMgr = GameManager::instance();
    auto gameObj = pGameMgr->getGameObject<GameObject>(objectId);
    
    return hasRequiredComponentsImpl(gameObj, false);
}

bool GameComponent::hasRequiredComponents (const std::shared_ptr<GameObject> & object) const
{
    return hasRequiredComponentsImpl(object, true);
}

bool GameComponent::hasRequiredComponentsImpl (const std::shared_ptr<GameObject> & object, bool checkObject) const
{
    if (!object)
    {
        return false;
    }
    
    if (checkObject)
    {
        Game::GameManager * pGameMgr = Game::GameManager::instance();
        if (!pGameMgr->hasGameObject(object->identity()))
        {
            return false;
        }
    }
    
    return hasRequiredComponentsCallback(object);
}

bool GameComponent::hasRequiredComponentsCallback (const std::shared_ptr<GameObject> & object) const
{
    if (!object->hasGameComponent(identity()))
    {
        return false;
    }
    
    if (!mDependentComponentTokens.empty())
    {
        Game::GameManager * pGameMgr = Game::GameManager::instance();
        for (const auto & token: mDependentComponentTokens)
        {
            auto compId = pGameMgr->getGameComponentId(token);
            auto comp = pGameMgr->getGameComponent<GameComponent>(compId);
            
            if (!comp || !comp->hasRequiredComponentsCallback(object))
            {
                return false;
            }
        }
    }
    
    return true;
}

} // namespace Game
} // namespace TUCUT
