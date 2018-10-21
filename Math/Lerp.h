//
//  Lerp.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/16/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Math_Lerp_h
#define TUCUT_Math_Lerp_h

namespace TUCUT {
namespace Math {
        
template <typename N, typename T>
T lerp (N n0, N n1, T t)
{
    return (n0 * (1 - t) + n1 * t);
}

} // namespace Math
} // namespace TUCUT

#endif // TUCUT_Math_Lerp_h
