//  ApplicationTime.h
//  TUCUT/ECS (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-12-04.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_ECS_ApplicationTime_h
#define TUCUT_ECS_ApplicationTime_h

#include <chrono>

namespace TUCUT::ECS
{
  using TimeClock = std::chrono::steady_clock;
  using TimePoint = TimeClock::time_point;
  using TimeResolution =
    std::chrono::duration<double, std::micro>;
  using TimeInSeconds = std::chrono::duration<double>;
} // namespace TUCUT::ECS

#endif // TUCUT_ECS_ApplicationTime_h
