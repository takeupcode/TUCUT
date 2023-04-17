//  Application.cpp
//  TUCUT/ECS (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-08-19.
//  Copyright © Take Up Code, Inc.
//
#include "Application.h"

#include <stdexcept>
#include <thread>

using namespace TUCUT;

ECS::TimeResolution const ECS::Application::FixedFrameTime =
  ECS::TimeResolution(ECS::TimeResolution::period::den /
    ECS::Application::FramesPerSecond);

Application * ECS::Application::instance ()
{
  static Application * mInstance = nullptr;

  if (not mInstance)
  {
    mInstance = new Application();
  }

  return mInstance;
}

void ECS::Application::initialize ()
{ }

void ECS::Application::deinitialize ()
{
  mEntities.clear();
  mRegisteredComponents.clear();
  mLoadedComponents.clear();
  mRegisteredSystems.clear();
  mLoadedSystems.clear();
  mRegisteredActions.clear();
  mLoadedActions.clear();
  mEntityActions.clear();
  mRegisteredAbilities.clear();
  mLoadedAbilities.clear();
  mRegisteredCommands.clear();
  mLoadedCommands.clear();
  mCommandEvents.clear();
}

void ECS::Application::run ()
{
  loop();
}

void ECS::Application::exit ()
{
  mExit = true;
}

void ECS::Application::pause ()
{
  mPaused = true;
}

void ECS::Application::resume ()
{
  mPaused = false;
  loop();
}

void ECS::Application::step ()
{
  processFrame(FixedFrameTime);
}

ECS::TimeResolution ECS::Application::elapsed () const
{
  return mElapsed;
}

void ECS::Application::restartClock ()
{
  auto currentTime = TimeClock::now();
  mElapsed = std::chrono::duration_cast<TimeResolution>(
    currentTime - mLastTime);
  mFixedFrameTotal += mElapsed;
  mLastTime = currentTime;
}

bool ECS::Application::isFixedFrameReady () const
{
  return mFixedFrameTotal > FixedFrameTime;
}

void ECS::Application::completeFixedFrame ()
{
  mFixedFrameTotal -= FixedFrameTime;
}

void ECS::Application::waitForNextFixedFrame ()
{
  auto waitDuration = FixedFrameTime - mFixedFrameTotal;
  if (waitDuration > waitDuration.zero())
  {
    std::this_thread::sleep_for(
      std::chrono::duration_cast<std::chrono::milliseconds>(
        waitDuration));
  }
}

void ECS::Application::loop ()
{
  mLastTime = TimeClock::now();

  while (not mExit && not mPaused)
  {
    if (isFixedFrameReady())
    {
      processFrame(elapsed());

      completeFixedFrame();
    }
    else
    {
      waitForNextFixedFrame();
    }
    restartClock();
  }
}

void ECS::Application::processFrame (
  TimeResolution elapsedTime)
{
  handleInput();
  update(elapsedTime);
  render();
}

int ECS::Application::createComponentId (
  std::string const & token)
{
  if (token.empty())
  {
    throw std::runtime_error("Unable to create component id");
  }

  mRegisteredComponents[token] = mNextComponentId;

  // Make sure there's always a matching entry in the
  // loaded components vector.
  while (mLoadedComponents.size() <= static_cast<size_t>(
    mNextComponentId))
  {
    mLoadedComponents.push_back(nullptr);
  }

  return mNextComponentId++;
}

int ECS::Application::getComponentId (
  std::string const & token) const
{
  auto componentMapResult = mRegisteredComponents.find(token);
  if (componentMapResult == mRegisteredComponents.end())
  {
    return 0;
  }

  return componentMapResult->second;
}

int ECS::Application::createSystemId (
  std::string const & token)
{
  if (token.empty())
  {
    throw std::runtime_error("Unable to create system id");
  }

  mRegisteredSystems[token] = mNextSystemId;

  // Make sure there's always a matching entry in the
  // loaded systems vector.
  while (mLoadedSystems.size() <= static_cast<size_t>(
    mNextSystemId))
  {
    mLoadedSystems.push_back(nullptr);
  }

  return mNextSystemId++;
}

