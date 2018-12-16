//
//  IMovementSystem.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 12/15/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_IMovementSystem_h
#define TUCUT_Game_IMovementSystem_h

#include <string>

#include "GameSystem.h"

namespace TUCUT {
namespace Game {

class IMovementSystem : public Game::GameSystem
{
public:
    static constexpr int moveCmd = 1;
    static const std::string targetIdName;
    static const std::string xAccelerationName;
    static const std::string yAccelerationName;
    static const std::string zAccelerationName;
    
protected:
    IMovementSystem (const std::string & token, int identity)
    : GameSystem(token, identity)
    { }
};

} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_IMovementSystem_h
