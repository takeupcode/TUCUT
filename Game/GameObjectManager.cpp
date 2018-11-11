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


std::shared_ptr<GameObject> GameObjectManager::createGameObject (const std::string & token)
{
    auto result = GameObject::createSharedGameObject(token, mNextId);
    mGameObjects.insert(std::make_pair(mNextId, result));
    ++mNextId;
    
    return result;
}

void GameObjectManager::removeGameObject (int identity)
{
    mGameObjects.erase(identity);
}

std::shared_ptr<GameObject> GameObjectManager::getGameObject (int identity) const
{
    auto gameObjectMapResult = mGameObjects.find(identity);
    if (gameObjectMapResult == mGameObjects.end())
    {
        return nullptr;
    }
    
    return gameObjectMapResult->second;
}

} // namespace Game
} // namespace TUCUT
