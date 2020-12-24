//
//  Compare.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/26/20.
//  Copyright © 2020 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Math_Compare_h
#define TUCUT_Math_Compare_h

#include <cfloat>
#include <cmath>

namespace TUCUT {
namespace Math {
        
template <typename T>
bool compareEq (T a, T b)
{
    return a == b;
}
        
inline bool compareEq (float a, float b, float margin = FLT_EPSILON, float smallFactor = 0.00001f)
{
    if (a == b)
    {
        // This will let +0.0 equal -0.0
        // and will let us compare similar infinities and exact matches.
        return true;
    }

    if (std::isnan(a) || std::isnan(b))
    {
        // A NaN is not equal to anything, even itself.
        return false;
    }

    if (std::signbit(a) != std::signbit(b))
    {
        // Check for infinities to avoid an overflow in the diff.
        if (std::isinf(a) || std::isinf(b))
        {
            return false;
        }

        // If a and b are close to each other, treat them
        // as not equal if they have different signs
        // unless one of the values is zero. We'll always let
        // a small value be compared with + or - zero.
        if (a != 0.0f && b != 0.0f)
        {
            return false;
        }
    }

    // Use a smaller fixed margin when the diff is near zero.
    auto diff = std::abs(a - b);
    if (diff <= FLT_MIN)
    {
        return diff <= FLT_MIN * smallFactor;
    }

    // Use a margin that grows as a and b increase.
    a = std::abs(a);
    b = std::abs(b);
    auto smallest = (a < b) ? a : b;
    smallest = (smallest < 1.0f) ? 1.0f : smallest;
    return diff <= smallest * margin;
}
        
inline bool compareEq (double a, double b, double margin = DBL_EPSILON * 2, double smallFactor = 0.000000000001)
{
    if (a == b)
    {
        // This will let +0.0 equal -0.0
        // and will let us compare similar infinities and exact matches.
        return true;
    }

    if (std::isnan(a) || std::isnan(b))
    {
        // A NaN is not equal to anything, even itself.
        return false;
    }

    if (std::signbit(a) != std::signbit(b))
    {
        // Check for infinities to avoid an overflow in the diff.
        if (std::isinf(a) || std::isinf(b))
        {
            return false;
        }

        // If a and b are close to each other, treat them
        // as not equal if they have different signs
        // unless one of the values is zero. We'll always let
        // a small value be compared with + or - zero.
        if (a != 0.0 && b != 0.0)
        {
            return false;
        }
    }

    // Use a smaller fixed margin when the diff is near zero.
    auto diff = std::abs(a - b);
    if (diff <= DBL_MIN)
    {
        return diff <= DBL_MIN * smallFactor;
    }

    // Use a margin that grows as a and b increase.
    a = std::abs(a);
    b = std::abs(b);
    auto smallest = (a < b) ? a : b;
    smallest = (smallest < 1.0) ? 1.0 : smallest;
    return diff <= smallest * margin;
}

// This seems to work best with a double margin instead of a long double.
inline bool compareEq (long double a, long double b, double margin = DBL_EPSILON * 2, double smallFactor = 0.000000000001)
{
    if (a == b)
    {
        // This will let +0.0 equal -0.0
        // and will let us compare similar infinities and exact matches.
        return true;
    }

    if (std::isnan(a) || std::isnan(b))
    {
        // A NaN is not equal to anything, even itself.
        return false;
    }

    if (std::signbit(a) != std::signbit(b))
    {
        // Check for infinities to avoid an overflow in the diff.
        if (std::isinf(a) || std::isinf(b))
        {
            return false;
        }

        // If a and b are close to each other, treat them
        // as not equal if they have different signs
        // unless one of the values is zero. We'll always let
        // a small value be compared with + or - zero.
        if (a != 0.0L && b != 0.0L)
        {
            return false;
        }
    }

    // Use a smaller fixed margin when the diff is near zero.
    auto diff = std::abs(a - b);
    if (diff <= LDBL_MIN)
    {
        return diff <= LDBL_MIN * smallFactor;
    }

    // Use a margin that grows as a and b increase.
    a = std::abs(a);
    b = std::abs(b);
    auto smallest = (a < b) ? a : b;
    smallest = (smallest < 1.0L) ? 1.0L : smallest;
    return diff <= smallest * margin;
}

} // namespace Math
} // namespace TUCUT

#endif // TUCUT_Math_Compare_h
