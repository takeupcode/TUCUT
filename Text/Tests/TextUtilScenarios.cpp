//
//  TextUtilScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 7/20/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//
#include "../../Test/Test.h"

#include "../TextUtil.h"

#include <string>

using namespace std;
using namespace TUCUT;

SCENARIO( TextUtil, "Operation/Normal", "unit,text", "TextUtil knows whitespace." )
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

SCENARIO( TextUtil, "Operation/Normal", "unit,text", "TextUtil can split strings." )
{
    std::string input = "1,2,3";
    auto result = Text::TextUtil::splitString(input, ',');
    VERIFY_EQUAL(3, static_cast<int>(result.size()));
    VERIFY_EQUAL("1", result[0]);
    VERIFY_EQUAL("2", result[1]);
    VERIFY_EQUAL("3", result[2]);
}

SCENARIO( TextUtil, "Operation/Corner", "unit,text", "TextUtil can split strings with empty spots." )
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

SCENARIO( TextUtil, "Operation/Corner", "unit,text", "TextUtil can replace empty strings." )
{
    std::string input = "";
    std::string search = "abc";
    std::string replace = "new";
    std::string result = input;
    Text::TextUtil::replaceAll(result, search, replace);
    VERIFY_EQUAL(input, result);

    input = "abc";
    search = "";
    replace = "new";
    result = input;
    Text::TextUtil::replaceAll(result, search, replace);
    VERIFY_EQUAL(input, result);

    input = "abc";
    search = "def";
    replace = "";
    result = input;
    Text::TextUtil::replaceAll(result, search, replace);
    VERIFY_EQUAL(input, result);

    input = "abcd";
    search = "bc";
    replace = "";
    result = input;
    Text::TextUtil::replaceAll(result, search, replace);
    VERIFY_EQUAL("ad", result);
}

SCENARIO( TextUtil, "Operation/Corner", "unit,text", "TextUtil can replace full strings." )
{
    std::string input = "abc";
    std::string search = "abc";
    std::string replace = "new";
    std::string result = input;
    Text::TextUtil::replaceAll(result, search, replace);
    VERIFY_EQUAL(replace, result);
}

SCENARIO( TextUtil, "Operation/Corner", "unit,text", "TextUtil can replace strings at beginning and end." )
{
    std::string input = "abcd";
    std::string search = "ab";
    std::string replace = "new";
    std::string result = input;
    Text::TextUtil::replaceAll(result, search, replace);
    VERIFY_EQUAL("newcd", result);

    input = "abcd";
    search = "cd";
    replace = "new";
    result = input;
    Text::TextUtil::replaceAll(result, search, replace);
    VERIFY_EQUAL("abnew", result);
}

SCENARIO( TextUtil, "Operation/Normal", "unit,text", "TextUtil can replace strings." )
{
    std::string input = "abcdef";
    std::string search = "cd";
    std::string replace = "x";
    std::string result = input;
    Text::TextUtil::replaceAll(result, search, replace);
    VERIFY_EQUAL("abxef", result);

    input = "abcdef";
    search = "cd";
    replace = "xyz";
    result = input;
    Text::TextUtil::replaceAll(result, search, replace);
    VERIFY_EQUAL("abxyzef", result);

    input = "abcabd";
    search = "ab";
    replace = "gone";
    result = input;
    Text::TextUtil::replaceAll(result, search, replace);
    VERIFY_EQUAL("gonecgoned", result);

    input = "abcd";
    search = "xyz";
    replace = "notfound";
    result = input;
    Text::TextUtil::replaceAll(result, search, replace);
    VERIFY_EQUAL(input, result);}
