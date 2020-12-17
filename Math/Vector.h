//
//  Vector.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/18/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Math_Vector_h
#define TUCUT_Math_Vector_h

#include "Adjust.h"
#include "Angle.h"
#include "Compare.h"
#include "../Exception/InvalidArgumentException.h"
#include "../Exception/InvalidOperationException.h"

#include <cmath>
#include <string>

namespace TUCUT {
namespace Math {

template <typename T>
class Vector1
{
public:
    static constexpr std::size_t dimensions = 1;
    static constexpr std::size_t axisX = 0;
    using type = T;
    
    constexpr Vector1 ()
    : x()
    { }

    explicit constexpr Vector1 (T x)
    : x(x)
    { }

    constexpr Vector1 (Vector1 const & src)
    : x(src.x)
    { }

    static constexpr Vector1 one ()
    {
        return Vector1(1);
    }

    static constexpr Vector1 right ()
    {
        return Vector1(1);
    }
    
    static constexpr Vector1 left ()
    {
        return Vector1(-1);
    }

    T component (std::size_t axis) const
    {
        switch (axis)
        {
        case 0:
            return x;
        }
        
        throw Exception::InvalidArgumentException("axis", "axis must be 0");
    }

    T lengthSquared () const
    {
        return x * x;
    }

    T lengthManhattan () const
    {
        return x >= 0 ? x : -x;
    }

    template<typename U = T>
    Vector1<U> normal () const
    {
        if (x == 0)
        {
            throw Exception::InvalidOperationException("normal", "normal cannot be calculated for zero length vector.");
        }
        
        return Vector1<U>(x > 0 ? 1 : -1);
    }

    Vector1 operator - () const
    {
        return Vector1(-x);
    }

    bool operator == (Vector1 const & rhs) const
    {
        return compareEq(x, rhs.x);
    }
    
    bool operator != (Vector1 const & rhs) const
    {
        return !operator==(rhs);
    }

    Vector1 operator + (Vector1 const & rhs) const
    {
        return Vector1(x + rhs.x);
    }
    
    Vector1 operator - (Vector1 const & rhs) const
    {
        return Vector1(x - rhs.x);
    }
    
    Vector1 operator * (T rhs) const
    {
        return Vector1(x * rhs);
    }
    
    Vector1 operator / (T rhs) const
    {
        return Vector1(x / rhs);
    }
    
    T dot (Vector1 const & rhs) const
    {
        return x * rhs.x;
    }
    
    std::string to_string () const
    {
        return "(vector: " + std::to_string(x) + ")";
    }
    
    operator std::string () const
    {
        return to_string();
    }

    T x;
};

template <typename T>
Vector1<T> operator * (T lhs, Vector1<T> const & rhs)
{
    return Vector1<T>(lhs * rhs.x);
}

template <typename T>
class Vector2
{
public:
    static constexpr std::size_t dimensions = 2;
    static constexpr std::size_t axisX = 0;
    static constexpr std::size_t axisY = 1;
    using type = T;
    
    constexpr Vector2 ()
    : x(), y()
    { }
    
    constexpr Vector2 (T x, T y)
    : x(x), y(y)
    { }

    constexpr Vector2 (Vector2 const & src)
    : x(src.x), y(src.y)
    { }

    static constexpr Vector2 one ()
    {
        return Vector2(1, 1);
    }
    
    static constexpr Vector2 right ()
    {
        return Vector2(1, 0);
    }
    
    static constexpr Vector2 left ()
    {
        return Vector2(-1, 0);
    }

    static constexpr Vector2 forward ()
    {
        return Vector2(0, 1);
    }
    
    static constexpr Vector2 backward ()
    {
        return Vector2(0, -1);
    }

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
    
    T lengthSquared () const
    {
        return x * x + y * y;
    }
    
    T lengthManhattan () const
    {
        T absoluteX = x >= 0 ? x : -x;
        T absoluteY = y >= 0 ? y : -y;
        
        return absoluteX + absoluteY;
    }

