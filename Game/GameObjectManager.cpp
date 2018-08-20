//
//  GameObjectManager.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 8/19/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "GameObjectManager.h"

namespace TUCUT {
namespace Game {

GameObjectManager * GameObjectManager::instance ()
{
    static GameObjectManager * mInstance = nullptr;
    
    if (!mInstance)
    {
        mInstance = new GameObjectManager();
    }
    
    return mInstance;
}

void GameObjectManager::initialize ()
{ }

void GameObjectManager::deinitialize ()
{
    mGameObjects.clear();
}


bool GameObjectManager::addGameObject (const std::string & gameObjectName, const std::shared_ptr<GameObject> & gameObject)
{
    auto result = mGameObjects.try_emplace(gameObjectName, gameObject);
    
    return result.second;
}

void GameObjectManager::removeGameObject (const std::string & gameObjectName)
{
    mGameObjects.erase(gameObjectName);
}

std::shared_ptr<GameObject> GameObjectManager::getGameObject (const std::string & gameObjectName) const
{
    auto gameObjectMapResult = mGameObjects.find(gameObjectName);
    if (gameObjectMapResult == mGameObjects.end())
    {
        return nullptr;
    }
    
    return gameObjectMapResult->second;
}

} // namespace Game
} // namespace TUCUT
