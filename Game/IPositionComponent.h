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
    static constexpr int x = 1;
    static constexpr int y = 2;
    static constexpr int z = 3;
    static constexpr int xOld = 4;
    static constexpr int yOld = 5;
    static constexpr int zOld = 6;
    static const std::string groupName;
    static const std::string xName;
    static const std::string yName;
    static const std::string zName;
    static const std::string xOldName;
    static const std::string yOldName;
    static const std::string zOldName;
    
protected:
    IPositionComponent (const std::string & token, int identity)
    : GameComponent(token, identity)
    { }
};

} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_IPositionComponent_h
