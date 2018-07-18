//
//  MessageParserScenarios.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 9/27/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../ProtoParser.h"
#include "../MessageParser.h"

using namespace std;
using namespace TUCUT;

SCENARIO( MessageParser, "Construction/Normal", "MessageParser can be constructed." )
{
    Protocol::MessageParser parser;
}

SCENARIO( MessageParser, "Parsing/Normal", "MessageParser can parse empty message." )
{
    shared_ptr<Protocol::ProtoModel> model;
    string name = "empty";

    Protocol::ProtoParser parser("Message.proto");
    model = parser.parse();

    int count = 0;
    auto begin = model->messages()->cbegin();
    auto end = model->messages()->cend();
    while (begin != end)
    {
        count++;
        auto message = *begin;
        verifyEqual(name, message->name());
        begin++;
    }
    verifyEqual(1, count);
}

SCENARIO( MessageParser, "Parsing/Normal", "MessageParser can parse multiple empty messages." )
{
    shared_ptr<Protocol::ProtoModel> model;

    Protocol::ProtoParser parser("MessageMultiple.proto");
    model = parser.parse();

    int count = 0;
    auto begin = model->messages()->cbegin();
    auto end = model->messages()->cend();
    while (begin != end)
    {
        count++;
        auto message = *begin;
        if (count == 1)
        {
            verifyEqual("one", message->name());
        }
        else
        {
            verifyEqual("two", message->name());
        }
        verifyEqual("", message->package());
        begin++;
    }
    verifyEqual(2, count);
}

SCENARIO( MessageParser, "Parsing/Normal", "MessageParser can assign current package." )
{
    shared_ptr<Protocol::ProtoModel> model;

    Protocol::ProtoParser parser("MessageMultiplePackage.proto");
    model = parser.parse();

    int count = 0;
    auto begin = model->messages()->cbegin();
    auto end = model->messages()->cend();
    while (begin != end)
    {
        count++;
        auto message = *begin;
        if (count == 1)
        {
            verifyEqual("abc", message->package());
        }
        else
        {
            verifyEqual("def", message->package());
        }
        begin++;
    }
    verifyEqual(2, count);
}

SCENARIO( MessageParser, "Parsing/Normal", "MessageParser can parse multiple nested messages." )
{
    shared_ptr<Protocol::ProtoModel> model;

    Protocol::ProtoParser parser("MessageNested.proto");
    model = parser.parse();

    int count1 = 0;
    auto begin1 = model->messages()->cbegin();
    auto end1 = model->messages()->cend();
    while (begin1 != end1)
    {
        count1++;
        auto message1 = *begin1;
        verifyEqual("one", message1->name());

        int count2 = 0;
        auto begin2 = message1->messages()->cbegin();
        auto end2 = message1->messages()->cend();
        while (begin2 != end2)
        {
            count2++;
            auto message2 = *begin2;
            verifyEqual("two", message2->name());

            int count3 = 0;
            auto begin3 = message2->messages()->cbegin();
            auto end3 = message2->messages()->cend();
            while (begin3 != end3)
            {
                count3++;
                auto message3 = *begin3;
                verifyEqual("three", message3->name());
                begin3++;
            }
            verifyEqual(1, count3);
            begin2++;
        }
        verifyEqual(1, count2);
        begin1++;
    }
    verifyEqual(1, count1);
}
