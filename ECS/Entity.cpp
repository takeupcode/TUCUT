//  Entity.cpp
//  TUCUT/ECS (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-08-19.
//  Copyright © Take Up Code, Inc.
//
#include "Entity.h"

#include "Application.h"
#include "Component.h"

#include <algorithm>
#include <stdexcept>

std::string const
TUCUT::ECS::Entity::defaultToken = "Entity";

void TUCUT::ECS::Entity::initialize ()
{ }

std::shared_ptr<TUCUT::ECS::Entity>
TUCUT::ECS::Entity::getSharedEntity ()
{
  return shared_from_this();
}

bool TUCUT::ECS::Entity::hasComponent (int componentId) const
{
  if (componentId < 1)
  {
    return false;
  }

  if (mComponents.size() > static_cast<size_t>(componentId))
  {
    return mComponents[componentId];
  }

  return false;
}

bool TUCUT::ECS::Entity::hasComponent (
  std::shared_ptr<Component> const & component) const
{
  return hasComponent(component->identity());
}

bool TUCUT::ECS::Entity::addComponent (int componentId)
{
  if (componentId < 1)
  {
    return false;
  }

  Application * app = Application::instance();
  auto component = app->getBaseComponent(componentId);

  return addComponent(component);

  return false;
}

bool TUCUT::ECS::Entity::addComponent (
  std::shared_ptr<Component> const & component)
{
  if (not component)
  {
    return false;
  }

  auto componentId = component->identity();
  while (mComponents.size() <= static_cast<size_t>(componentId))
  {
    mComponents.push_back(false);
  }

  if (mComponents[componentId])
  {
    return false;
  }

  Application * app = Application::instance();

  for (auto const & ability: component->getAbilities())
  {
    auto abilityId = app->getAbilityId(ability);
    if (abilityId < 1)
    {
      throw std::runtime_error(
        "Unable to find registered ability");
    }

    while (mAbilities.size() <= static_cast<size_t>(abilityId))
    {
      mAbilities.push_back({});
    }
    mAbilities[abilityId].push_back(component);
  }

  mComponents[componentId] = true;

  auto entity = getSharedEntity();
  component->addDefaultProperties(entity);

  app->onEntityComponentChanged(entity);

  return true;
}

void TUCUT::ECS::Entity::removeComponent (int componentId)
{
  if (componentId < 1)
  {
    return;
  }

  Application * app = Application::instance();
  auto component = app->getBaseComponent(componentId);

  removeComponent(component);
}

void TUCUT::ECS::Entity::removeComponent (
  std::shared_ptr<Component> const & component)
{
  if (not component)
  {
    return;
  }

  auto componentId = component->identity();
  if (mComponents.size() <= static_cast<size_t>(componentId))
  {
    return;
  }

  if (not mComponents[componentId])
  {
    return;
  }

  Application * app = Application::instance();

  mComponents[componentId] = false;

  for (auto const & ability: component->getAbilities())
  {
    auto abilityId = app->getAbilityId(ability);
    if (abilityId > 0 &&
      mAbilities.size() > static_cast<size_t>(abilityId))
    {
      mAbilities[abilityId].erase(
        std::find(mAbilities[abilityId].begin(),
          mAbilities[abilityId].end(), component));
    }
  }

  auto entity = getSharedEntity();
  component->removeProperties(entity);

  app->onEntityComponentChanged(entity);
}

bool TUCUT::ECS::Entity::hasAbility (int abilityId) const
{
  if (abilityId < 1)
  {
    return false;
  }

  if (mAbilities.size() > static_cast<size_t>(abilityId))
  {
    return not mAbilities[abilityId].empty();
  }

  return false;
}

bool TUCUT::ECS::Entity::hasAbility (
  std::string const & token) const
{
  Application * app = Application::instance();

  auto abilityId = app->getAbilityId(token);

  return hasAbility(abilityId);
}

std::shared_ptr<TUCUT::ECS::Component>
TUCUT::ECS::Entity::getComponentFromAbility (
  int abilityId) const
{
  if (abilityId < 1)
  {
    return nullptr;
  }

  if (mAbilities.size() > static_cast<size_t>(abilityId))
  {
    if (not mAbilities[abilityId].empty())
    {
      return mAbilities[abilityId].back();
    }
  }

  return nullptr;
}

std::shared_ptr<TUCUT::ECS::Component>
TUCUT::ECS::Entity::getComponentFromAbility (
  std::string const & token) const
{
  Application * app = Application::instance();

  auto abilityId = app->getAbilityId(token);

  return getComponentFromAbility(abilityId);
}