int ECS::Application::getSystemId (
  std::string const & token) const
{
  auto systemMapResult = mRegisteredSystems.find(token);
  if (systemMapResult == mRegisteredSystems.end())
  {
    return 0;
  }

  return systemMapResult->second;
}

int ECS::Application::createActionId (
  std::string const & token)
{
  if (token.empty())
  {
    throw std::runtime_error("Unable to create action id");
  }

  mRegisteredActions[token] = mNextActionId;

  // Make sure there's always a matching entry in the
  // loaded actions vector.
  while (mLoadedActions.size() <= static_cast<size_t>(
    mNextActionId))
  {
    mLoadedActions.push_back("");
  }

  return mNextActionId++;
}

int ECS::Application::getActionId (
  std::string const & token) const
{
  auto actionMapResult = mRegisteredActions.find(token);
  if (actionMapResult == mRegisteredActions.end())
  {
    return 0;
  }

  return actionMapResult->second;
}

int ECS::Application::createAbilityId (
  std::string const & token)
{
  if (token.empty())
  {
    throw std::runtime_error("Unable to create ability id");
  }

  mRegisteredAbilities[token] = mNextAbilityId;

  // Make sure there's always a matching entry in the
  // loaded abilities vector.
  while (mLoadedAbilities.size() <= static_cast<size_t>(
    mNextAbilityId))
  {
    mLoadedAbilities.push_back("");
  }

  return mNextAbilityId++;
}

int ECS::Application::getAbilityId (
  std::string const & token) const
{
  auto abilityMapResult = mRegisteredAbilities.find(token);
  if (abilityMapResult == mRegisteredAbilities.end())
  {
    return 0;
  }

  return abilityMapResult->second;
}

int ECS::Application::createCommandId (
  std::string const & token)
{
  if (token.empty())
  {
    throw std::runtime_error("Unable to create command id");
  }

  mRegisteredCommands[token] = mNextCommandId;

  // Make sure there's always a matching entry in the
  // loaded commands vector.
  while (mLoadedCommands.size() <= static_cast<size_t>(
    mNextCommandId))
  {
    mLoadedCommands.push_back("");
  }

  return mNextCommandId++;
}

int ECS::Application::getCommandId (
  std::string const & token) const
{
  auto commandMapResult = mRegisteredCommands.find(token);
  if (commandMapResult == mRegisteredCommands.end())
  {
    return 0;
  }

  return commandMapResult->second;
}

bool ECS::Application::hasEntity (int identity) const
{
  if (identity < 1)
  {
    return false;
  }

  auto entityMapResult = mEntities.find(identity);
  if (entityMapResult == mEntities.end())
  {
    return false;
  }

  return true;
}

void ECS::Application::removeEntity (int identity)
{
  if (identity < 1)
  {
    return;
  }

  auto entityMapResult = mEntities.find(identity);
  if (entityMapResult != mEntities.end())
  {
    mEntityRemoving->signal(entityMapResult->second);

    mEntities.erase(identity);
  }
}

bool ECS::Application::hasComponent (int identity) const
{
  if (identity < 1)
  {
    return false;
  }

  if (mLoadedComponents.size() > static_cast<size_t>(identity))
  {
    return mLoadedComponents[identity] != nullptr;
  }

  return false;
}

bool ECS::Application::hasComponent (
  std::string const & token) const
{
  auto componentId = getComponentId(token);
  if (componentId == 0)
  {
    return false;
  }

  return hasComponent(componentId);
}

bool ECS::Application::hasSystem (int identity) const
{
  if (identity < 1)
  {
    return false;
  }

  if (mLoadedSystems.size() > static_cast<size_t>(identity))
  {
    return mLoadedSystems[identity] != nullptr;
  }

  return false;
}

bool ECS::Application::hasSystem (
  std::string const & token) const
{
  auto systemId = getSystemId(token);
  if (systemId == 0)
  {
    return false;
  }

  return hasSystem(systemId);
}

