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
    
int GameManager::createGameComponentId (const std::string & token)
{
    if (token.empty())
    {
        throw std::runtime_error("Unable to create game component id");
    }
    
    mRegisteredGameComponents[token] = mNextGameComponentId;
    
    // Make sure there's always a matching entry in the loaded components vector.
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
    
int GameManager::createGameSystemId (const std::string & token)
{
    if (token.empty())
    {
        throw std::runtime_error("Unable to create game system id");
    }
    
    mRegisteredGameSystems[token] = mNextGameSystemId;
    
    // Make sure there's always a matching entry in the loaded systems vector.
    while (mLoadedGameSystems.size() <= static_cast<std::size_t>(mNextGameSystemId))
    {
        mLoadedGameSystems.push_back(nullptr);
    }
    
    return mNextGameSystemId++;
}

int GameManager::getGameSystemId (const std::string & token) const
{
    auto gameSystemMapResult = mRegisteredGameSystems.find(token);
    if (gameSystemMapResult == mRegisteredGameSystems.end())
    {
        return 0;
    }
    
    return gameSystemMapResult->second;
}

int GameManager::createGameActionId (const std::string & token)
{
    if (token.empty())
    {
        throw std::runtime_error("Unable to create game action id");
    }
    
    mRegisteredGameActions[token] = mNextGameActionId;
    
    // Make sure there's always a matching entry in the loaded actions vector.
    while (mLoadedGameActions.size() <= static_cast<std::size_t>(mNextGameActionId))
    {
        mLoadedGameActions.push_back("");
    }
    
    return mNextGameActionId++;
}

int GameManager::getGameActionId (const std::string & token) const
{
    auto gameActionMapResult = mRegisteredGameActions.find(token);
    if (gameActionMapResult == mRegisteredGameActions.end())
    {
        return 0;
    }
    
    return gameActionMapResult->second;
}

bool GameManager::hasGameObject (int identity) const
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

void GameManager::removeGameObject (int identity)
{
    if (identity < 1)
    {
        return;
    }
    
    auto gameObjectMapResult = mGameObjects.find(identity);
    if (gameObjectMapResult != mGameObjects.end())
    {
        mGameObjectRemoving->signal(gameObjectMapResult->second);
        
        mGameObjects.erase(identity);
    }
}

bool GameManager::hasGameComponent (int identity) const
{
    if (identity < 1)
    {
        return false;
    }
    
    if (mLoadedGameComponents.size() > static_cast<std::size_t>(identity))
    {
        return mLoadedGameComponents[identity] != nullptr;
    }
    
    return false;
}

bool GameManager::hasGameComponent (const std::string & token) const
{
    auto gameComponentId = getGameComponentId(token);
    if (gameComponentId == 0)
    {
        return false;
    }
    
    return hasGameComponent(gameComponentId);
}

bool GameManager::hasGameSystem (int identity) const
{
    if (identity < 1)
    {
        return false;
    }
    
    if (mLoadedGameSystems.size() > static_cast<std::size_t>(identity))
    {
        return mLoadedGameSystems[identity] != nullptr;
    }
    
    return false;
}

bool GameManager::hasGameSystem (const std::string & token) const
{
    auto gameSystemId = getGameSystemId(token);
    if (gameSystemId == 0)
    {
        return false;
    }
    
    return hasGameSystem(gameSystemId);
}

std::string GameManager::getGameAction (int identity) const
{
    if (identity < 1)
    {
        return "";
    }
    
    if (mLoadedGameActions.size() > static_cast<std::size_t>(identity))
    {
        return mLoadedGameActions[identity];
    }
    
    return "";
}

int GameManager::getOrCreateGameAction (const std::string & token)
{
    auto gameActionId = getGameActionId(token);
    if (gameActionId == 0)
    {
        gameActionId = createGameActionId(token);
        mLoadedGameActions[gameActionId] = token;
    }
    
    return gameActionId;
}

bool GameManager::hasGameAction (int identity) const
{
    if (identity < 1)
    {
        return false;
    }
    
    if (mLoadedGameActions.size() > static_cast<std::size_t>(identity))
    {
        return !mLoadedGameActions[identity].empty();
    }
    
    return false;
}

bool GameManager::hasGameAction (const std::string & token) const
{
    auto gameActionId = getGameActionId(token);
    if (gameActionId == 0)
    {
        return false;
    }
    
    return hasGameAction(gameActionId);
}

void GameManager::queueGameAction (int objectId, int actionId)
{
    if (objectId < 1 || actionId < 1)
    {
        return;
    }

    mGameObjectActions[objectId].push(actionId);
}
    
void GameManager::update ()
{
    auto actionQueueIter = mGameObjectActions.begin();
    while (actionQueueIter != mGameObjectActions.end())
    {
        while (!actionQueueIter->second.empty())
        {
            int actionId = actionQueueIter->second.front();
            for (const auto & gameSystem: mLoadedGameSystems)
            {
                if (gameSystem)
                {
                    gameSystem->onAction(actionQueueIter->first, actionId);
                }
            }
            actionQueueIter->second.pop();
        }
        mGameObjectActions.erase(actionQueueIter);
        actionQueueIter = mGameObjectActions.begin();
    }
}

} // namespace Game
} // namespace TUCUT
