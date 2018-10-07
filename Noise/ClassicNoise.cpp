//
//  ClassicNoise.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 9/20/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "Noise.h"
#include "NoiseUtil.h"

#include "../Hash/Hash.h"

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
    
    // First, calculate the nearest whole grid coordinates next to each
    // coordinate of the noise point.
    int ix0 = dtoiflr(x);
    int ix1 = ix0 + 1;
    
    // Get hashes for each grid point using the grid coordinates.
    Hash::FNVHashGenerator32 fnvGen(mSeed);
    Hash::HashAdapter<5> adapt5(fnvGen);
    int hp0 = adapt5.getHash(ix0);
    int hp1 = adapt5.getHash(ix1);

    // Then calculate individual dimension vectors to the noise point
    // from each grid coordinate.
    double x0 = x - ix0;
    double x1 = x0 - 1.0;

    // Define and calculate smooth blends starting with the letter s.
    // Only one blend is needed for each dimension.
    double s = blend(x0);
    
    // Define and calculate nodes based on the grid points.
    double a, b;
    a = node(hp0, x0);
    b = node(hp1, x1);
    
    // This method returns:
    //   lerp(a, b, s)
    // which substitutes to create:
    //   a(1 - s) + bs)
    // which becomes:
    //   a - as + bs
    // and after regrouping:
    // ==>  a + s(b - a)
    // The derivative is:
    // ==>  s'(b - a)
    
    // Define and calculate the constants needed.
    double c0 = b - a;
    
    result.push_back(a + s * c0);
    
    if (calcDerivatives)
    {
        // Calculate smooth blend derivatives
        // starting with the letters ds.
        double ds = derivativeBlend(x0);
        
        result.push_back(ds * c0);
    }
    
    return result;
}

std::vector<double> ClassicNoiseGenerator::generate (double x, double y, double angle, bool calcDerivatives) const
{
    std::vector<double> result;
    
    // First, calculate the nearest whole grid coordinates next to each
    // coordinate of the noise point.
    int ix0 = dtoiflr(x);
    int ix1 = ix0 + 1;
    int iy0 = dtoiflr(y);
    int iy1 = iy0 + 1;

    // Get hashes for each grid point using the grid coordinates.
    Hash::FNVHashGenerator32 fnvGen(mSeed);
    Hash::HashAdapter<5> adapt5(fnvGen);
    int hp00 = adapt5.getHash(ix0 + iy0);
    int hp01 = adapt5.getHash(ix0 + iy1);
    int hp10 = adapt5.getHash(ix1 + iy0);
    int hp11 = adapt5.getHash(ix1 + iy1);

    // Then calculate individual dimension vectors to the noise point
    // from each grid coordinate.
    double x0 = x - ix0;
    double x1 = x0 - 1.0;
    double y0 = y - iy0;
    double y1 = y0 - 1.0;

    // Define and calculate smooth blends starting with the letter s.
    // Only one blend is needed for each dimension.
    double s = blend(x0);
    double t = blend(y0);

    // Define and calculate nodes based on the grid points.
    double a, b, c, d;
    a = node(hp00, x0, y0);
    b = node(hp01, x0, y1);
    c = node(hp10, x1, y0);
    d = node(hp11, x1, y1);

    // This method returns:
    //   lerp(
    //     lerp(a, b, s),
    //     lerp(c, d, s),
    //     t)
    // which substitutes to create:
    //   (a(1 - s) + bs))(1 - t) +
    //   (c(1 - s) + ds))(t)
    // which becomes:
    //   a - as + bs - (a - as + bs)t +
    //   (c - cs + ds)t
    // which becomes:
    //   a - as + bs - at - ast + bst +
    //   ct - cst + dst
    // and after regrouping:
    // ==>  a + s(b - a) + t(c - a) + st(b + d - a - c)
    // The partial derivatives are:
    //      s'(b - a) + s't(b + d - a - c)
    // ==>  s'((b - a) + t(b + d - a - c))
    //
    //      t'(c - a) + st'(b + d - a - c)
    // ==>  t'((c - a) + s(b + d - a - c))

    // Define and calculate the constants needed.
    double c0 = b - a;
    double c1 = c - a;
    double c2 = b + d - a - c;
    
    result.push_back(a + s * c0 + t * c1 + s * t * c2);
    
    if (calcDerivatives)
    {
        // Calculate smooth blend derivatives
        // starting with the letters ds.
        double ds = derivativeBlend(x0);
        double dt = derivativeBlend(y0);

        result.push_back(ds * (c0 + t * c2));
        result.push_back(dt * (c1 + s * c2));
    }

    return result;
}

std::vector<double> ClassicNoiseGenerator::generate (double x, double y, double z, double angle, bool calcDerivatives) const
{
    std::vector<double> result;
    
    
    return result;
}

std::vector<double> ClassicNoiseGenerator::generate (double x, double y, double z, double w, double angle, bool calcDerivatives) const
{
    std::vector<double> result;
    
    
    return result;
}

} // namespace Noise
} // namespace TUCUT
