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

// Predefined gradients for 1 dimension noise.
extern double gradients1[];

// Predefined unit-vector gradients for other dimension noise.
// We have enough simple vectors for 3 and 4 dimensions to be able to use ints.
extern double unitVectors2[];
extern int unitVectors3[];
extern int unitVectors4[];

// double to int floor.
inline int dtoiflr (double value)
{
    int flr = static_cast<int>(value);
    if (value < 0)
    {
        --flr;
    }
    
    return flr;
}

// Classic improved Perlin continuous interpolant.
inline double blend (double t)
{
    // f(t) = 6t^5 – 15t^4 + 10t^3
    return t * t * t * (t * (t * 6 - 15) + 10);
}
 
// A precise lerp method guaranteed to return v1 when alpha equals 1.
inline double lerp (double v0, double v1, double alpha)
{
    return (1 - alpha) * v0 + alpha * v1;
}

inline double dot (double unitVector[], double x, double y)
{
    return unitVector[0] * x + unitVector[1] * y;
}

inline double dot (int unitVector[], double x, double y, double z)
{
    return unitVector[0] * x + unitVector[1] * y + unitVector[2] * z;
}

inline double dot (int unitVector[], double x, double y, double z, double w)
{
    return unitVector[0] * x + unitVector[1] * y + unitVector[2] * z + unitVector[3] * w;
}

inline double node (int hash, double x)
{
    int index = hash & 0x0f;
    
    return gradients1[index] * x;
}

inline double node (int hash, double x, double y)
{
    int index = hash % 12;
    
    return dot(unitVectors2[index], x, y);
}

inline double node (int hash, double x, double y, double z)
{
    int index = hash % 12;
    
    return dot(unitVectors3[index], x, y, z);
}

inline double node (int hash, double x, double y, double z, double w)
{
    int index = hash % 32;
    
    return dot(unitVectors4[index], x, y, z, w);
}

} // namespace Noise
} // namespace TUCUT

#endif // TUCUT_Noise_NoiseUtil_h

