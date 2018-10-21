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
    Math::Vector1i vec1;
    Math::Vector2i vec2;
    Math::Vector3i vec3;
    Math::Vector4i vec4;
    Math::Vector1i vec5(123);
    Math::Vector2i vec6(123, 124);
    Math::Vector3i vec7(123, 124, 125);
    Math::Vector4i vec8(123, 124, 125, 126);
    
    VERIFY_EQUAL(0, vec1.x);
    
    VERIFY_EQUAL(0, vec2.x);
    VERIFY_EQUAL(0, vec2.y);
    
    VERIFY_EQUAL(0, vec3.x);
    VERIFY_EQUAL(0, vec3.y);
    VERIFY_EQUAL(0, vec3.z);
    
    VERIFY_EQUAL(0, vec4.x);
    VERIFY_EQUAL(0, vec4.y);
    VERIFY_EQUAL(0, vec4.z);
    VERIFY_EQUAL(0, vec4.w);
    
    VERIFY_EQUAL(123, vec5.x);
    
    VERIFY_EQUAL(123, vec6.x);
    VERIFY_EQUAL(124, vec6.y);
    
    VERIFY_EQUAL(123, vec7.x);
    VERIFY_EQUAL(124, vec7.y);
    VERIFY_EQUAL(125, vec7.z);
    
    VERIFY_EQUAL(123, vec8.x);
    VERIFY_EQUAL(124, vec8.y);
    VERIFY_EQUAL(125, vec8.z);
    VERIFY_EQUAL(126, vec8.w);
}

SCENARIO( Vector, "Construction/Normal", "unit,math", "Vectors can be copy constructed." )
{
    Math::Vector1i vec1(123);
    Math::Vector1i vec2(vec1);
    
    VERIFY_EQUAL(vec1, vec2);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vectors can be assigned." )
{
    Math::Vector1i vec1(123);
    Math::Vector1i vec2(124);
    
    VERIFY_FALSE(vec1 == vec2);
    vec2 = vec1;
    VERIFY_EQUAL(vec1, vec2);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vectors can be added." )
{
    Math::Vector2i vec1(1, 2);
    Math::Vector2i vec2(4, 5);
    
    Math::Vector2i sum = vec1 + vec2;
    
    VERIFY_EQUAL(5, sum.x);
    VERIFY_EQUAL(7, sum.y);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vectors can be subtracted." )
{
    Math::Vector2i vec1(1, 2);
    Math::Vector2i vec2(4, 5);
    
    Math::Vector2i diff = vec2 - vec1;
    
    VERIFY_EQUAL(3, diff.x);
    VERIFY_EQUAL(3, diff.y);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vectors can be multiplied." )
{
    Math::Vector2i vec1(2, 3);
    
    Math::Vector2i prod = vec1 * 3;
    
    VERIFY_EQUAL(6, prod.x);
    VERIFY_EQUAL(9, prod.y);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vectors can be divided." )
{
    Math::Vector2i vec1(2, 10);
    
    Math::Vector2i quot = vec1 / 2;
    
    VERIFY_EQUAL(1, quot.x);
    VERIFY_EQUAL(5, quot.y);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vectors can be dot multiplied." )
{
    Math::Vector2i vec1(2, 3);
    Math::Vector2i vec2(5, 7);

    int dot = vec1.dot(vec2);
    
    VERIFY_EQUAL(31, dot);
}

SCENARIO( Vector, "Operation/Normal", "unit,math", "Vector3s can be cross multiplied." )
{
    Math::Vector3i vec1(2, 10, 5);
    Math::Vector3i vec2(-1, 4, 0);
    
    // vec1  vec2
    //   2    -1
    //  10     4
    //   5     0
    //
    // result
    //  10 * 0  - 5 * 4   = -20
    //   5 * -1 - 2 * 0   =  -5
    //   2 * 4  - 10 * -1 =  18

    Math::Vector3i prod = vec1.cross(vec2);
    
    VERIFY_EQUAL(-20, prod.x);
    VERIFY_EQUAL(-5, prod.y);
    VERIFY_EQUAL(18, prod.z);
}
