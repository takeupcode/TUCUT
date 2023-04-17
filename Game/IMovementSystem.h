//  IMovementSystem.h
//  TUCUT/Game (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-12-15.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_Game_IMovementSystem_h
#define TUCUT_Game_IMovementSystem_h

#include "../ECS/System.h"

#include <string>

namespace TUCUT::Game
{
  class IMovementSystem : public ECS::System
  {
  public:
    static constexpr int moveCmd = 1;
    static std::string const targetIdName;
    static std::string const xAccelerationName;
    static std::string const yAccelerationName;
    static std::string const zAccelerationName;

  protected:
    IMovementSystem (std::string const & token, int identity)
    : System(token, identity)
    { }
  };
} // namespace TUCUT::Game

#endif // TUCUT_Game_IMovementSystem_h
