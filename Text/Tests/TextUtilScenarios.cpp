//
//  TextUtilScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 7/20/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../TextUtil.h"

using namespace std;
using namespace TUCUT;

SCENARIO( ImportParser, "Operation/Normal", "unit", "TextUtil knows whitespace." )
{
    auto result = Text::TextUtil::isWhitespace('a');
    verifyFalse(result);
    
    result = Text::TextUtil::isWhitespace('0');
    verifyFalse(result);
    
    result = Text::TextUtil::isWhitespace(' ');
    verifyTrue(result);
    
    result = Text::TextUtil::isWhitespace('\t');
    verifyTrue(result);
    
    result = Text::TextUtil::isWhitespace('\n');
    verifyTrue(result);
}

SCENARIO( ImportParser, "Operation/Normal", "unit", "TextUtil can split strings." )
{
    std::string input = "1,2,3";
    auto result = Text::TextUtil::splitString(input, ',');
    verifyEqual(3, static_cast<int>(result.size()));
    verifyEqual("1", result[0]);
    verifyEqual("2", result[1]);
    verifyEqual("3", result[2]);
}
