//
//  GameManager.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 8/19/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_GameManager_h
#define TUCUT_Game_GameManager_h

#include <memory>
#include <queue>
#include <unordered_map>
#include <stdexcept>

#include "GameObject.h"
#include "GameComponent.h"
#include "GameSystem.h"
#include "GameTime.h"
#include "../Event/EventPublisher.h"

namespace TUCUT {
namespace Game {

class GameManager
{
public:
    const static int GameObjectCreatedEventId = 1;
    const static int GameObjectRemovingEventId = 2;
    const static int GameObjectComponentEventId = 3;

    using GameObjectCreatedEvent = Event::EventPublisher<const std::shared_ptr<GameObject> &>;
    using GameObjectRemovingEvent = Event::EventPublisher<const std::shared_ptr<GameObject> &>;
    using GameObjectComponentEvent = Event::EventPublisher<const std::shared_ptr<GameObject> &>;

    static GameManager * instance ();
    
    void initialize ();
    
    void deinitialize ();
    
    void play ();
    
    void exit ();

    template <typename T>
    std::shared_ptr<GameObject> createGameObject (const std::string & token = "")
    {
        std::string actualToken = token.empty() ? T::defaultToken : token;
        
        // This will be an instance of T but a pointer to the base GameObject class.
        auto gameObj = std::shared_ptr<GameObject>(new T(actualToken, mNextGameObjectId));
        
        gameObj->initialize();

        auto result = mGameObjects.try_emplace(mNextGameObjectId, gameObj);
        if (!result.second)
        {
            throw std::runtime_error("Unable to create game object");
        }
        
        ++mNextGameObjectId;
        
        mGameObjectCreated->signal(gameObj);
        
        return gameObj;
    }
    
    template <typename T>
    std::shared_ptr<GameObject> getGameObject (int identity) const
    {
        if (identity < 1)
        {
            return nullptr;
        }
        
        auto gameObjectMapResult = mGameObjects.find(identity);
        if (gameObjectMapResult == mGameObjects.end())
        {
            return nullptr;
        }
        
        // Do some extra type checking in case a different T is requested than was originally provided.
        return std::dynamic_pointer_cast<T>(gameObjectMapResult->second);
    }

    bool hasGameObject (int identity) const;
    
    void removeGameObject (int identity);

    // This method will try to get a component by id and return nullptr if not found.
    // It will also return nullptr if the requested type T is not correct.
    template <typename T>
    std::shared_ptr<T> getGameComponent (int identity) const
    {
        if (identity < 1)
        {
            return nullptr;
        }
        
        if (mLoadedGameComponents.size() > static_cast<std::size_t>(identity))
        {
            // Do some extra type checking in case a different T is requested than was originally provided.
            return std::dynamic_pointer_cast<T>(mLoadedGameComponents[identity]);
        }
        
        return nullptr;
    }

    // This method will try to get a component by token and will create a new component if not found.
    // It will return nullptr if the requested type T is not correct.
    template <typename T>
    std::shared_ptr<T> getOrCreateGameComponent (const std::string & token = "")
    {
        std::string actualToken = token.empty() ? T::defaultToken : token;
        
        auto gameComponentId = getGameComponentId(actualToken);
        if (gameComponentId == 0)
        {
            gameComponentId = createGameComponentId(actualToken);
            // This will be an instance of T but a pointer to the base GameComponent class.
            auto gameComponent = std::shared_ptr<GameComponent>(new T(actualToken, gameComponentId));
            
            gameComponent->initialize();

            mLoadedGameComponents[gameComponentId] = gameComponent;
            
            // We can be sure this cast will work.
            return std::static_pointer_cast<T>(gameComponent);
        }
        
        // Do some extra type checking in case a different T is requested than was originally provided.
        return std::dynamic_pointer_cast<T>(mLoadedGameComponents[gameComponentId]);
    }

    int getGameComponentId (const std::string & token) const;
    
    bool hasGameComponent (int identity) const;

    bool hasGameComponent (const std::string & token) const;

    // This method will try to get a system by id and return nullptr if not found.
    // It will also return nullptr if the requested type T is not correct.
    template <typename T>
    std::shared_ptr<T> getGameSystem (int identity) const
    {
        if (identity < 1)
        {
            return nullptr;
        }
        
        if (mLoadedGameSystems.size() > static_cast<std::size_t>(identity))
        {
            // Do some extra type checking in case a different T is requested than was originally provided.
            return std::dynamic_pointer_cast<T>(mLoadedGameSystems[identity]);
        }
        
        return nullptr;
    }
    
    // This method will try to get a system by token and will create a new system if not found.
    // It will return nullptr if the requested type T is not correct.
    template <typename T>
    std::shared_ptr<T> getOrCreateGameSystem (const std::string & token = "")
    {
        std::string actualToken = token.empty() ? T::defaultToken : token;
        
        auto gameSystemId = getGameSystemId(actualToken);
        if (gameSystemId == 0)
        {
            gameSystemId = createGameSystemId(actualToken);
            // This will be an instance of T but a pointer to the base GameSystem class.
            auto gameSystem = std::shared_ptr<GameSystem>(new T(actualToken, gameSystemId));
            
            gameSystem->initialize();
            
            mLoadedGameSystems[gameSystemId] = gameSystem;
            
            // We can be sure this cast will work.
            return std::static_pointer_cast<T>(gameSystem);
        }
        
        // Do some extra type checking in case a different T is requested than was originally provided.
        return std::dynamic_pointer_cast<T>(mLoadedGameSystems[gameSystemId]);
    }
    
