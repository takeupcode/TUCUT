//
//  Bounds.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/23/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Math_Bounds_h
#define TUCUT_Math_Bounds_h

#include "Point.h"

#include <array>
#include <string>

namespace TUCUT {
namespace Math {
        
template <typename T>
class Bounds1
{
public:
    static constexpr std::size_t dimensions = 1;
    using type = T;
    
    constexpr Bounds1 ()
    : mExtent()
    { }
    
    constexpr Bounds1 (T x, T extent)
    : mLocation(x), mExtent(extent)
    { }
    
    constexpr Bounds1 (Point1<T> const & location, T extent)
    : mLocation(location), mExtent(extent)
    { }

    constexpr Bounds1 (Bounds1 const & src)
    : mLocation(src.mLocation), mExtent(src.mExtent)
    { }

    bool operator == (Bounds1 const & rhs) const
    {
        return mLocation == rhs.mLocation &&
            compareEq(mExtent, rhs.mExtent);
    }

    bool operator != (Bounds1 const & rhs) const
    {
        return !operator==(rhs);
    }

    Point1<T> location () const
    {
        return mLocation;
    }
    
    void setLocation (Point1<T> const & location)
    {
        mLocation = location;
    }
    
    T extent () const
    {
        return mExtent;
    }
    
    void setExtent (T extent)
    {
        mExtent = extent;
    }
    
    Bounds1 operator + (Vector1<T> const & rhs) const
    {
        return Bounds1(mLocation.x + rhs.x, mExtent);
    }
    
    Bounds1 operator - (Vector1<T> const & rhs) const
    {
        return Bounds1(mLocation.x - rhs.x, mExtent);
    }
    
    Vector1<T> envelopeVector (Point1<T> const & point)
    {
        T x = 0;
        T loc = mLocation.x;
        T pointLoc = point.x;
        if (pointLoc > (loc + mExtent))
        {
            x = (loc + mExtent) - pointLoc;
        }
        else if (pointLoc < (loc - mExtent))
        {
            x = (loc - mExtent) - pointLoc;
        }
        
        return Vector1<T>(x);
    }
    
    Vector1<T> envelopeVector (Bounds1<T> const & bounds)
    {
        T x = 0;
        T loc = mLocation.x;
        T boundsLoc = bounds.mLocation.x;
        if (boundsLoc > (loc + mExtent))
        {
            x = (loc + mExtent) - boundsLoc;
        }
        else if (boundsLoc < (loc - mExtent))
        {
            x = (loc - mExtent) - boundsLoc;
        }
        
        return Vector1<T>(x);
    }

    Vector1<T> overlapVector (Bounds1<T> const & bounds)
    {
        T x = 0;
        T loc = mLocation.x;
        T boundsLoc = bounds.mLocation.x;
        if ((boundsLoc + bounds.mExtent) > (loc + mExtent))
        {
            if ((boundsLoc - bounds.mExtent) > (loc + mExtent))
            {
                x = (loc + mExtent) - (boundsLoc - bounds.mExtent);
            }
        }
        else if ((boundsLoc - bounds.mExtent) < (loc - mExtent))
        {
            if ((boundsLoc + bounds.mExtent) < (loc - mExtent))
            {
                x = (loc - mExtent) - (boundsLoc + bounds.mExtent);
            }
        }
        
        return Vector1<T>(x);
    }

    std::string to_string () const
    {
        return "(location: " + mLocation.to_string() + ", extent: " +
            std::to_string(mExtent) + ")";
    }
    
    operator std::string () const
    {
        return to_string();
    }

private:
    Point1<T> mLocation;
    T mExtent;
};
    
template <typename T>
class Bounds2
{
public:
    static constexpr std::size_t dimensions = 2;
    using type = T;
    
    constexpr Bounds2 ()
    : mExtent()
    { }
    
    constexpr Bounds2 (T x, T y, T extent)
    : mLocation(x, y), mExtent(extent)
    { }
    
    constexpr Bounds2 (Point2<T> const & location, T extent)
    : mLocation(location), mExtent(extent)
    { }

    constexpr Bounds2 (Bounds2 const & src)
    : mLocation(src.mLocation), mExtent(src.mExtent)
    { }

