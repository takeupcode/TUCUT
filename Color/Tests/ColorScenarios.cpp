//
//  ColorScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 10/17/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "../../Test/Test.h"

#include "../Color.h"

using namespace std;
using namespace TUCUT;

SCENARIO( Color, "Operation/Normal", "unit,geometry", "Colors can be lerped." )
{
    Color::ColorRGB indigo = Color::ColorRGB::createIndigo();
    Color::ColorRGB silver = Color::ColorRGB::createSilver();
    Color::ColorRGB lerpedColor = Color::lerpColor(indigo, silver, 0.5);
    
    VERIFY_EQUAL(133, lerpedColor.red());
    VERIFY_EQUAL(96, lerpedColor.green());
    VERIFY_EQUAL(161, lerpedColor.blue());
    VERIFY_EQUAL(255, lerpedColor.alpha());
}
