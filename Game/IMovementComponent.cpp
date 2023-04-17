//  IMovementComponent.cpp
//  TUCUT/Game (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-12-15.
//  Copyright © Take Up Code, Inc.
//
#include "IMovementComponent.h"

namespace TUCUT::Game
{
  std::string const
    IMovementComponent::groupName = "Moveable";
  std::string const
    IMovementComponent::xyzVelocityName = "xyzVelocity";
  std::string const
    IMovementComponent::xVelocityName = "xVelocity";
  std::string const
    IMovementComponent::yVelocityName = "yVelocity";
  std::string const
    IMovementComponent::zVelocityName = "zVelocity";
  std::string const
    IMovementComponent::xyzVelocityMaxName = "xyzVelocityMax";
  std::string const
    IMovementComponent::xVelocityMaxName = "xVelocityMax";
  std::string const
    IMovementComponent::yVelocityMaxName = "yVelocityMax";
  std::string const
    IMovementComponent::zVelocityMaxName = "zVelocityMax";
  std::string const
    IMovementComponent::xyzAccelerationName = "xyzAcceleration";
  std::string const
    IMovementComponent::xAccelerationName = "xAcceleration";
  std::string const
    IMovementComponent::yAccelerationName = "yAcceleration";
  std::string const
    IMovementComponent::zAccelerationName = "zAcceleration";
  std::string const
    IMovementComponent::xyzAccelerationDefaultName =
      "xyzAccelerationDefault";
  std::string const
    IMovementComponent::xAccelerationDefaultName =
      "xAccelerationDefault";
  std::string const
    IMovementComponent::yAccelerationDefaultName =
      "yAccelerationDefault";
  std::string const
    IMovementComponent::zAccelerationDefaultName =
      "zAccelerationDefault";
} // namespace TUCUT::Game
