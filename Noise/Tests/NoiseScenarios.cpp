//
//  NoiseScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 9/24/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "../../Test/Test.h"

#include "../Noise.h"

using namespace std;
using namespace TUCUT;

SCENARIO( Noise, "Construction/Normal", "unit,noise", "Noise generators can be constructed." )
{
    Noise::ClassicNoiseGenerator classicGen;
    Noise::SimpleNoiseGenerator simpleGen;
}

SCENARIO( Noise, "Operation/Normal", "unit,noise", "Classic generator can generate 1d noise." )
{
    Noise::ClassicNoiseGenerator classicGen;
    
    double noise0 = classicGen.generate(0.0)[0];
    double noise1 = classicGen.generate(1.0)[0];
    
    VERIFY_FALSE(noise0 == noise1);
}
