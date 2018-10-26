//
//  Bounds.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/23/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "Point.h"

#include <array>

#ifndef TUCUT_Math_Bounds_h
#define TUCUT_Math_Bounds_h

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
            mExtent.to_string() + ")";
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
    
    constexpr Bounds2 (const Point1<T> & location, T extent)
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
        std::array<T> values = {0, 0};
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
    
    Vector1<T> envelopeVector (const Bounds1<T> & bounds)
    {
        std::array<T> values = {0, 0};
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
    
    Vector1<T> overlapVector (const Bounds1<T> & bounds)
    {
        std::array<T> values = {0, 0};
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
        mExtent.to_string() + ")";
    }
    
    operator std::string () const
    {
        return to_string();
    }
    
private:
    Point2<T> mLocation;
    T mExtent;
};

} // namespace Math
} // namespace TUCUT

#endif // TUCUT_Math_Bounds_h
