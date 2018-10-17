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

constexpr double sqrt2d2 = 0.70710678118654752440084436210484904; // sqrt(2) / 2
constexpr double sqrt3d2 = 0.86602540378443864676372317075293618; // sqrt(3) / 2
    
// This is different from the other dimensions because 1 dimension doesn't
// use unit-length vectors. With one dimension, we can only define 2 unit-vectors
// (1 and -1) and that's not enough.
double gradients1[] =
{
    -8.0, -7.0, -6.0 -5.0, -4.0, -3.0, -2.0, -1.0,
     8.0,  7.0,  6.0, 5.0,  4.0,  3.0,  2.0,  1.0
};

// This is a set of 16 unit-length vectors around a circle with a radius of 1.
// We won't have enough values if we limit the choices to just 0, 1, and -1.
// Three vectors have been commented out to give 13 which seems to help prevent
// cycles from appearing in the output.
double unitVectors2[][2] =
{
    {-0.5,      sqrt3d2},
    { sqrt3d2,  0.5},
    { 0.5,      sqrt3d2},
    //{-sqrt2d2,  sqrt2d2},
    {-sqrt3d2,  0.5},
    //{ 1.0,      0.0},
    { sqrt2d2,  sqrt2d2},
    { 0.0,      1.0},
    { 0.5,     -sqrt3d2},
    {-1.0,      0.0},
    //{-sqrt3d2, -0.5},
    {-0.5,     -sqrt3d2},
    { sqrt2d2, -sqrt2d2},
    { 0.0,     -1.0},
    { sqrt3d2, -0.5},
    {-sqrt2d2, -sqrt2d2}
};

// This is a set of 12 unit-length vectors around a 2x2x2 cube centered around
// the origin. The vectors point to the middle of each edge of the cube.
double unitVectors3[][3] =
{
    { 0.0, 1.0, 1.0},{ 0.0, 1.0,-1.0},{ 0.0,-1.0, 1.0},{ 0.0,-1.0,-1.0},
    { 1.0, 0.0, 1.0},{ 1.0, 0.0,-1.0},{-1.0, 0.0, 1.0},{-1.0, 0.0,-1.0},
    { 1.0, 1.0, 0.0},{ 1.0,-1.0, 0.0},{-1.0, 1.0, 0.0},{-1.0,-1.0, 0.0}
};

// This is a set of 32 unit-length vectors around a 2x2x2x2 hyper-cube centered around
// the origin. The vectors point to the middle of each edge of the hyper-cube.
double unitVectors4[][4] =
{
    { 0.0, 1.0, 1.0, 1.0},{ 0.0, 1.0, 1.0,-1.0},{ 0.0, 1.0,-1.0, 1.0},{ 0.0, 1.0,-1.0,-1.0},
    { 0.0,-1.0, 1.0, 1.0},{ 0.0,-1.0, 1.0,-1.0},{ 0.0,-1.0,-1.0, 1.0},{ 0.0,-1.0,-1.0,-1.0},
    { 1.0, 0.0, 1.0, 1.0},{ 1.0, 0.0, 1.0,-1.0},{ 1.0, 0.0,-1.0, 1.0},{ 1.0, 0.0,-1.0,-1.0},
    {-1.0, 0.0, 1.0, 1.0},{-1.0, 0.0, 1.0,-1.0},{-1.0, 0.0,-1.0, 1.0},{-1.0, 0.0,-1.0,-1.0},
    { 1.0, 1.0, 0.0, 1.0},{ 1.0, 1.0, 0.0,-1.0},{ 1.0,-1.0, 0.0, 1.0},{ 1.0,-1.0, 0.0,-1.0},
    {-1.0, 1.0, 0.0, 1.0},{-1.0, 1.0, 0.0,-1.0},{-1.0,-1.0, 0.0, 1.0},{-1.0,-1.0, 0.0,-1.0},
    { 1.0, 1.0, 1.0, 0.0},{ 1.0, 1.0,-1.0, 0.0},{ 1.0,-1.0, 1.0, 0.0},{ 1.0,-1.0,-1.0, 0.0},
    {-1.0, 1.0, 1.0, 0.0},{-1.0, 1.0,-1.0, 0.0},{-1.0,-1.0, 1.0, 0.0},{-1.0,-1.0,-1.0, 0.0}
};

} // namespace Noise
} // namespace TUCUT

