//
//  BoundsScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 10/25/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "../../Test/Test.h"

#include "../Bounds.h"

using namespace std;
using namespace TUCUT;

SCENARIO( Bounds, "Construction/Normal", "unit,math", "Bounds can be constructed." )
{
    Math::Bounds1i bounds1;
    Math::Bounds2i bounds2;
    Math::Bounds3i bounds3;
    Math::Bounds4i bounds4;
    Math::Bounds1i bounds5(123, 5);
    Math::Bounds2i bounds6(123, 124, 5);
    Math::Bounds3i bounds7(123, 124, 125, 5);
    Math::Bounds4i bounds8(123, 124, 125, 126, 5);
    
    VERIFY_EQUAL(0, bounds1.location().x);
    VERIFY_EQUAL(0, bounds1.extent());

    VERIFY_EQUAL(0, bounds2.location().x);
    VERIFY_EQUAL(0, bounds2.location().y);
    VERIFY_EQUAL(0, bounds2.extent());

    VERIFY_EQUAL(0, bounds3.location().x);
    VERIFY_EQUAL(0, bounds3.location().y);
    VERIFY_EQUAL(0, bounds3.location().z);
    VERIFY_EQUAL(0, bounds3.extent());

    VERIFY_EQUAL(0, bounds4.location().x);
    VERIFY_EQUAL(0, bounds4.location().y);
    VERIFY_EQUAL(0, bounds4.location().z);
    VERIFY_EQUAL(0, bounds4.location().w);
    VERIFY_EQUAL(0, bounds4.extent());

    VERIFY_EQUAL(123, bounds5.location().x);
    VERIFY_EQUAL(5, bounds5.extent());

    VERIFY_EQUAL(123, bounds6.location().x);
    VERIFY_EQUAL(124, bounds6.location().y);
    VERIFY_EQUAL(5, bounds6.extent());

    VERIFY_EQUAL(123, bounds7.location().x);
    VERIFY_EQUAL(124, bounds7.location().y);
    VERIFY_EQUAL(125, bounds7.location().z);
    VERIFY_EQUAL(5, bounds7.extent());

    VERIFY_EQUAL(123, bounds8.location().x);
    VERIFY_EQUAL(124, bounds8.location().y);
    VERIFY_EQUAL(125, bounds8.location().z);
    VERIFY_EQUAL(126, bounds8.location().w);
    VERIFY_EQUAL(5, bounds8.extent());
}

SCENARIO( Bounds, "Construction/Normal", "unit,math", "Bounds can be copy constructed." )
{
    Math::Bounds1i bounds1(123, 5);
    Math::Bounds1i bounds2(bounds1);
    
    VERIFY_EQUAL(bounds1, bounds2);
}

SCENARIO( Bounds, "Operation/Normal", "unit,math", "Bounds can be assigned." )
{
    Math::Bounds1i bounds1(123, 5);
    Math::Bounds1i bounds2(124, 5);
    
    VERIFY_FALSE(bounds1 == bounds2);
    bounds2 = bounds1;
    VERIFY_EQUAL(bounds1, bounds2);
}

SCENARIO( Bounds, "Operation/Normal", "unit,math", "Bounds can add vectors." )
{
    Math::Bounds1i bounds1(1, 10);
    Math::Vector1i vec1(4);
    
    Math::Bounds1i result1 = bounds1 + vec1;
    
    VERIFY_EQUAL(5, result1.location().x);
    VERIFY_EQUAL(10, result1.extent());

    Math::Bounds2i bounds2(1, 2, 10);
    Math::Vector2i vec2(4, 5);
    
    Math::Bounds2i result2 = bounds2 + vec2;
    
    VERIFY_EQUAL(5, result2.location().x);
    VERIFY_EQUAL(7, result2.location().y);
    VERIFY_EQUAL(10, result2.extent());

    Math::Bounds3i bounds3(1, 2, 3, 10);
    Math::Vector3i vec3(4, 5, 7);
    
    Math::Bounds3i result3 = bounds3 + vec3;
    
    VERIFY_EQUAL(5, result3.location().x);
    VERIFY_EQUAL(7, result3.location().y);
    VERIFY_EQUAL(10, result3.location().z);
    VERIFY_EQUAL(10, result3.extent());

    Math::Bounds4i bounds4(1, 2, 3, 5, 10);
    Math::Vector4i vec4(4, 5, 7, 9);
    
    Math::Bounds4i result4 = bounds4 + vec4;
    
    VERIFY_EQUAL(5, result4.location().x);
    VERIFY_EQUAL(7, result4.location().y);
    VERIFY_EQUAL(10, result4.location().z);
    VERIFY_EQUAL(14, result4.location().w);
    VERIFY_EQUAL(10, result4.extent());
}