    int getGameSystemId (const std::string & token) const;

    bool hasGameSystem (int identity) const;
    
    bool hasGameSystem (const std::string & token) const;

    // This method will try to get an action by id and return an empty string if not found.
    std::string getGameAction (int identity) const;
    
    // This method will try to get an action by token and will create a new action if not found.
    int getOrCreateGameAction (const std::string & token);
    
    int getGameActionId (const std::string & token) const;
    
    bool hasGameAction (int identity) const;
    
    bool hasGameAction (const std::string & token) const;
    
    void queueGameAction (int objectId, int actionId);

    // This method will try to get an ability by id and return an empty string if not found.
    std::string getGameAbility (int identity) const;
    
    // This method will try to get an ability by token and will create a new ability if not found.
    int getOrCreateGameAbility (const std::string & token);
    
    int getGameAbilityId (const std::string & token) const;
    
    bool hasGameAbility (int identity) const;
    
    bool hasGameAbility (const std::string & token) const;

    void onGameObjectComponentChanged (const std::shared_ptr<GameObject> & gameObj) const
    {
        if (hasGameObject(gameObj->identity()))
        {
            mGameObjectComponent->signal(gameObj);
        }
    }

    GameObjectCreatedEvent * gameObjectCreated ()
    {
        return mGameObjectCreated.get();
    }

    GameObjectRemovingEvent * gameObjectRemoving ()
    {
        return mGameObjectRemoving.get();
    }

    GameObjectComponentEvent * gameObjectComponentChanged ()
    {
        return mGameObjectComponent.get();
    }

private:
    static constexpr int FramesPerSecond = 20; // This is a text game and doesn't need a high frame rate.
    static const TimeResolution FixedFrameTime;
    
    using GameObjectMap = std::unordered_map<int, std::shared_ptr<GameObject>>;
    using GameComponentMap = std::unordered_map<std::string, int>;
    using GameComponentVector = std::vector<std::shared_ptr<GameComponent>>;
    using GameSystemMap = std::unordered_map<std::string, int>;
    using GameSystemVector = std::vector<std::shared_ptr<GameSystem>>;
    using GameActionMap = std::unordered_map<std::string, int>;
    using GameActionVector = std::vector<std::string>;
    using GameActionQueue = std::queue<int>;
    using GameObjectActionMap = std::unordered_map<int, GameActionQueue>;
    using GameAbilityMap = std::unordered_map<std::string, int>;
    using GameAbilityVector = std::vector<std::string>;

    GameManager ()
    : mElapsed(0), mFixedFrameTotal(0), mExit(false),
    mNextGameObjectId(1), mNextGameComponentId(1), mNextGameSystemId(1),
    mNextGameActionId(1), mNextGameAbilityId(1),
    mGameObjectCreated(new GameObjectCreatedEvent(GameObjectCreatedEventId)),
    mGameObjectRemoving(new GameObjectRemovingEvent(GameObjectRemovingEventId)),
    mGameObjectComponent(new GameObjectComponentEvent(GameObjectComponentEventId))
    { }
    
    void loop ();
    
    void update (TimeResolution elapsedTime);

    TimeResolution elapsed () const;
    void restartClock ();
    bool isFixedFrameReady () const;
    void completeFixedFrame ();
    void waitForNextFixedFrame ();

    int createGameComponentId (const std::string & token);
    
    int createGameSystemId (const std::string & token);

    int createGameActionId (const std::string & token);

    int createGameAbilityId (const std::string & token);
    
    TimePoint mLastTime;
    TimeResolution mElapsed;
    TimeResolution mFixedFrameTotal;
    bool mExit;

    int mNextGameObjectId;
    int mNextGameComponentId;
    int mNextGameSystemId;
    int mNextGameActionId;
    int mNextGameAbilityId;
    GameObjectMap mGameObjects;
    GameComponentMap mRegisteredGameComponents;
    GameComponentVector mLoadedGameComponents;
    GameSystemMap mRegisteredGameSystems;
    GameSystemVector mLoadedGameSystems;
    GameActionMap mRegisteredGameActions;
    GameActionVector mLoadedGameActions;
    GameObjectActionMap mGameObjectActions;
    GameAbilityMap mRegisteredGameAbilities;
    GameAbilityVector mLoadedGameAbilities;
    std::unique_ptr<GameObjectCreatedEvent> mGameObjectCreated;
    std::unique_ptr<GameObjectRemovingEvent> mGameObjectRemoving;
    std::unique_ptr<GameObjectComponentEvent> mGameObjectComponent;
};

} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_GameManager_h
