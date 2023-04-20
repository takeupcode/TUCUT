//  Application.h
//  TUCUT/ECS (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-08-19.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_ECS_Application_h
#define TUCUT_ECS_Application_h

#include "../Notify/EventPublisher.h"
#include "ApplicationTime.h"
#include "Component.h"
#include "Entity.h"
#include "System.h"

#include <memory>
#include <queue>
#include <stdexcept>
#include <unordered_map>

namespace TUCUT::ECS
{
  class Application
  {
  public:
    static int const EntityCreatedEventId = 1;
    static int const EntityRemovingEventId = 2;
    static int const EntityComponentEventId = 3;
    static int const CommandSentEventId = 4;

    using EntityCreatedEvent =
      Notify::EventPublisher<std::shared_ptr<Entity> const &>;
    using EntityRemovingEvent =
      Notify::EventPublisher<std::shared_ptr<Entity> const &>;
    using EntityComponentEvent =
      Notify::EventPublisher<std::shared_ptr<Entity> const &>;
    using CommandSentEvent =
      Notify::EventPublisher<int, PropertyGroup const &>;

    static Application * instance ();

    void initialize ();

    void deinitialize ();

    void run ();

    void exit ();

    void pause ();

    void resume ();

    void step ();

    template <typename T>
    std::shared_ptr<Entity> createEntity (
      std::string const & token = "")
    {
      std::string actualToken =
        token.empty() ? T::defaultToken : token;

      // This will be an instance of T but a pointer to
      // the base Entity class.
      auto entity = std::shared_ptr<Entity>(
        new T(actualToken, mNextEntityId));

      entity->initialize();

      auto result = mEntities.try_emplace(
        mNextEntityId, entity);
      if (not result.second)
      {
        throw std::runtime_error(
          "Unable to create entity");
      }

      ++mNextEntityId;

      mEntityCreated->signal(entity);

      return entity;
    }

    // This method will try to get an entity by id and
    // return nullptr if not found. It will also return
    // nullptr if the requested type T is not correct.
    template <typename T>
    std::shared_ptr<T> getEntity (int identity) const
    {
      std::shared_ptr<Entity> base = getBaseEntity(identity);
      if (not base)
      {
        return nullptr;
      }

      return std::dynamic_pointer_cast<T>(base);
    }

    std::shared_ptr<Entity> getBaseEntity (int identity) const
    {
      if (identity < 1)
      {
        return nullptr;
      }

      auto entityMapResult = mEntities.find(identity);
      if (mEntities.contains(identity))
      {
        return mEntities[identity];
      }
      return nullptr;
    }

    bool hasEntity (int identity) const;

    void removeEntity (int identity);

    // This method will try to get a component by id and
    // return nullptr if not found. It will also return
    // nullptr if the requested type T is not correct.
    template <typename T>
    std::shared_ptr<T> getComponent (int identity) const
    {
      std::shared_ptr<Component> base =
        getBaseComponent(identity);
      if (not base)
      {
        return nullptr;
      }

      return std::dynamic_pointer_cast<T>(base);
    }

    std::shared_ptr<Component> getBaseComponent (
      int identity) const
    {
      if (identity < 1)
      {
        return nullptr;
      }

      if (mLoadedComponents.size() >
        static_cast<size_t>(identity))
      {
        return mLoadedComponents[identity];
      }

      return nullptr;
    }

    // This method will try to get a component by token
    // and will create a new component if not found.
    // It will return nullptr if the requested type T
    // is not correct.
    template <typename T>
    std::shared_ptr<T> getOrCreateComponent (
      std::string const & token = "")
    {
      std::string actualToken =
        token.empty() ? T::defaultToken : token;

      auto componentId = getComponentId(actualToken);
      if (componentId == 0)
      {
        componentId = createComponentId(actualToken);
        // This will be an instance of T but a pointer
        // to the base Component class.
        auto component = std::shared_ptr<Component>(
          new T(actualToken, componentId));

        component->initialize();

        mLoadedComponents[componentId] = component;

        // We can be sure this cast will work.
        return std::static_pointer_cast<T>(component);
      }

      // Do some extra type checking in case a different
      // T is requested than was originally provided.
      return std::dynamic_pointer_cast<T>(
        mLoadedComponents[componentId]);
    }

