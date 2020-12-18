//
//  Constants.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 12/11/20.
//  Copyright © 2020 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Math_Constants_h
#define TUCUT_Math_Constants_h

namespace TUCUT {
namespace Math {
        
constexpr float       PI_f = 3.14159265358979323846f;
constexpr double      PI_d = 3.14159265358979323846;
constexpr long double PI_l = 3.14159265358979323846L;

inline constexpr float multiplyPI (float multiple = 1.0f)
{
    return PI_f * multiple;
}

inline constexpr double multiplyPI (double multiple = 1.0)
{
    return PI_d * multiple;
}

inline constexpr long double multiplyPI (long double multiple = 1.0L)
{
    return PI_l * multiple;
}

} // namespace Math
} // namespace TUCUT

#endif // TUCUT_Math_Constants_h
