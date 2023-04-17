//  MovementSystem.cpp
//  TUCUT/Game (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-12-10.
//  Copyright © Take Up Code, Inc.
//
#include "MovementSystem.h"

#include "../Math/Adjust.h"
#include "MovementComponent.h"
#include "PositionComponent.h"
#include "Region.h"

using namespace TUCUT;

std::string const Game::MovementSystem::defaultToken =
  "MovementSystem";

bool Game::MovementSystem::isInstantMode () const
{
  return mInstantMode;
}

void Game::MovementSystem::setInstantMode (bool instant)
{
  mInstantMode = instant;
}

std::shared_ptr<Game::Region> Game::MovementSystem::region ()
{
  return mRegion;
}

void Game::MovementSystem::setRegion (
  std::shared_ptr<Region> region)
{
  mRegion = std::move(region);
}

void Game::MovementSystem::update (
  ECS::TimeResolution elapsedTime)
{
  if (not mRegion)
  {
    return;
  }

  ECS::TimeInSeconds seconds = elapsedTime;

  for (auto const & mapPair: mEntities)
  {
    auto movementComp =
      mapPair.second->getComponentFromAbility("Moveable");
    if (not movementComp)
    {
      continue;
    }

    auto positionComp =
      mapPair.second->getComponentFromAbility("Position");
    if (not positionComp)
    {
      continue;
    }

    auto x = positionComp->getFloating(
      mapPair.second, PositionComponent::x);
    auto y = positionComp->getFloating(
      mapPair.second, PositionComponent::y);
    auto z = positionComp->getFloating(
      mapPair.second, PositionComponent::z);

    double friction = mRegion->getFriction(
      Math::Point3d(x, y, z)) * seconds.count();

    auto xAcceleration = movementComp->getFloating(
      mapPair.second, MovementComponent::xAcceleration);
    auto xVelocity = movementComp->getFloating(
      mapPair.second, MovementComponent::xVelocity);
    if (xAcceleration || xVelocity)
    {
      auto xVelocityMax = movementComp->getFloating(
        mapPair.second, MovementComponent::xVelocityMax);

      if (isInstantMode())
      {
        xVelocity += xAcceleration;
        xVelocity = Math::clamp(
          -xVelocityMax, xVelocityMax, xVelocity);

        movementComp->setFloating(
          mapPair.second, MovementComponent::xAcceleration, 0);
        movementComp->setFloating(
          mapPair.second, MovementComponent::xVelocity, 0);
      }
      else
      {
        xVelocity += xAcceleration * seconds.count();
        xVelocity = Math::toZero(friction, xVelocity);
        xVelocity = Math::clamp(
          -xVelocityMax, xVelocityMax, xVelocity);

        movementComp->setFloating(
          mapPair.second,
          MovementComponent::xVelocity,
          xVelocity);
      }
    }

    auto yAcceleration = movementComp->getFloating(
      mapPair.second, MovementComponent::yAcceleration);
    auto yVelocity = movementComp->getFloating(
      mapPair.second, MovementComponent::yVelocity);
    if (yAcceleration || yVelocity)
    {
      auto yVelocityMax = movementComp->getFloating(
        mapPair.second, MovementComponent::yVelocityMax);

      if (isInstantMode())
      {
        yVelocity += yAcceleration;
        yVelocity = Math::clamp(
          -yVelocityMax, yVelocityMax, yVelocity);

        movementComp->setFloating(
          mapPair.second, MovementComponent::yAcceleration, 0);
        movementComp->setFloating(
          mapPair.second, MovementComponent::yVelocity, 0);
      }
      else
      {
        yVelocity += yAcceleration * seconds.count();
        yVelocity = Math::toZero(friction, yVelocity);
        yVelocity = Math::clamp(
          -yVelocityMax, yVelocityMax, yVelocity);

        movementComp->setFloating(
          mapPair.second,
          MovementComponent::yVelocity,
          yVelocity);
      }
    }

    auto zAcceleration = movementComp->getFloating(
      mapPair.second, MovementComponent::zAcceleration);
    auto zVelocity = movementComp->getFloating(
      mapPair.second, MovementComponent::zVelocity);
    if (zAcceleration || zVelocity)
    {
      auto zVelocityMax = movementComp->getFloating(
        mapPair.second, MovementComponent::zVelocityMax);

      zVelocity += zAcceleration * seconds.count();
      zVelocity = Math::clamp(
        -zVelocityMax, zVelocityMax, zVelocity);

      movementComp->setFloating(
        mapPair.second,
        MovementComponent::zVelocity,
        zVelocity);
    }

    if (xVelocity || yVelocity || zVelocity)
    {
      Math::Point3d currentPosition(x, y, z);
      x += isInstantMode() ?
        xVelocity : xVelocity * seconds.count();
      y += isInstantMode() ?
        yVelocity : yVelocity * seconds.count();
      z += zVelocity * seconds.count();

      auto resolvedPosition = mRegion->resolveCollisions(
        currentPosition, Math::Point3d(x, y, z));

      std::vector<double> positions;
      positions.push_back(resolvedPosition.x);
      positions.push_back(resolvedPosition.y);
      positions.push_back(resolvedPosition.z);

      // Set all three position coordinates at once so
      // the position component can queue a single
      // moved action.
      positionComp->setFloatings(
        mapPair.second, PositionComponent::xyz, positions);
    }
  }
}

void Game::MovementSystem::notify (
  int id,
  int commandId,
  ECS::PropertyGroup const & commandProperties)
{
  if (id != ECS::Application::CommandSentEventId)
  {
    return;
  }

  if (commandId != moveCmd)
  {
    return;
  }

  auto targetId =
    commandProperties.getValue(targetIdName)->getInteger();
  auto mapIter = mEntities.find(targetId);
  if (mapIter == mmEntities.end())
  {
    return;
  }

  auto movementComp =
    mapIter->second->getComponentFromAbility("Moveable");
  if (not movementComp)
  {
    return;
  }

  auto propValue =
    commandProperties.getValue(xAccelerationName);
  auto xAcceleration = propValue ? propValue->getFloating() : 0;
  propValue = commandProperties.getValue(yAccelerationName);
  auto yAcceleration = propValue ? propValue->getFloating() : 0;
  propValue = commandProperties.getValue(zAccelerationName);
  auto zAcceleration = propValue ? propValue->getFloating() : 0;

  if (xAcceleration)
  {
    movementComp->setFloating(mapIter->second,
      MovementComponent::xAcceleration, xAcceleration);
  }

  if (yAcceleration)
  {
    movementComp->setFloating(mapIter->second,
      MovementComponent::yAcceleration, yAcceleration);
  }

  if (zAcceleration)
  {
    movementComp->setFloating(mapIter->second,
      MovementComponent::zAcceleration, zAcceleration);
  }
}
