//
//  NoiseUtil.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 9/20/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Noise_NoiseUtil_h
#define TUCUT_Noise_NoiseUtil_h

namespace TUCUT {
namespace Noise {

// A random ordering of values from 0-255.
extern unsigned char randomBytes[];
    
// double to int floor
inline int dtoiflr (double value)
{
    int flr = static_cast<int>(value);
    if (value < 0)
    {
        --flr;
    }
    
    return flr;
}

// Classic improved Perlin continuous interpolant
inline double blend (double t)
{
    // f(t) = 6t^5 – 15t^4 + 10t^3
    return t * t * t * (t * (t * 6 - 15) + 10);
}
 
// A precise lerp method guaranteed to return v1 when alpha equals 1
inline double lerp(double v0, double v1, double alpha)
{
    return (1 - alpha) * v0 + alpha * v1;
}

inline double dot(int gradient[], double x, double y)
{
    return gradient[0] * x + gradient[1] * y;
}

inline double dot(int gradient[], double x, double y, double z)
{
    return gradient[0] * x + gradient[1] * y + gradient[2] * z;
}

inline double dot(int gradient[], double x, double y, double z, double w)
{
    return gradient[0] * x + gradient[1] * y + gradient[2] * z + gradient[3] * w;
}

} // namespace Noise
} // namespace TUCUT

#endif // TUCUT_Noise_NoiseUtil_h

