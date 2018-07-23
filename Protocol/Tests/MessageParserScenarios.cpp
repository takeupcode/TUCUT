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

SCENARIO( MessageParser, "Construction/Normal", "unit,protocol", "MessageParser can be constructed." )
{
    Protocol::MessageParser parser;
}

SCENARIO( MessageParser, "Parsing/Normal", "unit,protocol", "MessageParser can parse empty message." )
{
    shared_ptr<Protocol::ProtoModel> model;
    string name = "empty";

    Protocol::ProtoParser parser("Messages/Message.proto");
    model = parser.parse();

    int count = 0;
    auto begin = model->messages()->cbegin();
    auto end = model->messages()->cend();
    while (begin != end)
    {
        count++;
        auto message = *begin;
        VERIFY_EQUAL(name, message->name());
        begin++;
    }
    VERIFY_EQUAL(1, count);
}

SCENARIO( MessageParser, "Parsing/Normal", "unit,protocol", "MessageParser can parse multiple empty messages." )
{
    shared_ptr<Protocol::ProtoModel> model;

    Protocol::ProtoParser parser("Messages/MessageMultiple.proto");
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
            VERIFY_EQUAL("one", message->name());
        }
        else
        {
            VERIFY_EQUAL("two", message->name());
        }
        VERIFY_EQUAL("", message->package());
        begin++;
    }
    VERIFY_EQUAL(2, count);
}

SCENARIO( MessageParser, "Parsing/Normal", "unit,protocol", "MessageParser can assign current package." )
{
    shared_ptr<Protocol::ProtoModel> model;

    Protocol::ProtoParser parser("Messages/MessageMultiplePackage.proto");
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
            VERIFY_EQUAL("abc", message->package());
        }
        else
        {
            VERIFY_EQUAL("def", message->package());
        }
        begin++;
    }
    VERIFY_EQUAL(2, count);
}

SCENARIO( MessageParser, "Parsing/Normal", "unit,protocol", "MessageParser can parse multiple nested messages." )
{
    shared_ptr<Protocol::ProtoModel> model;

    Protocol::ProtoParser parser("Messages/MessageNested.proto");
    model = parser.parse();

    int count1 = 0;
    auto begin1 = model->messages()->cbegin();
    auto end1 = model->messages()->cend();
    while (begin1 != end1)
    {
        count1++;
        auto message1 = *begin1;
        VERIFY_EQUAL("one", message1->name());

        int count2 = 0;
        auto begin2 = message1->messages()->cbegin();
        auto end2 = message1->messages()->cend();
        while (begin2 != end2)
        {
            count2++;
            auto message2 = *begin2;
            VERIFY_EQUAL("two", message2->name());

            int count3 = 0;
            auto begin3 = message2->messages()->cbegin();
            auto end3 = message2->messages()->cend();
            while (begin3 != end3)
            {
                count3++;
                auto message3 = *begin3;
                VERIFY_EQUAL("three", message3->name());
                begin3++;
            }
            VERIFY_EQUAL(1, count3);
            begin2++;
        }
        VERIFY_EQUAL(1, count2);
        begin1++;
    }
    VERIFY_EQUAL(1, count1);
}
