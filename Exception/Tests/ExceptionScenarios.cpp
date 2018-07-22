//
//  ExceptionScenarios.cpp
//  TestTUCUT
//
//  Created by Wahid Tanner on 7/21/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../InvalidArgumentException.h"
#include "../InvalidExtensionException.h"
#include "../InvalidOperationException.h"
#include "../NullArgumentException.h"

using namespace std;
using namespace TUCUT;

SCENARIO( Exception, "Construction/Normal", "unit,exception", "Exceptions can be constructed." )
{
    Exception::InvalidArgumentException ex1("test");
    Exception::InvalidExtensionException ex2("test");
    Exception::InvalidOperationException ex3("test");
    Exception::NullArgumentException ex4("test");
}
