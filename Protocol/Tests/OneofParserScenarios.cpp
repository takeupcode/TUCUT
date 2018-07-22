//
//  OneofParserScenarios.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 10/5/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../ProtoParser.h"
#include "../OneofParser.h"

using namespace std;
using namespace TUCUT;

SCENARIO( OneofParser, "Construction/Normal", "unit", "OneofParser can be constructed." )
{
    Protocol::OneofParser parser;
}

SCENARIO( OneofParser, "Parsing/Normal", "unit", "OneofParser can parse simple message." )
{
    shared_ptr<Protocol::ProtoModel> model;

    Protocol::ProtoParser parser("MessageOneof.proto");
    model = parser.parse();

    int messageCount = 0;
    auto begin1 = model->messages()->cbegin();
    auto end1 = model->messages()->cend();
    while (begin1 != end1)
    {
        messageCount++;
        auto message = *begin1;
        VERIFY_EQUAL("messageOneof", message->name());
        VERIFY_TRUE(message->fields()->empty());

        int oneofCount = 0;
        auto begin2 = message->oneofs()->cbegin();
        auto end2 = message->oneofs()->cend();
        while (begin2 != end2)
        {
            oneofCount++;
            auto oneof = *begin2;

            int fieldCount = 0;
            auto begin3 = oneof->fields()->cbegin();
            auto end3 = oneof->fields()->cend();
            while (begin3 != end3)
            {
                fieldCount++;
                auto field = *begin3;
                if (fieldCount == 1)
                {
                    VERIFY_TRUE(Protocol::MessageFieldModel::Requiredness::optional == field->requiredness());
                    VERIFY_EQUAL("string", field->fieldType());
                    VERIFY_EQUAL("sOne", field->name());
                    unsigned int expectedIndex = 1;
                    VERIFY_EQUAL(expectedIndex, field->index());
                }
                else if (fieldCount == 2)
                {
                    VERIFY_TRUE(Protocol::MessageFieldModel::Requiredness::optional == field->requiredness());
                    VERIFY_EQUAL("bool", field->fieldType());
                    VERIFY_EQUAL("bOne", field->name());
                    unsigned int expectedIndex = 2;
                    VERIFY_EQUAL(expectedIndex, field->index());
                }
                else if (fieldCount == 3)
                {
                    VERIFY_TRUE(Protocol::MessageFieldModel::Requiredness::optional == field->requiredness());
                    VERIFY_EQUAL("int32", field->fieldType());
                    VERIFY_EQUAL("iOne", field->name());
                    unsigned int expectedIndex = 3;
                    VERIFY_EQUAL(expectedIndex, field->index());
                }
                begin3++;
            }
            VERIFY_EQUAL(3, fieldCount);
            begin2++;
        }
        VERIFY_EQUAL(1, oneofCount);
        begin1++;
    }
    VERIFY_EQUAL(1, messageCount);
}

SCENARIO( OneofParser, "Parsing/Normal", "unit", "OneofParser can parse oneof field with qualified type." )
{
    shared_ptr<Protocol::ProtoModel> model;

    Protocol::ProtoParser parser("MessageOneofQualified.proto");
    model = parser.parse();

    int messageCount = 0;
    auto messageBegin = model->messages()->cbegin();
    auto messageEnd = model->messages()->cend();
    while (messageBegin != messageEnd)
    {
        messageCount++;
        auto message = *messageBegin;
        VERIFY_EQUAL("messageOne", message->name());

        int oneofCount = 0;
        auto oneofBegin = message->oneofs()->cbegin();
        auto oneofEnd = message->oneofs()->cend();
        while (oneofBegin != oneofEnd)
        {
            oneofCount++;
            auto oneof = *oneofBegin;
            VERIFY_EQUAL("choicesOne", oneof->name());

            int fieldCount = 0;
            auto fieldBegin = oneof->fields()->cbegin();
            auto fieldEnd = oneof->fields()->cend();
            while (fieldBegin != fieldEnd)
            {
                fieldCount++;
                auto field = *fieldBegin;
                VERIFY_TRUE(Protocol::MessageFieldModel::Requiredness::optional == field->requiredness());
                VERIFY_EQUAL("Abc.Simple", field->fieldType());
                VERIFY_EQUAL("sOne", field->name());
                unsigned int expectedIndex = 1;
                VERIFY_EQUAL(expectedIndex, field->index());
                fieldBegin++;
            }
            VERIFY_EQUAL(1, fieldCount);
            oneofBegin++;
        }
        VERIFY_EQUAL(1, oneofCount);
        messageBegin++;
    }
    VERIFY_EQUAL(1, messageCount);
}

