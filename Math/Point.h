//
//  Point.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/14/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Math_Point_h
#define TUCUT_Math_Point_h

#include "Compare.h"
#include "../Exception/InvalidArgumentException.h"
#include "Vector.h"

#include <string>

namespace TUCUT {
namespace Math {

template <typename T, typename Angle = double>
class Point1
{
public:
    static constexpr std::size_t dimensions = 1;
    static constexpr std::size_t axisX = 0;
    using type = T;
    using angle = Angle;

    constexpr Point1 ()
    : x()
    { }

    explicit constexpr Point1 (T x)
    : x(x)
    { }

    constexpr Point1 (Point1 const & src)
    : x(src.x)
    { }

    T component (std::size_t axis) const
    {
        switch (axis)
        {
        case axisX:
            return x;
        }

        throw Exception::InvalidArgumentException("axis", "axis must be 0");
    }

    Point1 operator = (Point1 const & rhs)
    {
        if (this == &rhs)
        {
          return *this;
        }

        x = rhs.x;

        return *this;
    }

    bool operator == (Point1 const & rhs) const
    {
        return compareEq(x, rhs.x);
    }

    bool operator != (Point1 const & rhs) const
    {
        return !operator==(rhs);
    }

    Vector1<T, Angle> operator - (Point1 const & rhs) const
    {
        return Vector1<T, Angle>(x - rhs.x);
    }

    Point1 operator + (Vector1<T, Angle> const & rhs) const
    {
        return Point1(x + rhs.x);
    }

    Point1 operator - (Vector1<T, Angle> const & rhs) const
    {
        return Point1(x - rhs.x);
    }

    operator Vector1<T, Angle> () const
    {
        return Vector1<T, Angle>(x);
    }

    std::string to_string () const
    {
        return "(point: " + std::to_string(x) + ")";
    }

    operator std::string () const
    {
        return to_string();
    }

    T x;
};

template <typename T, typename Angle = double>
class Point2
{
public:
    static constexpr std::size_t dimensions = 2;
    static constexpr std::size_t axisX = 0;
    static constexpr std::size_t axisY = 1;
    using type = T;
    using angle = Angle;

    constexpr Point2 ()
    : x(), y()
    { }

    constexpr Point2 (T x, T y)
    : x(x), y(y)
    { }

    constexpr Point2 (Point2 const & src)
    : x(src.x), y(src.y)
    { }

    T component (std::size_t axis) const
    {
        switch (axis)
        {
        case axisX:
            return x;

        case axisY:
            return y;
        }

        throw Exception::InvalidArgumentException("axis", "axis must be between 0 and 1");
    }

    Point2 operator = (Point2 const & rhs)
    {
        if (this == &rhs)
        {
          return *this;
        }

        x = rhs.x;
        y = rhs.y;

        return *this;
    }

    bool operator == (Point2 const & rhs) const
    {
        return compareEq(x, rhs.x) &&
            compareEq(y, rhs.y);
    }

    bool operator != (Point2 const & rhs) const
    {
        return !operator==(rhs);
    }

    Vector2<T, Angle> operator - (Point2 const & rhs) const
    {
        return Vector2<T, Angle>(x - rhs.x, y - rhs.y);
    }

    Point2 operator + (Vector2<T, Angle> const & rhs) const
    {
        return Point2(x + rhs.x, y + rhs.y);
    }

    Point2 operator - (Vector2<T, Angle> const & rhs) const
    {
        return Point2(x - rhs.x, y - rhs.y);
    }

    operator Vector2<T, Angle> () const
    {
        return Vector2<T, Angle>(x, y);
    }

    std::string to_string () const
    {
        return "(point: " + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    operator std::string () const
    {
        return to_string();
    }

    T x;
    T y;
};

template <typename T, typename Angle = double>
class Point3
{
public:
    static constexpr std::size_t dimensions = 3;
    static constexpr std::size_t axisX = 0;
    static constexpr std::size_t axisY = 1;
    static constexpr std::size_t axisZ = 2;
    using type = T;
    using angle = Angle;

    constexpr Point3 ()
    : x(), y(), z()
    { }

    constexpr Point3 (T x, T y, T z)
    : x(x), y(y), z(z)
    { }

    constexpr Point3 (Point3 const & src)
    : x(src.x), y(src.y), z(src.z)
    { }

