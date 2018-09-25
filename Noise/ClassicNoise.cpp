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
        
std::vector<double> ClassicNoiseGenerator::generate (double x, double angle, bool calcDerivatives) const
{
    std::vector<double> result;
    
    int wholeX0 = dtoiflr(x);
    int wholeX1 = wholeX0 + 1;
    
    double fracX0 = x - wholeX0;
    double fracX1 = fracX0 - 1.0;
    
    Hash::FNVHashGenerator32 fnvGen;
    Hash::HashAdapter<8> adapt8(fnvGen);

    int hashX0 = adapt8.getHash(wholeX0, 0);
    int hashX1 = adapt8.getHash(wholeX1, 0);

    double alphaX = blend(fracX0);
    
    double node1a, node1b;
    node1a = node(hashX0, fracX0);
    node1b = node(hashX1, fracX1);
    
    result.push_back(lerp(node1a, node1b, alphaX));
    
    return result;
}

std::vector<double> ClassicNoiseGenerator::generate (double x, double y, double angle, bool calcDerivatives) const
{
    std::vector<double> result;
    
    int wholeX0 = dtoiflr(x);
    int wholeX1 = wholeX0 + 1;
    int wholeY0 = dtoiflr(y);
    int wholeY1 = wholeY0 + 1;
    
    double fracX0 = x - wholeX0;
    double fracX1 = fracX0 - 1.0;
    double fracY0 = y - wholeY0;
    double fracY1 = fracY0 - 1.0;
    
    Hash::FNVHashGenerator32 fnvGen;
    Hash::HashAdapter<8> adapt8(fnvGen);

    int hashX0 = adapt8.getHash(wholeX0, 0);
    int hashX1 = adapt8.getHash(wholeX1, 0);
    int hashY0 = adapt8.getHash(wholeY0, 0);
    int hashY1 = adapt8.getHash(wholeY1, 0);

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
    
    int wholeX0 = dtoiflr(x);
    int wholeX1 = wholeX0 + 1;
    int wholeY0 = dtoiflr(y);
    int wholeY1 = wholeY0 + 1;
    int wholeZ0 = dtoiflr(z);
    int wholeZ1 = wholeZ0 + 1;
    
    double fracX0 = x - wholeX0;
    double fracX1 = fracX0 - 1.0;
    double fracY0 = y - wholeY0;
    double fracY1 = fracY0 - 1.0;
    double fracZ0 = z - wholeZ0;
    double fracZ1 = fracZ0 - 1.0;
    
    Hash::FNVHashGenerator32 fnvGen;
    Hash::HashAdapter<8> adapt8(fnvGen);

    int hashX0 = adapt8.getHash(wholeX0, 0);
    int hashX1 = adapt8.getHash(wholeX1, 0);
    int hashY0 = adapt8.getHash(wholeY0, 0);
    int hashY1 = adapt8.getHash(wholeY1, 0);
    int hashZ0 = adapt8.getHash(wholeZ0, 0);
    int hashZ1 = adapt8.getHash(wholeZ1, 0);

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
    
    int wholeX0 = dtoiflr(x);
    int wholeX1 = wholeX0 + 1;
    int wholeY0 = dtoiflr(y);
    int wholeY1 = wholeY0 + 1;
    int wholeZ0 = dtoiflr(z);
    int wholeZ1 = wholeZ0 + 1;
    int wholeW0 = dtoiflr(w);
    int wholeW1 = wholeW0 + 1;
    
    double fracX0 = x - wholeX0;
    double fracX1 = fracX0 - 1.0;
    double fracY0 = y - wholeY0;
    double fracY1 = fracY0 - 1.0;
    double fracZ0 = z - wholeZ0;
    double fracZ1 = fracZ0 - 1.0;
    double fracW0 = w - wholeW0;
    double fracW1 = fracW0 - 1.0;
    
    Hash::FNVHashGenerator32 fnvGen;
    Hash::HashAdapter<8> adapt8(fnvGen);

    int hashX0 = adapt8.getHash(wholeX0, 0);
    int hashX1 = adapt8.getHash(wholeX1, 0);
    int hashY0 = adapt8.getHash(wholeY0, 0);
    int hashY1 = adapt8.getHash(wholeY1, 0);
    int hashZ0 = adapt8.getHash(wholeZ0, 0);
    int hashZ1 = adapt8.getHash(wholeZ1, 0);
    int hashW0 = adapt8.getHash(wholeW0, 0);
    int hashW1 = adapt8.getHash(wholeW1, 0);

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
