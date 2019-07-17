//
//  IPositionComponent.hpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 12/15/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_IPositionComponent_h
#define TUCUT_Game_IPositionComponent_h

#include <string>

#include "GameComponent.h"

namespace TUCUT {
namespace Game {

class IPositionComponent : public Game::GameComponent
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
    static const std::string groupName;
    static const std::string xyzName;
    static const std::string xName;
    static const std::string yName;
    static const std::string zName;
    static const std::string xyzOldName;
    static const std::string xOldName;
    static const std::string yOldName;
    static const std::string zOldName;
    static const std::string positionChangedToken;

protected:
    IPositionComponent (const std::string & token, int identity)
    : GameComponent(token, identity)
    { }
};

} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_IPositionComponent_h
