//
//  MinMaxScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 11/5/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "../../Test/Test.h"

#include "../MinMax.h"

using namespace std;
using namespace TUCUT;

SCENARIO( MinMax, "Operation/Normal", "unit,math", "MinMax can record single value." )
{
    Math::MinMax<int> minmax;
    
    minmax.record(10);
    
    VERIFY_EQUAL(10, minmax.min());
    VERIFY_EQUAL(10, minmax.max());
}

SCENARIO( MinMax, "Operation/Normal", "unit,math", "MinMax can record ascending values." )
{
    Math::MinMax<int> minmax;
    
    minmax.record(1);
    minmax.record(2);
    minmax.record(3);
    minmax.record(4);

    VERIFY_EQUAL(1, minmax.min());
    VERIFY_EQUAL(4, minmax.max());
}

SCENARIO( MinMax, "Operation/Normal", "unit,math", "MinMax can record descending values." )
{
    Math::MinMax<int> minmax;
    
    minmax.record(9);
    minmax.record(8);
    minmax.record(7);
    minmax.record(6);
    
    VERIFY_EQUAL(6, minmax.min());
    VERIFY_EQUAL(9, minmax.max());
}