    int getComponentId (std::string const & token) const;

    bool hasComponent (int identity) const;

    bool hasComponent (std::string const & token) const;

    // This method will try to get a system by id and
    // returns nullptr if not found. It will also return
    // nullptr if the requested type T is not correct.
    template <typename T>
    std::shared_ptr<T> getSystem (int identity) const
    {
      std::shared_ptr<System> base = getBaseSystem(identity);
      if (not base)
      {
        return nullptr;
      }

      return std::dynamic_pointer_cast<T>(base);
    }

    std::shared_ptr<System> getBaseSystem (int identity) const
    {
      if (identity < 1)
      {
        return nullptr;
      }

      if (mLoadedSystems.size() > static_cast<size_t>(identity))
      {
        return mLoadedSystems[identity];
      }

      return nullptr;
    }

    // This method will try to get a system by token
    // and will create a new system if not found.
    // It will return nullptr if the requested type T
    // is not correct.
    template <typename T>
    std::shared_ptr<T> getOrCreateSystem (
      std::string const & token = "")
    {
      std::string actualToken =
        token.empty() ? T::defaultToken : token;

      auto systemId = getSystemId(actualToken);
      if (systemId == 0)
      {
        systemId = createSystemId(actualToken);
        // This will be an instance of T but a pointer
        // to the base System class.
        auto system = std::shared_ptr<System>(
          new T(actualToken, systemId));

        system->initialize();

        mLoadedSystems[systemId] = system;

        // We can be sure this cast will work.
        return std::static_pointer_cast<T>(system);
      }

      // Do some extra type checking in case a different
      // T is requested than was originally provided.
      return std::dynamic_pointer_cast<T>(
        mLoadedSystems[systemId]);
    }

    int getSystemId (std::string const & token) const;

    bool hasSystem (int identity) const;

    bool hasSystem (std::string const & token) const;

    // This method will try to get an action by id and
    // return an empty string if not found.
    std::string getAction (int identity) const;

    // This method will try to get an action by token
    // and will create a new action if not found.
    int getOrCreateAction (std::string const & token);

    int getActionId (std::string const & token) const;

    bool hasAction (int identity) const;

    bool hasAction (std::string const & token) const;

    void queueAction (int objectId, int actionId);

    // This method will try to get an ability by id
    // and return an empty string if not found.
    std::string getAbility (int identity) const;

    // This method will try to get an ability by token
    // and will create a new ability if not found.
    int getOrCreateAbility (std::string const & token);

    int getAbilityId (std::string const & token) const;

    bool hasAbility (int identity) const;

    bool hasAbility (std::string const & token) const;

    // This method will try to get a command by id
    // and return an empty string if not found.
    std::string getCommand (int identity) const;

    // This method will try to get a command by token
    // and will create a new command if not found.
    int getOrCreateCommand (std::string const & token);

    int getCommandId (std::string const & token) const;

    bool hasCommand (int identity) const;

    bool hasCommand (std::string const & token) const;

    void onEntityComponentChanged (
      std::shared_ptr<Entity> const & entity) const
    {
      if (hasEntity(entity->identity()))
      {
        mEntityComponent->signal(entity);
      }
    }

    EntityCreatedEvent * entityCreated ()
    {
      return mEntityCreated.get();
    }

    EntityRemovingEvent * entityRemoving ()
    {
      return mEntityRemoving.get();
    }

    EntityComponentEvent * entityComponentChanged ()
    {
      return mEntityComponent.get();
    }

