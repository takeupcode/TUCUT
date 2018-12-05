//
//  GameTime.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 12/4/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Game_GameTime_h
#define TUCUT_Game_GameTime_h

#include <chrono>

namespace TUCUT {
namespace Game {
    
using TimeClock = std::chrono::steady_clock;
using TimePoint = TimeClock::time_point;
using TimeResolution = std::chrono::duration<double, std::micro>;

} // namespace Game
} // namespace TUCUT

#endif // TUCUT_Game_GameTime_h
