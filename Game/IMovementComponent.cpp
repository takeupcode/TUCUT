//
//  IMovementComponent.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 12/15/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "IMovementComponent.h"

namespace TUCUT {
namespace Game {

const std::string IMovementComponent::groupName = "GameMoveable";
const std::string IMovementComponent::xyzVelocityName = "xyzVelocity";
const std::string IMovementComponent::xVelocityName = "xVelocity";
const std::string IMovementComponent::yVelocityName = "yVelocity";
const std::string IMovementComponent::zVelocityName = "zVelocity";
const std::string IMovementComponent::xyzVelocityMaxName = "xyzVelocityMax";
const std::string IMovementComponent::xVelocityMaxName = "xVelocityMax";
const std::string IMovementComponent::yVelocityMaxName = "yVelocityMax";
const std::string IMovementComponent::zVelocityMaxName = "zVelocityMax";
const std::string IMovementComponent::xyzAccelerationName = "xyzAcceleration";
const std::string IMovementComponent::xAccelerationName = "xAcceleration";
const std::string IMovementComponent::yAccelerationName = "yAcceleration";
const std::string IMovementComponent::zAccelerationName = "zAcceleration";
const std::string IMovementComponent::xyzAccelerationDefaultName = "xyzAccelerationDefault";
const std::string IMovementComponent::xAccelerationDefaultName = "xAccelerationDefault";
const std::string IMovementComponent::yAccelerationDefaultName = "yAccelerationDefault";
const std::string IMovementComponent::zAccelerationDefaultName = "zAccelerationDefault";

} // namespace Game
} // namespace TUCUT
