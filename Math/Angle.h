//
//  Angle.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 12/13/20.
//  Copyright © 2020 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Math_Angle_h
#define TUCUT_Math_Angle_h

#include "Constants.h"

namespace TUCUT {
namespace Math {

inline constexpr float toDegrees (float radians)
{
    return radians * 180.0f / PI_f;
}

inline constexpr double toDegrees (double radians)
{
    return radians * 180.0 / PI_d;
}

inline constexpr long double toDegrees (long double radians)
{
    return radians * 180.0L / PI_l;
}

inline constexpr float toRadians (float degrees)
{
    return degrees * PI_f / 180.0f;
}

inline constexpr double toRadians (double degrees)
{
    return degrees * PI_d / 180.0;
}

inline constexpr long double toRadians (long double degrees)
{
    return degrees * PI_l / 180.0L;
}

template <typename T>
class Degrees;

template <typename T>
class Radians
{
public:
    using type = T;

    constexpr Radians ()
    : angle()
    { }

    explicit constexpr Radians (T rad)
    : angle(rad)
    { }

    constexpr Radians (Radians const & src)
    : angle(src.angle)
    { }

    explicit constexpr Radians (Degrees<T> const & deg);

    T angle;
};

template <typename T>
class Degrees
{
public:
    using type = T;

    constexpr Degrees ()
    : angle()
    { }

    explicit constexpr Degrees (T deg)
    : angle(deg)
    { }

    constexpr Degrees (Degrees const & src)
    : angle(src.angle)
    { }

    explicit constexpr Degrees (Radians<T> const & rad)
    : angle(toDegrees(rad.angle))
    { }

    T angle;
};

template <typename T>
constexpr Radians<T>::Radians (Degrees<T> const & deg)
: angle(toRadians(deg.angle))
{ }

using Radiansf = Radians<float>;
using Radiansd = Radians<double>;
using Radiansl = Radians<long double>;

using Degreesf = Degrees<float>;
using Degreesd = Degrees<double>;
using Degreesl = Degrees<long double>;

} // namespace Math
} // namespace TUCUT

#endif // TUCUT_Math_Angle_h
