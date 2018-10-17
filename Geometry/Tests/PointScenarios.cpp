//
//  PointScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 10/14/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "../../Test/Test.h"

#include "../Point.h"

using namespace std;
using namespace TUCUT;

SCENARIO( Point, "Construction/Normal", "unit,geometry", "Points can be constructed." )
{
    Geometry::Point1i pt1;
    Geometry::Point2i pt2;
    Geometry::Point3i pt3;
    Geometry::Point4i pt4;
    Geometry::Point1i pt5(123);
    Geometry::Point2i pt6(123, 124);
    Geometry::Point3i pt7(123, 124, 125);
    Geometry::Point4i pt8(123, 124, 125, 126);
    
    VERIFY_EQUAL(0, pt1.x);

    VERIFY_EQUAL(0, pt2.x);
    VERIFY_EQUAL(0, pt2.y);

    VERIFY_EQUAL(0, pt3.x);
    VERIFY_EQUAL(0, pt3.y);
    VERIFY_EQUAL(0, pt3.z);

    VERIFY_EQUAL(0, pt4.x);
    VERIFY_EQUAL(0, pt4.y);
    VERIFY_EQUAL(0, pt4.z);
    VERIFY_EQUAL(0, pt4.w);
    
    VERIFY_EQUAL(123, pt5.x);
    
    VERIFY_EQUAL(123, pt6.x);
    VERIFY_EQUAL(124, pt6.y);
    
    VERIFY_EQUAL(123, pt7.x);
    VERIFY_EQUAL(124, pt7.y);
    VERIFY_EQUAL(125, pt7.z);
    
    VERIFY_EQUAL(123, pt8.x);
    VERIFY_EQUAL(124, pt8.y);
    VERIFY_EQUAL(125, pt8.z);
    VERIFY_EQUAL(126, pt8.w);
}
