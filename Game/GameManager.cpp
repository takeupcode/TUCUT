//
//  GameManager.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 8/19/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "GameManager.h"

#include <stdexcept>

namespace TUCUT {
namespace Game {

GameManager * GameManager::instance ()
{
    static GameManager * mInstance = nullptr;
    
    if (!mInstance)
    {
        mInstance = new GameManager();
    }
    
    return mInstance;
}

void GameManager::initialize ()
{ }

void GameManager::deinitialize ()
{
    mGameObjects.clear();
}

GameManager::GameObjectMap * GameManager::getGameObjectMap (const std::string & token)
{
    auto gameObjectMapResult = mGameObjects.find(token);
    if (gameObjectMapResult == mGameObjects.end())
    {
        return nullptr;
    }
    
    return gameObjectMapResult->second.get();
}

const GameManager::GameObjectMap * GameManager::getGameObjectMap (const std::string & token) const
{
    auto gameObjectMapResult = mGameObjects.find(token);
    if (gameObjectMapResult == mGameObjects.end())
    {
        return nullptr;
    }
    
    return gameObjectMapResult->second.get();
}

bool GameManager::registerGameObjectToken (const std::string & token)
{
    auto result = mGameObjects.try_emplace(token, std::make_unique<GameObjectMap>());
    
    return result.second;
}
    
std::shared_ptr<GameObject> GameManager::createGameObject (const std::string & token)
{
    auto gameObjectMap = getGameObjectMap(token);
    if (!gameObjectMap)
    {
        return nullptr;
    }

    auto gameObj = GameObject::createSharedGameObject(token, mNextId);
    auto result = gameObjectMap->try_emplace(mNextId, gameObj);
    if (!result.second)
    {
        throw std::runtime_error("Unable to create game object");
    }
    
    ++mNextId;
    
    return gameObj;
}

void GameManager::removeGameObject (const std::string & token, int identity)
{
    auto gameObjectMap = getGameObjectMap(token);
    if (!gameObjectMap)
    {
        return;
    }
    
    gameObjectMap->erase(identity);
}

std::shared_ptr<GameObject> GameManager::getGameObject (const std::string & token, int identity) const
{
    auto gameObjectMap = getGameObjectMap(token);
    if (!gameObjectMap)
    {
        return nullptr;
    }
    
    auto gameObjectMapResult = gameObjectMap->find(identity);
    if (gameObjectMapResult == gameObjectMap->end())
    {
        return nullptr;
    }
    
    return gameObjectMapResult->second;
}

} // namespace Game
} // namespace TUCUT
