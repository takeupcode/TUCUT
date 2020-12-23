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

SCENARIO( Vector, "Construction/Normal", "unit,math", "Vector<int> can be constructed." )
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

SCENARIO( Vector, "Construction/Normal", "unit,math", "Vector<float> can be constructed." )
{
    Math::Vector1f vec1a;
    Math::Vector2f vec2a;
    Math::Vector3f vec3a;
    Math::Vector4f vec4a;
    Math::Vector1f vec1b(123.5f);
    Math::Vector2f vec2b(123.5f, 124.5f);
    Math::Vector3f vec3b(123.5f, 124.5f, 125.5f);
    Math::Vector4f vec4b(123.5f, 124.5f, 125.5f, 126.5f);

    VERIFY_EQUAL(0.0f, vec1a.x);

    VERIFY_EQUAL(0.0f, vec2a.x);
    VERIFY_EQUAL(0.0f, vec2a.y);

    VERIFY_EQUAL(0.0f, vec3a.x);
    VERIFY_EQUAL(0.0f, vec3a.y);
    VERIFY_EQUAL(0.0f, vec3a.z);

    VERIFY_EQUAL(0.0f, vec4a.x);
    VERIFY_EQUAL(0.0f, vec4a.y);
    VERIFY_EQUAL(0.0f, vec4a.z);
    VERIFY_EQUAL(0.0f, vec4a.w);

    VERIFY_EQUAL(123.5f, vec1b.x);

    VERIFY_EQUAL(123.5f, vec2b.x);
    VERIFY_EQUAL(124.5f, vec2b.y);

    VERIFY_EQUAL(123.5f, vec3b.x);
    VERIFY_EQUAL(124.5f, vec3b.y);
    VERIFY_EQUAL(125.5f, vec3b.z);

    VERIFY_EQUAL(123.5f, vec4b.x);
    VERIFY_EQUAL(124.5f, vec4b.y);
    VERIFY_EQUAL(125.5f, vec4b.z);
    VERIFY_EQUAL(126.5f, vec4b.w);
}

SCENARIO( Vector, "Construction/Normal", "unit,math", "Vector<double> can be constructed." )
{
    Math::Vector1d vec1a;
    Math::Vector2d vec2a;
    Math::Vector3d vec3a;
    Math::Vector4d vec4a;
    Math::Vector1d vec1b(123.5);
    Math::Vector2d vec2b(123.5, 124.5);
    Math::Vector3d vec3b(123.5, 124.5, 125.5);
    Math::Vector4d vec4b(123.5, 124.5, 125.5, 126.5);

    VERIFY_EQUAL(0.0, vec1a.x);

    VERIFY_EQUAL(0.0, vec2a.x);
    VERIFY_EQUAL(0.0, vec2a.y);

    VERIFY_EQUAL(0.0, vec3a.x);
    VERIFY_EQUAL(0.0, vec3a.y);
    VERIFY_EQUAL(0.0, vec3a.z);

    VERIFY_EQUAL(0.0, vec4a.x);
    VERIFY_EQUAL(0.0, vec4a.y);
    VERIFY_EQUAL(0.0, vec4a.z);
    VERIFY_EQUAL(0.0, vec4a.w);

    VERIFY_EQUAL(123.5, vec1b.x);

    VERIFY_EQUAL(123.5, vec2b.x);
    VERIFY_EQUAL(124.5, vec2b.y);

    VERIFY_EQUAL(123.5, vec3b.x);
    VERIFY_EQUAL(124.5, vec3b.y);
    VERIFY_EQUAL(125.5, vec3b.z);

    VERIFY_EQUAL(123.5, vec4b.x);
    VERIFY_EQUAL(124.5, vec4b.y);
    VERIFY_EQUAL(125.5, vec4b.z);
    VERIFY_EQUAL(126.5, vec4b.w);
}

SCENARIO( Vector, "Construction/Normal", "unit,math", "Vector<long double> can be constructed." )
{
    Math::Vector1l vec1a;
    Math::Vector2l vec2a;
    Math::Vector3l vec3a;
    Math::Vector4l vec4a;
    Math::Vector1l vec1b(123.5L);
    Math::Vector2l vec2b(123.5L, 124.5L);
    Math::Vector3l vec3b(123.5L, 124.5L, 125.5L);
    Math::Vector4l vec4b(123.5L, 124.5L, 125.5L, 126.5L);

    VERIFY_EQUAL(0.0L, vec1a.x);

    VERIFY_EQUAL(0.0L, vec2a.x);
    VERIFY_EQUAL(0.0L, vec2a.y);

    VERIFY_EQUAL(0.0L, vec3a.x);
    VERIFY_EQUAL(0.0L, vec3a.y);
    VERIFY_EQUAL(0.0L, vec3a.z);

    VERIFY_EQUAL(0.0L, vec4a.x);
    VERIFY_EQUAL(0.0L, vec4a.y);
    VERIFY_EQUAL(0.0L, vec4a.z);
    VERIFY_EQUAL(0.0L, vec4a.w);

    VERIFY_EQUAL(123.5L, vec1b.x);

    VERIFY_EQUAL(123.5L, vec2b.x);
    VERIFY_EQUAL(124.5L, vec2b.y);

    VERIFY_EQUAL(123.5L, vec3b.x);
    VERIFY_EQUAL(124.5L, vec3b.y);
    VERIFY_EQUAL(125.5L, vec3b.z);

    VERIFY_EQUAL(123.5L, vec4b.x);
    VERIFY_EQUAL(124.5L, vec4b.y);
    VERIFY_EQUAL(125.5L, vec4b.z);
    VERIFY_EQUAL(126.5L, vec4b.w);
}

SCENARIO( Vector, "Construction/Normal", "unit,math", "Vector<int> can be copy constructed." )
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

SCENARIO( Vector, "Construction/Normal", "unit,math", "Vector<float> can be copy constructed." )
{
    Math::Vector1f vec1a(123.5f);
    Math::Vector1f vec1b(vec1a);

    VERIFY_EQUAL(vec1a, vec1b);

    Math::Vector2f vec2a(123.5f, 124.5f);
    Math::Vector2f vec2b(vec2a);

    VERIFY_EQUAL(vec2a, vec2b);

    Math::Vector3f vec3a(123.5f, 124.5f, 125.5f);
    Math::Vector3f vec3b(vec3a);

    VERIFY_EQUAL(vec3a, vec3b);

    Math::Vector4f vec4a(123.5f, 124.5f, 125.5f, 126.5f);
    Math::Vector4f vec4b(vec4a);

    VERIFY_EQUAL(vec4a, vec4b);
}

