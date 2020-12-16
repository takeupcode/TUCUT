//
//  VectorScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 10/20/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "../Vector.h"

#include "../../Test/Test.h"

using namespace std;
using namespace TUCUT;

SCENARIO( Vector, "Construction/Normal", "unit,math", "Vector can be constructed." )
{
    Math::Vector1i vec1a;
    Math::Vector2i vec2a;
    Math::Vector3i vec3a;
    Math::Vector4i vec4a;
    Math::Vector1i vec1b(123);
    Math::Vector2i vec2b(123, 124);
    Math::Vector3i vec3b(123, 124, 125);
    Math::Vector4i vec4b(123, 124, 125, 126);
    
    VERIFY_EQUAL(0, vec1a.x);
    
    VERIFY_EQUAL(0, vec2a.x);
    VERIFY_EQUAL(0, vec2a.y);
    
    VERIFY_EQUAL(0, vec3a.x);
    VERIFY_EQUAL(0, vec3a.y);
    VERIFY_EQUAL(0, vec3a.z);
    
    VERIFY_EQUAL(0, vec4a.x);
    VERIFY_EQUAL(0, vec4a.y);
    VERIFY_EQUAL(0, vec4a.z);
    VERIFY_EQUAL(0, vec4a.w);
    
    VERIFY_EQUAL(123, vec1b.x);
    
    VERIFY_EQUAL(123, vec2b.x);
    VERIFY_EQUAL(124, vec2b.y);
    
    VERIFY_EQUAL(123, vec3b.x);
    VERIFY_EQUAL(124, vec3b.y);
    VERIFY_EQUAL(125, vec3b.z);
    
    VERIFY_EQUAL(123, vec4b.x);
    VERIFY_EQUAL(124, vec4b.y);
    VERIFY_EQUAL(125, vec4b.z);
    VERIFY_EQUAL(126, vec4b.w);
}

SCENARIO( Vector, "Construction/Normal", "unit,math", "Vector can be copy constructed." )
{
    Math::Vector1i vec1a(123);
    Math::Vector1i vec1b(vec1a);
    
    VERIFY_EQUAL(vec1a, vec1b);
    
    Math::Vector2i vec2a(123, 124);
    Math::Vector2i vec2b(vec2a);
    
    VERIFY_EQUAL(vec2a, vec2b);
    
    Math::Vector3i vec3a(123, 124, 125);
    Math::Vector3i vec3b(vec3a);
    
    VERIFY_EQUAL(vec3a, vec3b);
    
    Math::Vector4i vec4a(123, 124, 125, 126);
    Math::Vector4i vec4b(vec4a);
    
    VERIFY_EQUAL(vec4a, vec4b);
}

SCENARIO( Vector, "Construction/Normal", "unit,math", "Vector can be unit constructed." )
{
    Math::Vector1i vec1a = Math::Vector1i::one();
    Math::Vector1d vec1b = Math::Vector1d::one();
    
    VERIFY_EQUAL(1, vec1a.x);
    VERIFY_EQUAL(1.0, vec1b.x);

    Math::Vector2i vec2a = Math::Vector2i::one();
    Math::Vector2d vec2b = Math::Vector2d::one();
    
    VERIFY_EQUAL(1, vec2a.x);
    VERIFY_EQUAL(1, vec2a.y);
    VERIFY_EQUAL(1.0, vec2b.x);
    VERIFY_EQUAL(1.0, vec2b.y);

    Math::Vector3i vec3a = Math::Vector3i::one();
    Math::Vector3d vec3b = Math::Vector3d::one();
    
    VERIFY_EQUAL(1, vec3a.x);
    VERIFY_EQUAL(1, vec3a.y);
    VERIFY_EQUAL(1, vec3a.z);
    VERIFY_EQUAL(1.0, vec3b.x);
    VERIFY_EQUAL(1.0, vec3b.y);
    VERIFY_EQUAL(1.0, vec3b.z);

    Math::Vector4i vec4a = Math::Vector4i::one();
    Math::Vector4d vec4b = Math::Vector4d::one();
    
    VERIFY_EQUAL(1, vec4a.x);
    VERIFY_EQUAL(1, vec4a.y);
    VERIFY_EQUAL(1, vec4a.z);
    VERIFY_EQUAL(1, vec4a.w);
    VERIFY_EQUAL(1.0, vec4b.x);
    VERIFY_EQUAL(1.0, vec4b.y);
    VERIFY_EQUAL(1.0, vec4b.z);
    VERIFY_EQUAL(1.0, vec4b.w);
}