SCENARIO( OneofParser, "Parsing/Normal", "unit", "OneofParser can parse multiple nested messages with oneofs." )
{
    shared_ptr<Protocol::ProtoModel> model;

    Protocol::ProtoParser parser("MessageOneofMultiple.proto");
    model = parser.parse();

    int message1Count = 0;
    auto begin1 = model->messages()->cbegin();
    auto end1 = model->messages()->cend();
    while (begin1 != end1)
    {
        message1Count++;
        auto message1 = *begin1;
        unsigned long expectedSize = 1;
        VERIFY_EQUAL("messageOne", message1->name());
        VERIFY_EQUAL(expectedSize, message1->fields()->size());

        int oneof1Count = 0;
        auto begin2 = message1->oneofs()->cbegin();
        auto end2 = message1->oneofs()->cend();
        while (begin2 != end2)
        {
            oneof1Count++;
            auto oneof = *begin2;

            int fieldCount = 0;
            auto begin3 = oneof->fields()->cbegin();
            auto end3 = oneof->fields()->cend();
            while (begin3 != end3)
            {
                fieldCount++;
                auto field = *begin3;
                if (oneof1Count == 1)
                {
                    if (fieldCount == 1)
                    {
                        VERIFY_TRUE(Protocol::MessageFieldModel::Requiredness::optional == field->requiredness());
                        VERIFY_EQUAL("string", field->fieldType());
                        VERIFY_EQUAL("sOne", field->name());
                        unsigned int expectedIndex = 1;
                        VERIFY_EQUAL(expectedIndex, field->index());
                    }
                    else if (fieldCount == 2)
                    {
                        VERIFY_TRUE(Protocol::MessageFieldModel::Requiredness::optional == field->requiredness());
                        VERIFY_EQUAL("bool", field->fieldType());
                        VERIFY_EQUAL("bOne", field->name());
                        unsigned int expectedIndex = 2;
                        VERIFY_EQUAL(expectedIndex, field->index());
                    }
                }
                else if (oneof1Count == 2)
                {
                    if (fieldCount == 1)
                    {
                        VERIFY_TRUE(Protocol::MessageFieldModel::Requiredness::optional == field->requiredness());
                        VERIFY_EQUAL("bool", field->fieldType());
                        VERIFY_EQUAL("bThree", field->name());
                        unsigned int expectedIndex = 3;
                        VERIFY_EQUAL(expectedIndex, field->index());
                    }
                    else if (fieldCount == 2)
                    {
                        VERIFY_TRUE(Protocol::MessageFieldModel::Requiredness::optional == field->requiredness());
                        VERIFY_EQUAL("int32", field->fieldType());
                        VERIFY_EQUAL("iThree", field->name());
                        unsigned int expectedIndex = 4;
                        VERIFY_EQUAL(expectedIndex, field->index());
                    }
                }
                begin3++;
            }
            VERIFY_EQUAL(2, fieldCount);
            begin2++;
        }

        int message2Count = 0;
        auto begin4 = message1->messages()->cbegin();
        auto end4 = message1->messages()->cend();
        while (begin4 != end4)
        {
            message2Count++;
            auto message2 = *begin4;
            VERIFY_EQUAL("messageTwo", message2->name());
            VERIFY_EQUAL(expectedSize, message2->fields()->size());

            int oneof2Count = 0;
            auto begin5 = message2->oneofs()->cbegin();
            auto end5 = message2->oneofs()->cend();
            while (begin5 != end5)
            {
                oneof2Count++;
                auto oneof = *begin5;

                int fieldCount = 0;
                auto begin6 = oneof->fields()->cbegin();
                auto end6 = oneof->fields()->cend();
                while (begin6 != end6)
                {
                    fieldCount++;
                    auto field = *begin6;
                    if (fieldCount == 1)
                    {
                        VERIFY_TRUE(Protocol::MessageFieldModel::Requiredness::optional == field->requiredness());
                        VERIFY_EQUAL("string", field->fieldType());
                        VERIFY_EQUAL("sTwo", field->name());
                        unsigned int expectedIndex = 1;
                        VERIFY_EQUAL(expectedIndex, field->index());
                    }
                    else if (fieldCount == 2)
                    {
                        VERIFY_TRUE(Protocol::MessageFieldModel::Requiredness::optional == field->requiredness());
                        VERIFY_EQUAL("int32", field->fieldType());
                        VERIFY_EQUAL("iTwo", field->name());
                        unsigned int expectedIndex = 2;
                        VERIFY_EQUAL(expectedIndex, field->index());
                    }
                    begin6++;
                }
                VERIFY_EQUAL(2, fieldCount);
                begin5++;
            }
            VERIFY_EQUAL(1, oneof2Count);
            begin4++;
        }
        VERIFY_EQUAL(1, message2Count);
        VERIFY_EQUAL(2, oneof1Count);
        begin1++;
    }
    VERIFY_EQUAL(1, message1Count);
}
