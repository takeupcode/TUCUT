//
//  GameSystem.cpp
//  TUCUT
//
//  Created by Abdul Wahid Tanner on 11/27/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "GameSystem.h"
#include "GameManager.h"

namespace TUCUT {
namespace Game {
    
void GameSystem::initialize ()
{
    GameManager * pGameMgr = GameManager::instance();

    pGameMgr->gameObjectCreated()->connect(idToken().toString(), getSharedGameSystem());
    pGameMgr->gameObjectRemoving()->connect(idToken().toString(), getSharedGameSystem());
    pGameMgr->gameObjectComponentChanged()->connect(idToken().toString(), getSharedGameSystem());
}

std::shared_ptr<GameSystem> GameSystem::getSharedGameSystem ()
{
    return shared_from_this();
}

bool GameSystem::hasGameObject (int identity) const
{
    if (identity < 1)
    {
        return false;
    }
    
    auto gameObjectMapResult = mGameObjects.find(identity);
    if (gameObjectMapResult == mGameObjects.end())
    {
        return false;
    }
    
    return true;
}

void GameSystem::notify (int id, const std::shared_ptr<GameObject> & gameObject)
{
    bool gameObjectBelongs = true;
    if (id == GameManager::GameObjectCreatedEventId ||
        id == GameManager::GameObjectComponentEventId)
    {
        if (!mRequiredComponentTokens.empty())
        {
            Game::GameManager * pGameMgr = Game::GameManager::instance();
            for (const auto & token: mRequiredComponentTokens)
            {
                auto compId = pGameMgr->getGameComponentId(token);
                auto comp = pGameMgr->getGameComponent<GameComponent>(compId);
                
                if (!comp->hasRequiredComponents(gameObject))
                {
                    gameObjectBelongs = false;
                    break;
                }
            }
        }
    }
    else if (id == GameManager::GameObjectRemovingEventId)
    {
        gameObjectBelongs = false;
    }
    else
    {
        return;
    }
    
    if (gameObjectBelongs)
    {
        if (!hasGameObject(gameObject->identity()))
        {
            auto result = mGameObjects.try_emplace(gameObject->identity(), gameObject);
            if (!result.second)
            {
                throw std::runtime_error("Unable to add game object to system");
            }
        }
    }
    else
    {
        auto gameObjectMapResult = mGameObjects.find(gameObject->identity());
        if (gameObjectMapResult != mGameObjects.end())
        {
            mGameObjects.erase(gameObject->identity());
        }
    }
}

} // namespace Game
} // namespace TUCUT
