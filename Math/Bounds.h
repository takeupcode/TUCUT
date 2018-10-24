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
    : mLocation(x), mExtent(extent)
    { }

    bool operator == (const Point1 & rhs) const
    {
        return mLocation == rhs.mLocation &&
            mExtent == rhs.mExtent;
    }

    bool operator != (const Point1 & rhs) const
    {
        return !operator==(rhs);
    }

    Point1<T> location () const
    {
        return mLocation;
    }
    
    void setLocation (const Point<T> & location)
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
    
    Vector1<T> envelope (const Point1<T> point)
    {
        if (point.x > mLocation.x + mExtent)
        {
            return Vector1<T>(point.x - mLocation - mExtent);
        }
        else if (point.x < mLocation.x - mExtent)
        {
            return Vector1<T>(point.x - mLocation - mExtent);
        }
        return Vector<T>();
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

} // namespace Math
} // namespace TUCUT

#endif // TUCUT_Math_Bounds_h