    template<typename U = T>
    Vector2<U> normal () const
    {
        if (x == 0 && y == 0)
        {
            throw Exception::InvalidOperationException("normal", "normal cannot be calculated for zero length vector.");
        }
        
        U length = std::sqrt(static_cast<U>(lengthSquared()));
        
        return Vector2<U>(static_cast<U>(x) / length, static_cast<U>(y) / length);
    }

    Vector2 rotate (Degrees<T> const & deg) const
    {
        return rotate(Radians<T>(deg));
    }

    Vector2 rotate (Radians<T> const & rad) const
    {
        auto sine = sin(rad.angle);
        auto cosine = cos(rad.angle);

        return Vector2(
            x * cosine - y * sine,
            x * sine + y * cosine
            );
    }

    Vector2 rotateQuarter () const
    {
        return Vector2(-y, x);
    }

    Vector2 operator - () const
    {
        return Vector2(-x, -y);
    }

    bool operator == (Vector2 const & rhs) const
    {
        return compareEq(x, rhs.x) &&
            compareEq(y, rhs.y);
    }
    
    bool operator != (Vector2 const & rhs) const
    {
        return !operator==(rhs);
    }

    Vector2 operator + (Vector2 const & rhs) const
    {
        return Vector2(x + rhs.x, y + rhs.y);
    }
    
    Vector2 operator - (Vector2 const & rhs) const
    {
        return Vector2(x - rhs.x, y - rhs.y);
    }
    
    Vector2 operator * (T rhs) const
    {
        return Vector2(x * rhs, y * rhs);
    }
    
    Vector2 operator / (T rhs) const
    {
        return Vector2(x / rhs, y / rhs);
    }
    
    T dot (Vector2 const & rhs) const
    {
        return x * rhs.x + y * rhs.y;
    }

    Radians<T> angleInRadians (Vector2 const & rhs) const
    {
        auto norm = normal();
        auto product = norm.dot(rhs.normal());
        return Radians<T>(acos(product));
    }

    Degrees<T> angleInDegrees (Vector2 const & rhs) const
    {
        return Degrees<T>(angleInRadians(rhs));
    }

    bool isParallel (Vector2 const & rhs) const
    {
        return compareEq(T(0), dot(rhs.rotateQuarter()));
    }

    std::string to_string () const
    {
        return "(vector: " + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
    
    operator std::string () const
    {
        return to_string();
    }

    T x;
    T y;
};

template <typename T>
Vector2<T> operator * (T lhs, Vector2<T> const & rhs)
{
    return Vector2<T>(lhs * rhs.x, lhs * rhs.y);
}

template <typename T>
class Vector3
{
public:
    static constexpr std::size_t dimensions = 3;
    static constexpr std::size_t axisX = 0;
    static constexpr std::size_t axisY = 1;
    static constexpr std::size_t axisZ = 2;
    using type = T;
    
    constexpr Vector3 ()
    : x(), y(), z()
    { }
    
    constexpr Vector3 (T x, T y, T z)
    : x(x), y(y), z(z)
    { }

    constexpr Vector3 (Vector3 const & src)
    : x(src.x), y(src.y), z(src.z)
    { }

    static constexpr Vector3 one ()
    {
        return Vector3(1, 1, 1);
    }
    
    static constexpr Vector3 right ()
    {
        return Vector3(1, 0, 0);
    }
    
    static constexpr Vector3 left ()
    {
        return Vector3(-1, 0, 0);
    }
    
    static constexpr Vector3 forward ()
    {
        return Vector3(0, 1, 0);
    }
    
    static constexpr Vector3 backward ()
    {
        return Vector3(0, -1, 0);
    }

    static constexpr Vector3 up ()
    {
        return Vector3(0, 0, 1);
    }
    
    static constexpr Vector3 down ()
    {
        return Vector3(0, 0, -1);
    }

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
    
    T lengthSquared () const
    {
        return x * x + y * y + z * z;
    }
    
