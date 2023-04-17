//  IPositionComponent.h
//  TUCUT/Game (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-12-15.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_Game_IPositionComponent_h
#define TUCUT_Game_IPositionComponent_h

#include "../ECS/Component.h"

#include <string>

namespace TUCUT::Game
{
  class IPositionComponent : public ECS::Component
  {
  public:
    static constexpr int xyz = 1;
    static constexpr int x = 2;
    static constexpr int y = 3;
    static constexpr int z = 4;
    static constexpr int xyzOld = 5;
    static constexpr int xOld = 6;
    static constexpr int yOld = 7;
    static constexpr int zOld = 8;
    static std::string const groupName;
    static std::string const xyzName;
    static std::string const xName;
    static std::string const yName;
    static std::string const zName;
    static std::string const xyzOldName;
    static std::string const xOldName;
    static std::string const yOldName;
    static std::string const zOldName;
    static std::string const positionChangedToken;

  protected:
    IPositionComponent (std::string const & token, int identity)
    : Component(token, identity)
    { }
  };
} // namespace TUCUT::Game

#endif // TUCUT_Game_IPositionComponent_h
