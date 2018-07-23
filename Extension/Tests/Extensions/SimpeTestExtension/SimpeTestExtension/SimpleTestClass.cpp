//
//  SimpleTestClass.cpp
//  SimpleTestExtension
//
//  Created by Wahid Tanner on 6/12/14.
//  Copyright © 2014 Take Up Code. All rights reserved.
//

#include "SimpleTestClass.h"

namespace Extensions
{
    SimpleTestClass::SimpleTestClass ()
    { }

    std::string SimpleTestClass::process (const std::string & message)
    {
        return "Success from SimpleTestClass: " + message;
    }
}
