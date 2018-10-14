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

// Predefined gradients for 1 dimension noise.
extern double gradients1[];

// Predefined unit-vector gradients for other dimension noise.
extern double unitVectors2[][2];
extern double unitVectors3[][3];
extern double unitVectors4[][4];

// double to int floor.
inline int dtoiflr (double d)
{
    int iflr = static_cast<int>(d);
    if (d < 0)
    {
        --iflr;
    }
    
    return iflr;
}

// Classic improved Perlin continuous interpolant.
inline double blend (double t)
{
    // f(t) = 6t^5 – 15t^4 + 10t^3
    return t * t * t * (t * (t * 6 - 15) + 10);
}

// Classic improved Perlin derivative.
inline double derivativeBlend (double t)
{
    // f'(t) = 30t^4 – 60t^3 + 30t^2
    return 30 * t * t * (t * (t - 2) + 1);
}

// The dot methods try to use 0, 1, and -1 for unit
// vectors when possible.
inline double simpleMultiply (double vec, double d)
{
    if (vec == 0.0)
    {
        return 0.0;
    }
    else if (vec == 1.0)
    {
        return d;
    }
    else if (vec == -1.0)
    {
        return -d;
    }
    else
    {
        return vec * d;
    }
}

inline double dot (double unitVector[], double x, double y)
{
    double dotX = simpleMultiply(unitVector[0], x);
    double dotY = simpleMultiply(unitVector[1], y);
    
    return dotX + dotY;
}

inline double dot (double unitVector[], double x, double y, double z)
{
    double dotX = simpleMultiply(unitVector[0], x);
    double dotY = simpleMultiply(unitVector[1], y);
    double dotZ = simpleMultiply(unitVector[2], z);
    
    return dotX + dotY + dotZ;
}

inline double dot (double unitVector[], double x, double y, double z, double w)
{
    double dotX = simpleMultiply(unitVector[0], x);
    double dotY = simpleMultiply(unitVector[1], y);
    double dotZ = simpleMultiply(unitVector[2], z);
    double dotW = simpleMultiply(unitVector[3], w);
    
    return dotX + dotY + dotZ + dotW;
}

// For all the node methods below:
//   the int values should be between 0 and 255
//   the double values should be between 0 and 1
inline double node (int hash, double x)
{
    return gradients1[hash % 16] * x;
}

inline double node (int hash, double x, double y)
{
    return dot(unitVectors2[hash % 13], x, y);
}

inline double node (int hash, double x, double y, double z)
{
    return dot(unitVectors3[hash % 12], x, y, z);
}

inline double node (int hash, double x, double y, double z, double w)
{
    return dot(unitVectors4[hash % 32], x, y, z, w);
}

} // namespace Noise
} // namespace TUCUT

#endif // TUCUT_Noise_NoiseUtil_h

