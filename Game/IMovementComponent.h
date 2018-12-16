//
//  IMovementComponent.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 12/15/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_IMovementComponent_h
#define TUCUT_Game_IMovementComponent_h

#include <string>

#include "GameComponent.h"

namespace TUCUT {
namespace Game {

class IMovementComponent : public Game::GameComponent
{
public:
    static constexpr int xVelocity = 1;
    static constexpr int yVelocity = 2;
    static constexpr int zVelocity = 3;
    static constexpr int xVelocityMax = 4;
    static constexpr int yVelocityMax = 5;
    static constexpr int zVelocityMax = 6;
    static constexpr int xAcceleration = 7;
    static constexpr int yAcceleration = 8;
    static constexpr int zAcceleration = 9;
    static constexpr int xAccelerationDefault = 10;
    static constexpr int yAccelerationDefault = 11;
    static constexpr int zAccelerationDefault = 12;
    static const std::string groupName;
    static const std::string xVelocityName;
    static const std::string yVelocityName;
    static const std::string zVelocityName;
    static const std::string xVelocityMaxName;
    static const std::string yVelocityMaxName;
    static const std::string zVelocityMaxName;
    static const std::string xAccelerationName;
    static const std::string yAccelerationName;
    static const std::string zAccelerationName;
    static const std::string xAccelerationDefaultName;
    static const std::string yAccelerationDefaultName;
    static const std::string zAccelerationDefaultName;

protected:
    IMovementComponent (const std::string & token, int identity)
    : GameComponent(token, identity)
    { }
};

} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_IMovementComponent_h