SCENARIO( Vector, "Construction/Normal", "unit,math", "Vector<double> can be copy constructed." )
{
    Math::Vector1d vec1a(123.5);
    Math::Vector1d vec1b(vec1a);

    VERIFY_EQUAL(vec1a, vec1b);

    Math::Vector2d vec2a(123.5, 124.5);
    Math::Vector2d vec2b(vec2a);

    VERIFY_EQUAL(vec2a, vec2b);

    Math::Vector3d vec3a(123.5, 124.5, 125.5);
    Math::Vector3d vec3b(vec3a);

    VERIFY_EQUAL(vec3a, vec3b);

    Math::Vector4d vec4a(123.5, 124.5, 125.5, 126.5);
    Math::Vector4d vec4b(vec4a);

    VERIFY_EQUAL(vec4a, vec4b);
}

SCENARIO( Vector, "Construction/Normal", "unit,math", "Vector<long double> can be copy constructed." )
{
    Math::Vector1f vec1a(123.5L);
    Math::Vector1f vec1b(vec1a);

    VERIFY_EQUAL(vec1a, vec1b);

    Math::Vector2f vec2a(123.5L, 124.5L);
    Math::Vector2f vec2b(vec2a);

    VERIFY_EQUAL(vec2a, vec2b);

    Math::Vector3f vec3a(123.5L, 124.5L, 125.5L);
    Math::Vector3f vec3b(vec3a);

    VERIFY_EQUAL(vec3a, vec3b);

    Math::Vector4f vec4a(123.5L, 124.5L, 125.5L, 126.5L);
    Math::Vector4f vec4b(vec4a);

    VERIFY_EQUAL(vec4a, vec4b);
}

