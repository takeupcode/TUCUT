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
    Math::Point1i pt1a;
    Math::Point2i pt2a;
    Math::Point3i pt3a;
    Math::Point4i pt4a;
    Math::Point1i pt1b(123);
    Math::Point2i pt2b(123, 124);
    Math::Point3i pt3b(123, 124, 125);
    Math::Point4i pt4b(123, 124, 125, 126);
    
    VERIFY_EQUAL(0, pt1a.x);

    VERIFY_EQUAL(0, pt2a.x);
    VERIFY_EQUAL(0, pt2a.y);

    VERIFY_EQUAL(0, pt3a.x);
    VERIFY_EQUAL(0, pt3a.y);
    VERIFY_EQUAL(0, pt3a.z);

    VERIFY_EQUAL(0, pt4a.x);
    VERIFY_EQUAL(0, pt4a.y);
    VERIFY_EQUAL(0, pt4a.z);
    VERIFY_EQUAL(0, pt4a.w);
    
    VERIFY_EQUAL(123, pt1b.x);
    
    VERIFY_EQUAL(123, pt2b.x);
    VERIFY_EQUAL(124, pt2b.y);
    
    VERIFY_EQUAL(123, pt3b.x);
    VERIFY_EQUAL(124, pt3b.y);
    VERIFY_EQUAL(125, pt3b.z);
    
    VERIFY_EQUAL(123, pt4b.x);
    VERIFY_EQUAL(124, pt4b.y);
    VERIFY_EQUAL(125, pt4b.z);
    VERIFY_EQUAL(126, pt4b.w);
}

SCENARIO( Point, "Construction/Normal", "unit,math", "Points can be copy constructed." )
{
    Math::Point1i pt1a(123);
    Math::Point1i pt1b(pt1a);
    
    VERIFY_EQUAL(pt1a, pt1b);
    
    Math::Point2i pt2a(123, 124);
    Math::Point2i pt2b(pt2a);
    
    VERIFY_EQUAL(pt2a, pt2b);
    
    Math::Point3i pt3a(123, 124, 125);
    Math::Point3i pt3b(pt3a);
    
    VERIFY_EQUAL(pt3a, pt3b);
    
    Math::Point4i pt4a(123, 124, 125, 126);
    Math::Point4i pt4b(pt4a);
    
    VERIFY_EQUAL(pt4a, pt4b);
}

SCENARIO( Point, "Operation/Normal", "unit,math", "Points can be assigned." )
{
    Math::Point1i pt1a(123);
    Math::Point1i pt1b(124);
    
    VERIFY_FALSE(pt1a == pt1b);
    pt1b = pt1a;
    VERIFY_EQUAL(pt1a, pt1b);
    
    Math::Point2i pt2a(123, 124);
    Math::Point2i pt2b(124, 125);
    
    VERIFY_FALSE(pt2a == pt2b);
    pt2b = pt2a;
    VERIFY_EQUAL(pt2a, pt2b);
    
    Math::Point3i pt3a(123, 124, 125);
    Math::Point3i pt3b(124, 125, 126);
    
    VERIFY_FALSE(pt3a == pt3b);
    pt3b = pt3a;
    VERIFY_EQUAL(pt3a, pt3b);
    
    Math::Point4i pt4a(123, 124, 125, 126);
    Math::Point4i pt4b(124, 125, 126, 127);
    
    VERIFY_FALSE(pt4a == pt4b);
    pt4b = pt4a;
    VERIFY_EQUAL(pt4a, pt4b);
}

SCENARIO( Point, "Operation/Normal", "unit,math", "Points can be subtracted and interact with vector." )
{
    Math::Point1i pt1a(123);
    Math::Point1i pt1b(124);
    Math::Vector1i vec1 = pt1b - pt1a;
    VERIFY_EQUAL(1, vec1.x);
    
    Math::Point1i pt1c = pt1a + vec1;
    VERIFY_EQUAL(pt1b, pt1c);
    
    Math::Point1i pt1d = pt1b - vec1;
    VERIFY_EQUAL(pt1a, pt1d);

    Math::Point2i pt2a(123, 123);
    Math::Point2i pt2b(124, 124);
    Math::Vector2i vec2 = pt2b - pt2a;
    VERIFY_EQUAL(1, vec2.x);
    VERIFY_EQUAL(1, vec2.y);
    
    Math::Point2i pt2c = pt2a + vec2;
    VERIFY_EQUAL(pt2b, pt2c);
    
    Math::Point2i pt2d = pt2b - vec2;
    VERIFY_EQUAL(pt2a, pt2d);

    Math::Point3i pt3a(123, 123, 123);
    Math::Point3i pt3b(124, 124, 124);
    Math::Vector3i vec3 = pt3b - pt3a;
    VERIFY_EQUAL(1, vec3.x);
    VERIFY_EQUAL(1, vec3.y);
    VERIFY_EQUAL(1, vec3.z);

    Math::Point3i pt3c = pt3a + vec3;
    VERIFY_EQUAL(pt3b, pt3c);
    
    Math::Point3i pt3d = pt3b - vec3;
    VERIFY_EQUAL(pt3a, pt3d);

    Math::Point4i pt4a(123, 123, 123, 123);
    Math::Point4i pt4b(124, 124, 124, 124);
    Math::Vector4i vec4 = pt4b - pt4a;
    VERIFY_EQUAL(1, vec4.x);
    VERIFY_EQUAL(1, vec4.y);
    VERIFY_EQUAL(1, vec4.z);
    VERIFY_EQUAL(1, vec4.w);

    Math::Point4i pt4c = pt4a + vec4;
    VERIFY_EQUAL(pt4b, pt4c);
    
    Math::Point4i pt4d = pt4b - vec4;
    VERIFY_EQUAL(pt4a, pt4d);
}

SCENARIO( Point, "Operation/Normal", "unit,math", "Points can convert to vector." )
{
    Math::Point1i pt1(123);
    Math::Vector1i vec1 = pt1;
    
    VERIFY_EQUAL(123, vec1.x);

    Math::Point2i pt2(123, 123);
    Math::Vector2i vec2 = pt2;
    
    VERIFY_EQUAL(123, vec2.x);
    VERIFY_EQUAL(123, vec2.y);

    Math::Point3i pt3(123, 123, 123);
    Math::Vector3i vec3 = pt3;
    
    VERIFY_EQUAL(123, vec3.x);
    VERIFY_EQUAL(123, vec3.y);
    VERIFY_EQUAL(123, vec3.z);

    Math::Point4i pt4(123, 123, 123, 123);
    Math::Vector4i vec4 = pt4;
    
    VERIFY_EQUAL(123, vec4.x);
    VERIFY_EQUAL(123, vec4.y);
    VERIFY_EQUAL(123, vec4.z);
    VERIFY_EQUAL(123, vec4.w);
}
