//
//  Lerp.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/16/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Geometry_Lerp_h
#define TUCUT_Geometry_Lerp_h

namespace TUCUT {
namespace Geometry {
        
template <typename N, typename T>
T lerp (N n1, N n2, T t)
{
    return (n1 * (1 - t) + n2 * t);
}

} // namespace Geometry
} // namespace TUCUT

#endif // TUCUT_Geometry_Lerp_h
