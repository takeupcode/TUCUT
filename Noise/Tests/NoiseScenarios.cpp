//
//  NoiseScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 10/8/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <fstream>
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
    
    const uint32_t width = 512, height = 512;
    double *noiseMap = new double[width * height];
    size_t layers = 3;

    for (uint32_t y = 0; y < height; ++y)
    {
        for (uint32_t x = 0; x < width; ++x)
        {
            noiseMap[y * width + x] = noise.generate(static_cast<double>(x) / 64, static_cast<double>(y) / 64, layers)[0];
        }
    }

    std::ofstream ofs;
    ofs.open("./noise.ppm", std::ios::out | std::ios::binary | std::ios::trunc);
    ofs << "P6\n" << width << " " << height << "\n255\n";
    double min = 0.0;
    double max = 0.0;
    for (unsigned i = 0; i < width * height; ++i)
    {
        if (noiseMap[i] < min)
        {
            min = noiseMap[i];
        }
        else if (noiseMap[i] > max)
        {
            max = noiseMap[i];
        }
        unsigned char n = static_cast<unsigned char>((noiseMap[i] + .8) / 1.6 * 255);
        ofs << n << n << n;
    }
    ofs.close();
    std::cout << "min=" << min << "\nmax=" << max << "\n";
    
    delete[] noiseMap;
}
