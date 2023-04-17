//  PositionComponent.cpp
//  TUCUT/Game (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-12-05.
//  Copyright © Take Up Code, Inc.
//
#include "PositionComponent.h"

#include "../Math/Adjust.h"

std::string const
TUCUT::Game::PositionComponent::defaultToken =
  "PositionComponent";

void TUCUT::Game::PositionComponent::initialize ()
{
  ECS::Component::initialize();

  ECS::Application * app = ECS::Application::instance();
  mPositionChangedActionId =
    app->getOrCreateAction(positionChangedToken);
}

std::shared_ptr<TUCUT::Game::PositionComponent>
TUCUT::Game::PositionComponent::getSharedPositionComponent ()
{
  return std::static_pointer_cast<PositionComponent>(
    shared_from_this());
}

void TUCUT::Game::PositionComponent::addDefaultProperties (
  std::shared_ptr<ECS::Entity> const & entity) const
{
  if (not entity)
  {
    return;
  }

  auto group = entity->properties().addGroup(groupName);

  double defaultFloatValue = 0.0;
  group->addValue(xName, defaultFloatValue);
  group->addValue(yName, defaultFloatValue);
  group->addValue(zName, defaultFloatValue);
  group->addValue(xOldName, defaultFloatValue);
  group->addValue(yOldName, defaultFloatValue);
  group->addValue(zOldName, defaultFloatValue);
}

void TUCUT::Game::PositionComponent::removeProperties (
  std::shared_ptr<ECS::Entity> const & entity) const
{
  if (not entity)
  {
    return;
  }

  entity->properties().removeGroup(groupName);
}

double TUCUT::Game::PositionComponent::getFloating (
  std::shared_ptr<ECS::Entity> const & entity,
  int propertyId) const
{
  if (not entity)
  {
      return 0;
  }

  switch (propertyId)
  {
  case x:
    return entity->properties().getValue(
      groupName, xName)->getFloating();

  case y:
    return entity->properties().getValue(
      groupName, yName)->getFloating();

  case z:
    return entity->properties().getValue(
      groupName, zName)->getFloating();

  case xOld:
    return entity->properties().getValue(
      groupName, xOldName)->getFloating();

  case yOld:
    return entity->properties().getValue(
      groupName, yOldName)->getFloating();

  case zOld:
    return entity->properties().getValue(
      groupName, zOldName)->getFloating();
  }

  return 0;
}

std::vector<double>
TUCUT::Game::PositionComponent::getFloatings (
  std::shared_ptr<ECS::Entity> const & entity,
  int propertyId) const
{
  std::vector<double> result;

  if (not entity)
  {
    return result;
  }

  switch (propertyId)
  {
  case xyz:
    result.push_back(entity->properties().getValue(
      groupName, xName)->getFloating());

    result.push_back(entity->properties().getValue(
      groupName, yName)->getFloating());

    result.push_back(entity->properties().getValue(
      groupName, zName)->getFloating());
    break;

  case xyzOld:
    result.push_back(entity->properties().getValue(
      groupName, xOldName)->getFloating());

    result.push_back(entity->properties().getValue(
      groupName, yOldName)->getFloating());

    result.push_back(entity->properties().getValue(
      groupName, zOldName)->getFloating());
    break;
  }

  return result;
}

void TUCUT::Game::PositionComponent::setFloating (
  std::shared_ptr<ECS::Entity> const & entity,
  int propertyId,
  double value) const
{
  if (not entity)
  {
    return;
  }

  ECS::Application * app = ECS::Application::instance();

  double old;
  switch (propertyId)
  {
  case x:
    value = Math::clamp(mMinPosition.x, mMaxPosition.x, value);
    old = entity->properties().getValue(
      groupName, xName)->getFloating();
    entity->properties().getValue(
      groupName, xOldName)->setFloating(old);
    entity->properties().getValue(
      groupName, xName)->setFloating(value);

    app->queueAction(
      entity->identity(), mPositionChangedActionId);
    break;

  case y:
    value = Math::clamp(mMinPosition.y, mMaxPosition.y, value);
    old = entity->properties().getValue(
      groupName, yName)->getFloating();
    entity->properties().getValue(
      groupName, yOldName)->setFloating(old);
    entity->properties().getValue(
      groupName, yName)->setFloating(value);

    app->queueAction(
      entity->identity(), mPositionChangedActionId);
    break;

  case z:
    value = Math::clamp(mMinPosition.z, mMaxPosition.z, value);
    old = entity->properties().getValue(
      groupName, zName)->getFloating();
    entity->properties().getValue(
      groupName, zOldName)->setFloating(old);
    entity->properties().getValue(
      groupName, zName)->setFloating(value);

    app->queueAction(
      entity->identity(), mPositionChangedActionId);
    break;

  case xOld:
    value = Math::clamp(mMinPosition.x, mMaxPosition.x, value);
    entity->properties().getValue(
      groupName, xOldName)->setFloating(value);
    break;

  case yOld:
    value = Math::clamp(mMinPosition.y, mMaxPosition.y, value);
    entity->properties().getValue(
      groupName, yOldName)->setFloating(value);
    break;

  case zOld:
    value = Math::clamp(mMinPosition.z, mMaxPosition.z, value);
    entity->properties().getValue(
      groupName, zOldName)->setFloating(value);
    break;
  }
}

void TUCUT::Game::PositionComponent::setFloatings (
  std::shared_ptr<ECS::Entity> const & entity,
  int propertyId,
  std::vector<double> const & value) const
{
  if (not entity || value.size() != 3)
  {
    return;
  }

  ECS::Application * app = ECS::Application::instance();

  double old;
  double singleValue;
  switch (propertyId)
  {
  case xyz:
    singleValue = Math::clamp(
      mMinPosition.x, mMaxPosition.x, value[0]);
    old = entity->properties().getValue(
      groupName, xName)->getFloating();
    entity->properties().getValue(
      groupName, xOldName)->setFloating(old);
    entity->properties().getValue(
      groupName, xName)->setFloating(singleValue);

    singleValue = Math::clamp(
      mMinPosition.y, mMaxPosition.y, value[1]);
    old = entity->properties().getValue(
      groupName, yName)->getFloating();
    entity->properties().getValue(
      groupName, yOldName)->setFloating(old);
    entity->properties().getValue(
      groupName, yName)->setFloating(singleValue);

    singleValue = Math::clamp(
      mMinPosition.z, mMaxPosition.z, value[2]);
    old = entity->properties().getValue(
      groupName, zName)->getFloating();
    entity->properties().getValue(
      groupName, zOldName)->setFloating(old);
    entity->properties().getValue(
      groupName, zName)->setFloating(singleValue);

    app->queueAction(
      entity->identity(), mPositionChangedActionId);
    break;

  case xyzOld:
    singleValue = Math::clamp(
      mMinPosition.x, mMaxPosition.x, value[0]);
    entity->properties().getValue(
      groupName, xOldName)->setFloating(singleValue);

    singleValue = Math::clamp(
      mMinPosition.y, mMaxPosition.y, value[1]);
    entity->properties().getValue(
      groupName, yOldName)->setFloating(singleValue);

    singleValue = Math::clamp(
      mMinPosition.z, mMaxPosition.z, value[2]);
    entity->properties().getValue(
      groupName, zOldName)->setFloating(singleValue);
    break;
  }
}

void TUCUT::Game::PositionComponent::setMinPosition (
  Math::Vector3d const & position)
{
    mMinPosition = position;
}

void TUCUT::Game::PositionComponent::setMaxPosition (
  Math::Vector3d const & position)
{
    mMaxPosition = position;
}
