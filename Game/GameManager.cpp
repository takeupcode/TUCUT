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
    mRegisteredGameComponents.clear();
    mLoadedGameComponents.clear();
}

GameManager::GameObjectMap * GameManager::createGameObjectMap (const std::string & token)
{
    auto result = mGameObjects.try_emplace(token, std::make_unique<GameObjectMap>());
    if (!result.second)
    {
        throw std::runtime_error("Unable to create game object map");
    }
    
    return result.first->second.get();
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
    
int GameManager::createGameComponentId (const std::string & token)
{
    auto result = mRegisteredGameComponents.try_emplace(token, mNextGameComponentId);
    if (!result.second)
    {
        throw std::runtime_error("Unable to create game component id");
    }
    
    // Makse sure there's always a matching entry in the loaded components vector.
    while (mLoadedGameComponents.size() <= static_cast<std::size_t>(mNextGameComponentId))
    {
        mLoadedGameComponents.push_back(nullptr);
    }

    return mNextGameComponentId++;
}

int GameManager::getGameComponentId (const std::string & token) const
{
    auto gameComponentMapResult = mRegisteredGameComponents.find(token);
    if (gameComponentMapResult == mRegisteredGameComponents.end())
    {
        return 0;
    }
    
    return gameComponentMapResult->second;
}

void GameManager::removeGameObject (const std::string & token, int identity)
{
    if (identity < 1)
    {
        return;
    }
    
    auto gameObjectMap = getGameObjectMap(token);
    if (!gameObjectMap)
    {
        return;
    }
    
    gameObjectMap->erase(identity);
}

} // namespace Game
} // namespace TUCUT
