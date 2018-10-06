//
//  ClassicNoise.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 9/20/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "Noise.h"
#include "NoiseUtil.h"

namespace TUCUT {
namespace Noise {

// lerp is a method to interpolate a value between two nodes, n1 and n2.
// By using blended values for r, we get a smooth curve. We're not calling
// lerp directly. Instead, we expand the formulas so that we can calculate
// the various constants shared between the noise and the derivatives.
// lerp is defined as: lerp (n1, n2, r)
//   (n1 * (1 - r) + n2 * r)
        
std::vector<double> ClassicNoiseGenerator::generate (double x, double angle, bool calcDerivatives) const
{
    std::vector<double> result;
    
    // First, calculate the nearest whole indices next to the point.
    // If x is not negative, this makes sure that ix0 is less than or
    // equal to x and ix1 is greater than x.
    // If x is negative, this makes sure that ix0 is less than x and
    // ix1 is greater to or equal to x.
    int ix0 = dtoiflr(x);
    int ix1 = ix0 + 1;
    
    // Then wrap the indices so the random values will form a cycle.
    ix0 = cyclicIndex(ix0);
    ix1 = cyclicIndex(ix1);
    
    // Then calculate vectors to the point from each index.
    double x0 = x - ix0;
    double x1 = x0 - 1.0;

    // Define and calculate smooth blends and their derivative
    // starting with the letter s.
    double sx = blend(x0);
    
    // Define and calculate nodes.
    double a, b;
    a = node(ix0, x0);
    b = node(ix1, x1);
    
    // This method returns:
    //   lerp(a, b, sx)
    // which substitutes to create:
    //   a(1 - sx) + b(sx))
    // which becomes:
    //   a - a(sx) + b(sx)
    // and after regrouping:
    // ==>  a + sx(b - a)
    // The derivative is:
    // ==>  sx'(b - a)
    
    // Define and calculate the constants needed.
    double c0 = b - a;
    
    result.push_back(a + sx * c0);
    
    if (calcDerivatives)
    {
        // Calculate smooth blend derivatives
        // starting with the letters ds.
        double dsx = derivativeBlend(x0);
        
        result.push_back(dsx * c0);
    }
    
    return result;
}

std::vector<double> ClassicNoiseGenerator::generate (double x, double y, double angle, bool calcDerivatives) const
{
    std::vector<double> result;
    
    int ix0 = dtoiflr(x);
    int ix1 = ix0 + 1;
    int iy0 = dtoiflr(y);
    int iy1 = iy0 + 1;
    
    double fracX0 = x - ix0;
    double fracX1 = fracX0 - 1.0;
    double fracY0 = y - iy0;
    double fracY1 = fracY0 - 1.0;
    
    Hash::FNVHashGenerator32 fnvGen;
    Hash::HashAdapter<8> adapt8(fnvGen);

    int hashX0 = adapt8.getHash(ix0, 0);
    int hashX1 = adapt8.getHash(ix1, 0);
    int hashY0 = adapt8.getHash(iy0, 0);
    int hashY1 = adapt8.getHash(iy1, 0);

    double alphaX = blend(fracX0);
    double alphaY = blend(fracY0);
    
    double node1a, node1b, node2a, node2b;
    node2a = node(hashX0 ^ hashY0, fracX0, fracY0);
    node2b = node(hashX0 ^ hashY1, fracX0, fracY1);
    node1a = lerp(node2a, node2b, alphaY);
    
    node2a = node(hashX1 ^ hashY0, fracX1, fracY0);
    node2b = node(hashX1 ^ hashY1, fracX1, fracY1);
    node1b = lerp(node2a, node2b, alphaY);
    
    result.push_back(lerp(node1a, node1b, alphaX));
    
    return result;
}

std::vector<double> ClassicNoiseGenerator::generate (double x, double y, double z, double angle, bool calcDerivatives) const
{
    std::vector<double> result;
    
    int ix0 = dtoiflr(x);
    int ix1 = ix0 + 1;
    int iy0 = dtoiflr(y);
    int iy1 = iy0 + 1;
    int iz0 = dtoiflr(z);
    int iz1 = iz0 + 1;
    
    double fracX0 = x - ix0;
    double fracX1 = fracX0 - 1.0;
    double fracY0 = y - iy0;
    double fracY1 = fracY0 - 1.0;
    double fracZ0 = z - iz0;
    double fracZ1 = fracZ0 - 1.0;
    
    Hash::FNVHashGenerator32 fnvGen;
    Hash::HashAdapter<8> adapt8(fnvGen);

    int hashX0 = adapt8.getHash(ix0, 0);
    int hashX1 = adapt8.getHash(ix1, 0);
    int hashY0 = adapt8.getHash(iy0, 0);
    int hashY1 = adapt8.getHash(iy1, 0);
    int hashZ0 = adapt8.getHash(iz0, 0);
    int hashZ1 = adapt8.getHash(iz1, 0);

    double alphaX = blend(fracX0);
    double alphaY = blend(fracY0);
    double alphaZ = blend(fracZ0);
    
    double node1a, node1b, node2a, node2b, node3a, node3b;
    node3a = node(hashX0 ^ hashY0 ^ hashZ0, fracX0, fracY0, fracZ0);
    node3b = node(hashX0 ^ hashY0 ^ hashZ1, fracX0, fracY0, fracZ1);
    node2a = lerp(node3a, node3b, alphaZ);
    
    node3a = node(hashX0 ^ hashY1 ^ hashZ0, fracX0, fracY1, fracZ0);
    node3b = node(hashX0 ^ hashY1 ^ hashZ1, fracX0, fracY1, fracZ1);
    node2b = lerp(node3a, node3b, alphaZ);
    node1a = lerp(node2a, node2b, alphaY);
    
    node3a = node(hashX1 ^ hashY0 ^ hashZ0, fracX1, fracY0, fracZ0);
    node3b = node(hashX1 ^ hashY0 ^ hashZ1, fracX1, fracY0, fracZ1);
    node2a = lerp(node3a, node3b, alphaZ);
    
    node3a = node(hashX1 ^ hashY1 ^ hashZ0, fracX1, fracY1, fracZ0);
    node3b = node(hashX1 ^ hashY1 ^ hashZ1, fracX1, fracY1, fracZ1);
    node2b = lerp(node3a, node3b, alphaZ);
    node1b = lerp(node2a, node2b, alphaY);
    
    result.push_back(lerp(node1a, node1b, alphaX));
    
    return result;
}

std::vector<double> ClassicNoiseGenerator::generate (double x, double y, double z, double w, double angle, bool calcDerivatives) const
{
    std::vector<double> result;
    
    int ix0 = dtoiflr(x);
    int ix1 = ix0 + 1;
    int iy0 = dtoiflr(y);
    int iy1 = iy0 + 1;
    int iz0 = dtoiflr(z);
    int iz1 = iz0 + 1;
    int iw0 = dtoiflr(w);
    int iw1 = iw0 + 1;
    
    double fracX0 = x - ix0;
    double fracX1 = fracX0 - 1.0;
    double fracY0 = y - iy0;
    double fracY1 = fracY0 - 1.0;
    double fracZ0 = z - iz0;
    double fracZ1 = fracZ0 - 1.0;
    double fracW0 = w - iw0;
    double fracW1 = fracW0 - 1.0;
    
    Hash::FNVHashGenerator32 fnvGen;
    Hash::HashAdapter<8> adapt8(fnvGen);

    int hashX0 = adapt8.getHash(ix0, 0);
    int hashX1 = adapt8.getHash(ix1, 0);
    int hashY0 = adapt8.getHash(iy0, 0);
    int hashY1 = adapt8.getHash(iy1, 0);
    int hashZ0 = adapt8.getHash(iz0, 0);
    int hashZ1 = adapt8.getHash(iz1, 0);
    int hashW0 = adapt8.getHash(iw0, 0);
    int hashW1 = adapt8.getHash(iw1, 0);

    double alphaX = blend(fracX0);
    double alphaY = blend(fracY0);
    double alphaZ = blend(fracZ0);
    double alphaW = blend(fracW0);
    
    double node1a, node1b, node2a, node2b, node3a, node3b, node4a, node4b;
    node4a = node(hashX0 ^ hashY0 ^ hashZ0 ^ hashW0, fracX0, fracY0, fracZ0, fracW0);
    node4b = node(hashX0 ^ hashY0 ^ hashZ0 ^ hashW1, fracX0, fracY0, fracZ0, fracW1);
    node3a = lerp(node4a, node4b, alphaW);
    
    node4a = node(hashX0 ^ hashY0 ^ hashZ1 ^ hashW0, fracX0, fracY0, fracZ1, fracW0);
    node4b = node(hashX0 ^ hashY0 ^ hashZ1 ^ hashW1, fracX0, fracY0, fracZ1, fracW1);
    node3b = lerp(node4a, node4b, alphaW);
    node2a = lerp(node3a, node3b, alphaZ);
    
    node4a = node(hashX0 ^ hashY1 ^ hashZ0 ^ hashW0, fracX0, fracY1, fracZ0, fracW0);
    node4b = node(hashX0 ^ hashY1 ^ hashZ0 ^ hashW1, fracX0, fracY1, fracZ0, fracW1);
    node3a = lerp(node4a, node4b, alphaW);
    
    node4a = node(hashX0 ^ hashY1 ^ hashZ1 ^ hashW0, fracX0, fracY1, fracZ1, fracW0);
    node4b = node(hashX0 ^ hashY1 ^ hashZ1 ^ hashW1, fracX0, fracY1, fracZ1, fracW1);
    node3b = lerp(node4a, node4b, alphaW);
    node2b = lerp(node3a, node3b, alphaZ);
    node1a = lerp(node2a, node2b, alphaY);

    node4a = node(hashX1 ^ hashY0 ^ hashZ0 ^ hashW0, fracX1, fracY0, fracZ0, fracW0);
    node4b = node(hashX1 ^ hashY0 ^ hashZ0 ^ hashW1, fracX1, fracY0, fracZ0, fracW1);
    node3a = lerp(node4a, node4b, alphaW);
    
    node4a = node(hashX1 ^ hashY0 ^ hashZ1 ^ hashW0, fracX1, fracY0, fracZ1, fracW0);
    node4b = node(hashX1 ^ hashY0 ^ hashZ1 ^ hashW1, fracX1, fracY0, fracZ1, fracW1);
    node3b = lerp(node4a, node4b, alphaW);
    node2a = lerp(node3a, node3b, alphaZ);
    
    node4a = node(hashX1 ^ hashY1 ^ hashZ0 ^ hashW0, fracX1, fracY1, fracZ0, fracW0);
    node4b = node(hashX1 ^ hashY1 ^ hashZ0 ^ hashW1, fracX1, fracY1, fracZ0, fracW1);
    node3a = lerp(node4a, node4b, alphaW);
    
    node4a = node(hashX1 ^ hashY1 ^ hashZ1 ^ hashW0, fracX1, fracY1, fracZ1, fracW0);
    node4b = node(hashX1 ^ hashY1 ^ hashZ1 ^ hashW1, fracX1, fracY1, fracZ1, fracW1);
    node3b = lerp(node4a, node4b, alphaW);
    node2b = lerp(node3a, node3b, alphaZ);
    node1b = lerp(node2a, node2b, alphaY);
    
    result.push_back(lerp(node1a, node1b, alphaX));
    
    return result;
}

} // namespace Noise
} // namespace TUCUT