std::string ECS::Application::getAction (
  int identity) const
{
  if (identity < 1)
  {
    return "";
  }

  if (mLoadedActions.size() > static_cast<size_t>(identity))
  {
    return mLoadedActions[identity];
  }

  return "";
}

int ECS::Application::getOrCreateAction (
  std::string const & token)
{
  auto actionId = getActionId(token);
  if (actionId == 0)
  {
    actionId = createActionId(token);
    mLoadedActions[actionId] = token;
  }

  return actionId;
}

bool ECS::Application::hasAction (int identity) const
{
  if (identity < 1)
  {
    return false;
  }

  if (mLoadedActions.size() > static_cast<size_t>(identity))
  {
    return not mLoadedActions[identity].empty();
  }

  return false;
}

bool ECS::Application::hasAction (
  std::string const & token) const
{
  auto actionId = getActionId(token);
  if (actionId == 0)
  {
    return false;
  }

  return hasAction(actionId);
}

void ECS::Application::queueAction (
  int objectId, int actionId)
{
  if (objectId < 1 || actionId < 1)
  {
    return;
  }

  mEntityActions[objectId].push(actionId);
}

std::string ECS::Application::getAbility (
  int identity) const
{
  if (identity < 1)
  {
    return "";
  }

  if (mLoadedAbilities.size() > static_cast<size_t>(identity))
  {
    return mLoadedAbilities[identity];
  }

  return "";
}

int ECS::Application::getOrCreateAbility (
  std::string const & token)
{
  auto abilityId = getAbilityId(token);
  if (abilityId == 0)
  {
    abilityId = createAbilityId(token);
    mLoadedAbilities[abilityId] = token;
  }

  return abilityId;
}

bool ECS::Application::hasAbility (int identity) const
{
  if (identity < 1)
  {
    return false;
  }

  if (mLoadedAbilities.size() > static_cast<size_t>(identity))
  {
    return not mLoadedAbilities[identity].empty();
  }

  return false;
}

bool ECS::Application::hasAbility (
  std::string const & token) const
{
  auto abilityId = getAbilityId(token);
  if (abilityId == 0)
  {
    return false;
  }

  return hasAbility(abilityId);
}

std::string ECS::Application::getCommand (int identity) const
{
  if (identity < 1)
  {
    return "";
  }

  if (mLoadedCommands.size() > static_cast<size_t>(identity))
  {
    return mLoadedCommands[identity];
  }

  return "";
}

int ECS::Application::getOrCreateCommand (
  std::string const & token)
{
  auto commandId = getCommandId(token);
  if (commandId == 0)
  {
    commandId = createCommandId(token);
    mLoadedCommands[commandId] = token;
  }

  return commandId;
}

bool ECS::Application::hasCommand (int identity) const
{
  if (identity < 1)
  {
    return false;
  }

  if (mLoadedCommands.size() > static_cast<size_t>(identity))
  {
    return not mLoadedCommands[identity].empty();
  }

  return false;
}

bool ECS::Application::hasCommand (
  std::string const & token) const
{
  auto commandId = getCommandId(token);
  if (commandId == 0)
  {
    return false;
  }

  return hasCommand(commandId);
}

void ECS::Application::handleInput ()
{
  for (auto const & system: mLoadedSystems)
  {
    if (system)
    {
      system->handleInput();
    }
  }
}

void ECS::Application::update (
  TimeResolution elapsedTime)
{
  for (auto const & system: mLoadedSystems)
  {
    if (system)
    {
      system->update(elapsedTime);
    }
  }

  auto actionQueueIter = mEntityActions.begin();
  while (actionQueueIter != mEntityActions.end())
  {
    while (not actionQueueIter->second.empty())
    {
      int actionId = actionQueueIter->second.front();
      for (auto const & system: mLoadedSystems)
      {
        if (system)
        {
          system->onAction(actionQueueIter->first, actionId);
        }
      }
      actionQueueIter->second.pop();
    }
    mEntityActions.erase(actionQueueIter);
    actionQueueIter = mEntityActions.begin();
  }
}

void ECS::Application::render ()
{
  for (auto const & system: mLoadedSystems)
  {
    if (system)
    {
      system->render();
    }
  }
}