    bool operator == (Bounds2 const & rhs) const
    {
        return mLocation == rhs.mLocation &&
            compareEq(mExtent, rhs.mExtent);
    }
    
    bool operator != (Bounds2 const & rhs) const
    {
        return !operator==(rhs);
    }
    
    Point2<T> location () const
    {
        return mLocation;
    }
    
    void setLocation (Point2<T> const & location)
    {
        mLocation = location;
    }
    
    T extent () const
    {
        return mExtent;
    }
    
    void setExtent (T extent)
    {
        mExtent = extent;
    }
    
    Bounds2 operator + (Vector2<T> const & rhs) const
    {
        return Bounds2(mLocation.x + rhs.x,
            mLocation.y + rhs.y, mExtent);
    }
    
    Bounds2 operator - (Vector2<T> const & rhs) const
    {
        return Bounds2(mLocation.x - rhs.x,
            mLocation.y - rhs.y, mExtent);
    }
    
    Vector2<T> envelopeVector (Point2<T> const & point)
    {
        std::array<T, 2> values = {0, 0};
        for (std::size_t axis = 0; axis < 2; ++axis)
        {
            T loc = mLocation.component(axis);
            T pointLoc = point.component(axis);
            if (pointLoc > (loc + mExtent))
            {
                values[axis] = (loc + mExtent) - pointLoc;
            }
            else if (pointLoc < (loc - mExtent))
            {
                values[axis] = (loc - mExtent) - pointLoc;
            }
        }

        return Vector2<T>(values[0], values[1]);
    }
    
    Vector2<T> envelopeVector (Bounds2<T> const & bounds)
    {
        std::array<T, 2> values = {0, 0};
        for (std::size_t axis = 0; axis < 2; ++axis)
        {
            T loc = mLocation.component(axis);
            T boundsLoc = bounds.mLocation.component(axis);
            if (boundsLoc > (loc + mExtent))
            {
                values[axis] = (loc + mExtent) - boundsLoc;
            }
            else if (boundsLoc < (loc - mExtent))
            {
                values[axis] = (loc - mExtent) - boundsLoc;
            }
        }
        
        return Vector2<T>(values[0], values[1]);
    }
    
    Vector2<T> overlapVector (Bounds2<T> const & bounds)
    {
        std::array<T, 2> values = {0, 0};
        for (std::size_t axis = 0; axis < 2; ++axis)
        {
            T loc = mLocation.component(axis);
            T boundsLoc = bounds.mLocation.component(axis);
            if ((boundsLoc + bounds.mExtent) > (loc + mExtent))
            {
                if ((boundsLoc - bounds.mExtent) > (loc + mExtent))
                {
                    values[axis] = (loc + mExtent) - (boundsLoc - bounds.mExtent);
                }
            }
            else if ((boundsLoc - bounds.mExtent) < (loc - mExtent))
            {
                if ((boundsLoc + bounds.mExtent) < (loc - mExtent))
                {
                    values[axis] = (loc - mExtent) - (boundsLoc + bounds.mExtent);
                }
            }
        }
        
        return Vector2<T>(values[0], values[1]);
    }
    
    std::string to_string () const
    {
        return "(location: " + mLocation.to_string() + ", extent: " +
            std::to_string(mExtent) + ")";
    }
    
    operator std::string () const
    {
        return to_string();
    }
    
private:
    Point2<T> mLocation;
    T mExtent;
};

template <typename T>
class Bounds3
{
public:
    static constexpr std::size_t dimensions = 3;
    using type = T;
    
    constexpr Bounds3 ()
    : mExtent()
    { }
    
    constexpr Bounds3 (T x, T y, T z, T extent)
    : mLocation(x, y, z), mExtent(extent)
    { }
    
    constexpr Bounds3 (Point3<T> const & location, T extent)
    : mLocation(location), mExtent(extent)
    { }

    constexpr Bounds3 (Bounds3 const & src)
    : mLocation(src.mLocation), mExtent(src.mExtent)
    { }

    bool operator == (Bounds3 const & rhs) const
    {
        return mLocation == rhs.mLocation &&
            compareEq(mExtent, rhs.mExtent);
    }
    
