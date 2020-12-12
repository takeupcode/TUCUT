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
    
    constexpr Bounds1 (const Point1<T> & location, T extent)
    : mLocation(location), mExtent(extent)
    { }

    bool operator == (const Bounds1 & rhs) const
    {
        return mLocation == rhs.mLocation &&
            mExtent == rhs.mExtent;
    }

    bool operator != (const Bounds1 & rhs) const
    {
        return !operator==(rhs);
    }

    Point1<T> location () const
    {
        return mLocation;
    }
    
    void setLocation (const Point1<T> & location)
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
    
    Bounds1 operator + (const Vector1<T> & rhs) const
    {
        return Bounds1(mLocation.x + rhs.x, mExtent);
    }
    
    Bounds1 operator - (const Vector1<T> & rhs) const
    {
        return Bounds1(mLocation.x - rhs.x, mExtent);
    }
    
    Vector1<T> envelopeVector (const Point1<T> & point)
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
    
    Vector1<T> envelopeVector (const Bounds1<T> & bounds)
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

    Vector1<T> overlapVector (const Bounds1<T> & bounds)
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
    
    constexpr Bounds2 (const Point2<T> & location, T extent)
    : mLocation(location), mExtent(extent)
    { }
    
    bool operator == (const Bounds2 & rhs) const
    {
        return mLocation == rhs.mLocation &&
        mExtent == rhs.mExtent;
    }
    
    bool operator != (const Bounds2 & rhs) const
    {
        return !operator==(rhs);
    }
    
    Point2<T> location () const
    {
        return mLocation;
    }
    
    void setLocation (const Point2<T> & location)
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
    
    Bounds2 operator + (const Vector2<T> & rhs) const
    {
        return Bounds2(mLocation.x + rhs.x, mLocation.y + rhs.y, mExtent);
    }
    
    Bounds2 operator - (const Vector2<T> & rhs) const
    {
        return Bounds2(mLocation.x - rhs.x, mLocation.y - rhs.y, mExtent);
    }
    
    Vector2<T> envelopeVector (const Point2<T> & point)
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
    
    Vector2<T> envelopeVector (const Bounds2<T> & bounds)
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
    
    Vector2<T> overlapVector (const Bounds2<T> & bounds)
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
    
    constexpr Bounds3 (const Point3<T> & location, T extent)
    : mLocation(location), mExtent(extent)
    { }
    
    bool operator == (const Bounds3 & rhs) const
    {
        return mLocation == rhs.mLocation &&
        mExtent == rhs.mExtent;
    }
    
    bool operator != (const Bounds3 & rhs) const
    {
        return !operator==(rhs);
    }
    
    Point3<T> location () const
    {
        return mLocation;
    }
    
    void setLocation (const Point3<T> & location)
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
    
    Bounds3 operator + (const Vector3<T> & rhs) const
    {
        return Bounds3(mLocation.x + rhs.x, mLocation.y + rhs.y,
                       mLocation.z + rhs.z, mExtent);
    }
    
    Bounds3 operator - (const Vector3<T> & rhs) const
    {
        return Bounds3(mLocation.x - rhs.x, mLocation.y - rhs.y,
                       mLocation.z - rhs.z, mExtent);
    }
    
    Vector3<T> envelopeVector (const Point3<T> & point)
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
    
    Vector3<T> envelopeVector (const Bounds3<T> & bounds)
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
    
    Vector3<T> overlapVector (const Bounds3<T> & bounds)
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
    
    constexpr Bounds4 (const Point4<T> & location, T extent)
    : mLocation(location), mExtent(extent)
    { }
    
    bool operator == (const Bounds4 & rhs) const
    {
        return mLocation == rhs.mLocation &&
        mExtent == rhs.mExtent;
    }
    
    bool operator != (const Bounds4 & rhs) const
    {
        return !operator==(rhs);
    }
    
    Point4<T> location () const
    {
        return mLocation;
    }
    
    void setLocation (const Point4<T> & location)
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
    
    Bounds4 operator + (const Vector4<T> & rhs) const
    {
        return Bounds4(mLocation.x + rhs.x, mLocation.y + rhs.y,
                       mLocation.z + rhs.z, mLocation.w + rhs.w, mExtent);
    }
    
    Bounds4 operator - (const Vector4<T> & rhs) const
    {
        return Bounds4(mLocation.x - rhs.x, mLocation.y - rhs.y,
                       mLocation.z - rhs.z, mLocation.w - rhs.w, mExtent);
    }
    
    Vector4<T> envelopeVector (const Point4<T> & point)
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
    
    Vector4<T> envelopeVector (const Bounds4<T> & bounds)
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
    
    Vector4<T> overlapVector (const Bounds4<T> & bounds)
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

using Bounds1d = Bounds1<double>;
using Bounds2d = Bounds2<double>;
using Bounds3d = Bounds3<double>;
using Bounds4d = Bounds4<double>;

} // namespace Math
} // namespace TUCUT

#endif // TUCUT_Math_Bounds_h
