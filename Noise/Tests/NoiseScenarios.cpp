//
//  NoiseScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 10/8/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <fstream>
#include <limits>
#include <string>

#include "../../Test/Test.h"

#include "../Noise.h"

using namespace std;
using namespace TUCUT;

SCENARIO( Hash, "Construction/Normal", "unit,hash", "NoiseGenerator can be constructed." )
{
    Noise::NoiseGenerator gen1;
    Noise::NoiseGenerator gen2(123, 3.0);
    Noise::NoiseGenerator gen3(123, 3.0, 4.0);
    Noise::NoiseGenerator gen4(123, 3.0, 4.0, 5.0);
    Noise::NoiseGenerator gen5(123, 3.0, 4.0, 5.0, 6.0);
}

SCENARIO( Hash, "Operation/Normal", "unit,hash", "NoiseGenerator can generate 2D noise." )
{
    Noise::NoiseGenerator noise;
    int seed = noise.seed();
    
    const uint32_t width = 512, height = 512;
    double *noiseMap = new double[width * height];
    size_t layers = 4;

    double min = std::numeric_limits<double>::max();
    double max = std::numeric_limits<double>::min();
    for (uint32_t y = 0; y < height; ++y)
    {
        for (uint32_t x = 0; x < width; ++x)
        {
            double noiseValue = noise.generate(static_cast<double>(x) / 64, static_cast<double>(y) / 64, nullptr, layers);
            noiseMap[y * width + x] = noiseValue;
            
            if (noiseValue < min)
            {
                min = noiseValue;
            }
            else if (noiseValue > max)
            {
                max = noiseValue;
            }
        }
    }
    
    double minMaxShift = -min;
    double minMaxRange = max - min;
    if (minMaxRange == 0)
    {
        minMaxRange = 1;
    }

    std::string fileName = "./noise";
    fileName += std::to_string(seed);
    fileName += ".ppm";
    std::ofstream ofs;
    ofs.open(fileName, std::ios::out | std::ios::binary | std::ios::trunc);
    ofs << "P6\n" << width << " " << height << "\n255\n";
    for (unsigned i = 0; i < width * height; ++i)
    {
        unsigned char n = static_cast<unsigned char>((noiseMap[i] + minMaxShift) / minMaxRange * 255);
        ofs << n << n << n;
    }
    ofs.close();
    
    delete[] noiseMap;
}
