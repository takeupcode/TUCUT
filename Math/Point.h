//
//  Point.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/14/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Math_Point_h
#define TUCUT_Math_Point_h

#include <string>

#include "Vector.h"

#include "../Exception/InvalidArgumentException.h"

namespace TUCUT {
namespace Math {

template <typename T>
class Point1
{
public:
    static constexpr std::size_t dimensions = 1;
    using type = T;
    
    constexpr Point1 ()
    : x()
    { }
    
    explicit constexpr Point1 (T x)
    : x(x)
    { }
    
    T component (std::size_t axis) const
    {
        switch (axis)
        {
        case 0:
            return x;
        }
        
        throw Exception::InvalidArgumentException("axis", "axis must be 0");
    }

    bool operator == (const Point1 & rhs) const
    {
        return x == rhs.x;
    }

    bool operator != (const Point1 & rhs) const
    {
        return !operator==(rhs);
    }

    Vector1<T> operator - (const Point1 & rhs) const
    {
        return Vector1<T>(x - rhs.x);
    }
    
    Point1 operator + (const Vector1<T> & rhs) const
    {
        return Point1(x + rhs.x);
    }
    
    Point1 operator - (const Vector1<T> & rhs) const
    {
        return Point1(x - rhs.x);
    }
    
    operator Vector1<T> () const
    {
        return Vector1<T>(x);
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

template <typename T>
class Point2
{
public:
    static constexpr std::size_t dimensions = 2;
    using type = T;

    constexpr Point2 ()
    : x(), y()
    { }
    
    constexpr Point2 (T x, T y)
    : x(x), y(y)
    { }
    
    T component (std::size_t axis) const
    {
        switch (axis)
        {
        case 0:
            return x;
            
        case 1:
            return y;
        }
        
        throw Exception::InvalidArgumentException("axis", "axis must be between 0 and 1");
    }

    bool operator == (const Point2 & rhs) const
    {
        return x == rhs.x &&
            y == rhs.y;
    }
    
    bool operator != (const Point2 & rhs) const
    {
        return !operator==(rhs);
    }

    Vector2<T> operator - (const Point2 & rhs) const
    {
        return Vector2<T>(x - rhs.x, y - rhs.y);
    }
    
    Point2 operator + (const Vector2<T> & rhs) const
    {
        return Point2(x + rhs.x, y + rhs.y);
    }
    
    Point2 operator - (const Vector2<T> & rhs) const
    {
        return Point2(x - rhs.x, y - rhs.y);
    }
    
    operator Vector2<T> () const
    {
        return Vector2<T>(x, y);
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

template <typename T>
class Point3
{
public:
    static constexpr std::size_t dimensions = 3;
    using type = T;

    constexpr Point3 ()
    : x(), y(), z()
    { }
    
    constexpr Point3 (T x, T y, T z)
    : x(x), y(y), z(z)
    { }
    
    T component (std::size_t axis) const
    {
        switch (axis)
        {
        case 0:
            return x;
            
        case 1:
            return y;
            
        case 2:
            return z;
        }
        
        throw Exception::InvalidArgumentException("axis", "axis must be between 0 and 2");
    }

    bool operator == (const Point3 & rhs) const
    {
        return x == rhs.x &&
            y == rhs.y &&
            z == rhs.z;
    }
    
    bool operator != (const Point3 & rhs) const
    {
        return !operator==(rhs);
    }

    Vector3<T> operator - (const Point3 & rhs) const
    {
        return Vector3<T>(x - rhs.x, y - rhs.y, z - rhs.z);
    }
    
    Point3 operator + (const Vector3<T> & rhs) const
    {
        return Point3(x + rhs.x, y + rhs.y, z + rhs.z);
    }
    
    Point3 operator - (const Vector3<T> & rhs) const
    {
        return Point3(x - rhs.x, y - rhs.y, z - rhs.z);
    }
    
    operator Vector3<T> () const
    {
        return Vector3<T>(x, y, z);
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

template <typename T>
class Point4
{
public:
    static constexpr std::size_t dimensions = 4;
    using type = T;

    constexpr Point4 ()
    : x(), y(), z(), w()
    { }
    
    constexpr Point4 (T x, T y, T z, T w)
    : x(x), y(y), z(z), w(w)
    { }
    
    T component (std::size_t axis) const
    {
        switch (axis)
        {
        case 0:
            return x;
            
        case 1:
            return y;
            
        case 2:
            return z;
            
        case 3:
            return w;
        }
        
        throw Exception::InvalidArgumentException("axis", "axis must be between 0 and 3");
    }

    bool operator == (const Point4 & rhs) const
    {
        return x == rhs.x &&
            y == rhs.y &&
            z == rhs.z &&
            w == rhs.w;
    }
    
    bool operator != (const Point4 & rhs) const
    {
        return !operator==(rhs);
    }

    Vector4<T> operator - (const Point4 & rhs) const
    {
        return Vector4<T>(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
    }
    
    Point4 operator + (const Vector4<T> & rhs) const
    {
        return Point4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
    }
    
    Point4 operator - (const Vector4<T> & rhs) const
    {
        return Point4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
    }
    
    operator Vector4<T> () const
    {
        return Vector4<T>(x, y, z, w);
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

using Point1f = Point1<float>;
using Point2f = Point2<float>;
using Point3f = Point3<float>;
using Point4f = Point4<float>;

using Point1d = Point1<double>;
using Point2d = Point2<double>;
using Point3d = Point3<double>;
using Point4d = Point4<double>;

} // namespace Math
} // namespace TUCUT

#endif // TUCUT_Math_Point_h