SCENARIO( Vector, "Construction/Normal", "unit,math", "Vector can be constructed of all ones." )
{
    Math::Vector1i vec1a = Math::Vector1i::ones();
    Math::Vector1d vec1b = Math::Vector1d::ones();
    
    VERIFY_EQUAL(1, vec1a.x);
    VERIFY_EQUAL(1.0, vec1b.x);

    Math::Vector2i vec2a = Math::Vector2i::ones();
    Math::Vector2d vec2b = Math::Vector2d::ones();
    
    VERIFY_EQUAL(1, vec2a.x);
    VERIFY_EQUAL(1, vec2a.y);
    VERIFY_EQUAL(1.0, vec2b.x);
    VERIFY_EQUAL(1.0, vec2b.y);

    Math::Vector3i vec3a = Math::Vector3i::ones();
    Math::Vector3d vec3b = Math::Vector3d::ones();
    
    VERIFY_EQUAL(1, vec3a.x);
    VERIFY_EQUAL(1, vec3a.y);
    VERIFY_EQUAL(1, vec3a.z);
    VERIFY_EQUAL(1.0, vec3b.x);
    VERIFY_EQUAL(1.0, vec3b.y);
    VERIFY_EQUAL(1.0, vec3b.z);

    Math::Vector4i vec4a = Math::Vector4i::ones();
    Math::Vector4d vec4b = Math::Vector4d::ones();
    
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
    Math::Vector1i vec1c(-4);

    Math::Vector1i sum1 = vec1a + vec1b;
    VERIFY_EQUAL(5, sum1.x);
    sum1 = vec1a + vec1c;
    VERIFY_EQUAL(-3, sum1.x);

    Math::Vector2i vec2a(1, 2);
    Math::Vector2i vec2b(4, 5);
    Math::Vector2i vec2c(-4, -5);

    Math::Vector2i sum2 = vec2a + vec2b;
    VERIFY_EQUAL(5, sum2.x);
    VERIFY_EQUAL(7, sum2.y);
    sum2 = vec2a + vec2c;
    VERIFY_EQUAL(-3, sum2.x);
    VERIFY_EQUAL(-3, sum2.y);

    Math::Vector3i vec3a(1, 2, 3);
    Math::Vector3i vec3b(4, 5, 6);
    Math::Vector3i vec3c(-4, -5, -6);

    Math::Vector3i sum3 = vec3a + vec3b;
    VERIFY_EQUAL(5, sum3.x);
    VERIFY_EQUAL(7, sum3.y);
    VERIFY_EQUAL(9, sum3.z);
    sum3 = vec3a + vec3c;
    VERIFY_EQUAL(-3, sum3.x);
    VERIFY_EQUAL(-3, sum3.y);
    VERIFY_EQUAL(-3, sum3.z);

    Math::Vector4i vec4a(1, 2, 3, 4);
    Math::Vector4i vec4b(4, 5, 6, 7);
    Math::Vector4i vec4c(-4, -5, -6, -7);

    Math::Vector4i sum4 = vec4a + vec4b;
    VERIFY_EQUAL(5, sum4.x);
    VERIFY_EQUAL(7, sum4.y);
    VERIFY_EQUAL(9, sum4.z);
    VERIFY_EQUAL(11, sum4.w);
    sum4 = vec4a + vec4c;
    VERIFY_EQUAL(-3, sum4.x);
    VERIFY_EQUAL(-3, sum4.y);
    VERIFY_EQUAL(-3, sum4.z);
    VERIFY_EQUAL(-3, sum4.w);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector can be subtracted." )
{
    Math::Vector1i vec1a(1);
    Math::Vector1i vec1b(4);
    Math::Vector1i vec1c(-4);

    Math::Vector1i diff1 = vec1b - vec1a;
    VERIFY_EQUAL(3, diff1.x);
    diff1 = vec1a - vec1c;
    VERIFY_EQUAL(5, diff1.x);

    Math::Vector2i vec2a(1, 2);
    Math::Vector2i vec2b(4, 5);
    Math::Vector2i vec2c(-4, -5);

    Math::Vector2i diff2 = vec2b - vec2a;
    VERIFY_EQUAL(3, diff2.x);
    VERIFY_EQUAL(3, diff2.y);
    diff2 = vec2a - vec2c;
    VERIFY_EQUAL(5, diff2.x);
    VERIFY_EQUAL(7, diff2.y);

    Math::Vector3i vec3a(1, 2, 3);
    Math::Vector3i vec3b(4, 5, 6);
    Math::Vector3i vec3c(-4, -5, -6);

    Math::Vector3i diff3 = vec3b - vec3a;
    VERIFY_EQUAL(3, diff3.x);
    VERIFY_EQUAL(3, diff3.y);
    VERIFY_EQUAL(3, diff3.z);
    diff3 = vec3a - vec3c;
    VERIFY_EQUAL(5, diff3.x);
    VERIFY_EQUAL(7, diff3.y);
    VERIFY_EQUAL(9, diff3.z);

    Math::Vector4i vec4a(1, 2, 3, 4);
    Math::Vector4i vec4b(4, 5, 6, 7);
    Math::Vector4i vec4c(-4, -5, -6, -7);

    Math::Vector4i diff4 = vec4b - vec4a;
    VERIFY_EQUAL(3, diff4.x);
    VERIFY_EQUAL(3, diff4.y);
    VERIFY_EQUAL(3, diff4.z);
    VERIFY_EQUAL(3, diff4.w);
    diff4 = vec4a - vec4c;
    VERIFY_EQUAL(5, diff4.x);
    VERIFY_EQUAL(7, diff4.y);
    VERIFY_EQUAL(9, diff4.z);
    VERIFY_EQUAL(11, diff4.w);
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

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector<int> can be projected." )
{
    Math::Vector1i vec1a(2);
    Math::Vector1i vec1b(5);
    Math::Vector1i vec1c(-5);
    Math::Vector1i vec1d;

    auto proj1 = vec1a.projectOnto(vec1b);
    VERIFY_EQUAL(Math::Vector1i(2), proj1);
    proj1 = vec1a.projectOnto(vec1c);
    VERIFY_EQUAL(Math::Vector1i(2), proj1);
    proj1 = vec1a.projectOnto(vec1d);
    VERIFY_EQUAL(Math::Vector1i(), proj1);
    proj1 = vec1b.projectOnto(vec1a);
    VERIFY_EQUAL(Math::Vector1i(5), proj1);

    Math::Vector2i vec2a(2, 3);
    Math::Vector2i vec2b(5, 7);
    Math::Vector2i vec2c(-5, -7);
    Math::Vector2i vec2d;

    auto proj2 = vec2a.projectOnto(vec2b);
    VERIFY_EQUAL(Math::Vector2i(2, 3), proj2);
    proj2 = vec2a.projectOnto(vec2c);
    VERIFY_EQUAL(Math::Vector2i(2, 3), proj2);
    proj2 = vec2a.projectOnto(vec2d);
    VERIFY_EQUAL(Math::Vector2i(), proj2);
    proj2 = vec2b.projectOnto(vec2a);
    VERIFY_EQUAL(Math::Vector2i(5, 7), proj2);

    Math::Vector3i vec3a(2, 3, 4);
    Math::Vector3i vec3b(5, 7, 9);
    Math::Vector3i vec3c(-5, -7, -9);
    Math::Vector3i vec3d;

    auto proj3 = vec3a.projectOnto(vec3b);
    VERIFY_EQUAL(Math::Vector3i(2, 3, 4), proj3);
    proj3 = vec3a.projectOnto(vec3c);
    VERIFY_EQUAL(Math::Vector3i(2, 3, 4), proj3);
    proj3 = vec3a.projectOnto(vec3d);
    VERIFY_EQUAL(Math::Vector3i(), proj3);
    proj3 = vec3b.projectOnto(vec3a);
    VERIFY_EQUAL(Math::Vector3i(5, 7, 9), proj3);

    Math::Vector4i vec4a(2, 3, 4, 5);
    Math::Vector4i vec4b(5, 7, 9, 11);
    Math::Vector4i vec4c(-5, -7, -9, -11);
    Math::Vector4i vec4d;

    auto proj4 = vec4a.projectOnto(vec4b);
    VERIFY_EQUAL(Math::Vector4i(2, 3, 4, 5), proj4);
    proj4 = vec4a.projectOnto(vec4c);
    VERIFY_EQUAL(Math::Vector4i(2, 3, 4, 5), proj4);
    proj4 = vec4a.projectOnto(vec4d);
    VERIFY_EQUAL(Math::Vector4i(), proj4);
    proj4 = vec4b.projectOnto(vec4a);
    VERIFY_EQUAL(Math::Vector4i(5, 7, 9, 11), proj4);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector<float> can be projected." )
{
    Math::Vector1f vec1a(2.0f);
    Math::Vector1f vec1b(5.0f);
    Math::Vector1f vec1c(-5.0f);
    Math::Vector1f vec1d;

    auto proj1 = vec1a.projectOnto(vec1b);
    VERIFY_EQUAL(Math::Vector1i(2.0f), proj1);
    proj1 = vec1a.projectOnto(vec1c);
    VERIFY_EQUAL(Math::Vector1i(2.0f), proj1);
    proj1 = vec1a.projectOnto(vec1d);
    VERIFY_EQUAL(Math::Vector1i(), proj1);
    proj1 = vec1b.projectOnto(vec1a);
    VERIFY_EQUAL(Math::Vector1i(5.0f), proj1);

    Math::Vector2f vec2a(2.0f, 3.0f);
    Math::Vector2f vec2b(5.0f, 7.0f);
    Math::Vector2f vec2c(-5.0f, -7.0f);
    Math::Vector2f vec2d;

    auto proj2 = vec2a.projectOnto(vec2b);
    VERIFY_EQUAL(Math::Vector2i(2.0f, 3.0f), proj2);
    proj2 = vec2a.projectOnto(vec2c);
    VERIFY_EQUAL(Math::Vector2i(2.0f, 3.0f), proj2);
    proj2 = vec2a.projectOnto(vec2d);
    VERIFY_EQUAL(Math::Vector2i(), proj2);
    proj2 = vec2b.projectOnto(vec2a);
    VERIFY_EQUAL(Math::Vector2i(5.0f, 7.0f), proj2);

    Math::Vector3f vec3a(2.0f, 3.0f, 4.0f);
    Math::Vector3f vec3b(5.0f, 7.0f, 9.0f);
    Math::Vector3f vec3c(-5.0f, -7.0f, -9.0f);
    Math::Vector3f vec3d;

    auto proj3 = vec3a.projectOnto(vec3b);
    VERIFY_EQUAL(Math::Vector3i(2.0f, 3.0f, 4.0f), proj3);
    proj3 = vec3a.projectOnto(vec3c);
    VERIFY_EQUAL(Math::Vector3i(2.0f, 3.0f, 4.0f), proj3);
    proj3 = vec3a.projectOnto(vec3d);
    VERIFY_EQUAL(Math::Vector3i(), proj3);
    proj3 = vec3b.projectOnto(vec3a);
    VERIFY_EQUAL(Math::Vector3i(5.0f, 7.0f, 9.0f), proj3);

    Math::Vector4f vec4a(2.0f, 3.0f, 4.0f, 5.0f);
    Math::Vector4f vec4b(5.0f, 7.0f, 9.0f, 11.0f);
    Math::Vector4f vec4c(-5.0f, -7.0f, -9.0f, -11.0f);
    Math::Vector4f vec4d;

    auto proj4 = vec4a.projectOnto(vec4b);
    VERIFY_EQUAL(Math::Vector4i(2.0f, 3.0f, 4.0f, 5.0f), proj4);
    proj4 = vec4a.projectOnto(vec4c);
    VERIFY_EQUAL(Math::Vector4i(2.0f, 3.0f, 4.0f, 5.0f), proj4);
    proj4 = vec4a.projectOnto(vec4d);
    VERIFY_EQUAL(Math::Vector4i(), proj4);
    proj4 = vec4b.projectOnto(vec4a);
    VERIFY_EQUAL(Math::Vector4i(5.0f, 7.0f, 9.0f, 11.0f), proj4);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector<double> can be projected." )
{
    Math::Vector1d vec1a(2.0);
    Math::Vector1d vec1b(5.0);
    Math::Vector1d vec1c(-5.0);
    Math::Vector1d vec1d;

    auto proj1 = vec1a.projectOnto(vec1b);
    VERIFY_EQUAL(Math::Vector1d(2.0), proj1);
    proj1 = vec1a.projectOnto(vec1c);
    VERIFY_EQUAL(Math::Vector1d(2.0), proj1);
    proj1 = vec1a.projectOnto(vec1d);
    VERIFY_EQUAL(Math::Vector1d(), proj1);
    proj1 = vec1b.projectOnto(vec1a);
    VERIFY_EQUAL(Math::Vector1d(5.0), proj1);

    Math::Vector2d vec2a(2.0, 3.0);
    Math::Vector2d vec2b(5.0, 7.0);
    Math::Vector2d vec2c(-5.0, -7.0);
    Math::Vector2d vec2d;

    auto proj2 = vec2a.projectOnto(vec2b);
    VERIFY_EQUAL(Math::Vector2d(2.0, 3.0), proj2);
    proj2 = vec2a.projectOnto(vec2c);
    VERIFY_EQUAL(Math::Vector2d(2.0, 3.0), proj2);
    proj2 = vec2a.projectOnto(vec2d);
    VERIFY_EQUAL(Math::Vector2d(), proj2);
    proj2 = vec2b.projectOnto(vec2a);
    VERIFY_EQUAL(Math::Vector2d(5.0, 7.0), proj2);

    Math::Vector3d vec3a(2.0, 3.0, 4.0);
    Math::Vector3d vec3b(5.0, 7.0, 9.0);
    Math::Vector3d vec3c(-5.0, -7.0, -9.0);
    Math::Vector3d vec3d;

    auto proj3 = vec3a.projectOnto(vec3b);
    VERIFY_EQUAL(Math::Vector3d(2.0, 3.0, 4.0), proj3);
    proj3 = vec3a.projectOnto(vec3c);
    VERIFY_EQUAL(Math::Vector3d(2.0, 3.0, 4.0), proj3);
    proj3 = vec3a.projectOnto(vec3d);
    VERIFY_EQUAL(Math::Vector3d(), proj3);
    proj3 = vec3b.projectOnto(vec3a);
    VERIFY_EQUAL(Math::Vector3d(5.0, 7.0, 9.0), proj3);

    Math::Vector4d vec4a(2.0, 3.0, 4.0, 5.0);
    Math::Vector4d vec4b(5.0, 7.0, 9.0, 11.0);
    Math::Vector4d vec4c(-5.0, -7.0, -9.0, -11.0);
    Math::Vector4d vec4d;

    auto proj4 = vec4a.projectOnto(vec4b);
    VERIFY_EQUAL(Math::Vector4d(2.0, 3.0, 4.0, 5.0), proj4);
    proj4 = vec4a.projectOnto(vec4c);
    VERIFY_EQUAL(Math::Vector4d(2.0, 3.0, 4.0, 5.0), proj4);
    proj4 = vec4a.projectOnto(vec4d);
    VERIFY_EQUAL(Math::Vector4d(), proj4);
    proj4 = vec4b.projectOnto(vec4a);
    VERIFY_EQUAL(Math::Vector4d(5.0, 7.0, 9.0, 11.0), proj4);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector<long double> can be projected." )
{
    Math::Vector1l vec1a(2.0L);
    Math::Vector1l vec1b(5.0L);
    Math::Vector1l vec1c(-5.0L);
    Math::Vector1l vec1d;

    auto proj1 = vec1a.projectOnto(vec1b);
    VERIFY_EQUAL(Math::Vector1l(2.0L), proj1);
    proj1 = vec1a.projectOnto(vec1c);
    VERIFY_EQUAL(Math::Vector1l(2.0L), proj1);
    proj1 = vec1a.projectOnto(vec1d);
    VERIFY_EQUAL(Math::Vector1l(), proj1);
    proj1 = vec1b.projectOnto(vec1a);
    VERIFY_EQUAL(Math::Vector1l(5.0L), proj1);

    Math::Vector2l vec2a(2.0L, 3.0L);
    Math::Vector2l vec2b(5.0L, 7.0L);
    Math::Vector2l vec2c(-5.0L, -7.0L);
    Math::Vector2l vec2d;

    auto proj2 = vec2a.projectOnto(vec2b);
    VERIFY_EQUAL(Math::Vector2l(2.0L, 3.0L), proj2);
    proj2 = vec2a.projectOnto(vec2c);
    VERIFY_EQUAL(Math::Vector2l(2.0L, 3.0L), proj2);
    proj2 = vec2a.projectOnto(vec2d);
    VERIFY_EQUAL(Math::Vector2l(), proj2);
    proj2 = vec2b.projectOnto(vec2a);
    VERIFY_EQUAL(Math::Vector2l(5.0L, 7.0L), proj2);

    Math::Vector3l vec3a(2.0L, 3.0L, 4.0L);
    Math::Vector3l vec3b(5.0L, 7.0L, 9.0L);
    Math::Vector3l vec3c(-5.0L, -7.0L, -9.0L);
    Math::Vector3l vec3d;

    auto proj3 = vec3a.projectOnto(vec3b);
    VERIFY_EQUAL(Math::Vector3l(2.0L, 3.0L, 4.0L), proj3);
    proj3 = vec3a.projectOnto(vec3c);
    VERIFY_EQUAL(Math::Vector3l(2.0L, 3.0L, 4.0L), proj3);
    proj3 = vec3a.projectOnto(vec3d);
    VERIFY_EQUAL(Math::Vector3l(), proj3);
    proj3 = vec3b.projectOnto(vec3a);
    VERIFY_EQUAL(Math::Vector3l(5.0L, 7.0L, 9.0L), proj3);

    Math::Vector4l vec4a(2.0L, 3.0L, 4.0L, 5.0L);
    Math::Vector4l vec4b(5.0L, 7.0L, 9.0L, 11.0L);
    Math::Vector4l vec4c(-5.0L, -7.0L, -9.0L, -11.0L);
    Math::Vector4l vec4d;

    auto proj4 = vec4a.projectOnto(vec4b);
    VERIFY_EQUAL(Math::Vector4l(2.0L, 3.0L, 4.0L, 5.0L), proj4);
    proj4 = vec4a.projectOnto(vec4c);
    VERIFY_EQUAL(Math::Vector4l(2.0L, 3.0L, 4.0L, 5.0L), proj4);
    proj4 = vec4a.projectOnto(vec4d);
    VERIFY_EQUAL(Math::Vector4l(), proj4);
    proj4 = vec4b.projectOnto(vec4a);
    VERIFY_EQUAL(Math::Vector4l(5.0L, 7.0L, 9.0L, 11.0L), proj4);
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
    Math::Vector3i vec3left = Math::Vector3i::left();
    Math::Vector3i vec3forward = Math::Vector3i::forward();
    Math::Vector3i vec3backward = Math::Vector3i::backward();
    Math::Vector3i vec3up = Math::Vector3i::up();
    Math::Vector3i vec3down = Math::Vector3i::down();

    Math::Vector3i prod3 = vec3right.cross(vec3right);
    VERIFY_EQUAL(Math::Vector3i(), prod3);

    prod3 = vec3right.cross(vec3left);
    VERIFY_EQUAL(Math::Vector3i(), prod3);

    prod3 = vec3right.cross(vec3forward);
    VERIFY_EQUAL(Math::Vector3i::up(), prod3);

    prod3 = vec3right.cross(vec3backward);
    VERIFY_EQUAL(Math::Vector3i::down(), prod3);

    prod3 = vec3right.cross(vec3up);
    VERIFY_EQUAL(Math::Vector3i::backward(), prod3);

    prod3 = vec3right.cross(vec3down);
    VERIFY_EQUAL(Math::Vector3i::forward(), prod3);

    prod3 = vec3left.cross(vec3right);
    VERIFY_EQUAL(Math::Vector3i(), prod3);

    prod3 = vec3left.cross(vec3left);
    VERIFY_EQUAL(Math::Vector3i(), prod3);

    prod3 = vec3left.cross(vec3forward);
    VERIFY_EQUAL(Math::Vector3i::down(), prod3);

    prod3 = vec3left.cross(vec3backward);
    VERIFY_EQUAL(Math::Vector3i::up(), prod3);

    prod3 = vec3left.cross(vec3up);
    VERIFY_EQUAL(Math::Vector3i::forward(), prod3);

    prod3 = vec3left.cross(vec3down);
    VERIFY_EQUAL(Math::Vector3i::backward(), prod3);

    prod3 = vec3forward.cross(vec3right);
    VERIFY_EQUAL(Math::Vector3i::down(), prod3);

    prod3 = vec3forward.cross(vec3left);
    VERIFY_EQUAL(Math::Vector3i::up(), prod3);

    prod3 = vec3forward.cross(vec3forward);
    VERIFY_EQUAL(Math::Vector3i(), prod3);

    prod3 = vec3forward.cross(vec3backward);
    VERIFY_EQUAL(Math::Vector3i(), prod3);

    prod3 = vec3forward.cross(vec3up);
    VERIFY_EQUAL(Math::Vector3i::right(), prod3);

    prod3 = vec3forward.cross(vec3down);
    VERIFY_EQUAL(Math::Vector3i::left(), prod3);

    prod3 = vec3backward.cross(vec3right);
    VERIFY_EQUAL(Math::Vector3i::up(), prod3);

    prod3 = vec3backward.cross(vec3left);
    VERIFY_EQUAL(Math::Vector3i::down(), prod3);

    prod3 = vec3backward.cross(vec3forward);
    VERIFY_EQUAL(Math::Vector3i(), prod3);

    prod3 = vec3backward.cross(vec3backward);
    VERIFY_EQUAL(Math::Vector3i(), prod3);

    prod3 = vec3backward.cross(vec3up);
    VERIFY_EQUAL(Math::Vector3i::left(), prod3);

    prod3 = vec3backward.cross(vec3down);
    VERIFY_EQUAL(Math::Vector3i::right(), prod3);

    prod3 = vec3up.cross(vec3right);
    VERIFY_EQUAL(Math::Vector3i::forward(), prod3);

    prod3 = vec3up.cross(vec3left);
    VERIFY_EQUAL(Math::Vector3i::backward(), prod3);

    prod3 = vec3up.cross(vec3forward);
    VERIFY_EQUAL(Math::Vector3i::left(), prod3);

    prod3 = vec3up.cross(vec3backward);
    VERIFY_EQUAL(Math::Vector3i::right(), prod3);

    prod3 = vec3up.cross(vec3up);
    VERIFY_EQUAL(Math::Vector3i(), prod3);

    prod3 = vec3up.cross(vec3down);
    VERIFY_EQUAL(Math::Vector3i(), prod3);

    prod3 = vec3down.cross(vec3right);
    VERIFY_EQUAL(Math::Vector3i::backward(), prod3);

    prod3 = vec3down.cross(vec3left);
    VERIFY_EQUAL(Math::Vector3i::forward(), prod3);

    prod3 = vec3down.cross(vec3forward);
    VERIFY_EQUAL(Math::Vector3i::right(), prod3);

    prod3 = vec3down.cross(vec3backward);
    VERIFY_EQUAL(Math::Vector3i::left(), prod3);

    prod3 = vec3down.cross(vec3up);
    VERIFY_EQUAL(Math::Vector3i(), prod3);

    prod3 = vec3down.cross(vec3down);
    VERIFY_EQUAL(Math::Vector3i(), prod3);
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

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector can calculate unit." )
{
    Math::Vector1i vec1a(2);
    Math::Vector1i uniti = vec1a.unit();
    VERIFY_EQUAL(1, uniti.x);
    Math::Vector1d unitd = vec1a.unit<double>();
    VERIFY_EQUAL(1.0, unitd.x);
    
    Math::Vector1i vec1b(-5);
    uniti = vec1b.unit();
    VERIFY_EQUAL(-1, uniti.x);
    unitd = vec1b.unit<double>();
    VERIFY_EQUAL(-1.0, unitd.x);

    Math::Vector1d vec1c(3.0);
    uniti = vec1c.unit<int>();
    VERIFY_EQUAL(1, uniti.x);
    unitd = vec1c.unit();
    VERIFY_EQUAL(1.0, unitd.x);

    Math::Vector1d vec1d(-4.0);
    uniti = vec1d.unit<int>();
    VERIFY_EQUAL(-1, uniti.x);
    unitd = vec1d.unit();
    VERIFY_EQUAL(-1.0, unitd.x);

    Math::Vector2i vec2a(2, -5);
    Math::Vector2d unit2 = vec2a.unit<double>();
    VERIFY_EQUAL(2.0 / std::sqrt(vec2a.lengthSquared()), unit2.x);
    VERIFY_EQUAL(-5.0 / std::sqrt(vec2a.lengthSquared()), unit2.y);

    Math::Vector2d vec2b(3.0, -4.0);
    unit2 = vec2b.unit();
    VERIFY_EQUAL(3.0 / std::sqrt(vec2b.lengthSquared()), unit2.x);
    VERIFY_EQUAL(-4.0 / std::sqrt(vec2b.lengthSquared()), unit2.y);

    Math::Vector3i vec3a(2, -5, 8);
    Math::Vector3d unit3 = vec3a.unit<double>();
    VERIFY_EQUAL(2.0 / std::sqrt(vec3a.lengthSquared()), unit3.x);
    VERIFY_EQUAL(-5.0 / std::sqrt(vec3a.lengthSquared()), unit3.y);
    VERIFY_EQUAL(8.0 / std::sqrt(vec3a.lengthSquared()), unit3.z);

    Math::Vector3d vec3b(3.0, -4.0, 5.0);
    unit3 = vec3b.unit();
    VERIFY_EQUAL(3.0 / std::sqrt(vec3b.lengthSquared()), unit3.x);
    VERIFY_EQUAL(-4.0 / std::sqrt(vec3b.lengthSquared()), unit3.y);
    VERIFY_EQUAL(5.0 / std::sqrt(vec3b.lengthSquared()), unit3.z);

    Math::Vector4i vec4a(2, -5, 8, 3);
    Math::Vector4d unit4 = vec4a.unit<double>();
    VERIFY_EQUAL(2.0 / std::sqrt(vec4a.lengthSquared()), unit4.x);
    VERIFY_EQUAL(-5.0 / std::sqrt(vec4a.lengthSquared()), unit4.y);
    VERIFY_EQUAL(8.0 / std::sqrt(vec4a.lengthSquared()), unit4.z);
    VERIFY_EQUAL(3.0 / std::sqrt(vec4a.lengthSquared()), unit4.w);

    Math::Vector4d vec4b(3.0, -4.0, 5.0, 3.5);
    unit4 = vec4b.unit();
    VERIFY_EQUAL(3.0 / std::sqrt(vec4b.lengthSquared()), unit4.x);
    VERIFY_EQUAL(-4.0 / std::sqrt(vec4b.lengthSquared()), unit4.y);
    VERIFY_EQUAL(5.0 / std::sqrt(vec4b.lengthSquared()), unit4.z);
    VERIFY_EQUAL(3.5 / std::sqrt(vec4b.lengthSquared()), unit4.w);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector2f can be rotated." )
{
    Math::Vector2f vec2a = Math::Vector2f::right();
    Math::Vector2f vec2b = Math::Vector2f::forward();

    vec2a = vec2a.rotate(Math::Degreesd(45));
    vec2a = vec2a.rotateQuarter();

    vec2b = vec2b.rotate(Math::Radiansd(Math::PI_d / 4));

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

    vec3a = vec3a.rotate(Math::Vector3f::axisY, Math::Radiansd(Math::PI_d / 18));
    vec3a = vec3a.rotate(Math::Vector3f::axisZ, Math::Degreesd(45));
    vec3a = vec3a.rotateQuarter(Math::Vector3f::axisZ);

    vec3b = vec3b.rotate(Math::Vector3f::axisX, Math::Degreesd(10));
    vec3b = vec3b.rotate(Math::Vector3f::axisZ, Math::Radiansd(Math::PI_d / 4));

    vec3c = vec3c.rotate(Math::Vector3f::axisX, Math::Degreesd(-80));
    vec3c = vec3c.rotate(Math::Vector3f::axisZ, Math::Radiansd(Math::PI_d / 4));

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

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector2f can determine angle between another." )
{
    auto vec2a = Math::Vector2<float, float>::right();
    auto vec2b = Math::Vector2<float, float>::forward();
    Math::Vector2<float, float> vec2c(5.0f, 2.886751f);

    VERIFY_EQUAL(90.0f, vec2a.angleInDegrees(vec2b).angle);
    VERIFY_EQUAL(90.0f, vec2b.angleInDegrees(vec2a).angle);
    VERIFY_EQUAL(30.0f, vec2a.angleInDegrees(vec2c).angle);
    VERIFY_EQUAL(30.0f, vec2c.angleInDegrees(vec2a).angle);
    VERIFY_EQUAL(60.0f, vec2c.angleInDegrees(vec2b).angle);
    VERIFY_EQUAL(60.0f, vec2b.angleInDegrees(vec2c).angle);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector2d can determine angle between another." )
{
    auto vec2a = Math::Vector2d::right();
    auto vec2b = Math::Vector2d::forward();
    Math::Vector2d vec2c(5.0, 2.886751345948129);

    VERIFY_EQUAL(90.0, vec2a.angleInDegrees(vec2b).angle);
    VERIFY_EQUAL(90.0, vec2b.angleInDegrees(vec2a).angle);
    VERIFY_EQUAL(30.0, vec2a.angleInDegrees(vec2c).angle);
    VERIFY_EQUAL(30.0, vec2c.angleInDegrees(vec2a).angle);
    VERIFY_EQUAL(60.0, vec2c.angleInDegrees(vec2b).angle);
    VERIFY_EQUAL(60.0, vec2b.angleInDegrees(vec2c).angle);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector3f can determine angle between another." )
{
    auto vec3a = Math::Vector3<float, float>::right();
    auto vec3b = Math::Vector3<float, float>::forward();
    auto vec3c = Math::Vector3<float, float>::up();
    Math::Vector3<float, float> vec3d(5.0f, 2.041241f, 2.041241f);

    VERIFY_EQUAL(90.0f, vec3a.angleInDegrees(vec3b).angle);
    VERIFY_EQUAL(90.0f, vec3b.angleInDegrees(vec3a).angle);
    VERIFY_EQUAL(90.0f, vec3a.angleInDegrees(vec3c).angle);
    VERIFY_EQUAL(90.0f, vec3c.angleInDegrees(vec3a).angle);
    VERIFY_EQUAL(90.0f, vec3b.angleInDegrees(vec3c).angle);
    VERIFY_EQUAL(90.0f, vec3c.angleInDegrees(vec3b).angle);
    VERIFY_EQUAL(30.0f, vec3a.angleInDegrees(vec3d).angle);
    VERIFY_EQUAL(30.0f, vec3d.angleInDegrees(vec3a).angle);
    VERIFY_EQUAL(69.295189f, vec3d.angleInDegrees(vec3b).angle);
    VERIFY_EQUAL(69.295189f, vec3b.angleInDegrees(vec3d).angle);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector3d can determine angle between another." )
{
    auto vec3a = Math::Vector3d::right();
    auto vec3b = Math::Vector3d::forward();
    auto vec3c = Math::Vector3d::up();
    Math::Vector3d vec3d(5.0, 2.041241452319315, 2.041241452319315);

    VERIFY_EQUAL(90.0, vec3a.angleInDegrees(vec3b).angle);
    VERIFY_EQUAL(90.0, vec3b.angleInDegrees(vec3a).angle);
    VERIFY_EQUAL(90.0, vec3a.angleInDegrees(vec3c).angle);
    VERIFY_EQUAL(90.0, vec3c.angleInDegrees(vec3a).angle);
    VERIFY_EQUAL(90.0, vec3b.angleInDegrees(vec3c).angle);
    VERIFY_EQUAL(90.0, vec3c.angleInDegrees(vec3b).angle);
    VERIFY_EQUAL(30.0, vec3a.angleInDegrees(vec3d).angle);
    VERIFY_EQUAL(30.0, vec3d.angleInDegrees(vec3a).angle);
    VERIFY_EQUAL(69.29518894536457, vec3d.angleInDegrees(vec3b).angle);
    VERIFY_EQUAL(69.29518894536457, vec3b.angleInDegrees(vec3d).angle);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector4f can determine angle between another." )
{
    auto vec4a = Math::Vector4<float, float>::right();
    auto vec4b = Math::Vector4<float, float>::forward();
    auto vec4c = Math::Vector4<float, float>::up();
    auto vec4d = Math::Vector4<float, float>::ana();
    Math::Vector4<float, float> vec4e(5.0f, 2.041241f, 2.041241f, 0.0f);

    VERIFY_EQUAL(90.0f, vec4a.angleInDegrees(vec4b).angle);
    VERIFY_EQUAL(90.0f, vec4b.angleInDegrees(vec4a).angle);
    VERIFY_EQUAL(90.0f, vec4a.angleInDegrees(vec4c).angle);
    VERIFY_EQUAL(90.0f, vec4c.angleInDegrees(vec4a).angle);
    VERIFY_EQUAL(90.0f, vec4a.angleInDegrees(vec4d).angle);
    VERIFY_EQUAL(90.0f, vec4d.angleInDegrees(vec4a).angle);
    VERIFY_EQUAL(90.0f, vec4b.angleInDegrees(vec4c).angle);
    VERIFY_EQUAL(90.0f, vec4c.angleInDegrees(vec4b).angle);
    VERIFY_EQUAL(90.0f, vec4b.angleInDegrees(vec4d).angle);
    VERIFY_EQUAL(90.0f, vec4d.angleInDegrees(vec4b).angle);
    VERIFY_EQUAL(90.0f, vec4c.angleInDegrees(vec4d).angle);
    VERIFY_EQUAL(90.0f, vec4d.angleInDegrees(vec4c).angle);
    VERIFY_EQUAL(30.0f, vec4a.angleInDegrees(vec4e).angle);
    VERIFY_EQUAL(30.0f, vec4e.angleInDegrees(vec4a).angle);
    VERIFY_EQUAL(69.295189f, vec4e.angleInDegrees(vec4b).angle);
    VERIFY_EQUAL(69.295189f, vec4b.angleInDegrees(vec4e).angle);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector4d can determine angle between another." )
{
    auto vec4a = Math::Vector4d::right();
    auto vec4b = Math::Vector4d::forward();
    auto vec4c = Math::Vector4d::up();
    auto vec4d = Math::Vector4d::ana();
    Math::Vector4d vec4e(5.0, 2.041241452319315, 2.041241452319315, 0.0);

    VERIFY_EQUAL(90.0, vec4a.angleInDegrees(vec4b).angle);
    VERIFY_EQUAL(90.0, vec4b.angleInDegrees(vec4a).angle);
    VERIFY_EQUAL(90.0, vec4a.angleInDegrees(vec4c).angle);
    VERIFY_EQUAL(90.0, vec4c.angleInDegrees(vec4a).angle);
    VERIFY_EQUAL(90.0, vec4a.angleInDegrees(vec4d).angle);
    VERIFY_EQUAL(90.0, vec4d.angleInDegrees(vec4a).angle);
    VERIFY_EQUAL(90.0, vec4b.angleInDegrees(vec4c).angle);
    VERIFY_EQUAL(90.0, vec4c.angleInDegrees(vec4b).angle);
    VERIFY_EQUAL(90.0, vec4b.angleInDegrees(vec4d).angle);
    VERIFY_EQUAL(90.0, vec4d.angleInDegrees(vec4b).angle);
    VERIFY_EQUAL(90.0, vec4c.angleInDegrees(vec4d).angle);
    VERIFY_EQUAL(90.0, vec4d.angleInDegrees(vec4c).angle);
    VERIFY_EQUAL(30.0, vec4a.angleInDegrees(vec4e).angle);
    VERIFY_EQUAL(30.0, vec4e.angleInDegrees(vec4a).angle);
    VERIFY_EQUAL(69.29518894536457, vec4e.angleInDegrees(vec4b).angle);
    VERIFY_EQUAL(69.29518894536457, vec4b.angleInDegrees(vec4e).angle);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector2f can determine parallel with another." )
{
    Math::Vector2f vec2a(5.0f, 2.5f);
    Math::Vector2f vec2b(5.0f, 3.0f);
    Math::Vector2f vec2c(7.5f, 4.5f);
    Math::Vector2f vec2d(-7.5f, -4.5f);

    VERIFY_TRUE(vec2a.isParallel(vec2a));
    VERIFY_FALSE(vec2a.isParallel(vec2b));
    VERIFY_FALSE(vec2c.isParallel(vec2a));
    VERIFY_FALSE(vec2a.isParallel(vec2d));
    VERIFY_TRUE(vec2b.isParallel(vec2c));
    VERIFY_TRUE(vec2c.isParallel(vec2b));
    VERIFY_TRUE(vec2b.isParallel(vec2d));
    VERIFY_TRUE(vec2d.isParallel(vec2b));
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector2d can determine parallel with another." )
{
    Math::Vector2d vec2a(5.0, 2.5);
    Math::Vector2d vec2b(5.0, 3.0);
    Math::Vector2d vec2c(7.5, 4.5);
    Math::Vector2d vec2d(-7.5, -4.5);

    VERIFY_TRUE(vec2a.isParallel(vec2a));
    VERIFY_FALSE(vec2a.isParallel(vec2b));
    VERIFY_FALSE(vec2c.isParallel(vec2a));
    VERIFY_FALSE(vec2a.isParallel(vec2d));
    VERIFY_TRUE(vec2b.isParallel(vec2c));
    VERIFY_TRUE(vec2c.isParallel(vec2b));
    VERIFY_TRUE(vec2b.isParallel(vec2d));
    VERIFY_TRUE(vec2d.isParallel(vec2b));
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector3f can determine parallel with another." )
{
    Math::Vector3f vec3a(5.0f, 2.5f, 0.0f);
    Math::Vector3f vec3b(5.0f, 3.0f, 0.0f);
    Math::Vector3f vec3c(7.5f, 4.5f, 0.0f);
    Math::Vector3f vec3d(-7.5f, -4.5f, 0.0f);
    Math::Vector3f vec3e(5.0f, 3.0f, 1.0f);
    Math::Vector3f vec3f(7.5f, 4.5f, 1.5f);

    VERIFY_TRUE(vec3a.isParallel(vec3a));
    VERIFY_FALSE(vec3a.isParallel(vec3b));
    VERIFY_FALSE(vec3c.isParallel(vec3a));
    VERIFY_FALSE(vec3a.isParallel(vec3d));
    VERIFY_FALSE(vec3a.isParallel(vec3e));
    VERIFY_FALSE(vec3a.isParallel(vec3f));
    VERIFY_TRUE(vec3b.isParallel(vec3c));
    VERIFY_TRUE(vec3c.isParallel(vec3b));
    VERIFY_TRUE(vec3b.isParallel(vec3d));
    VERIFY_TRUE(vec3d.isParallel(vec3b));
    VERIFY_FALSE(vec3b.isParallel(vec3e));
    VERIFY_TRUE(vec3e.isParallel(vec3f));
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector3d can determine parallel with another." )
{
    Math::Vector3d vec3a(5.0, 2.5, 0.0);
    Math::Vector3d vec3b(5.0, 3.0, 0.0);
    Math::Vector3d vec3c(7.5, 4.5, 0.0);
    Math::Vector3d vec3d(-7.5, -4.5, 0.0);
    Math::Vector3d vec3e(5.0, 3.0, 1.0);
    Math::Vector3d vec3f(7.5, 4.5, 1.5);

    VERIFY_TRUE(vec3a.isParallel(vec3a));
    VERIFY_FALSE(vec3a.isParallel(vec3b));
    VERIFY_FALSE(vec3c.isParallel(vec3a));
    VERIFY_FALSE(vec3a.isParallel(vec3d));
    VERIFY_FALSE(vec3a.isParallel(vec3e));
    VERIFY_FALSE(vec3a.isParallel(vec3f));
    VERIFY_TRUE(vec3b.isParallel(vec3c));
    VERIFY_TRUE(vec3c.isParallel(vec3b));
    VERIFY_TRUE(vec3b.isParallel(vec3d));
    VERIFY_TRUE(vec3d.isParallel(vec3b));
    VERIFY_FALSE(vec3b.isParallel(vec3e));
    VERIFY_TRUE(vec3e.isParallel(vec3f));
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector4f can determine parallel with another." )
{
    Math::Vector4f vec4a(5.0f, 2.5f, 0.0f, 0.0f);
    Math::Vector4f vec4b(5.0f, 3.0f, 0.0f, 0.0f);
    Math::Vector4f vec4c(7.5f, 4.5f, 0.0f, 0.0f);
    Math::Vector4f vec4d(-7.5f, -4.5f, 0.0f, 0.0f);
    Math::Vector4f vec4e(5.0f, 3.0f, 1.0f, 0.0f);
    Math::Vector4f vec4f(7.5f, 4.5f, 1.5f, 0.0f);
    Math::Vector4f vec4g(5.0f, 3.0f, 1.0f, 2.0f);
    Math::Vector4f vec4h(7.5f, 4.5f, 1.5f, 3.0f);

    VERIFY_TRUE(vec4a.isParallel(vec4a));
    VERIFY_FALSE(vec4a.isParallel(vec4b));
    VERIFY_FALSE(vec4c.isParallel(vec4a));
    VERIFY_FALSE(vec4a.isParallel(vec4d));
    VERIFY_FALSE(vec4a.isParallel(vec4e));
    VERIFY_FALSE(vec4a.isParallel(vec4f));
    VERIFY_FALSE(vec4a.isParallel(vec4g));
    VERIFY_FALSE(vec4a.isParallel(vec4h));
    VERIFY_TRUE(vec4b.isParallel(vec4c));
    VERIFY_TRUE(vec4c.isParallel(vec4b));
    VERIFY_TRUE(vec4b.isParallel(vec4d));
    VERIFY_TRUE(vec4d.isParallel(vec4b));
    VERIFY_FALSE(vec4b.isParallel(vec4e));
    VERIFY_TRUE(vec4e.isParallel(vec4f));
    VERIFY_FALSE(vec4b.isParallel(vec4g));
    VERIFY_FALSE(vec4e.isParallel(vec4g));
    VERIFY_TRUE(vec4g.isParallel(vec4h));
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector4d can determine parallel with another." )
{
    Math::Vector4d vec4a(5.0, 2.5, 0.0, 0.0);
    Math::Vector4d vec4b(5.0, 3.0, 0.0, 0.0);
    Math::Vector4d vec4c(7.5, 4.5, 0.0, 0.0);
    Math::Vector4d vec4d(-7.5, -4.5, 0.0, 0.0);
    Math::Vector4d vec4e(5.0, 3.0, 1.0, 0.0);
    Math::Vector4d vec4f(7.5, 4.5, 1.5, 0.0);
    Math::Vector4d vec4g(5.0, 3.0, 1.0, 2.0);
    Math::Vector4d vec4h(7.5, 4.5, 1.5, 3.0);

    VERIFY_TRUE(vec4a.isParallel(vec4a));
    VERIFY_FALSE(vec4a.isParallel(vec4b));
    VERIFY_FALSE(vec4c.isParallel(vec4a));
    VERIFY_FALSE(vec4a.isParallel(vec4d));
    VERIFY_FALSE(vec4a.isParallel(vec4e));
    VERIFY_FALSE(vec4a.isParallel(vec4f));
    VERIFY_FALSE(vec4a.isParallel(vec4g));
    VERIFY_FALSE(vec4a.isParallel(vec4h));
    VERIFY_TRUE(vec4b.isParallel(vec4c));
    VERIFY_TRUE(vec4c.isParallel(vec4b));
    VERIFY_TRUE(vec4b.isParallel(vec4d));
    VERIFY_TRUE(vec4d.isParallel(vec4b));
    VERIFY_FALSE(vec4b.isParallel(vec4e));
    VERIFY_TRUE(vec4e.isParallel(vec4f));
    VERIFY_FALSE(vec4b.isParallel(vec4g));
    VERIFY_FALSE(vec4e.isParallel(vec4g));
    VERIFY_TRUE(vec4g.isParallel(vec4h));
}
