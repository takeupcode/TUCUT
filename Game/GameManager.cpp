//
//  GameManager.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 8/19/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "GameManager.h"

#include <stdexcept>
#include <thread>

namespace TUCUT {
namespace Game {

const TimeResolution GameManager::FixedFrameTime =
    TimeResolution(TimeResolution::period::den / GameManager::FramesPerSecond);

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
    mRegisteredGameSystems.clear();
    mLoadedGameSystems.clear();
    mRegisteredGameActions.clear();
    mLoadedGameActions.clear();
    mGameObjectActions.clear();
    mRegisteredGameAbilities.clear();
    mLoadedGameAbilities.clear();
}

void GameManager::play ()
{
    loop();
}

void GameManager::exit ()
{
    mExit = true;
}

TimeResolution GameManager::elapsed () const
{
    return mElapsed;
}

void GameManager::restartClock ()
{
    auto currentTime = TimeClock::now();
    mElapsed = std::chrono::duration_cast<TimeResolution>(currentTime - mLastTime);
    mFixedFrameTotal += mElapsed;
    mLastTime = currentTime;
}

bool GameManager::isFixedFrameReady () const
{
    return mFixedFrameTotal > FixedFrameTime;
}

void GameManager::completeFixedFrame ()
{
    mFixedFrameTotal -= FixedFrameTime;
}

void GameManager::waitForNextFixedFrame ()
{
    auto waitDuration = FixedFrameTime - mFixedFrameTotal;
    if (waitDuration > waitDuration.zero())
    {
        std::this_thread::sleep_for(std::chrono::duration_cast<std::chrono::milliseconds>(waitDuration));
    }
}

void GameManager::loop ()
{
    mLastTime = TimeClock::now();
    
    while (!mExit)
    {
        if (isFixedFrameReady())
        {
            update(elapsed());
            
            completeFixedFrame();
        }
        else
        {
            waitForNextFixedFrame();
        }
        restartClock();
    }
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

int GameManager::createGameAbilityId (const std::string & token)
{
    if (token.empty())
    {
        throw std::runtime_error("Unable to create game ability id");
    }
    
    mRegisteredGameAbilities[token] = mNextGameAbilityId;
    
    // Make sure there's always a matching entry in the loaded abilities vector.
    while (mLoadedGameAbilities.size() <= static_cast<std::size_t>(mNextGameAbilityId))
    {
        mLoadedGameAbilities.push_back("");
    }
    
    return mNextGameAbilityId++;
}

int GameManager::getGameAbilityId (const std::string & token) const
{
    auto gameAbilityMapResult = mRegisteredGameAbilities.find(token);
    if (gameAbilityMapResult == mRegisteredGameAbilities.end())
    {
        return 0;
    }
    
    return gameAbilityMapResult->second;
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

std::string GameManager::getGameAbility (int identity) const
{
    if (identity < 1)
    {
        return "";
    }
    
    if (mLoadedGameAbilities.size() > static_cast<std::size_t>(identity))
    {
        return mLoadedGameAbilities[identity];
    }
    
    return "";
}

int GameManager::getOrCreateGameAbility (const std::string & token)
{
    auto gameAbilityId = getGameAbilityId(token);
    if (gameAbilityId == 0)
    {
        gameAbilityId = createGameAbilityId(token);
        mLoadedGameAbilities[gameAbilityId] = token;
    }
    
    return gameAbilityId;
}

bool GameManager::hasGameAbility (int identity) const
{
    if (identity < 1)
    {
        return false;
    }
    
    if (mLoadedGameAbilities.size() > static_cast<std::size_t>(identity))
    {
        return !mLoadedGameAbilities[identity].empty();
    }
    
    return false;
}

bool GameManager::hasGameAbility (const std::string & token) const
{
    auto gameAbilityId = getGameAbilityId(token);
    if (gameAbilityId == 0)
    {
        return false;
    }
    
    return hasGameAbility(gameAbilityId);
}

void GameManager::update (TimeResolution elapsedTime)
{
    for (const auto & gameSystem: mLoadedGameSystems)
    {
        if (gameSystem)
        {
            gameSystem->update(elapsedTime);
        }
    }
    
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
