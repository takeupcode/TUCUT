//
//  GameManager.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 8/19/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "GameManager.h"

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


std::shared_ptr<GameObject> GameManager::createGameObject (const std::string & token)
{
    auto result = GameObject::createSharedGameObject(token, mNextId);
    mGameObjects.insert(std::make_pair(mNextId, result));
    ++mNextId;
    
    return result;
}

void GameManager::removeGameObject (int identity)
{
    mGameObjects.erase(identity);
}

std::shared_ptr<GameObject> GameManager::getGameObject (int identity) const
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
