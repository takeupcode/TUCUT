//
//  Easing.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/21/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Math_Easing_h
#define TUCUT_Math_Easing_h

#include "Bezier.h"

namespace TUCUT {
namespace Math {

template <typename T>
T easeLinear (T t)
{
    return t;
}

template <typename T>
T easeInFast (T t)
{
    constexpr Point2<T> b0(0.0, 0.0);
    constexpr Point2<T> b1(0.4, 0.0);
    constexpr Point2<T> b2(1.0, 1.0);
    std::vector<Point2<T>> points = {b0, b1, b2};

    return Bezier2<T>::calculate(points, t).y;
};

template <typename T>
T easeOutFast (T t)
{
    constexpr Point2<T> b0(0.0, 0.0);
    constexpr Point2<T> b1(0.6, 1.0);
    constexpr Point2<T> b2(1.0, 1.0);
    std::vector<Point2<T>> points = {b0, b1, b2};
    
    return Bezier2<T>::calculate(points, t).y;
};

template <typename T>
T easeInOutFast (T t)
{
    constexpr Point2<T> b0(0.0, 0.0);
    constexpr Point2<T> b1(0.4, 0.0);
    constexpr Point2<T> b2(0.6, 1.0);
    constexpr Point2<T> b3(1.0, 1.0);
    std::vector<Point2<T>> points = {b0, b1, b2, b3};
    
    return Bezier2<T>::calculate(points, t).y;
};

template <typename T>
T easeInMedium (T t)
{
    constexpr Point2<T> b0(0.0, 0.0);
    constexpr Point2<T> b1(0.6, 0.0);
    constexpr Point2<T> b2(1.0, 1.0);
    std::vector<Point2<T>> points = {b0, b1, b2};
    
    return Bezier2<T>::calculate(points, t).y;
};

template <typename T>
T easeOutMedium (T t)
{
    constexpr Point2<T> b0(0.0, 0.0);
    constexpr Point2<T> b1(0.4, 1.0);
    constexpr Point2<T> b2(1.0, 1.0);
    std::vector<Point2<T>> points = {b0, b1, b2};
    
    return Bezier2<T>::calculate(points, t).y;
};

template <typename T>
T easeInOutMedium (T t)
{
    constexpr Point2<T> b0(0.0, 0.0);
    constexpr Point2<T> b1(0.6, 0.0);
    constexpr Point2<T> b2(0.4, 1.0);
    constexpr Point2<T> b3(1.0, 1.0);
    std::vector<Point2<T>> points = {b0, b1, b2, b3};
    
    return Bezier2<T>::calculate(points, t).y;
};

template <typename T>
T easeInSlow (T t)
{
    constexpr Point2<T> b0(0.0, 0.0);
    constexpr Point2<T> b1(0.8, 0.0);
    constexpr Point2<T> b2(1.0, 1.0);
    std::vector<Point2<T>> points = {b0, b1, b2};
    
    return Bezier2<T>::calculate(points, t).y;
};

template <typename T>
T easeOutSlow (T t)
{
    constexpr Point2<T> b0(0.0, 0.0);
    constexpr Point2<T> b1(0.2, 1.0);
    constexpr Point2<T> b2(1.0, 1.0);
    std::vector<Point2<T>> points = {b0, b1, b2};
    
    return Bezier2<T>::calculate(points, t).y;
};

template <typename T>
T easeInOutSlow (T t)
{
    constexpr Point2<T> b0(0.0, 0.0);
    constexpr Point2<T> b1(0.8, 0.0);
    constexpr Point2<T> b2(0.2, 1.0);
    constexpr Point2<T> b3(1.0, 1.0);
    std::vector<Point2<T>> points = {b0, b1, b2, b3};
    
    return Bezier2<T>::calculate(points, t).y;
};

template <typename T>
T easeInBack (T t)
{
    constexpr Point2<T> b0(0.0, 0.0);
    constexpr Point2<T> b1(0.5, 0.0);
    constexpr Point2<T> b2(0.7, -0.4);
    constexpr Point2<T> b3(1.0, 1.0);
    std::vector<Point2<T>> points = {b0, b1, b2, b3};
    
    return Bezier2<T>::calculate(points, t).y;
};

template <typename T>
T easeOutBack (T t)
{
    constexpr Point2<T> b0(0.0, 0.0);
    constexpr Point2<T> b1(0.3, 1.4);
    constexpr Point2<T> b2(0.5, 1.0);
    constexpr Point2<T> b3(1.0, 1.0);
    std::vector<Point2<T>> points = {b0, b1, b2, b3};
    
    return Bezier2<T>::calculate(points, t).y;
};

// Classic improved Perlin continuous interpolant.
template <typename T>
T easeInOutPerlin (T t)
{
    // f(t) = 6t^5 – 15t^4 + 10t^3
    return t * t * t * (t * (t * 6 - 15) + 10);
}

// Classic improved Perlin derivative.
template <typename T>
T easeInOutPerlinDerivative (T t)
{
    // f'(t) = 30t^4 – 60t^3 + 30t^2
    return 30 * t * t * (t * (t - 2) + 1);
}

} // namespace Math
} // namespace TUCUT

#endif // TUCUT_Math_Easing_h