SCENARIO( Vector, "Construction/Normal", "unit,math", "Vector can be direction constructed." )
{
    Math::Vector1i vec1a = Math::Vector1i::right();
    Math::Vector1i vec1b = Math::Vector1i::left();
    
    VERIFY_EQUAL( 1, vec1a.x);
    VERIFY_EQUAL(-1, vec1b.x);
    
    Math::Vector2i vec2a = Math::Vector2i::right();
    Math::Vector2i vec2b = Math::Vector2i::left();
    Math::Vector2i vec2c = Math::Vector2i::forward();
    Math::Vector2i vec2d = Math::Vector2i::backward();

    VERIFY_EQUAL( 1, vec2a.x);
    VERIFY_EQUAL( 0, vec2a.y);
    VERIFY_EQUAL(-1, vec2b.x);
    VERIFY_EQUAL( 0, vec2b.y);
    VERIFY_EQUAL( 0, vec2c.x);
    VERIFY_EQUAL( 1, vec2c.y);
    VERIFY_EQUAL( 0, vec2d.x);
    VERIFY_EQUAL(-1, vec2d.y);

    Math::Vector3i vec3a = Math::Vector3i::right();
    Math::Vector3i vec3b = Math::Vector3i::left();
    Math::Vector3i vec3c = Math::Vector3i::forward();
    Math::Vector3i vec3d = Math::Vector3i::backward();
    Math::Vector3i vec3e = Math::Vector3i::up();
    Math::Vector3i vec3f = Math::Vector3i::down();

    VERIFY_EQUAL( 1, vec3a.x);
    VERIFY_EQUAL( 0, vec3a.y);
    VERIFY_EQUAL( 0, vec3a.z);
    VERIFY_EQUAL(-1, vec3b.x);
    VERIFY_EQUAL( 0, vec3b.y);
    VERIFY_EQUAL( 0, vec3b.z);
    VERIFY_EQUAL( 0, vec3c.x);
    VERIFY_EQUAL( 1, vec3c.y);
    VERIFY_EQUAL( 0, vec3c.z);
    VERIFY_EQUAL( 0, vec3d.x);
    VERIFY_EQUAL(-1, vec3d.y);
    VERIFY_EQUAL( 0, vec3d.z);
    VERIFY_EQUAL( 0, vec3e.x);
    VERIFY_EQUAL( 0, vec3e.y);
    VERIFY_EQUAL( 1, vec3e.z);
    VERIFY_EQUAL( 0, vec3f.x);
    VERIFY_EQUAL( 0, vec3f.y);
    VERIFY_EQUAL(-1, vec3f.z);

    Math::Vector4i vec4a = Math::Vector4i::right();
    Math::Vector4i vec4b = Math::Vector4i::left();
    Math::Vector4i vec4c = Math::Vector4i::forward();
    Math::Vector4i vec4d = Math::Vector4i::backward();
    Math::Vector4i vec4e = Math::Vector4i::up();
    Math::Vector4i vec4f = Math::Vector4i::down();
    Math::Vector4i vec4g = Math::Vector4i::ana();
    Math::Vector4i vec4h = Math::Vector4i::kata();

    VERIFY_EQUAL( 1, vec4a.x);
    VERIFY_EQUAL( 0, vec4a.y);
    VERIFY_EQUAL( 0, vec4a.z);
    VERIFY_EQUAL( 0, vec4a.w);
    VERIFY_EQUAL(-1, vec4b.x);
    VERIFY_EQUAL( 0, vec4b.y);
    VERIFY_EQUAL( 0, vec4b.z);
    VERIFY_EQUAL( 0, vec4b.w);
    VERIFY_EQUAL( 0, vec4c.x);
    VERIFY_EQUAL( 1, vec4c.y);
    VERIFY_EQUAL( 0, vec4c.z);
    VERIFY_EQUAL( 0, vec4c.w);
    VERIFY_EQUAL( 0, vec4d.x);
    VERIFY_EQUAL(-1, vec4d.y);
    VERIFY_EQUAL( 0, vec4d.z);
    VERIFY_EQUAL( 0, vec4d.w);
    VERIFY_EQUAL( 0, vec4e.x);
    VERIFY_EQUAL( 0, vec4e.y);
    VERIFY_EQUAL( 1, vec4e.z);
    VERIFY_EQUAL( 0, vec4e.w);
    VERIFY_EQUAL( 0, vec4f.x);
    VERIFY_EQUAL( 0, vec4f.y);
    VERIFY_EQUAL(-1, vec4f.z);
    VERIFY_EQUAL( 0, vec4f.w);
    VERIFY_EQUAL( 0, vec4g.x);
    VERIFY_EQUAL( 0, vec4g.y);
    VERIFY_EQUAL( 0, vec4g.z);
    VERIFY_EQUAL( 1, vec4g.w);
    VERIFY_EQUAL( 0, vec4h.x);
    VERIFY_EQUAL( 0, vec4h.y);
    VERIFY_EQUAL( 0, vec4h.z);
    VERIFY_EQUAL(-1, vec4h.w);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector can be assigned." )
{
    Math::Vector1i vec1a(123);
    Math::Vector1i vec1b(124);
    
    VERIFY_FALSE(vec1a == vec1b);
    vec1b = vec1a;
    VERIFY_EQUAL(vec1a, vec1b);
    
    Math::Vector2i vec2a(123, 123);
    Math::Vector2i vec2b(124, 124);
    
    VERIFY_FALSE(vec2a == vec2b);
    vec2b = vec2a;
    VERIFY_EQUAL(vec2a, vec2b);
    
    Math::Vector3i vec3a(123, 123, 123);
    Math::Vector3i vec3b(124, 124, 124);
    
    VERIFY_FALSE(vec3a == vec3b);
    vec3b = vec3a;
    VERIFY_EQUAL(vec3a, vec3b);
    
    Math::Vector4i vec4a(123, 123, 123, 123);
    Math::Vector4i vec4b(124, 124, 124, 124);
    
    VERIFY_FALSE(vec4a == vec4b);
    vec4b = vec4a;
    VERIFY_EQUAL(vec4a, vec4b);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector can be negated." )
{
    Math::Vector1i vec1a(1);
    Math::Vector1i vec1b(-4);
    
    Math::Vector1i neg1a = -vec1a;
    VERIFY_EQUAL(-1, neg1a.x);

    Math::Vector1i neg1b = -vec1b;
    VERIFY_EQUAL(4, neg1b.x);

    Math::Vector2i vec2a(1, 2);
    Math::Vector2i vec2b(-4, -5);
    
    Math::Vector2i neg2a = -vec2a;
    VERIFY_EQUAL(-1, neg2a.x);
    VERIFY_EQUAL(-2, neg2a.y);

    Math::Vector2i neg2b = -vec2b;
    VERIFY_EQUAL(4, neg2b.x);
    VERIFY_EQUAL(5, neg2b.y);

    Math::Vector3i vec3a(1, 2, 3);
    Math::Vector3i vec3b(-4, -5, -6);
    
    Math::Vector3i neg3a = -vec3a;
    VERIFY_EQUAL(-1, neg3a.x);
    VERIFY_EQUAL(-2, neg3a.y);
    VERIFY_EQUAL(-3, neg3a.z);

    Math::Vector3i neg3b = -vec3b;
    VERIFY_EQUAL(4, neg3b.x);
    VERIFY_EQUAL(5, neg3b.y);
    VERIFY_EQUAL(6, neg3b.z);

    Math::Vector4i vec4a(1, 2, 3, 4);
    Math::Vector4i vec4b(-4, -5, -6, -7);
    
    Math::Vector4i neg4a = -vec4a;
    VERIFY_EQUAL(-1, neg4a.x);
    VERIFY_EQUAL(-2, neg4a.y);
    VERIFY_EQUAL(-3, neg4a.z);
    VERIFY_EQUAL(-4, neg4a.w);

    Math::Vector4i neg4b = -vec4b;
    VERIFY_EQUAL(4, neg4b.x);
    VERIFY_EQUAL(5, neg4b.y);
    VERIFY_EQUAL(6, neg4b.z);
    VERIFY_EQUAL(7, neg4b.w);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector can be added." )
{
    Math::Vector1i vec1a(1);
    Math::Vector1i vec1b(4);

    Math::Vector1i sum1 = vec1a + vec1b;
    VERIFY_EQUAL(5, sum1.x);

    Math::Vector2i vec2a(1, 2);
    Math::Vector2i vec2b(4, 5);

    Math::Vector2i sum2 = vec2a + vec2b;
    VERIFY_EQUAL(5, sum2.x);
    VERIFY_EQUAL(7, sum2.y);

    Math::Vector3i vec3a(1, 2, 3);
    Math::Vector3i vec3b(4, 5, 6);

    Math::Vector3i sum3 = vec3a + vec3b;
    VERIFY_EQUAL(5, sum3.x);
    VERIFY_EQUAL(7, sum3.y);
    VERIFY_EQUAL(9, sum3.z);

    Math::Vector4i vec4a(1, 2, 3, 4);
    Math::Vector4i vec4b(4, 5, 6, 7);

    Math::Vector4i sum4 = vec4a + vec4b;
    VERIFY_EQUAL(5, sum4.x);
    VERIFY_EQUAL(7, sum4.y);
    VERIFY_EQUAL(9, sum4.z);
    VERIFY_EQUAL(11, sum4.w);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector can be subtracted." )
{
    Math::Vector1i vec1a(1);
    Math::Vector1i vec1b(4);
    
    Math::Vector1i diff1 = vec1b - vec1a;
    VERIFY_EQUAL(3, diff1.x);
    
    Math::Vector2i vec2a(1, 2);
    Math::Vector2i vec2b(4, 5);
    
    Math::Vector2i diff2 = vec2b - vec2a;
    VERIFY_EQUAL(3, diff2.x);
    VERIFY_EQUAL(3, diff2.y);
    
    Math::Vector3i vec3a(1, 2, 3);
    Math::Vector3i vec3b(4, 5, 6);
    
    Math::Vector3i diff3 = vec3b - vec3a;
    VERIFY_EQUAL(3, diff3.x);
    VERIFY_EQUAL(3, diff3.y);
    VERIFY_EQUAL(3, diff3.z);
    
    Math::Vector4i vec4a(1, 2, 3, 4);
    Math::Vector4i vec4b(4, 5, 6, 7);
    
    Math::Vector4i diff4 = vec4b - vec4a;
    VERIFY_EQUAL(3, diff4.x);
    VERIFY_EQUAL(3, diff4.y);
    VERIFY_EQUAL(3, diff4.z);
    VERIFY_EQUAL(3, diff4.w);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector can be multiplied." )
{
    Math::Vector1i vec1(2);
    
    Math::Vector1i prod1 = vec1 * 3;
    VERIFY_EQUAL(6, prod1.x);

    Math::Vector2i vec2(2, 3);
    
    Math::Vector2i prod2 = vec2 * 3;
    VERIFY_EQUAL(6, prod2.x);
    VERIFY_EQUAL(9, prod2.y);

    Math::Vector3i vec3(2, 3, 4);
    
    Math::Vector3i prod3 = vec3 * 3;
    VERIFY_EQUAL(6, prod3.x);
    VERIFY_EQUAL(9, prod3.y);
    VERIFY_EQUAL(12, prod3.z);

    Math::Vector4i vec4(2, 3, 4, 5);
    
    Math::Vector4i prod4 = vec4 * 3;
    VERIFY_EQUAL(6, prod4.x);
    VERIFY_EQUAL(9, prod4.y);
    VERIFY_EQUAL(12, prod4.z);
    VERIFY_EQUAL(15, prod4.w);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector can be divided." )
{
    Math::Vector1i vec1(2);
    
    Math::Vector1i quot1 = vec1 / 2;
    VERIFY_EQUAL(1, quot1.x);

    Math::Vector2i vec2(2, 10);
    
    Math::Vector2i quot2 = vec2 / 2;
    VERIFY_EQUAL(1, quot2.x);
    VERIFY_EQUAL(5, quot2.y);

    Math::Vector3i vec3(2, 10, 14);
    
    Math::Vector3i quot3 = vec3 / 2;
    VERIFY_EQUAL(1, quot3.x);
    VERIFY_EQUAL(5, quot3.y);
    VERIFY_EQUAL(7, quot3.z);

    Math::Vector4i vec4(2, 10, 14, 18);
    
    Math::Vector4i quot4 = vec4 / 2;
    VERIFY_EQUAL(1, quot4.x);
    VERIFY_EQUAL(5, quot4.y);
    VERIFY_EQUAL(7, quot4.z);
    VERIFY_EQUAL(9, quot4.w);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector can be dot multiplied." )
{
    Math::Vector1i vec1a(2);
    Math::Vector1i vec1b(5);
    
    int dot1 = vec1a.dot(vec1b);
    VERIFY_EQUAL(10, dot1);

    Math::Vector2i vec2a(2, 3);
    Math::Vector2i vec2b(5, 7);

    int dot2 = vec2a.dot(vec2b);
    VERIFY_EQUAL(31, dot2);

    Math::Vector3i vec3a(2, 3, 4);
    Math::Vector3i vec3b(5, 7, 9);
    
    int dot3 = vec3a.dot(vec3b);
    VERIFY_EQUAL(67, dot3);

    Math::Vector4i vec4a(2, 3, 4, 5);
    Math::Vector4i vec4b(5, 7, 9, 11);
    
    int dot4 = vec4a.dot(vec4b);
    VERIFY_EQUAL(122, dot4);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector3 can be cross multiplied." )
{
    Math::Vector3i vec3a(2, 10, 5);
    Math::Vector3i vec3b(-1, 4, 0);
    
    // vec3a vec3b
    //   2    -1
    //  10     4
    //   5     0
    //
    // result
    //  10 * 0  - 5 * 4   = -20
    //   5 * -1 - 2 * 0   =  -5
    //   2 * 4  - 10 * -1 =  18

    Math::Vector3i prod3 = vec3a.cross(vec3b);
    
    VERIFY_EQUAL(-20, prod3.x);
    VERIFY_EQUAL(-5, prod3.y);
    VERIFY_EQUAL(18, prod3.z);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector3 cross product points in the right direction." )
{
    Math::Vector3i vec3right = Math::Vector3i::right();
    Math::Vector3i vec3forward = Math::Vector3i::forward();
    
    Math::Vector3i prod3 = vec3right.cross(vec3forward);
    
    VERIFY_EQUAL(Math::Vector3i::up(), prod3);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector can calculate length squared." )
{
    Math::Vector1i vec1a(2);
    Math::Vector1i vec1b(-5);
    
    int length1 = vec1a.lengthSquared();
    VERIFY_EQUAL(4, length1);
    length1 = vec1b.lengthSquared();
    VERIFY_EQUAL(25, length1);

    Math::Vector2i vec2a(2, -3);
    Math::Vector2i vec2b(-5, 7);
    
    int length2 = vec2a.lengthSquared();
    VERIFY_EQUAL(13, length2);
    length2 = vec2b.lengthSquared();
    VERIFY_EQUAL(74, length2);

    Math::Vector3i vec3a(2, -3, 4);
    Math::Vector3i vec3b(-5, 7, -9);
    
    int length3 = vec3a.lengthSquared();
    VERIFY_EQUAL(29, length3);
    length3 = vec3b.lengthSquared();
    VERIFY_EQUAL(155, length3);

    Math::Vector4i vec4a(2, -3, 4, -5);
    Math::Vector4i vec4b(-5, 7, -9, 11);
    
    int length4 = vec4a.lengthSquared();
    VERIFY_EQUAL(54, length4);
    length4 = vec4b.lengthSquared();
    VERIFY_EQUAL(276, length4);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector can calculate length Manhattan." )
{
    Math::Vector1i vec1a(2);
    Math::Vector1i vec1b(-5);
    
    int length1 = vec1a.lengthManhattan();
    VERIFY_EQUAL(2, length1);
    length1 = vec1b.lengthManhattan();
    VERIFY_EQUAL(5, length1);
    
    Math::Vector2i vec2a(2, -3);
    Math::Vector2i vec2b(-5, 7);
    
    int length2 = vec2a.lengthManhattan();
    VERIFY_EQUAL(5, length2);
    length2 = vec2b.lengthManhattan();
    VERIFY_EQUAL(12, length2);
    
    Math::Vector3i vec3a(2, -3, 4);
    Math::Vector3i vec3b(-5, 7, -9);
    
    int length3 = vec3a.lengthManhattan();
    VERIFY_EQUAL(9, length3);
    length3 = vec3b.lengthManhattan();
    VERIFY_EQUAL(21, length3);
    
    Math::Vector4i vec4a(2, -3, 4, -5);
    Math::Vector4i vec4b(-5, 7, -9, 11);
    
    int length4 = vec4a.lengthManhattan();
    VERIFY_EQUAL(14, length4);
    length4 = vec4b.lengthManhattan();
    VERIFY_EQUAL(32, length4);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector can calculate normal." )
{
    Math::Vector1i vec1a(2);
    Math::Vector1i normi = vec1a.normal();
    VERIFY_EQUAL(1, normi.x);
    Math::Vector1d normd = vec1a.normal<double>();
    VERIFY_EQUAL(1.0, normd.x);
    
    Math::Vector1i vec1b(-5);
    normi = vec1b.normal();
    VERIFY_EQUAL(-1, normi.x);
    normd = vec1b.normal<double>();
    VERIFY_EQUAL(-1.0, normd.x);

    Math::Vector1d vec1c(3.0);
    normi = vec1c.normal<int>();
    VERIFY_EQUAL(1, normi.x);
    normd = vec1c.normal();
    VERIFY_EQUAL(1.0, normd.x);

    Math::Vector1d vec1d(-4.0);
    normi = vec1d.normal<int>();
    VERIFY_EQUAL(-1, normi.x);
    normd = vec1d.normal();
    VERIFY_EQUAL(-1.0, normd.x);

    Math::Vector2i vec2a(2, -5);
    Math::Vector2d norm2 = vec2a.normal<double>();
    VERIFY_EQUAL(2.0 / std::sqrt(vec2a.lengthSquared()), norm2.x);
    VERIFY_EQUAL(-5.0 / std::sqrt(vec2a.lengthSquared()), norm2.y);

    Math::Vector2d vec2b(3.0, -4.0);
    norm2 = vec2b.normal();
    VERIFY_EQUAL(3.0 / std::sqrt(vec2b.lengthSquared()), norm2.x);
    VERIFY_EQUAL(-4.0 / std::sqrt(vec2b.lengthSquared()), norm2.y);

    Math::Vector3i vec3a(2, -5, 8);
    Math::Vector3d norm3 = vec3a.normal<double>();
    VERIFY_EQUAL(2.0 / std::sqrt(vec3a.lengthSquared()), norm3.x);
    VERIFY_EQUAL(-5.0 / std::sqrt(vec3a.lengthSquared()), norm3.y);
    VERIFY_EQUAL(8.0 / std::sqrt(vec3a.lengthSquared()), norm3.z);

    Math::Vector3d vec3b(3.0, -4.0, 5.0);
    norm3 = vec3b.normal();
    VERIFY_EQUAL(3.0 / std::sqrt(vec3b.lengthSquared()), norm3.x);
    VERIFY_EQUAL(-4.0 / std::sqrt(vec3b.lengthSquared()), norm3.y);
    VERIFY_EQUAL(5.0 / std::sqrt(vec3b.lengthSquared()), norm3.z);

    Math::Vector4i vec4a(2, -5, 8, 3);
    Math::Vector4d norm4 = vec4a.normal<double>();
    VERIFY_EQUAL(2.0 / std::sqrt(vec4a.lengthSquared()), norm4.x);
    VERIFY_EQUAL(-5.0 / std::sqrt(vec4a.lengthSquared()), norm4.y);
    VERIFY_EQUAL(8.0 / std::sqrt(vec4a.lengthSquared()), norm4.z);
    VERIFY_EQUAL(3.0 / std::sqrt(vec4a.lengthSquared()), norm4.w);

    Math::Vector4d vec4b(3.0, -4.0, 5.0, 3.5);
    norm4 = vec4b.normal();
    VERIFY_EQUAL(3.0 / std::sqrt(vec4b.lengthSquared()), norm4.x);
    VERIFY_EQUAL(-4.0 / std::sqrt(vec4b.lengthSquared()), norm4.y);
    VERIFY_EQUAL(5.0 / std::sqrt(vec4b.lengthSquared()), norm4.z);
    VERIFY_EQUAL(3.5 / std::sqrt(vec4b.lengthSquared()), norm4.w);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector2f can be rotated." )
{
    Math::Vector2f vec2a = Math::Vector2f::right();
    Math::Vector2f vec2b = Math::Vector2f::forward();

    vec2a = vec2a.rotate(Math::Degreesf(45));
    vec2a = vec2a.rotateQuarter();

    vec2b = vec2b.rotate(Math::Radiansf(Math::PI_f / 4));

    VERIFY_EQUAL(vec2a, vec2b);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector2d can be rotated." )
{
    Math::Vector2d vec2a = Math::Vector2d::right();
    Math::Vector2d vec2b = Math::Vector2d::forward();

    vec2a = vec2a.rotate(Math::Degreesd(45));
    vec2a = vec2a.rotateQuarter();

    vec2b = vec2b.rotate(Math::Radiansd(Math::PI_d / 4));

    VERIFY_EQUAL(vec2a, vec2b);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector3f can be rotated." )
{
    Math::Vector3f vec3a = Math::Vector3f::right();
    Math::Vector3f vec3b = Math::Vector3f::forward();
    Math::Vector3f vec3c = Math::Vector3f::up();

    vec3a = vec3a.rotate(Math::Vector3f::axisY, Math::Radiansf(Math::PI_f / 18));
    vec3a = vec3a.rotate(Math::Vector3f::axisZ, Math::Degreesf(45));
    vec3a = vec3a.rotateQuarter(Math::Vector3f::axisZ);

    vec3b = vec3b.rotate(Math::Vector3f::axisX, Math::Degreesf(10));
    vec3b = vec3b.rotate(Math::Vector3f::axisZ, Math::Radiansf(Math::PI_f / 4));

    vec3c = vec3c.rotate(Math::Vector3f::axisX, Math::Degreesf(-80));
    vec3c = vec3c.rotate(Math::Vector3f::axisZ, Math::Radiansf(Math::PI_f / 4));

    VERIFY_EQUAL(vec3a, vec3b);
    VERIFY_EQUAL(vec3a, vec3c);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector3d can be rotated." )
{
    Math::Vector3d vec3a = Math::Vector3d::right();
    Math::Vector3d vec3b = Math::Vector3d::forward();
    Math::Vector3d vec3c = Math::Vector3d::up();

    vec3a = vec3a.rotate(Math::Vector3d::axisY, Math::Radiansd(Math::PI_d / 18));
    vec3a = vec3a.rotate(Math::Vector3d::axisZ, Math::Degreesd(45));
    vec3a = vec3a.rotateQuarter(Math::Vector3d::axisZ);

    vec3b = vec3b.rotate(Math::Vector3d::axisX, Math::Degreesd(10));
    vec3b = vec3b.rotate(Math::Vector3d::axisZ, Math::Radiansd(Math::PI_d / 4));

    vec3c = vec3c.rotate(Math::Vector3d::axisX, Math::Degreesd(-80));
    vec3c = vec3c.rotate(Math::Vector3d::axisZ, Math::Radiansd(Math::PI_d / 4));

    VERIFY_EQUAL(vec3a, vec3b);
    VERIFY_EQUAL(vec3a, vec3c);
}