    bool operator != (Bounds3 const & rhs) const
    {
        return !operator==(rhs);
    }
    
    Point3<T> location () const
    {
        return mLocation;
    }
    
    void setLocation (Point3<T> const & location)
    {
        mLocation = location;
    }
    
    T extent () const
    {
        return mExtent;
    }
    
    void setExtent (T extent)
    {
        mExtent = extent;
    }
    
    Bounds3 operator + (Vector3<T> const & rhs) const
    {
        return Bounds3(mLocation.x + rhs.x,
            mLocation.y + rhs.y,
            mLocation.z + rhs.z, mExtent);
    }
    
    Bounds3 operator - (Vector3<T> const & rhs) const
    {
        return Bounds3(mLocation.x - rhs.x,
            mLocation.y - rhs.y,
            mLocation.z - rhs.z, mExtent);
    }
    
    Vector3<T> envelopeVector (Point3<T> const & point)
    {
        std::array<T, 3> values = {0, 0, 0};
        for (std::size_t axis = 0; axis < 3; ++axis)
        {
            T loc = mLocation.component(axis);
            T pointLoc = point.component(axis);
            if (pointLoc > (loc + mExtent))
            {
                values[axis] = (loc + mExtent) - pointLoc;
            }
            else if (pointLoc < (loc - mExtent))
            {
                values[axis] = (loc - mExtent) - pointLoc;
            }
        }
        
        return Vector3<T>(values[0], values[1], values[2]);
    }
    
    Vector3<T> envelopeVector (Bounds3<T> const & bounds)
    {
        std::array<T, 3> values = {0, 0, 0};
        for (std::size_t axis = 0; axis < 3; ++axis)
        {
            T loc = mLocation.component(axis);
            T boundsLoc = bounds.mLocation.component(axis);
            if (boundsLoc > (loc + mExtent))
            {
                values[axis] = (loc + mExtent) - boundsLoc;
            }
            else if (boundsLoc < (loc - mExtent))
            {
                values[axis] = (loc - mExtent) - boundsLoc;
            }
        }
        
        return Vector3<T>(values[0], values[1], values[2]);
    }
    
    Vector3<T> overlapVector (Bounds3<T> const & bounds)
    {
        std::array<T, 3> values = {0, 0, 0};
        for (std::size_t axis = 0; axis < 3; ++axis)
        {
            T loc = mLocation.component(axis);
            T boundsLoc = bounds.mLocation.component(axis);
            if ((boundsLoc + bounds.mExtent) > (loc + mExtent))
            {
                if ((boundsLoc - bounds.mExtent) > (loc + mExtent))
                {
                    values[axis] = (loc + mExtent) - (boundsLoc - bounds.mExtent);
                }
            }
            else if ((boundsLoc - bounds.mExtent) < (loc - mExtent))
            {
                if ((boundsLoc + bounds.mExtent) < (loc - mExtent))
                {
                    values[axis] = (loc - mExtent) - (boundsLoc + bounds.mExtent);
                }
            }
        }
        
        return Vector3<T>(values[0], values[1], values[2]);
    }
    
    std::string to_string () const
    {
        return "(location: " + mLocation.to_string() + ", extent: " +
            std::to_string(mExtent) + ")";
    }
    
    operator std::string () const
    {
        return to_string();
    }
    
private:
    Point3<T> mLocation;
    T mExtent;
};

template <typename T>
class Bounds4
{
public:
    static constexpr std::size_t dimensions = 4;
    using type = T;
    
    constexpr Bounds4 ()
    : mExtent()
    { }
    
    constexpr Bounds4 (T x, T y, T z, T w, T extent)
    : mLocation(x, y, z, w), mExtent(extent)
    { }
    
    constexpr Bounds4 (Point4<T> const & location, T extent)
    : mLocation(location), mExtent(extent)
    { }

    constexpr Bounds4 (Bounds4 const & src)
    : mLocation(src.mLocation), mExtent(src.mExtent)
    { }

    bool operator == (Bounds4 const & rhs) const
    {
        return mLocation == rhs.mLocation &&
            compareEq(mExtent, rhs.mExtent);    }
    
    bool operator != (Bounds4 const & rhs) const
    {
        return !operator==(rhs);
    }
    