SCENARIO( Bounds, "Operation/Normal", "unit,math", "Bounds can subtract vectors." )
{
    Math::Bounds1i bounds1(1, 10);
    Math::Vector1i vec1(4);
    
    Math::Bounds1i result1 = bounds1 - vec1;
    
    VERIFY_EQUAL(-3, result1.location().x);
    VERIFY_EQUAL(10, result1.extent());
    
    Math::Bounds2i bounds2(1, 2, 10);
    Math::Vector2i vec2(4, 5);
    
    Math::Bounds2i result2 = bounds2 - vec2;
    
    VERIFY_EQUAL(-3, result2.location().x);
    VERIFY_EQUAL(-3, result2.location().y);
    VERIFY_EQUAL(10, result2.extent());
    
    Math::Bounds3i bounds3(1, 2, 3, 10);
    Math::Vector3i vec3(4, 5, 7);
    
    Math::Bounds3i result3 = bounds3 - vec3;
    
    VERIFY_EQUAL(-3, result3.location().x);
    VERIFY_EQUAL(-3, result3.location().y);
    VERIFY_EQUAL(-4, result3.location().z);
    VERIFY_EQUAL(10, result3.extent());
    
    Math::Bounds4i bounds4(1, 2, 3, 5, 10);
    Math::Vector4i vec4(4, 5, 7, 9);
    
    Math::Bounds4i result4 = bounds4 - vec4;
    
    VERIFY_EQUAL(-3, result4.location().x);
    VERIFY_EQUAL(-3, result4.location().y);
    VERIFY_EQUAL(-4, result4.location().z);
    VERIFY_EQUAL(-4, result4.location().w);
    VERIFY_EQUAL(10, result4.extent());
}

SCENARIO( Bounds, "Operation/Normal", "unit,math", "Bounds can calculate envelope to point." )
{
    Math::Bounds1i bounds1(1, 10);
    Math::Point1i target1(4);
    
    Math::Vector1i result1 = bounds1.envelopeVector(target1);
    
    VERIFY_EQUAL(0, result1.x);
    
    Math::Bounds2i bounds2(1, 2, 10);
    Math::Point2i target2(14, 15);
    
    Math::Vector2i result2 = bounds2.envelopeVector(target2);
    
    VERIFY_EQUAL(-3, result2.x);
    VERIFY_EQUAL(-3, result2.y);
    
    Math::Bounds3i bounds3(11, 12, 13, 10);
    Math::Point3i target3(-4, -5, -9);
    
    Math::Vector3i result3 = bounds3.envelopeVector(target3);
    
    VERIFY_EQUAL(5, result3.x);
    VERIFY_EQUAL(7, result3.y);
    VERIFY_EQUAL(12, result3.z);
    
    Math::Bounds4i bounds4(10, 20, 30, 50, 10);
    Math::Point4i target4(-4, 15, 27, 65);
    
    Math::Vector4i result4 = bounds4.envelopeVector(target4);
    
    VERIFY_EQUAL(4, result4.x);
    VERIFY_EQUAL(0, result4.y);
    VERIFY_EQUAL(0, result4.z);
    VERIFY_EQUAL(-5, result4.w);
}

SCENARIO( Bounds, "Operation/Normal", "unit,math", "Bounds can calculate envelope to bounds." )
{
    Math::Bounds1i bounds1(1, 10);
    Math::Bounds1i target1(4, 1);
    
    Math::Vector1i result1 = bounds1.envelopeVector(target1);
    
    VERIFY_EQUAL(0, result1.x);
    
    Math::Bounds2i bounds2(1, 2, 10);
    Math::Bounds2i target2(14, 15, 5);
    
    Math::Vector2i result2 = bounds2.envelopeVector(target2);
    
    VERIFY_EQUAL(-3, result2.x);
    VERIFY_EQUAL(-3, result2.y);
    
    Math::Bounds3i bounds3(11, 12, 13, 10);
    Math::Bounds3i target3(-4, -5, -9, 15);
    
    Math::Vector3i result3 = bounds3.envelopeVector(target3);
    
    VERIFY_EQUAL(5, result3.x);
    VERIFY_EQUAL(7, result3.y);
    VERIFY_EQUAL(12, result3.z);
    
    Math::Bounds4i bounds4(10, 20, 30, 50, 10);
    Math::Bounds4i target4(-4, 15, 27, 65, 20);
    
    Math::Vector4i result4 = bounds4.envelopeVector(target4);
    
    VERIFY_EQUAL(4, result4.x);
    VERIFY_EQUAL(0, result4.y);
    VERIFY_EQUAL(0, result4.z);
    VERIFY_EQUAL(-5, result4.w);
}

SCENARIO( Bounds, "Operation/Normal", "unit,math", "Bounds can calculate overlap to bounds." )
{
    Math::Bounds1i bounds1(1, 10);
    Math::Bounds1i target1(4, 1);
    
    Math::Vector1i result1 = bounds1.overlapVector(target1);
    
    VERIFY_EQUAL(0, result1.x);
    
    Math::Bounds2i bounds2(1, 2, 10);
    Math::Bounds2i target2(14, 18, 5);
    
    Math::Vector2i result2 = bounds2.overlapVector(target2);
    
    VERIFY_EQUAL(0, result2.x);
    VERIFY_EQUAL(-1, result2.y);
    
    Math::Bounds3i bounds3(11, 12, 13, 10);
    Math::Bounds3i target3(-20, -5, 40, 15);
    
    Math::Vector3i result3 = bounds3.overlapVector(target3);
    
    VERIFY_EQUAL(6, result3.x);
    VERIFY_EQUAL(0, result3.y);
    VERIFY_EQUAL(-2, result3.z);
    
    Math::Bounds4i bounds4(10, 20, 30, 50, 10);
    Math::Bounds4i target4(-30, -9, 59, 85, 20);
    
    Math::Vector4i result4 = bounds4.overlapVector(target4);
    
    VERIFY_EQUAL(10, result4.x);
    VERIFY_EQUAL(0, result4.y);
    VERIFY_EQUAL(0, result4.z);
    VERIFY_EQUAL(-5, result4.w);
}
