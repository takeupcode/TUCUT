//
//  NoiseUtil.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 9/20/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "NoiseUtil.h"

namespace TUCUT {
namespace Noise {

// A collection of all values from 0-255 in a random order as used
// by the Perlin noise algorithm.
unsigned char randomBytes[] =
{
    151,160,137, 91, 90, 15,131, 13,201, 95, 96, 53,194,233,  7,225,
    140, 36,103, 30, 69,142,  8, 99, 37,240, 21, 10, 23,190,  6,148,
    247,120,234, 75,  0, 26,197, 62, 94,252,219,203,117, 35, 11, 32,
     57,177, 33, 88,237,149, 56, 87,174, 20,125,136,171,168, 68,175,
     74,165, 71,134,139, 48, 27,166, 77,146,158,231, 83,111,229,122,
     60,211,133,230,220,105, 92, 41, 55, 46,245, 40,244,102,143, 54,
     65, 25, 63,161,  1,216, 80, 73,209, 76,132,187,208, 89, 18,169,
    200,196,135,130,116,188,159, 86,164,100,109,198,173,186,  3, 64,
     52,217,226,250,124,123,  5,202, 38,147,118,126,255, 82, 85,212,
    207,206, 59,227, 47, 16, 58, 17,182,189, 28, 42,223,183,170,213,
    119,248,152,  2, 44,154,163, 70,221,153,101,155,167, 43,172,  9,
    129, 22, 39,253, 19, 98,108,110, 79,113,224,232,178,185,112,104,
    218,246, 97,228,251, 34,242,193,238,210,144, 12,191,179,162,241,
     81, 51,145,235,249, 14,239,107, 49,192,214, 31,181,199,106,157,
    184, 84,204,176,115,121, 50, 45,127,  4,150,254,138,236,205, 93,
    222,114, 67, 29, 24, 72,243,141,128,195, 78, 66,215, 61,156,180
};

constexpr double sqrt3 = 1.73205080756887729352744634150587237;

// This is different from the other dimensions because 1 dimension doesn't
// use unit-length vectors. With one dimension, we can only define 2 unit-vectors
// (1 and -1) and that's not enough.
double gradients1[] =
{
    -8.0, -7.0, -6.0 -5.0 -4.0 -3.0, -2.0, -1.0,
     8.0,  7.0,  6.0  5.0  4.0  3.0,  2.0,  1.0
};

// This is a set of 12 unit-length vectors around a circle with a radius of 1.
// We won't have enough values if we limit the choices to just 0, 1, and -1 so
// this uses regularly spaced double points every 30 degrees around the circle.
double unitVectors2[][2] =
{
    { 1.0,    0.0},
    { sqrt3,  0.5},
    { 0.5,    sqrt3},
    { 0.0,    1.0},
    {-0.5,    sqrt3},
    {-sqrt3,  0.5},
    {-1.0,    0.0},
    {-sqrt3, -0.5},
    {-0.5,   -sqrt3},
    { 0.0,   -1.0},
    { 0.5,   -sqrt3},
    { sqrt3, -0.5}
};

// This is a set of 12 unit-length vectors around a 2x2x2 cube centered around
// the origin. The vectors point to the middle of each edge of the cube.
int unitVectors3[][3] =
{
    { 0, 1, 1},{ 0, 1,-1},{ 0,-1, 1},{ 0,-1,-1},
    { 1, 0, 1},{ 1, 0,-1},{-1, 0, 1},{-1, 0,-1},
    { 1, 1, 0},{ 1,-1, 0},{-1, 1, 0},{-1,-1, 0}
};

// This is a set of 32 unit-length vectors around a 2x2x2x2 hyper-cube centered around
// the origin. The vectors point to the middle of each edge of the hyper-cube.
int unitVectors4[][4] =
{
    { 0, 1, 1, 1},{ 0, 1, 1,-1},{ 0, 1,-1, 1},{ 0, 1,-1,-1},
    { 0,-1, 1, 1},{ 0,-1, 1,-1},{ 0,-1,-1, 1},{ 0,-1,-1,-1},
    { 1, 0, 1, 1},{ 1, 0, 1,-1},{ 1, 0,-1, 1},{ 1, 0,-1,-1},
    {-1, 0, 1, 1},{-1, 0, 1,-1},{-1, 0,-1, 1},{-1, 0,-1,-1},
    { 1, 1, 0, 1},{ 1, 1, 0,-1},{ 1,-1, 0, 1},{ 1,-1, 0,-1},
    {-1, 1, 0, 1},{-1, 1, 0,-1},{-1,-1, 0, 1},{-1,-1, 0,-1},
    { 1, 1, 1, 0},{ 1, 1,-1, 0},{ 1,-1, 1, 0},{ 1,-1,-1, 0},
    {-1, 1, 1, 0},{-1, 1,-1, 0},{-1,-1, 1, 0},{-1,-1,-1, 0}
};

} // namespace Noise
} // namespace TUCUT

