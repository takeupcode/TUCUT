//
//  GameManager.hpp
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

#include "GameObject.h"
#include "GameComponent.h"
#include "../Event/EventPublisher.h"

namespace TUCUT {
namespace Game {

class GameManager
{
public:
    const static int GameObjectCreatedEventId = 1;
    const static int GameObjectRemovingEventId = 2;
    const static int GameObjectChangedEventId = 3;

    using GameObjectCreatedEvent = Event::EventPublisher<GameObject &>;
    using GameObjectRemovingEvent = Event::EventPublisher<GameObject &>;
    using GameObjectChangedEvent = Event::EventPublisher<GameObject &>;

    static GameManager * instance ();
    
    void initialize ();
    
    void deinitialize ();

    template <typename T>
    std::shared_ptr<GameObject> createGameObject (const std::string & token)
    {
        // This will be an instance of T but a pointer to the base GameObject class.
        auto gameObj = T::createSharedGameObject(token, mNextGameObjectId);
        auto result = mGameObjects.try_emplace(mNextGameObjectId, gameObj);
        if (!result.second)
        {
            throw std::runtime_error("Unable to create game object");
        }
        
        ++mNextGameObjectId;
        
        mGameObjectCreated->signal(*gameObj);
        
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
    std::shared_ptr<T> getGameComponent (const std::string & token)
    {
        auto gameComponentId = getGameComponentId(token);
        if (gameComponentId == 0)
        {
            gameComponentId = createGameComponentId(token);
            // This will be an instance of T but a pointer to the base GameComponent class.
            auto gameComponent = T::createSharedGameComponent(token, gameComponentId);
            mLoadedGameComponents[gameComponentId] = gameComponent;
            
            // We can be sure this cast will work.
            return std::static_pointer_cast<T>(gameComponent);
        }
        
        // Do some extra type checking in case a different T is requested than was originally provided.
        return std::dynamic_pointer_cast<T>(mLoadedGameComponents[gameComponentId]);
    }

    bool hasGameComponent (int identity) const;

    bool hasGameComponent (const std::string & token) const;

    // This method will try to get an action by id and return an empty string if not found.
    std::string getGameAction (int identity) const;
    
    // This method will try to get an action by token and will create a new action if not found.
    int getGameAction (const std::string & token);
    
    bool hasGameAction (int identity) const;
    
    bool hasGameAction (const std::string & token) const;

    void onGameObjectChanged (GameObject & gameObj) const
    {
        if (hasGameObject(gameObj.identity()))
        {
            mGameObjectChanged->signal(gameObj);
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

    GameObjectChangedEvent * gameObjectChanged ()
    {
        return mGameObjectChanged.get();
    }

private:
    using GameObjectMap = std::unordered_map<int, std::shared_ptr<GameObject>>;
    using GameComponentMap = std::unordered_map<std::string, int>;
    using GameComponentVector = std::vector<std::shared_ptr<GameComponent>>;
    using GameActionMap = std::unordered_map<std::string, int>;
    using GameActionVector = std::vector<std::string>;
    using GameObjectActionMap = std::unordered_map<int, std::queue<int>>;

    GameManager ()
    : mNextGameObjectId(1), mNextGameComponentId(1), mNextGameActionId(1),
    mGameObjectCreated(new GameObjectCreatedEvent(GameObjectCreatedEventId)),
    mGameObjectRemoving(new GameObjectRemovingEvent(GameObjectRemovingEventId)),
    mGameObjectChanged(new GameObjectChangedEvent(GameObjectChangedEventId))
    { }
    
    int createGameComponentId (const std::string & token);
    int getGameComponentId (const std::string & token) const;

    int createGameActionId (const std::string & token);
    int getGameActionId (const std::string & token) const;

    int mNextGameObjectId;
    int mNextGameComponentId;
    int mNextGameActionId;
    GameObjectMap mGameObjects;
    GameComponentMap mRegisteredGameComponents;
    GameComponentVector mLoadedGameComponents;
    GameActionMap mRegisteredGameActions;
    GameActionVector mLoadedGameActions;
    GameObjectActionMap mGameObjectActions;
    std::unique_ptr<GameObjectCreatedEvent> mGameObjectCreated;
    std::unique_ptr<GameObjectRemovingEvent> mGameObjectRemoving;
    std::unique_ptr<GameObjectChangedEvent> mGameObjectChanged;
};

} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_GameManager_h
