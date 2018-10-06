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
constexpr int randomBytesSize = 256;
constexpr int randomByteMask = randomBytesSize - 1;
extern unsigned char randomBytes[randomBytesSize * 2];

// Calculate cyclical indices into random bytes taking into
// account that the index could be negative. All we need to
// do is mask the input.
//  mask
//      0000 0000 1111 1111
//  input                     output
//  258 0000 0001 0000 0010     2 0000 0010
//  257 0000 0001 0000 0001     1 0000 0001
//  256 0000 0001 0000 0000     0 0000 0000
//  255 0000 0000 1111 1111   255 1111 1111
//    2 0000 0000 0000 0010     2 0000 0010
//    1 0000 0000 0000 0001     1 0000 0001
//    0 0000 0000 0000 0000     0 0000 0000
//   -1 1111 1111 1111 1111   255 1111 1111
// -254 1111 1111 0000 0010     2 0000 0010
// -255 1111 1111 0000 0001     1 0000 0001
// -256 1111 1111 0000 0000     0 0000 0000
// -257 1111 1110 1111 1111   255 1111 1111
inline int cyclicIndex (int i)
{
    return i & randomByteMask;
}

// Predefined gradients for 1 dimension noise.
extern double gradients1[];

// Predefined unit-vector gradients for other dimension noise.
extern double unitVectors2[];
extern double unitVectors3[];
extern double unitVectors4[];

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

// A precise lerp method that accepts 0 <= t <= 1
// and is guaranteed to return high when t equals 1.
// Using raw coordinate values for t will result in
// straight linear interpolation between low and high.
// Putting t through a blend method will instead result
// in a smooth curve.
inline double lerp (double low, double high, double t)
{
    return low * (1 - t) + high * t;
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
inline double node (int ix, double x)
{
    int index = randomBytes[ix];
    index %= 16;
    
    return gradients1[index] * x;
}

inline double node (int ix, int iy, double x, double y)
{
    int index = randomBytes[randomBytes[ix] + iy];
    index %= 12;
    
    return dot(unitVectors2[index], x, y);
}

inline double node (int ix, int iy, int iz, double x, double y, double z)
{
    int index = randomBytes[randomBytes[randomBytes[ix] + iy] + iz];
    index %= 12;
    
    return dot(unitVectors3[index], x, y, z);
}

inline double node (int ix, int iy, int iz, int iw, double x, double y, double z, double w)
{
    int index = randomBytes[randomBytes[randomBytes[randomBytes[ix] + iy] + iz] + iw];
    index %= 32;
    
    return dot(unitVectors4[index], x, y, z, w);
}

} // namespace Noise
} // namespace TUCUT

#endif // TUCUT_Noise_NoiseUtil_h

