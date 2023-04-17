//  System.cpp
//  TUCUT/ECS (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-11-27.
//  Copyright © Take Up Code, Inc.
//
#include "System.h"

#include "Application.h"

#include <stdexcept>

std::string const
TUCUT::ECS::System::defaultToken = "System";

void TUCUT::ECS::System::initialize ()
{
  Application * app = Application::instance();
  for (auto const & token: mRequiredAbilityTokens)
  {
    app->getOrCreateAbility(token);
  }
  for (auto const & token: mRequiredCommandTokens)
  {
    auto commandId = app->getOrCreateCommand(token);
    app->commandSent(commandId)->connect(
      idToken().toString(), getSharedSystem());
  }
  for (auto const & token: mActionTokens)
  {
    app->getOrCreateAction(token);
  }

  app->entityCreated()->connect(
    idToken().toString(), getSharedSystem());
  app->entityRemoving()->connect(
    idToken().toString(), getSharedSystem());
  app->entityComponentChanged()->connect(
    idToken().toString(), getSharedSystem());
}

std::shared_ptr<TUCUT::ECS::System>
TUCUT::ECS::System::getSharedSystem ()
{
  return shared_from_this();
}

bool TUCUT::ECS::System::hasEntity (int identity) const
{
  if (identity < 1)
  {
    return false;
  }

  return mEntities.contains(identity);
}

void TUCUT::ECS::System::notify (
  int id,
  std::shared_ptr<Entity> const & entity)
{
  bool entityBelongs = false;
  if (id == Application::EntityCreatedEventId ||
    id == Application::EntityComponentEventId)
  {
    // An entity will belong by default unless it's
    // missing a required component.
    entityBelongs = true;

    for (auto const & token: mRequiredAbilityTokens)
    {
      if (not entity->hasAbility(token))
      {
        entityBelongs = false;
        break;
      }
    }
  }
  else if (id == Application::EntityRemovingEventId)
  {
    entityBelongs = false;
  }
  else
  {
    return;
  }

  if (entityBelongs)
  {
    if (not hasEntity(entity->identity()))
    {
      auto result = mEntities.try_emplace(
        entity->identity(), entity);
      if (not result.second)
      {
        throw std::runtime_error(
          "Unable to add entity to system");
      }
    }
  }
  else
  {
    auto entityMapResult = mEntities.find(entity->identity());
    if (entityMapResult != mEntities.end())
    {
      mEntities.erase(entity->identity());
    }
  }
}

void TUCUT::ECS::System::notify (
  int,
  int,
  PropertyGroup const &)
{ }
