//
//  EnumParserScenarios.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 10/1/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../ProtoParser.h"
#include "../EnumParser.h"

using namespace std;
using namespace TUCUT;

SCENARIO( EnumParser, "Construction/Normal", "EnumParser can be constructed." )
{
    Protocol::EnumParser parser;
}

SCENARIO( EnumParser, "Parsing/Normal", "EnumParser can parse empty enum." )
{
    shared_ptr<Protocol::ProtoModel> model;
    string name = "empty";

    Protocol::ProtoParser parser("Enum.proto");
    model = parser.parse();

    int count = 0;
    auto begin = model->enums()->cbegin();
    auto end = model->enums()->cend();
    while (begin != end)
    {
        count++;
        auto enumeration = *begin;
        verifyEqual(name, enumeration->name());
        begin++;
    }
    verifyEqual(1, count);
}

SCENARIO( EnumParser, "Parsing/Normal", "EnumParser can parse multiple empty enums." )
{
    shared_ptr<Protocol::ProtoModel> model;

    Protocol::ProtoParser parser("EnumMultiple.proto");
    model = parser.parse();

    int count = 0;
    auto begin = model->enums()->cbegin();
    auto end = model->enums()->cend();
    while (begin != end)
    {
        count++;
        auto enumeration = *begin;
        if (count == 1)
        {
            verifyEqual("one", enumeration->name());
        }
        else
        {
            verifyEqual("two", enumeration->name());
        }
        verifyEqual("", enumeration->package());
        begin++;
    }
    verifyEqual(2, count);
}

SCENARIO( EnumParser, "Parsing/Normal", "EnumParser can parse multiple empty enums with different parents." )
{
    shared_ptr<Protocol::ProtoModel> model;

    Protocol::ProtoParser parser("EnumMultipleMessage.proto");
    model = parser.parse();

    int enum0Count = 0;
    auto begin = model->enums()->cbegin();
    auto end = model->enums()->cend();
    while (begin != end)
    {
        enum0Count++;
        auto enumeration = *begin;
        if (enum0Count == 1)
        {
            verifyEqual("enumZero1", enumeration->name());
        }
        else
        {
            verifyEqual("enumZero2", enumeration->name());
        }
        verifyEqual("", enumeration->package());
        begin++;
    }

    int message1Count = 0;
    auto begin1 = model->messages()->cbegin();
    auto end1 = model->messages()->cend();
    while (begin1 != end1)
    {
        message1Count++;
        auto message1 = *begin1;
        verifyEqual("messageOne", message1->name());

        int message2Count = 0;
        auto begin2 = message1->messages()->cbegin();
        auto end2 = message1->messages()->cend();
        while (begin2 != end2)
        {
            message2Count++;
            auto message2 = *begin2;
            verifyEqual("messageTwo", message2->name());

            int enum2Count = 0;
            auto begin3 = message2->enums()->cbegin();
            auto end3 = message2->enums()->cend();
            while (begin3 != end3)
            {
                enum2Count++;
                auto enumeration = *begin3;
                verifyEqual("enumTwo", enumeration->name());
                verifyEqual("", enumeration->package());
                begin3++;
            }
            verifyEqual(1, enum2Count);
            begin2++;
        }

        int enum1Count = 0;
        auto begin4 = message1->enums()->cbegin();
        auto end4 = message1->enums()->cend();
        while (begin4 != end4)
        {
            enum1Count++;
            auto enumeration = *begin4;
            verifyEqual("enumOne", enumeration->name());
            verifyEqual("", enumeration->package());
            begin4++;
        }
        verifyEqual(1, enum1Count);
        verifyEqual(1, message2Count);
        begin1++;
    }
    verifyEqual(2, enum0Count);
    verifyEqual(1, message1Count);
}

SCENARIO( EnumParser, "Parsing/Normal", "EnumParser can assign current package." )
{
    shared_ptr<Protocol::ProtoModel> model;

    Protocol::ProtoParser parser("EnumMultiplePackage.proto");
    model = parser.parse();

    int count = 0;
    auto begin = model->enums()->cbegin();
    auto end = model->enums()->cend();
    while (begin != end)
    {
        count++;
        auto enumeration = *begin;
        if (count == 1)
        {
            verifyEqual("abc", enumeration->package());
        }
        else
        {
            verifyEqual("def", enumeration->package());
        }
        begin++;
    }
    verifyEqual(2, count);
}
