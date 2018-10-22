//
//  Vector.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/18/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Math_Vector_h
#define TUCUT_Math_Vector_h

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

    bool operator == (const Vector1 & rhs) const
    {
        return x == rhs.x;
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
    
    operator std::string () const
    {
        return "(vector: " + std::to_string(x) + ")";
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

    bool operator == (const Vector2 & rhs) const
    {
        return x == rhs.x &&
            y == rhs.y;
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
    
    operator std::string () const
    {
        return "(vector: " + std::to_string(x) + ", " + std::to_string(y) + ")";
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

    bool operator == (const Vector3 & rhs) const
    {
        return x == rhs.x &&
            y == rhs.y &&
            z == rhs.z;
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
    
    operator std::string () const
    {
        return "(vector: " + std::to_string(x) + ", " + std::to_string(y) +
        ", " + std::to_string(z) + ")";
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

    bool operator == (const Vector4 & rhs) const
    {
        return x == rhs.x &&
        y == rhs.y &&
        z == rhs.z &&
        w == rhs.w;
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
    
    operator std::string () const
    {
        return "(vector: " + std::to_string(x) + ", " + std::to_string(y) +
        ", " + std::to_string(z) + ", " + std::to_string(w) + ")";
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

using Vector1d = Vector1<double>;
using Vector2d = Vector2<double>;
using Vector3d = Vector3<double>;
using Vector4d = Vector4<double>;

} // namespace Math
} // namespace TUCUT

#endif // TUCUT_Math_Vector_h