    T lengthManhattan () const
    {
        T absoluteX = x >= 0 ? x : -x;
        T absoluteY = y >= 0 ? y : -y;
        T absoluteZ = z >= 0 ? z : -z;

        return absoluteX + absoluteY + absoluteZ;
    }

    template<typename U = T>
    Vector3<U> normal () const
    {
        if (x == 0 && y == 0 && z == 0)
        {
            throw Exception::InvalidOperationException("normal", "normal cannot be calculated for zero length vector.");
        }
        
        U length = std::sqrt(static_cast<U>(lengthSquared()));

        return Vector3<U>(static_cast<U>(x) / length, static_cast<U>(y) / length,
            static_cast<U>(z) / length);
    }

    Vector3 rotate (std::size_t axis, Degrees<T> const & deg) const
    {
        return rotate(axis, Radians<T>(deg));
    }

    Vector3 rotate (std::size_t axis, Radians<T> const & rad) const
    {
        auto sine = sin(rad.angle);
        auto cosine = cos(rad.angle);

        switch (axis)
        {
        case axisX:
            return Vector3(
                x,
                y * cosine - z * sine,
                y * sine + z * cosine
                );

        case axisY:
            return Vector3(
                x * cosine - z * sine,
                y,
                x * sine + z * cosine
                );

        case axisZ:
            return Vector3(
                x * cosine - y * sine,
                x * sine + y * cosine,
                z
                );
        }

        throw Exception::InvalidArgumentException("axis", "axis must be between 0 and 2");
    }

    Vector3 rotateQuarter (std::size_t axis) const
    {
        switch (axis)
        {
        case axisX:
            return Vector3(x, -z, y);

        case axisY:
            return Vector3(-z, y, x);

        case axisZ:
            return Vector3(-y, x, z);
        }

        throw Exception::InvalidArgumentException("axis", "axis must be between 0 and 2");
    }

    Vector3 operator - () const
    {
        return Vector3(-x, -y, -z);
    }

    bool operator == (Vector3 const & rhs) const
    {
        return compareEq(x, rhs.x) &&
            compareEq(y, rhs.y) &&
            compareEq(z, rhs.z);
    }
    
    bool operator != (Vector3 const & rhs) const
    {
        return !operator==(rhs);
    }

    Vector3 operator + (Vector3 const & rhs) const
    {
        return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
    }
    
    Vector3 operator - (Vector3 const & rhs) const
    {
        return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
    }
    
    Vector3 operator * (T rhs) const
    {
        return Vector3(x * rhs, y * rhs, z * rhs);
    }
    
    Vector3 operator / (T rhs) const
    {
        return Vector3(x / rhs, y / rhs, z / rhs);
    }
    
    T dot (Vector3 const & rhs) const
    {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }
    
