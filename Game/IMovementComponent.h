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
    static const std::string groupName;
    static const std::string xVelocityName;
    static const std::string yVelocityName;
    static const std::string zVelocityName;
    
protected:
    IMovementComponent (const std::string & token, int identity)
    : GameComponent(token, identity)
    { }
};

} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_IMovementComponent_h
