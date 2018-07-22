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

SCENARIO( TextUtil, "Operation/Normal", "unit", "TextUtil knows whitespace." )
{
    auto result = Text::TextUtil::isWhitespace('a');
    VERIFY_FALSE(result);
    
    result = Text::TextUtil::isWhitespace('0');
    VERIFY_FALSE(result);
    
    result = Text::TextUtil::isWhitespace(' ');
    VERIFY_TRUE(result);
    
    result = Text::TextUtil::isWhitespace('\t');
    VERIFY_TRUE(result);
    
    result = Text::TextUtil::isWhitespace('\n');
    VERIFY_TRUE(result);
}

SCENARIO( TextUtil, "Operation/Normal", "unit", "TextUtil can split strings." )
{
    std::string input = "1,2,3";
    auto result = Text::TextUtil::splitString(input, ',');
    VERIFY_EQUAL(3, static_cast<int>(result.size()));
    VERIFY_EQUAL("1", result[0]);
    VERIFY_EQUAL("2", result[1]);
    VERIFY_EQUAL("3", result[2]);
}

SCENARIO( TextUtil, "Operation/Edge", "unit", "TextUtil can split strings with empty spots." )
{
    std::string input = "";
    auto result = Text::TextUtil::splitString(input, ',');
    VERIFY_EQUAL(1, static_cast<int>(result.size()));
    VERIFY_EQUAL("", result[0]);
    
    input = ",2,3";
    result = Text::TextUtil::splitString(input, ',');
    VERIFY_EQUAL(3, static_cast<int>(result.size()));
    VERIFY_EQUAL("", result[0]);
    VERIFY_EQUAL("2", result[1]);
    VERIFY_EQUAL("3", result[2]);
    
    input = "1,,3";
    result = Text::TextUtil::splitString(input, ',');
    VERIFY_EQUAL(3, static_cast<int>(result.size()));
    VERIFY_EQUAL("1", result[0]);
    VERIFY_EQUAL("", result[1]);
    VERIFY_EQUAL("3", result[2]);
    
    input = "1,2,";
    result = Text::TextUtil::splitString(input, ',');
    VERIFY_EQUAL(3, static_cast<int>(result.size()));
    VERIFY_EQUAL("1", result[0]);
    VERIFY_EQUAL("2", result[1]);
    VERIFY_EQUAL("", result[2]);
    
    input = ",,";
    result = Text::TextUtil::splitString(input, ',');
    VERIFY_EQUAL(3, static_cast<int>(result.size()));
    VERIFY_EQUAL("", result[0]);
    VERIFY_EQUAL("", result[1]);
    VERIFY_EQUAL("", result[2]);
}
