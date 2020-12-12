//
//  Bezier.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/18/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Math_Bezier_h
#define TUCUT_Math_Bezier_h

#include "Point.h"

namespace TUCUT {
namespace Math {

// Linear - Two points, p0, p1 (This is the same as a lerp)
// B(t) = (1 - t) * p0 +
//        t * p1
//
// Quadratic - Three points, p0, p1, p2
// B(t) = (1 - t)^2 * p0 +
//        2 * t * (1 - t) * p1 +
//        t^2 * p2
//
// Cubic - Four points, p0, p1, p2, p3
// B(t) = (1 - t)^3 * p0 +
//        3 * t * (1 - t)^2 * p1 +
//        3 * t^2 * (1 - t) * p2 +
//        t^3 * p3
//
// Higher orders are possible with more points. Note that
// each point can itself be 2D, 3D, or 4D.
template <typename T, typename P, typename V>
P calculateImpl (std::vector<P> const & points, T t)
{
    if (points.size() == 2)
    {
        // Linear
        return points[0] + t * (points[1] - points[0]);
    }
    else if (points.size() == 3)
    {
        // Quadratic
        V v0 = points[0];
        V v1 = points[1];
        V v2 = points[2];
        V result;
        
        result = (1 - t) * (1 - t) * v0 +
        2 * t * (1 - t) * v1 +
        t * t * v2;
        
        return P() + result;
    }
    else if (points.size() == 4)
    {
        // Cubic
        V v0 = points[0];
        V v1 = points[1];
        V v2 = points[2];
        V v3 = points[3];
        V result;
        
        result = (1 - t) * (1 - t) * (1 - t) * v0 +
        3 * t * (1 - t) * (1 - t) * v1 +
        3 * t * t * (1 - t) * v2 +
        t * t * t * v3;
        
        return P() + result;
    }
    else
    {
        std::vector<P> temp(points);
        
        std::size_t dimensionIndex = temp.size() - 1;
        while (dimensionIndex != 0)
        {
            for (std::size_t currentIndex = 0; currentIndex < dimensionIndex; ++currentIndex)
            {
                temp[currentIndex] = temp[currentIndex] + t * (temp[currentIndex + 1] - temp[currentIndex]);
            }
            --dimensionIndex;
        }
        
        return temp[0];
    }
}

template <typename T>
struct Bezier2
{
    static constexpr std::size_t dimensions = 2;
    using type = T;
    
    static Point2<T> calculate (std::vector<Point2<T>> const & points, T t)
    {
        return calculateImpl<T, Point2<T>, Vector2<T>>(points, t);
    }
};

template <typename T>
struct Bezier3
{
    static constexpr std::size_t dimensions = 3;
    using type = T;
    
    static Point3<T> calculate (std::vector<Point3<T>> const & points, T t)
    {
        return calculateImpl<T, Point3<T>, Vector3<T>>(points, t);
    }
};

template <typename T>
struct Bezier4
{
    static constexpr std::size_t dimensions = 4;
    using type = T;
    
    static Point4<T> calculate (std::vector<Point4<T>> const & points, T t)
    {
        return calculateImpl<T, Point4<T>, Vector4<T>>(points, t);
    }
};

using Bezier2f = Bezier2<float>;
using Bezier3f = Bezier3<float>;
using Bezier4f = Bezier4<float>;

using Bezier2d = Bezier2<double>;
using Bezier3d = Bezier3<double>;
using Bezier4d = Bezier4<double>;

using Bezier2l = Bezier2<long double>;
using Bezier3l = Bezier3<long double>;
using Bezier4l = Bezier4<long double>;

} // namespace Math
} // namespace TUCUT

#endif // TUCUT_Math_Bezier_h
