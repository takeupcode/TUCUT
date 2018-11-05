//
//  MinMax.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/4/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Math_MinMax_h
#define TUCUT_Math_MinMax_h

#include <limits>

namespace TUCUT {
namespace Math {
    
template <typename T>
class MinMax
{
public:
    void record (T value)
    {
        if (value < mMin)
        {
            mMin = value;
        }
        
        if (value > mMax)
        {
            mMax = value;
        }
    }
    
    T min () const
    {
        return mMin;
    }
    
    T max () const
    {
        return mMax;
    }

private:
    T mMin = std::numeric_limits<T>::max();
    T mMax = std::numeric_limits<T>::min();
};
    
} // namespace Math
} // namespace TUCUT

#endif // TUCUT_Math_MinMax_h
