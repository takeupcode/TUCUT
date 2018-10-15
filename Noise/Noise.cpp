//
//  Noise.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 9/20/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "Noise.h"

#include <random>

#include "NoiseUtil.h"
#include "../Hash/Hash.h"

namespace TUCUT {
namespace Noise {

// This noise code was inspired by the classic Perlin noise. It has some
// differences designed to add more noise at the expense of extra calculations.
// For example, it starts off with a regularly spaced grid but then shifts
// the grid points by a random but deterministic amount based on the grid
// point coordinate hash. The following factor is based on an 8 bit hash.
constexpr double shiftFactor = 0.2 / 255;

// lerp is a method to interpolate a value between two nodes, n1 and n2.
// By using blended values for r, we get a smooth curve. We're not calling
// lerp directly. Instead, we expand the formulas so that we can calculate
// the various constants shared between the noise and the derivatives.
// lerp is defined as: lerp (n1, n2, r)
//   (n1 * (1 - r) + n2 * r)

NoiseGenerator::NoiseGenerator (int seed,
                                double frequency,
                                double amplitude,
                                double lacunarity,
                                double persistence)
: mSeed(seed), mFrequency(frequency), mAmplitude(amplitude), mLacunarity(lacunarity), mPersistence(persistence)
{
    if (mSeed == 0)
    {
        mSeed = std::random_device()();
    }
}

int NoiseGenerator::seed () const
{
    return mSeed;
}

double NoiseGenerator::generate (double x, Geometry::Point1d * offset, size_t layers, Geometry::Point1d * derivative) const
{
    double result;
    
    std::mt19937 rng;
    rng.seed(mSeed);
    // An int distribution seems to be more reliable.
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 10000);

    double frequency = mFrequency;
    double amplitude = mAmplitude;
    double originalX = x;
    double noise = 0.0;
    double dx = 0.0;
    
    for (size_t currentLayer = 0; currentLayer < layers; currentLayer++)
    {
        x = originalX * frequency + dist(rng);
        if (offset)
        {
            x += offset->x;
        }

        // First, calculate the nearest whole unshifted grid coordinates next to each
        // coordinate of the noise point.
        int ix0 = dtoiflr(x);
        int ix1 = ix0 + 1;
        
        // Get hashes for each grid point using the grid coordinates. 1 dimension is
        // easier because we can combine the hash of the dimension and the hash of the
        // grid point because they're the same.
        Hash::FNVHashGenerator32 fnvGen(mSeed);
        Hash::HashAdapter<8> adapt(fnvGen);
        int hp0 = adapt.getHash(ix0);
        int hp1 = adapt.getHash(ix1);

        // These are the grid point coordinates. They might change if the point
        // is determined to be in a different grid cell after shifting.
        double gx0 = ix0;
        double gx1 = ix1;
        gx0 += (hp0 & 1) ? shiftFactor * hp0: -shiftFactor * hp0;
        gx1 += (hp1 & 1) ? shiftFactor * hp1: -shiftFactor * hp1;

        if (x < gx0)
        {
            // We need to use the previous cell.
            --ix0;
            --ix1;
            hp1 = hp0;
            gx1 = gx0;
            hp0 = adapt.getHash(ix0);
            gx0 = ix0;
            gx0 += (hp0 & 1) ? shiftFactor * hp0: -shiftFactor * hp0;
        }
        else if (x > gx1)
        {
            // We need to use the next cell.
            ++ix0;
            ++ix1;
            hp0 = hp1;
            gx0 = gx1;
            hp1 = adapt.getHash(ix1);
            gx1 = ix1;
            gx1 += (hp1 & 1) ? shiftFactor * hp1: -shiftFactor * hp1;
        }

        // Then calculate individual dimension vectors to the noise point
        // from each grid coordinate.
        double x0 = x - gx0;
        double x1 = x - gx1;

        // Define and calculate smooth blends starting with the letter s.
        // Only one blend is needed for each dimension.
        double s = blend(x0 / (gx1 - gx0));
        
        // Define and calculate nodes based on the grid points.
        double a, b;
        a = node(hp0, x0);
        b = node(hp1, x1);
        
        // This method returns:
        //   lerp(a, b, s)
        // which substitutes to create:
        //   a(1 - s) + bs
        // which becomes:
        //   a - as + bs
        // and after regrouping:
        // ==>  a + s(b - a)
        // The derivative is:
        // ==>  s'(b - a)
        
        // Define and calculate the constants needed.
        double c0 = b - a;
        
        noise += amplitude * (a + s * c0);
        
        if (derivative)
        {
            // Calculate smooth blend derivatives
            // starting with the letters ds.
            double ds = derivativeBlend(x0);
            
            dx += amplitude * (ds * c0);
        }
        
        frequency *= mLacunarity;
        amplitude *= mPersistence;
    }
    
    result = noise;
    
    if (derivative)
    {
        derivative->x = dx;
    }

    return result;
}

double NoiseGenerator::generate (double x, double y, Geometry::Point2d * offset, size_t layers, Geometry::Point2d * derivative) const
{
    double result;
    
    std::mt19937 rng;
    rng.seed(mSeed);
    // An int distribution seems to be more reliable.
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 10000);

    double frequency = mFrequency;
    double amplitude = mAmplitude;
    double originalX = x;
    double originalY = y;
    double noise = 0.0;
    double dx = 0.0;
    double dy = 0.0;