    Point4<T> location () const
    {
        return mLocation;
    }
    
    void setLocation (Point4<T> const & location)
    {
        mLocation = location;
    }
    
    T extent () const
    {
        return mExtent;
    }
    
    void setExtent (T extent)
    {
        mExtent = extent;
    }
    
    Bounds4 operator + (Vector4<T> const & rhs) const
    {
        return Bounds4(mLocation.x + rhs.x,
            mLocation.y + rhs.y,
            mLocation.z + rhs.z,
            mLocation.w + rhs.w, mExtent);
    }
    
    Bounds4 operator - (Vector4<T> const & rhs) const
    {
        return Bounds4(mLocation.x - rhs.x,
            mLocation.y - rhs.y,
            mLocation.z - rhs.z,
            mLocation.w - rhs.w, mExtent);
    }
    
    Vector4<T> envelopeVector (Point4<T> const & point)
    {
        std::array<T, 4> values = {0, 0, 0, 0};
        for (std::size_t axis = 0; axis < 4; ++axis)
        {
            T loc = mLocation.component(axis);
            T pointLoc = point.component(axis);
            if (pointLoc > (loc + mExtent))
            {
                values[axis] = (loc + mExtent) - pointLoc;
            }
            else if (pointLoc < (loc - mExtent))
            {
                values[axis] = (loc - mExtent) - pointLoc;
            }
        }
        
        return Vector4<T>(values[0], values[1], values[2], values[3]);
    }
    
    Vector4<T> envelopeVector (Bounds4<T> const & bounds)
    {
        std::array<T, 4> values = {0, 0, 0, 0};
        for (std::size_t axis = 0; axis < 4; ++axis)
        {
            T loc = mLocation.component(axis);
            T boundsLoc = bounds.mLocation.component(axis);
            if (boundsLoc > (loc + mExtent))
            {
                values[axis] = (loc + mExtent) - boundsLoc;
            }
            else if (boundsLoc < (loc - mExtent))
            {
                values[axis] = (loc - mExtent) - boundsLoc;
            }
        }
        
        return Vector4<T>(values[0], values[1], values[2], values[3]);
    }
    
    Vector4<T> overlapVector (Bounds4<T> const & bounds)
    {
        std::array<T, 4> values = {0, 0, 0, 0};
        for (std::size_t axis = 0; axis < 4; ++axis)
        {
            T loc = mLocation.component(axis);
            T boundsLoc = bounds.mLocation.component(axis);
            if ((boundsLoc + bounds.mExtent) > (loc + mExtent))
            {
                if ((boundsLoc - bounds.mExtent) > (loc + mExtent))
                {
                    values[axis] = (loc + mExtent) - (boundsLoc - bounds.mExtent);
                }
            }
            else if ((boundsLoc - bounds.mExtent) < (loc - mExtent))
            {
                if ((boundsLoc + bounds.mExtent) < (loc - mExtent))
                {
                    values[axis] = (loc - mExtent) - (boundsLoc + bounds.mExtent);
                }
            }
        }
        
        return Vector4<T>(values[0], values[1], values[2], values[3]);
    }
    
    std::string to_string () const
    {
        return "(location: " + mLocation.to_string() + ", extent: " +
            std::to_string(mExtent) + ")";
    }
    
    operator std::string () const
    {
        return to_string();
    }
    
private:
    Point4<T> mLocation;
    T mExtent;
};
    
using Bounds1i = Bounds1<int>;
using Bounds2i = Bounds2<int>;
using Bounds3i = Bounds3<int>;
using Bounds4i = Bounds4<int>;

using Bounds1f = Bounds1<float>;
using Bounds2f = Bounds2<float>;
using Bounds3f = Bounds3<float>;
using Bounds4f = Bounds4<float>;

using Bounds1d = Bounds1<double>;
using Bounds2d = Bounds2<double>;
using Bounds3d = Bounds3<double>;
using Bounds4d = Bounds4<double>;

using Bounds1l = Bounds1<long double>;
using Bounds2l = Bounds2<long double>;
using Bounds3l = Bounds3<long double>;
using Bounds4l = Bounds4<long double>;

} // namespace Math
} // namespace TUCUT

#endif // TUCUT_Math_Bounds_h
