//
//  VectorScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 10/20/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "../../Test/Test.h"

#include "../Vector.h"

using namespace std;
using namespace TUCUT;

SCENARIO( Vector, "Construction/Normal", "unit,math", "Vectors can be constructed." )
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

SCENARIO( Vector, "Construction/Normal", "unit,math", "Vectors can be copy constructed." )
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

SCENARIO( Vector, "Construction/Normal", "unit,math", "Vectors can be unit constructed." )
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

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vectors can be assigned." )
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

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vectors can be added." )
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

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vectors can be subtracted." )
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

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vectors can be multiplied." )
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

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vectors can be divided." )
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

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vectors can be dot multiplied." )
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

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector3s can be cross multiplied." )
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

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vectors can calculate length squared." )
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

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vectors can calculate length Manhattan." )
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

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vectors can calculate normal." )
{
    Math::Vector1i vec1a(2);
    Math::Vector1d norm1 = vec1a.normal();
    VERIFY_EQUAL(1.0, norm1.x);
    
    Math::Vector1i vec1b(-5);
    norm1 = vec1b.normal();
    VERIFY_EQUAL(-1.0, norm1.x);

    Math::Vector1d vec1c(3.0);
    norm1 = vec1c.normal();
    VERIFY_EQUAL(1.0, norm1.x);
    
    Math::Vector1d vec1d(-4.0);
    norm1 = vec1d.normal();
    VERIFY_EQUAL(-1.0, norm1.x);

    Math::Vector2i vec2a(2, -5);
    Math::Vector2d norm2 = vec2a.normal();
    VERIFY_EQUAL(2.0 / std::sqrt(vec2a.lengthSquared()), norm2.x);
    VERIFY_EQUAL(-5.0 / std::sqrt(vec2a.lengthSquared()), norm2.y);

    Math::Vector2d vec2b(3.0, -4.0);
    norm2 = vec2b.normal();
    VERIFY_EQUAL(3.0 / std::sqrt(vec2b.lengthSquared()), norm2.x);
    VERIFY_EQUAL(-4.0 / std::sqrt(vec2b.lengthSquared()), norm2.y);

    Math::Vector3i vec3a(2, -5, 8);
    Math::Vector3d norm3 = vec3a.normal();
    VERIFY_EQUAL(2.0 / std::sqrt(vec3a.lengthSquared()), norm3.x);
    VERIFY_EQUAL(-5.0 / std::sqrt(vec3a.lengthSquared()), norm3.y);
    VERIFY_EQUAL(8.0 / std::sqrt(vec3a.lengthSquared()), norm3.z);

    Math::Vector3d vec3b(3.0, -4.0, 5.0);
    norm3 = vec3b.normal();
    VERIFY_EQUAL(3.0 / std::sqrt(vec3b.lengthSquared()), norm3.x);
    VERIFY_EQUAL(-4.0 / std::sqrt(vec3b.lengthSquared()), norm3.y);
    VERIFY_EQUAL(5.0 / std::sqrt(vec3b.lengthSquared()), norm3.z);

    Math::Vector4i vec4a(2, -5, 8, 3);
    Math::Vector4d norm4 = vec4a.normal();
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
