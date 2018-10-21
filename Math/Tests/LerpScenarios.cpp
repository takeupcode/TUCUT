//
//  LerpScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 10/16/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "../../Test/Test.h"

#include "../Lerp.h"

using namespace std;
using namespace TUCUT;

SCENARIO( Lerp, "Operation/Normal", "unit,math", "Values can be lerped." )
{
    double result = Math::lerp(1, 9, 0.5);
    
    VERIFY_EQUAL(5.0, result);
    
    result = Math::lerp(1.0, 9.0, 0.5);
    
    VERIFY_EQUAL(5.0, result);
    
    result = Math::lerp(1.0, 10.0, 0.5);
    
    VERIFY_EQUAL(5.5, result);
    
    result = Math::lerp(1.0, 10.0, 0.0);
    
    VERIFY_EQUAL(1.0, result);
    
    result = Math::lerp(1.0, 10.0, 1.0);
    
    VERIFY_EQUAL(10.0, result);
    
    result = Math::lerp(1.1, 10.3, 0.0);
    
    VERIFY_EQUAL(1.1, result);
    
    result = Math::lerp(1.1, 10.3, 1.0);
    
    VERIFY_EQUAL(10.3, result);
}

SCENARIO( Lerp, "Operation/Normal", "unit,math", "Reversed values can be lerped." )
{
    double result = Math::lerp(9, 1, 0.5);
    
    VERIFY_EQUAL(5.0, result);
}
