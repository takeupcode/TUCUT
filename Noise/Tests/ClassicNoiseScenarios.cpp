//
//  ClassicNoiseScenarios.cpp
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

SCENARIO( Hash, "Construction/Normal", "unit,hash", "ClassicNoiseGenerator can be constructed." )
{
    Noise::ClassicNoiseGenerator gen1;
    Noise::ClassicNoiseGenerator gen2(123, 3.0);
    Noise::ClassicNoiseGenerator gen3(123, 3.0, 4.0);
    Noise::ClassicNoiseGenerator gen4(123, 3.0, 4.0, 5.0);
    Noise::ClassicNoiseGenerator gen5(123, 3.0, 4.0, 5.0, 6.0);
}

SCENARIO( Hash, "Operation/Normal", "unit,hash", "ClassicNoiseGenerator can generate 2D noise." )
{
    Noise::ClassicNoiseGenerator noise;
    
    const uint32_t width = 512, height = 512;
    double *noiseMap = new double[width * height];
    
    for (uint32_t y = 0; y < height; ++y)
    {
        for (uint32_t x = 0; x < width; ++x)
        {
            noiseMap[y * width + x] = noise.generate(static_cast<double>(x) / 128, static_cast<double>(y) /128)[0];
        }
    }
    std::cout << "(" << 10 << ", " << 0 << ")=" << noiseMap[0 * width + 10] << "\n";
    std::cout << "(" << 11 << ", " << 0 << ")=" << noiseMap[0 * width + 11] << "\n";
    std::cout << "(" << 12 << ", " << 0 << ")=" << noiseMap[0 * width + 12] << "\n";
    std::cout << "(" << 13 << ", " << 0 << ")=" << noiseMap[0 * width + 13] << "\n";
    std::cout << "(" << 14 << ", " << 0 << ")=" << noiseMap[0 * width + 14] << "\n";
    std::cout << "(" << 15 << ", " << 0 << ")=" << noiseMap[0 * width + 15] << "\n";
    std::cout << "(" << 10 << ", " << 1 << ")=" << noiseMap[1 * width + 10] << "\n";
    std::cout << "(" << 11 << ", " << 1 << ")=" << noiseMap[1 * width + 11] << "\n";
    std::cout << "(" << 12 << ", " << 1 << ")=" << noiseMap[1 * width + 12] << "\n";
    std::cout << "(" << 13 << ", " << 1 << ")=" << noiseMap[1 * width + 13] << "\n";
    std::cout << "(" << 14 << ", " << 1 << ")=" << noiseMap[1 * width + 14] << "\n";
    std::cout << "(" << 15 << ", " << 1 << ")=" << noiseMap[1 * width + 15] << "\n";

    std::ofstream ofs;
    ofs.open("./noise.ppm", std::ios::out | std::ios::binary | std::ios::trunc);
    ofs << "P6\n" << width << " " << height << "\n255\n";
    for (unsigned i = 0; i < width * height; ++i)
    {
        unsigned char n = static_cast<unsigned char>(noiseMap[i] * 255);
        ofs << n << n << n;
    }
    ofs.close();
    
    delete[] noiseMap;
}
