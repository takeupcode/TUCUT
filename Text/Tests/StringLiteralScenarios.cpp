//
//  StringLiteralScenarios.cpp
//  TestTUCUT
//
//  Created by Wahid Tanner on 8/3/14.
//  Copyright © 2014 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../StringLiteral.h"

using namespace std;
using namespace TUCUT;

SCENARIO( StringLiteral, "Construction/Normal", "unit,text", "StringLiteral can be constructed with a string literal." )
{
    constexpr Text::StringLiteral literal = "ABC";

    VERIFY_EQUAL('A', literal[0]);
    VERIFY_EQUAL('B', literal[1]);
    VERIFY_EQUAL('C', literal[2]);
    VERIFY_EQUAL('\0', literal[3]);
}

SCENARIO( StringLiteral, "Construction/Normal", "unit,text", "StringLiteral can be constructed with concatenated string literals." )
{
    constexpr Text::StringLiteral literal = "ABC";
    Text::StringLiteral combinedLiteral = literal + "DEF";
    
    // Avoid situations like this where temporaries are created.
    // Text::StringLiteral combinedLiteral = literal + "DEF" + "GHI";

    VERIFY_EQUAL('A', combinedLiteral[0]);
    VERIFY_EQUAL('B', combinedLiteral[1]);
    VERIFY_EQUAL('C', combinedLiteral[2]);
    VERIFY_EQUAL('D', combinedLiteral[3]);
    VERIFY_EQUAL('E', combinedLiteral[4]);
    VERIFY_EQUAL('F', combinedLiteral[5]);
    VERIFY_EQUAL('\0', combinedLiteral[6]);
}

SCENARIO( StringLiteral, "Construction/Normal", "unit,text", "StringLiteral can be constructed with concatenated StringLiterals." )
{
    constexpr Text::StringLiteral literal1 = "ABC";
    constexpr Text::StringLiteral literal2 = "DEF";
    Text::StringLiteral combinedLiteral = literal1 + literal2;

    VERIFY_EQUAL('A', combinedLiteral[0]);
    VERIFY_EQUAL('B', combinedLiteral[1]);
    VERIFY_EQUAL('C', combinedLiteral[2]);
    VERIFY_EQUAL('D', combinedLiteral[3]);
    VERIFY_EQUAL('E', combinedLiteral[4]);
    VERIFY_EQUAL('F', combinedLiteral[5]);
    VERIFY_EQUAL('\0', combinedLiteral[6]);
}

SCENARIO( StringLiteral, "Construction/Empty", "unit,text", "StringLiteral can be constructed with an empty string literal." )
{
    constexpr Text::StringLiteral literal = "";

    VERIFY_EQUAL('\0', literal[0]);
}

SCENARIO( StringLiteral, "Construction/Empty", "unit,text", "StringLiteral can append an empty string literal." )
{
    constexpr Text::StringLiteral literal = "ABC";
    Text::StringLiteral combinedLiteral = literal + "";

    VERIFY_EQUAL('A', combinedLiteral[0]);
    VERIFY_EQUAL('B', combinedLiteral[1]);
    VERIFY_EQUAL('C', combinedLiteral[2]);
    VERIFY_EQUAL('\0', combinedLiteral[3]);
}

SCENARIO( StringLiteral, "Construction/Empty", "unit,text", "Empty StringLiteral can append a string literal." )
{
    constexpr Text::StringLiteral literal = "";
    Text::StringLiteral combinedLiteral = literal + "ABC";

    VERIFY_EQUAL('A', combinedLiteral[0]);
    VERIFY_EQUAL('B', combinedLiteral[1]);
    VERIFY_EQUAL('C', combinedLiteral[2]);
    VERIFY_EQUAL('\0', combinedLiteral[3]);
}
