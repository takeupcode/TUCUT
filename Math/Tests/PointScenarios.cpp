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

SCENARIO( Point, "Construction/Normal", "unit,math", "Points can be constructed." )
{
    Math::Point1i pt1;
    Math::Point2i pt2;
    Math::Point3i pt3;
    Math::Point4i pt4;
    Math::Point1i pt5(123);
    Math::Point2i pt6(123, 124);
    Math::Point3i pt7(123, 124, 125);
    Math::Point4i pt8(123, 124, 125, 126);
    
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

SCENARIO( Point, "Construction/Normal", "unit,math", "Points can be copy constructed." )
{
    Math::Point1i pt1(123);
    Math::Point1i pt2(pt1);
    
    VERIFY_EQUAL(pt1, pt2);
}

SCENARIO( Point, "Operation/Normal", "unit,math", "Points can be assigned." )
{
    Math::Point1i pt1(123);
    Math::Point1i pt2(124);
    
    VERIFY_FALSE(pt1 == pt2);
    pt2 = pt1;
    VERIFY_EQUAL(pt1, pt2);
}

SCENARIO( Point, "Operation/Normal", "unit,math", "Points can be subtracted and interact with vector." )
{
    Math::Point2i pt1(123, 123);
    Math::Point2i pt2(124, 124);
    
    Math::Vector2i diff = pt2 - pt1;

    VERIFY_EQUAL(1, diff.x);
    VERIFY_EQUAL(1, diff.y);
    
    Math::Point2i pt3 = pt1 + diff;;

    VERIFY_EQUAL(pt2, pt3);
    
    Math::Point2i pt4 = pt2 - diff;;
    
    VERIFY_EQUAL(pt1, pt4);
}

SCENARIO( Point, "Operation/Normal", "unit,math", "Points can convert to vector." )
{
    Math::Point2i pt1(123, 123);
    
    Math::Vector2i diff = pt1;
    
    VERIFY_EQUAL(123, diff.x);
    VERIFY_EQUAL(123, diff.y);
}
