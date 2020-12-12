//
//  Vector.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/18/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Math_Vector_h
#define TUCUT_Math_Vector_h

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
    using type = T;
    
    constexpr Vector1 ()
    : x()
    { }

    explicit constexpr Vector1 (T x)
    : x(x)
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

    bool operator == (const Vector1 & rhs) const
    {
        return compareEq(x, rhs.x);
    }
    
    bool operator != (const Vector1 & rhs) const
    {
        return !operator==(rhs);
    }

    Vector1 operator + (const Vector1 & rhs) const
    {
        return Vector1(x + rhs.x);
    }
    
    Vector1 operator - (const Vector1 & rhs) const
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
    
    T dot (const Vector1 & rhs) const
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
Vector1<T> operator * (T lhs, const Vector1<T> & rhs)
{
    return Vector1<T>(lhs * rhs.x);
}

template <typename T>
class Vector2
{
public:
    static constexpr std::size_t dimensions = 2;
    using type = T;
    
    constexpr Vector2 ()
    : x(), y()
    { }
    
    constexpr Vector2 (T x, T y)
    : x(x), y(y)
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
        case 0:
            return x;
            
        case 1:
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

    bool operator == (const Vector2 & rhs) const
    {
        return compareEq(x, rhs.x) &&
            compareEq(y, rhs.y);
    }
    
    bool operator != (const Vector2 & rhs) const
    {
        return !operator==(rhs);
    }

    Vector2 operator + (const Vector2 & rhs) const
    {
        return Vector2(x + rhs.x, y + rhs.y);
    }
    
    Vector2 operator - (const Vector2 & rhs) const
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
    
    T dot (const Vector2 & rhs) const
    {
        return x * rhs.x + y * rhs.y;
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
Vector2<T> operator * (T lhs, const Vector2<T> & rhs)
{
    return Vector2<T>(lhs * rhs.x, lhs * rhs.y);
}

template <typename T>
class Vector3
{
public:
    static constexpr std::size_t dimensions = 3;
    using type = T;
    
    constexpr Vector3 ()
    : x(), y(), z()
    { }
    
    constexpr Vector3 (T x, T y, T z)
    : x(x), y(y), z(z)
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
            case 0:
                return x;
                
            case 1:
                return y;
                
            case 2:
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

    bool operator == (const Vector3 & rhs) const
    {
        return compareEq(x, rhs.x) &&
            compareEq(y, rhs.y) &&
            compareEq(z, rhs.z);
    }
    
    bool operator != (const Vector3 & rhs) const
    {
        return !operator==(rhs);
    }

    Vector3 operator + (const Vector3 & rhs) const
    {
        return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
    }
    
    Vector3 operator - (const Vector3 & rhs) const
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
    
    T dot (const Vector3 & rhs) const
    {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }
    
    Vector3 cross (const Vector3 & rhs) const
    {
        return Vector3(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
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
Vector3<T> operator * (T lhs, const Vector3<T> & rhs)
{
    return Vector3<T>(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
}

template <typename T>
class Vector4
{
public:
    static constexpr std::size_t dimensions = 4;
    using type = T;
    
    constexpr Vector4 ()
    : x(), y(), z(), w()
    { }
    
    constexpr Vector4 (T x, T y, T z, T w)
    : x(x), y(y), z(z), w(w)
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

    bool operator == (const Vector4 & rhs) const
    {
        return compareEq(x, rhs.x) &&
        compareEq(y, rhs.y) &&
        compareEq(z, rhs.z) &&
        compareEq(w, rhs.w);
    }
    
    bool operator != (const Vector4 & rhs) const
    {
        return !operator==(rhs);
    }

    Vector4 operator + (const Vector4 & rhs) const
    {
        return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
    }
    
    Vector4 operator - (const Vector4 & rhs) const
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
    
    T dot (const Vector4 & rhs) const
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
Vector4<T> operator * (T lhs, const Vector4<T> & rhs)
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
