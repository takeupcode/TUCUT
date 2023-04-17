//  MovementComponent.cpp
//  TUCUT/Game (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-12-09.
//  Copyright © Take Up Code, Inc.
//
#include "MovementComponent.h"

#include "../Math/Adjust.h"

std::string const
TUCUT::Game::MovementComponent::defaultToken =
  "MovementComponent";

std::shared_ptr<TUCUT::Game::MovementComponent>
TUCUT::Game::MovementComponent::getSharedMovementComponent ()
{
  return std::static_pointer_cast<MovementComponent>(
    shared_from_this());
}

void TUCUT::Game::MovementComponent::addDefaultProperties (
  std::shared_ptr<ECS::Entity> const & entity) const
{
  if (not entity)
  {
    return;
  }

  auto group = entity->properties().addGroup(groupName);

  double defaultFloatValue = 0.0;
  group->addValue(xVelocityName, defaultFloatValue);
  group->addValue(yVelocityName, defaultFloatValue);
  group->addValue(zVelocityName, defaultFloatValue);
  group->addValue(xVelocityMaxName, defaultFloatValue);
  group->addValue(yVelocityMaxName, defaultFloatValue);
  group->addValue(zVelocityMaxName, defaultFloatValue);
  group->addValue(xAccelerationName, defaultFloatValue);
  group->addValue(yAccelerationName, defaultFloatValue);
  group->addValue(zAccelerationName, defaultFloatValue);
  group->addValue(xAccelerationDefaultName, defaultFloatValue);
  group->addValue(yAccelerationDefaultName, defaultFloatValue);
  group->addValue(zAccelerationDefaultName, defaultFloatValue);
}

void TUCUT::Game::MovementComponent::removeProperties (
  std::shared_ptr<ECS::Entity> const & entity) const
{
  if (not entity)
  {
    return;
  }

  entity->properties().removeGroup(groupName);
}

double TUCUT::Game::MovementComponent::getFloating (
  std::shared_ptr<ECS::Entity> const & entity,
  int propertyId) const
{
  if (not entity)
  {
    return 0;
  }

  switch (propertyId)
  {
  case xVelocity:
    return entity->properties().getValue(
      groupName, xVelocityName)->getFloating();

  case yVelocity:
    return entity->properties().getValue(
      groupName, yVelocityName)->getFloating();

  case zVelocity:
    return entity->properties().getValue(
      groupName, zVelocityName)->getFloating();

  case xVelocityMax:
    return entity->properties().getValue(
      groupName, xVelocityMaxName)->getFloating();

  case yVelocityMax:
    return entity->properties().getValue(
      groupName, yVelocityMaxName)->getFloating();

  case zVelocityMax:
    return entity->properties().getValue(
      groupName, zVelocityMaxName)->getFloating();

  case xAcceleration:
    return entity->properties().getValue(
      groupName, xAccelerationName)->getFloating();

  case yAcceleration:
    return entity->properties().getValue(
      groupName, yAccelerationName)->getFloating();

  case zAcceleration:
    return entity->properties().getValue(
      groupName, zAccelerationName)->getFloating();

  case xAccelerationDefault:
    return entity->properties().getValue(
      groupName, xAccelerationDefaultName)->getFloating();

  case yAccelerationDefault:
    return entity->properties().getValue(
      groupName, yAccelerationDefaultName)->getFloating();

  case zAccelerationDefault:
    return entity->properties().getValue(
      groupName, zAccelerationDefaultName)->getFloating();
  }

  return 0;
}

std::vector<double>
TUCUT::Game::MovementComponent::getFloatings (
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
  case xyzVelocity:
    result.push_back(entity->properties().getValue(
      groupName, xVelocityName)->getFloating());
    result.push_back(entity->properties().getValue(
      groupName, yVelocityName)->getFloating());
    result.push_back(entity->properties().getValue(
      groupName, zVelocityName)->getFloating());
    break;

  case xyzVelocityMax:
    result.push_back(entity->properties().getValue(
      groupName, xVelocityMaxName)->getFloating());
    result.push_back(entity->properties().getValue(
      groupName, yVelocityMaxName)->getFloating());
    result.push_back(entity->properties().getValue(
      groupName, zVelocityMaxName)->getFloating());
    break;

  case xyzAcceleration:
    result.push_back(entity->properties().getValue(
      groupName, xAccelerationName)->getFloating());
    result.push_back(entity->properties().getValue(
      groupName, yAccelerationName)->getFloating());
    result.push_back(entity->properties().getValue(
      groupName, zAccelerationName)->getFloating());
    break;

  case xyzAccelerationDefault:
    result.push_back(entity->properties().getValue(
      groupName, xAccelerationDefaultName)->getFloating());
    result.push_back(entity->properties().getValue(
      groupName, yAccelerationDefaultName)->getFloating());
    result.push_back(entity->properties().getValue(
      groupName, zAccelerationDefaultName)->getFloating());
    break;
  }

  return result;
}

