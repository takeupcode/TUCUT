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

    pGameMgr->gameObjectChanged()->connect(idToken().toString(), getSharedGameSystem());
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

void GameSystem::notify (int id, Game::GameObject & gameObject)
{
    if (id != GameManager::GameObjectChangedEventId)
    {
        return;
    }
    
    bool gameObjectMeetsRequirements = true;
    if (!mRequiredComponentTokens.empty())
    {
        Game::GameManager * pGameMgr = Game::GameManager::instance();
        for (const auto & token: mRequiredComponentTokens)
        {
            auto compId = pGameMgr->getGameComponentId(token);
            if (!gameObject.hasGameComponent(compId))
            {
                gameObjectMeetsRequirements = false;
                break;
            }
        }
    }
    
    if (gameObjectMeetsRequirements)
    {
        if (!hasGameObject(gameObject.identity()))
        {
            auto result = mGameObjects.try_emplace(gameObject.identity(), gameObject.getSharedGameObject());
            if (!result.second)
            {
                throw std::runtime_error("Unable to add game object to system");
            }
        }
    }
    else
    {
        auto gameObjectMapResult = mGameObjects.find(gameObject.identity());
        if (gameObjectMapResult != mGameObjects.end())
        {
            mGameObjects.erase(gameObject.identity());
        }
    }
}

} // namespace Game
} // namespace TUCUT