    for (size_t currentLayer = 0; currentLayer < layers; currentLayer++)
    {
        x = originalX * frequency + dist(rng);
        y = originalY * frequency + dist(rng);
        if (offset)
        {
            x += offset->x;
            y += offset->y;
        }

        // First, calculate the nearest whole unshifted grid coordinates next to each
        // coordinate of the noise point.
        int ix0 = dtoiflr(x);
        int ix1 = ix0 + 1;
        int iy0 = dtoiflr(y);
        int iy1 = iy0 + 1;

        // Get hashes for each grid point dimension.
        Hash::FNVHashGenerator32 fnvGen(mSeed);
        Hash::HashAdapter<8> adapt(fnvGen);
        int hx0 = adapt.getHash(ix0);
        int hx1 = adapt.getHash(ix1);
        int hy0 = adapt.getHash(iy0);
        int hy1 = adapt.getHash(iy1);

        // These are the grid point coordinates. They might change if the point
        // is determined to be in a different grid cell after shifting.
        double gx0 = ix0;
        double gx1 = ix1;
        double gy0 = iy0;
        double gy1 = iy1;
        gx0 += (hx0 & 1) ? shiftFactor * hx0: -shiftFactor * hx0;
        gx1 += (hx1 & 1) ? shiftFactor * hx1: -shiftFactor * hx1;
        gy0 += (hy0 & 1) ? shiftFactor * hy0: -shiftFactor * hy0;
        gy1 += (hy1 & 1) ? shiftFactor * hy1: -shiftFactor * hy1;

        if (x < gx0)
        {
            // We need to use the previous cell.
            --ix0;
            --ix1;
            hx1 = hx0;
            gx1 = gx0;
            hx0 = adapt.getHash(ix0);
            gx0 = ix0;
            gx0 += (hx0 & 1) ? shiftFactor * hx0: -shiftFactor * hx0;
        }
        else if (x > gx1)
        {
            // We need to use the next cell.
            ++ix0;
            ++ix1;
            hx0 = hx1;
            gx0 = gx1;
            hx1 = adapt.getHash(ix1);
            gx1 = ix1;
            gx1 += (hx1 & 1) ? shiftFactor * hx1: -shiftFactor * hx1;
        }

        if (y < gy0)
        {
            // We need to use the previous cell.
            --iy0;
            --iy1;
            hy1 = hy0;
            gy1 = gy0;
            hy0 = adapt.getHash(iy0);
            gy0 = iy0;
            gy0 += (hy0 & 1) ? shiftFactor * hy0: -shiftFactor * hy0;
        }
        else if (y > gy1)
        {
            // We need to use the next cell.
            ++iy0;
            ++iy1;
            hy0 = hy1;
            gy0 = gy1;
            hy1 = adapt.getHash(iy1);
            gy1 = iy1;
            gy1 += (hy1 & 1) ? shiftFactor * hy1: -shiftFactor * hy1;
        }

        // Then calculate individual dimension vectors to the noise point
        // from each grid coordinate.
        double x0 = x - gx0;
        double x1 = x - gx1;
        double y0 = y - gy0;
        double y1 = y - gy1;

        // Define and calculate smooth blends starting with the letter s.
        // Only one blend is needed for each dimension.
        double s = blend(x0 / (gx1 - gx0));
        double t = blend(y0 / (gy1 - gy0));

        // Get hashes for each grid point using the grid coordinates.
        int hp00 = hx0 + hy0;
        int hp10 = hx1 + hy0;
        int hp01 = hx0 + hy1;
        int hp11 = hx1 + hy1;

        // Define and calculate nodes based on the grid points.
        double a, b, c, d;
        a = node(hp00, x0, y0);
        b = node(hp10, x1, y0);
        c = node(hp01, x0, y1);
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
        //   a - as + bs - at + ast - bst +
        //   ct - cst + dst
        // and after regrouping:
        // ==>  a + s(b - a) + t(c - a) + st(a + d - b - c)
        // The partial derivatives are:
        //      s'(b - a) + s't(a + d - b - c)
        // ==>  s'((b - a) + t(a + d - b - c))
        //
        //      t'(c - a) + st'(a + d - b - c)
        // ==>  t'((c - a) + s(a + d - b - c))

        // Define and calculate the constants needed.
        double c0 = b - a;
        double c1 = c - a;
        double c2 = a + d - b - c;
        
        noise += amplitude * (a + s * c0 + t * c1 + s * t * c2);
        
        if (derivative)
        {
            // Calculate smooth blend derivatives
            // starting with the letters ds.
            double ds = derivativeBlend(x0);
            double dt = derivativeBlend(y0);

            dx += amplitude * (ds * (c0 + t * c2));
            dy += amplitude * (dt * (c1 + s * c2));
        }
        
        frequency *= mLacunarity;
        amplitude *= mPersistence;
    }
    
    result = noise;
    
    if (derivative)
    {
        derivative->x = dx;
        derivative->y = dy;
    }

    return result;
}

double NoiseGenerator::generate (double x, double y, double z, Geometry::Point3d * offset, size_t layers, Geometry::Point3d * derivative) const
{
    double result = 0.0;
    
    
    return result;
}

double NoiseGenerator::generate (double x, double y, double z, double w, Geometry::Point4d * offset, size_t layers, Geometry::Point4d * derivative) const
{
    double result = 0.0;
    
    
    return result;
}

} // namespace Noise
} // namespace TUCUT