void TUCUT::Game::MovementComponent::setFloating (
  std::shared_ptr<ECS::Entity> const & entity,
  int propertyId,
  double value) const
{
  if (not entity)
  {
    return;
  }

  double max;
  switch (propertyId)
  {
  case xVelocity:
    max = entity->properties().getValue(
      groupName, xVelocityMaxName)->getFloating();
    value = Math::clamp(-max, max, value);
    entity->properties().getValue(
      groupName, xVelocityName)->setFloating(value);
    break;

  case yVelocity:
    max = entity->properties().getValue(
      groupName, yVelocityMaxName)->getFloating();
    value = Math::clamp(-max, max, value);
    entity->properties().getValue(
      groupName, yVelocityName)->setFloating(value);
    break;

  case zVelocity:
    max = entity->properties().getValue(
      groupName, zVelocityMaxName)->getFloating();
    value = Math::clamp(-max, max, value);
    entity->properties().getValue(
      groupName, zVelocityName)->setFloating(value);
    break;

  case xVelocityMax:
    value = Math::makePositive(value);
    entity->properties().getValue(
      groupName, xVelocityMaxName)->setFloating(value);
    break;

  case yVelocityMax:
    value = Math::makePositive(value);
    entity->properties().getValue(
      groupName, yVelocityMaxName)->setFloating(value);
    break;

  case zVelocityMax:
    value = Math::makePositive(value);
    entity->properties().getValue(
      groupName, zVelocityMaxName)->setFloating(value);
    break;

  case xAcceleration:
    entity->properties().getValue(
      groupName, xAccelerationName)->setFloating(value);
    break;

  case yAcceleration:
    entity->properties().getValue(
      groupName, yAccelerationName)->setFloating(value);
    break;

  case zAcceleration:
    entity->properties().getValue(
      groupName, zAccelerationName)->setFloating(value);
    break;

  case xAccelerationDefault:
    value = Math::makePositive(value);
    entity->properties().getValue(
      groupName, xAccelerationDefaultName)->setFloating(value);
    break;

  case yAccelerationDefault:
    value = Math::makePositive(value);
    entity->properties().getValue(
      groupName, yAccelerationDefaultName)->setFloating(value);
    break;

  case zAccelerationDefault:
    value = Math::makePositive(value);
    entity->properties().getValue(
      groupName, zAccelerationDefaultName)->setFloating(value);
    break;
  }
}

void TUCUT::Game::MovementComponent::setFloatings (
  std::shared_ptr<ECS::Entity> const & entity,
  int propertyId,
  std::vector<double> const & value) const
{
  if (not entity || value.size() != 3)
  {
    return;
  }

  double max;
  double singleValue;
  switch (propertyId)
  {
  case xyzVelocity:
    max = entity->properties().getValue(
      groupName, xVelocityMaxName)->getFloating();
    singleValue = Math::clamp(-max, max, value[0]);
    entity->properties().getValue(
      groupName, xVelocityName)->setFloating(singleValue);

    max = entity->properties().getValue(
      groupName, yVelocityMaxName)->getFloating();
    singleValue = Math::clamp(-max, max, value[1]);
    entity->properties().getValue(
      groupName, yVelocityName)->setFloating(singleValue);

    max = entity->properties().getValue(
      groupName, zVelocityMaxName)->getFloating();
    singleValue = Math::clamp(-max, max, value[2]);
    entity->properties().getValue(
      groupName, zVelocityName)->setFloating(singleValue);
    break;

  case xyzVelocityMax:
    singleValue = Math::makePositive(value[0]);
    entity->properties().getValue(
      groupName, xVelocityMaxName)->setFloating(singleValue);

    singleValue = Math::makePositive(value[1]);
    entity->properties().getValue(
      groupName, yVelocityMaxName)->setFloating(singleValue);

    singleValue = Math::makePositive(value[2]);
    entity->properties().getValue(
      groupName, zVelocityMaxName)->setFloating(singleValue);
    break;

  case xyzAcceleration:
    entity->properties().getValue(
      groupName, xAccelerationName)->setFloating(value[0]);

    entity->properties().getValue(
      groupName, yAccelerationName)->setFloating(value[1]);

    entity->properties().getValue(
      groupName, zAccelerationName)->setFloating(value[2]);
    break;

  case xyzAccelerationDefault:
    singleValue = Math::makePositive(value[0]);
    entity->properties().getValue(
      groupName, xAccelerationDefaultName)->setFloating(
        singleValue);

    singleValue = Math::makePositive(value[1]);
    entity->properties().getValue(
      groupName, yAccelerationDefaultName)->setFloating(
        singleValue);

    singleValue = Math::makePositive(value[2]);
    entity->properties().getValue(
      groupName, zAccelerationDefaultName)->setFloating(
        singleValue);
    break;
  }
}
