//  IMovementComponent.h
//  TUCUT/Game (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-12-15.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_Game_IMovementComponent_h
#define TUCUT_Game_IMovementComponent_h

#include "../ECS/Component.h"

#include <string>

namespace TUCUT::Game
{
  class IMovementComponent : public ECS::Component
  {
  public:
    static constexpr int xyzVelocity = 1;
    static constexpr int xVelocity = 2;
    static constexpr int yVelocity = 3;
    static constexpr int zVelocity = 4;
    static constexpr int xyzVelocityMax = 5;
    static constexpr int xVelocityMax = 6;
    static constexpr int yVelocityMax = 7;
    static constexpr int zVelocityMax = 8;
    static constexpr int xyzAcceleration = 9;
    static constexpr int xAcceleration = 10;
    static constexpr int yAcceleration = 11;
    static constexpr int zAcceleration = 12;
    static constexpr int xyzAccelerationDefault = 13;
    static constexpr int xAccelerationDefault = 14;
    static constexpr int yAccelerationDefault = 15;
    static constexpr int zAccelerationDefault = 16;
    static std::string const groupName;
    static std::string const xyzVelocityName;
    static std::string const xVelocityName;
    static std::string const yVelocityName;
    static std::string const zVelocityName;
    static std::string const xyzVelocityMaxName;
    static std::string const xVelocityMaxName;
    static std::string const yVelocityMaxName;
    static std::string const zVelocityMaxName;
    static std::string const xyzAccelerationName;
    static std::string const xAccelerationName;
    static std::string const yAccelerationName;
    static std::string const zAccelerationName;
    static std::string const xyzAccelerationDefaultName;
    static std::string const xAccelerationDefaultName;
    static std::string const yAccelerationDefaultName;
    static std::string const zAccelerationDefaultName;

  protected:
    IMovementComponent (std::string const & token, int identity)
    : Component(token, identity)
    { }
  };
} // namespace TUCUT::Game

#endif // TUCUT_Game_IMovementComponent_h