    T component (std::size_t axis) const
    {
        switch (axis)
        {
        case axisX:
            return x;

        case axisY:
            return y;

        case axisZ:
            return z;
        }

        throw Exception::InvalidArgumentException("axis", "axis must be between 0 and 2");
    }

    Point3 operator = (Point3 const & rhs)
    {
        if (this == &rhs)
        {
          return *this;
        }

        x = rhs.x;
        y = rhs.y;
        z = rhs.z;

        return *this;
    }

    bool operator == (Point3 const & rhs) const
    {
        return compareEq(x, rhs.x) &&
            compareEq(y, rhs.y) &&
            compareEq(z, rhs.z);
    }

    bool operator != (Point3 const & rhs) const
    {
        return !operator==(rhs);
    }

    Vector3<T, Angle> operator - (Point3 const & rhs) const
    {
        return Vector3<T, Angle>(x - rhs.x, y - rhs.y, z - rhs.z);
    }

    Point3 operator + (Vector3<T, Angle> const & rhs) const
    {
        return Point3(x + rhs.x, y + rhs.y, z + rhs.z);
    }

    Point3 operator - (Vector3<T, Angle> const & rhs) const
    {
        return Point3(x - rhs.x, y - rhs.y, z - rhs.z);
    }

    operator Vector3<T, Angle> () const
    {
        return Vector3<T, Angle>(x, y, z);
    }

    std::string to_string () const
    {
        return "(point: " + std::to_string(x) + ", " + std::to_string(y) +
             ", " + std::to_string(z) + ")";
    }

    operator std::string () const
    {
        return to_string();
    }

    T x;
    T y;
    T z;
};

template <typename T, typename Angle = double>
class Point4
{
public:
    static constexpr std::size_t dimensions = 4;
    static constexpr std::size_t axisX = 0;
    static constexpr std::size_t axisY = 1;
    static constexpr std::size_t axisZ = 2;
    static constexpr std::size_t axisW = 3;
    using type = T;
    using angle = Angle;

    constexpr Point4 ()
    : x(), y(), z(), w()
    { }

    constexpr Point4 (T x, T y, T z, T w)
    : x(x), y(y), z(z), w(w)
    { }

    constexpr Point4 (Point4 const & src)
    : x(src.x), y(src.y), z(src.z), w(src.w)
    { }

    T component (std::size_t axis) const
    {
        switch (axis)
        {
        case axisX:
            return x;

        case axisY:
            return y;

        case axisZ:
            return z;

        case axisW:
            return w;
        }

        throw Exception::InvalidArgumentException("axis", "axis must be between 0 and 3");
    }

    Point4 operator = (Point4 const & rhs)
    {
        if (this == &rhs)
        {
          return *this;
        }

        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        w = rhs.w;

        return *this;
    }

    bool operator == (Point4 const & rhs) const
    {
        return compareEq(x, rhs.x) &&
            compareEq(y, rhs.y) &&
            compareEq(z, rhs.z) &&
            compareEq(w, rhs.w);
    }

    bool operator != (Point4 const & rhs) const
    {
        return !operator==(rhs);
    }

    Vector4<T, Angle> operator - (Point4 const & rhs) const
    {
        return Vector4<T, Angle>(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
    }

    Point4 operator + (Vector4<T, Angle> const & rhs) const
    {
        return Point4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
    }

    Point4 operator - (Vector4<T, Angle> const & rhs) const
    {
        return Point4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
    }

    operator Vector4<T, Angle> () const
    {
        return Vector4<T, Angle>(x, y, z, w);
    }

    std::string to_string () const
    {
        return "(point: " + std::to_string(x) + ", " + std::to_string(y) +
            ", " + std::to_string(z) + ", " + std::to_string(w) + ")";
    }

    operator std::string () const
    {
        return to_string();
    }

    T x;
    T y;
    T z;
    T w;
};

using Point1i = Point1<int>;
using Point2i = Point2<int>;
using Point3i = Point3<int>;
using Point4i = Point4<int>;

using Point1f = Point1<float, float>;
using Point2f = Point2<float, float>;
using Point3f = Point3<float, float>;
using Point4f = Point4<float, float>;

using Point1d = Point1<double>;
using Point2d = Point2<double>;
using Point3d = Point3<double>;
using Point4d = Point4<double>;

using Point1l = Point1<long double>;
using Point2l = Point2<long double>;
using Point3l = Point3<long double>;
using Point4l = Point4<long double>;

} // namespace Math
} // namespace TUCUT

#endif // TUCUT_Math_Point_h
