//
//  EnumValueParserScenarios.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 10/7/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../ProtoParser.h"
#include "../EnumValueParser.h"

using namespace std;
using namespace TUCUT;

SCENARIO( EnumValueParser, "Construction/Normal", "EnumValueParser can be constructed." )
{
    Protocol::EnumValueParser parser;
}

SCENARIO( EnumValueParser, "Parsing/Normal", "EnumParser can parse simple enum." )
{
    shared_ptr<Protocol::ProtoModel> model;

    Protocol::ProtoParser parser("EnumValue.proto");
    model = parser.parse();

    int count = 0;
    auto begin = model->enums()->cbegin();
    auto end = model->enums()->cend();
    while (begin != end)
    {
        count++;
        auto enumeration = *begin;
        verifyEqual("enumOne", enumeration->name());

        int valueCount = 0;
        auto begin1 = enumeration->enumValues()->cbegin();
        auto end1 = enumeration->enumValues()->cend();
        while (begin1 != end1)
        {
            valueCount++;
            auto value = *begin1;
            unsigned int expectedValue = 0;
            if (valueCount == 1)
            {
                verifyEqual("empty", value->name());
                expectedValue = 0;
                verifyEqual(expectedValue, value->value());
            }
            else
            {
                verifyEqual("full", value->name());
                expectedValue = 1;
                verifyEqual(expectedValue, value->value());
            }
            begin1++;
        }
        verifyEqual(2, valueCount);
        begin++;
    }
    verifyEqual(1, count);
}

SCENARIO( EnumValueParser, "Parsing/Normal", "EnumValueParser can parse multiple enums with values and different parents." )
{
    shared_ptr<Protocol::ProtoModel> model;

    Protocol::ProtoParser parser("EnumValueMultipleMessage.proto");
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

            int valueCount = 0;
            auto begin5 = enumeration->enumValues()->cbegin();
            auto end5 = enumeration->enumValues()->cend();
            while (begin5 != end5)
            {
                valueCount++;
                auto value = *begin5;
                unsigned int expectedValue = 0;
                if (valueCount == 1)
                {
                    verifyEqual("abc", value->name());
                    expectedValue = 5;
                    verifyEqual(expectedValue, value->value());
                }
                else
                {
                    verifyEqual("def", value->name());
                    expectedValue = 10;
                    verifyEqual(expectedValue, value->value());
                }
                begin5++;
            }
            verifyEqual(2, valueCount);
        }
        else
        {
            verifyEqual("enumZero2", enumeration->name());

            int valueCount = 0;
            auto begin5 = enumeration->enumValues()->cbegin();
            auto end5 = enumeration->enumValues()->cend();
            while (begin5 != end5)
            {
                valueCount++;
                auto value = *begin5;
                unsigned int expectedValue = 15;
                verifyEqual("ghi", value->name());
                verifyEqual(expectedValue, value->value());
                begin5++;
            }
            verifyEqual(1, valueCount);
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

                int valueCount = 0;
                auto begin5 = enumeration->enumValues()->cbegin();
                auto end5 = enumeration->enumValues()->cend();
                while (begin5 != end5)
                {
                    valueCount++;
                    auto value = *begin5;
                    unsigned int expectedValue = 0;
                    if (valueCount == 1)
                    {
                        verifyEqual("true", value->name());
                        expectedValue = 1;
                        verifyEqual(expectedValue, value->value());
                    }
                    else
                    {
                        verifyEqual("false", value->name());
                        expectedValue = 0;
                        verifyEqual(expectedValue, value->value());
                    }
                    begin5++;
                }
                verifyEqual(2, valueCount);
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

            int valueCount = 0;
            auto begin5 = enumeration->enumValues()->cbegin();
            auto end5 = enumeration->enumValues()->cend();
            while (begin5 != end5)
            {
                valueCount++;
                auto value = *begin5;
                unsigned int expectedValue = 0;
                if (valueCount == 1)
                {
                    verifyEqual("and", value->name());
                    expectedValue = 0;
                    verifyEqual(expectedValue, value->value());
                }
                else if (valueCount == 2)
                {
                    verifyEqual("or", value->name());
                    expectedValue = 1;
                    verifyEqual(expectedValue, value->value());
                }
                else
                {
                    verifyEqual("xor", value->name());
                    expectedValue = 2;
                    verifyEqual(expectedValue, value->value());
                }
                begin5++;
            }
            verifyEqual(3, valueCount);
            begin4++;
        }
        verifyEqual(1, enum1Count);
        verifyEqual(1, message2Count);
        begin1++;
    }
    verifyEqual(2, enum0Count);
    verifyEqual(1, message1Count);
}