    CommandSentEvent * commandSent (int commandId)
    {
      if (not hasCommand(commandId))
      {
        return nullptr;
      }

      auto commandEventMapResult =
        mCommandEvents.find(commandId);
      if (commandEventMapResult == mCommandEvents.end())
      {
        auto result = mCommandEvents.try_emplace(commandId,
          std::unique_ptr<CommandSentEvent>(
            new CommandSentEvent(CommandSentEventId)));
        if (not result.second)
        {
          throw std::runtime_error(
            "Unable to create command sent event");
        }

        return result.first->second.get();
      }

      return commandEventMapResult->second.get();
    }

  private:
    // This is a text app and doesn't need a high frame rate.
    static constexpr int FramesPerSecond = 20;
    static TimeResolution const FixedFrameTime;

    using EntityMap = std::unordered_map<
      int, std::shared_ptr<Entity>>;
    using ComponentMap = std::unordered_map<std::string, int>;
    using ComponentVector = std::vector<
      std::shared_ptr<Component>>;
    using SystemMap = std::unordered_map<std::string, int>;
    using SystemVector = std::vector<std::shared_ptr<System>>;
    using ActionMap = std::unordered_map<std::string, int>;
    using ActionVector = std::vector<std::string>;
    using ActionQueue = std::queue<int>;
    using EntityActionMap = std::unordered_map<
      int, ActionQueue>;
    using AbilityMap = std::unordered_map<std::string, int>;
    using AbilityVector = std::vector<std::string>;
    using CommandMap = std::unordered_map<std::string, int>;
    using CommandVector = std::vector<std::string>;
    using CommandEventMap = std::unordered_map<
      int, std::unique_ptr<CommandSentEvent>>;

    Application ()
    : mElapsed(0),
      mFixedFrameTotal(0),
      mExit(false),
      mPaused(false),
      mNextEntityId(1),
      mNextComponentId(1),
      mNextSystemId(1),
      mNextActionId(1),
      mNextAbilityId(1),
      mNextCommandId(1),
      mEntityCreated(new EntityCreatedEvent(
        EntityCreatedEventId)),
      mEntityRemoving(new EntityRemovingEvent(
        EntityRemovingEventId)),
      mEntityComponent(new EntityComponentEvent(
        EntityComponentEventId))
    { }

    void loop ();

    void processFrame (TimeResolution elapsedTime);

    void handleInput ();

    void update (TimeResolution elapsedTime);

    void render ();

    TimeResolution elapsed () const;
    void restartClock ();
    bool isFixedFrameReady () const;
    void completeFixedFrame ();
    void waitForNextFixedFrame ();

    int createComponentId (std::string const & token);

    int createSystemId (std::string const & token);

    int createActionId (std::string const & token);

    int createAbilityId (std::string const & token);

    int createCommandId (std::string const & token);

    TimePoint mLastTime;
    TimeResolution mElapsed;
    TimeResolution mFixedFrameTotal;
    bool mExit;
    bool mPaused;

    int mNextEntityId;
    int mNextComponentId;
    int mNextSystemId;
    int mNextActionId;
    int mNextAbilityId;
    int mNextCommandId;
    EntityMap mEntities;
    ComponentMap mRegisteredComponents;
    ComponentVector mLoadedComponents;
    SystemMap mRegisteredSystems;
    SystemVector mLoadedSystems;
    ActionMap mRegisteredActions;
    ActionVector mLoadedActions;
    EntityActionMap mEntityActions;
    AbilityMap mRegisteredGameAbilities;
    AbilityVector mLoadedGameAbilities;
    CommandMap mRegisteredCommands;
    CommandVector mLoadedCommands;
    CommandEventMap mCommandEvents;
    std::unique_ptr<EntityCreatedEvent> mEntityCreated;
    std::unique_ptr<EntityRemovingEvent> mEntityRemoving;
    std::unique_ptr<EntityComponentEvent> mEntityComponent;
  };
} // namespace TUCUT::ECS

#endif // TUCUT_ECS_Application_h
