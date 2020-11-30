//
//  Adjust.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 12/14/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Math_Adjust_h
#define TUCUT_Math_Adjust_h

namespace TUCUT {
namespace Math {

template <typename T>
T clamp (T min, T max, T value)
{
    if (value <= min)
    {
        return min;
    }
    if (value >= max)
    {
        return max;
    }
    
    return value;
}

template <typename T>
T toZero (T delta, T value)
{
    if (value > 0)
    {
        value -= delta;
        if (value < 0)
        {
            value = 0;
        }
    }
    else if (value < 0)
    {
        value += delta;
        if (value > 0)
        {
            value = 0;
        }
    }
    
    return value;
}

template <typename T>
T makePositive (T value)
{
    if (value < 0)
    {
        return -value;
    }
    
    return value;
}

template <typename T>
T makeNegative (T value)
{
    if (value > 0)
    {
        return -value;
    }
    
    return value;
}
    
template <typename T, typename U>
T rowMajorIndex (T x, T y, U columns)
{
    return x + y * columns;
}

template <typename T, typename U>
T columnMajorIndex (T x, T y, U rows)
{
    return y + x * rows;
}

} // namespace Math
} // namespace TUCUT

#endif // TUCUT_Math_Adjust_h
