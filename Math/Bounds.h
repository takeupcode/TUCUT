//
//  Bounds.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/23/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "Point.h"

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
        if (point.x > (mLocation.x + mExtent))
        {
            x = (mLocation.x + mExtent) - point.x;
        }
        else if (point.x < (mLocation.x - mExtent))
        {
            x = (mLocation.x - mExtent) - point.x;
        }
        
        return Vector1<T>(x);
    }
    
    Vector1<T> envelopeVector (const Bounds1<T> & bounds)
    {
        T x = 0;
        if (bounds.mLocation.x > (mLocation.x + mExtent))
        {
            x = (mLocation.x + mExtent) - bounds.mLocation.x;
        }
        else if (bounds.mLocation.x < (mLocation.x - mExtent))
        {
            x = (mLocation.x - mExtent) - bounds.mLocation.x;
        }
        
        return Vector1<T>(x);
    }

    Vector1<T> overlapVector (const Bounds1<T> & bounds)
    {
        T x = 0;
        if ((bounds.mLocation.x + bounds.mExtent) > (mLocation.x + mExtent))
        {
            if ((bounds.mLocation.x - bounds.mExtent) > (mLocation.x + mExtent))
            {
                x = (mLocation.x + mExtent) - (bounds.mLocation.x - bounds.mExtent);
            }
        }
        else if ((bounds.mLocation.x - bounds.mExtent) < (mLocation.x - mExtent))
        {
            if ((bounds.mLocation.x + bounds.mExtent) < (mLocation.x - mExtent))
            {
                x = (mLocation.x - mExtent) - (bounds.mLocation.x + bounds.mExtent);
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
        T x = 0;
        if (point.x > (mLocation.x + mExtent))
        {
            x = (mLocation.x + mExtent) - point.x;
        }
        else if (point.x < (mLocation.x - mExtent))
        {
            x = (mLocation.x - mExtent) - point.x;
        }
        
        T y = 0;
        if (point.y > (mLocation.y + mExtent))
        {
            y = (mLocation.y + mExtent) - point.y;
        }
        else if (point.y < (mLocation.y - mExtent))
        {
            y = (mLocation.y - mExtent) - point.y;
        }

        return Vector2<T>(x, y);
    }
    
    Vector1<T> envelopeVector (const Bounds1<T> & bounds)
    {
        T x = 0;
        if (bounds.mLocation.x > (mLocation.x + mExtent))
        {
            x = (mLocation.x + mExtent) - bounds.mLocation.x;
        }
        else if (bounds.mLocation.x < (mLocation.x - mExtent))
        {
            x = (mLocation.x - mExtent) - bounds.mLocation.x;
        }
        
        T y = 0;
        if (bounds.mLocation.y > (mLocation.y + mExtent))
        {
            y = (mLocation.y + mExtent) - bounds.mLocation.y;
        }
        else if (bounds.mLocation.y < (mLocation.y - mExtent))
        {
            y = (mLocation.y - mExtent) - bounds.mLocation.y;
        }
        
        return Vector2<T>(x, y);
    }
    
    Vector1<T> overlapVector (const Bounds1<T> & bounds)
    {
        T x = 0;
        if ((bounds.mLocation.x + bounds.mExtent) > (mLocation.x + mExtent))
        {
            if ((bounds.mLocation.x - bounds.mExtent) > (mLocation.x + mExtent))
            {
                x = (mLocation.x + mExtent) - (bounds.mLocation.x - bounds.mExtent);
            }
        }
        else if ((bounds.mLocation.x - bounds.mExtent) < (mLocation.x - mExtent))
        {
            if ((bounds.mLocation.x + bounds.mExtent) < (mLocation.x - mExtent))
            {
                x = (mLocation.x - mExtent) - (bounds.mLocation.x + bounds.mExtent);
            }
        }
        
        T y = 0;
        if ((bounds.mLocation.y + bounds.mExtent) > (mLocation.y + mExtent))
        {
            if ((bounds.mLocation.y - bounds.mExtent) > (mLocation.y + mExtent))
            {
                y = (mLocation.y + mExtent) - (bounds.mLocation.y - bounds.mExtent);
            }
        }
        else if ((bounds.mLocation.y - bounds.mExtent) < (mLocation.y - mExtent))
        {
            if ((bounds.mLocation.y + bounds.mExtent) < (mLocation.y - mExtent))
            {
                y = (mLocation.y - mExtent) - (bounds.mLocation.y + bounds.mExtent);
            }
        }
        
        return Vector2<T>(x, y);
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