    Vector3 cross (Vector3 const & rhs) const
    {
        return Vector3(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
    }

    Radians<T> angleInRadians (Vector3 const & rhs) const
    {
        auto norm = normal();
        auto product = norm.dot(rhs.normal());
        return Radians<T>(acos(product));
    }

    Degrees<T> angleInDegrees (Vector3 const & rhs) const
    {
        return Degrees<T>(angleInRadians(rhs));
    }

    bool isParallel (Vector3 const & rhs) const
    {
        return compareEq(T(0), dot(rhs.rotateQuarter()));
    }

    std::string to_string () const
    {
        return "(vector: " + std::to_string(x) + ", " + std::to_string(y) +
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
Vector3<T> operator * (T lhs, Vector3<T> const & rhs)
{
    return Vector3<T>(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
}

template <typename T>
class Vector4
{
public:
    static constexpr std::size_t dimensions = 4;
    static constexpr std::size_t axisX = 0;
    static constexpr std::size_t axisY = 1;
    static constexpr std::size_t axisZ = 2;
    static constexpr std::size_t axisW = 3;
    using type = T;
    
    constexpr Vector4 ()
    : x(), y(), z(), w()
    { }
    
    constexpr Vector4 (T x, T y, T z, T w)
    : x(x), y(y), z(z), w(w)
    { }

    constexpr Vector4 (Vector4 const & src)
    : x(src.x), y(src.y), z(src.z), w(src.w)
    { }

    static constexpr Vector4 one ()
    {
        return Vector4(1, 1, 1, 1);
    }
    
    static constexpr Vector4 right ()
    {
        return Vector4(1, 0, 0, 0);
    }
    
    static constexpr Vector4 left ()
    {
        return Vector4(-1, 0, 0, 0);
    }
    
    static constexpr Vector4 forward ()
    {
        return Vector4(0, 1, 0, 0);
    }
    
    static constexpr Vector4 backward ()
    {
        return Vector4(0, -1, 0, 0);
    }
    
    static constexpr Vector4 up ()
    {
        return Vector4(0, 0, 1, 0);
    }
    
    static constexpr Vector4 down ()
    {
        return Vector4(0, 0, -1, 0);
    }
    
    static constexpr Vector4 ana ()
    {
        return Vector4(0, 0, 0, 1);
    }
    
    static constexpr Vector4 kata ()
    {
        return Vector4(0, 0, 0, -1);
    }

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
    
    T lengthSquared () const
    {
        return x * x + y * y + z * z + w * w;
    }
    
    T lengthManhattan () const
    {
        T absoluteX = x >= 0 ? x : -x;
        T absoluteY = y >= 0 ? y : -y;
        T absoluteZ = z >= 0 ? z : -z;
        T absoluteW = w >= 0 ? w : -w;

        return absoluteX + absoluteY + absoluteZ + absoluteW;
    }

    template<typename U = T>
    Vector4<U> normal () const
    {
        if (x == 0 && y == 0 && z == 0 && w == 0)
        {
            throw Exception::InvalidOperationException("normal", "normal cannot be calculated for zero length vector.");
        }
        
        U length = std::sqrt(static_cast<U>(lengthSquared()));

        return Vector4<U>(static_cast<U>(x) / length, static_cast<U>(y) / length,
            static_cast<U>(z) / length, static_cast<U>(w) / length);
    }

    Vector4 operator - () const
    {
        return Vector4(-x, -y, -z, -w);
    }

    bool operator == (Vector4 const & rhs) const
    {
        return compareEq(x, rhs.x) &&
        compareEq(y, rhs.y) &&
        compareEq(z, rhs.z) &&
        compareEq(w, rhs.w);
    }
    
    bool operator != (Vector4 const & rhs) const
    {
        return !operator==(rhs);
    }

    Vector4 operator + (Vector4 const & rhs) const
    {
        return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
    }
    
    Vector4 operator - (Vector4 const & rhs) const
    {
        return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
    }
    
    Vector4 operator * (T rhs) const
    {
        return Vector4(x * rhs, y * rhs, z * rhs, w * rhs);
    }
    
    Vector4 operator / (T rhs) const
    {
        return Vector4(x / rhs, y / rhs, z / rhs, w / rhs);
    }
    
    T dot (Vector4 const & rhs) const
    {
        return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
    }
    
    std::string to_string () const
    {
        return "(vector: " + std::to_string(x) + ", " + std::to_string(y) +
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

template <typename T>
Vector4<T> operator * (T lhs, Vector4<T> const & rhs)
{
    return Vector4<T>(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w);
}

using Vector1i = Vector1<int>;
using Vector2i = Vector2<int>;
using Vector3i = Vector3<int>;
using Vector4i = Vector4<int>;

using Vector1f = Vector1<float>;
using Vector2f = Vector2<float>;
using Vector3f = Vector3<float>;
using Vector4f = Vector4<float>;

using Vector1d = Vector1<double>;
using Vector2d = Vector2<double>;
using Vector3d = Vector3<double>;
using Vector4d = Vector4<double>;

using Vector1l = Vector1<long double>;
using Vector2l = Vector2<long double>;
using Vector3l = Vector3<long double>;
using Vector4l = Vector4<long double>;

} // namespace Math
} // namespace TUCUT

#endif // TUCUT_Math_Vector_h
