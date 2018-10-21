//
//  BezierScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 10/21/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "../../Test/Test.h"

#include "../Bezier.h"

using namespace std;
using namespace TUCUT;

SCENARIO( Bezier, "Construction/Normal", "unit,math", "Bezier can calculate linear." )
{
    Math::Point2d pt1(0.0, 0.0);
    Math::Point2d pt2(2.0, 2.0);
    std::vector<Math::Point2d> points = {pt1, pt2};
    
    Math::Point2d result = Math::Bezier2d::calculate(points, 0.0);
    VERIFY_EQUAL(0.0, result.x);
    VERIFY_EQUAL(0.0, result.y);
    
    result = Math::Bezier2d::calculate(points, 0.5);
    VERIFY_EQUAL(1.0, result.x);
    VERIFY_EQUAL(1.0, result.y);

    result = Math::Bezier2d::calculate(points, 1.0);
    VERIFY_EQUAL(2.0, result.x);
    VERIFY_EQUAL(2.0, result.y);
}

SCENARIO( Bezier, "Construction/Normal", "unit,math", "Bezier can calculate quadratic." )
{
    Math::Point2d pt1(0.0, 0.0);
    Math::Point2d pt2(2.0, 2.0);
    Math::Point2d pt3(4.0, 0.0);
    std::vector<Math::Point2d> points = {pt1, pt2, pt3};
    
    Math::Point2d result = Math::Bezier2d::calculate(points, 0.0);
    VERIFY_EQUAL(0.0, result.x);
    VERIFY_EQUAL(0.0, result.y);
    
    result = Math::Bezier2d::calculate(points, 0.5);
    VERIFY_EQUAL(2.0, result.x);
    VERIFY_EQUAL(1.0, result.y);
    
    result = Math::Bezier2d::calculate(points, 1.0);
    VERIFY_EQUAL(4.0, result.x);
    VERIFY_EQUAL(0.0, result.y);
}

