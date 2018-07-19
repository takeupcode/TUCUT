//
//  MessageFieldParserScenarios.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 10/3/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../ProtoParser.h"
#include "../MessageFieldParser.h"

using namespace std;
using namespace TUCUT;

SCENARIO( MessageFieldParser, "Construction/Normal", "unit", "MessageFieldParser can be constructed." )
{
    Protocol::MessageFieldParser parser;
}

SCENARIO( MessageFieldParser, "Parsing/Normal", "unit", "MessageFieldParser can parse simple message." )
{
    shared_ptr<Protocol::ProtoModel> model;

    Protocol::ProtoParser parser("MessageField.proto");
    model = parser.parse();

    int messageCount = 0;
    auto messageBegin = model->messages()->cbegin();
    auto messageEnd = model->messages()->cend();
    while (messageBegin != messageEnd)
    {
        messageCount++;
        auto message = *messageBegin;
        verifyEqual("messageOne", message->name());

        int fieldCount = 0;
        auto fieldBegin = message->fields()->cbegin();
        auto fieldEnd = message->fields()->cend();
        while (fieldBegin != fieldEnd)
        {
            fieldCount++;
            auto field = *fieldBegin;
            if (fieldCount == 1)
            {
                verifyTrue(Protocol::MessageFieldModel::Requiredness::required == field->requiredness());
                verifyEqual("string", field->fieldType());
                verifyEqual("sOne", field->name());
                unsigned int expectedIndex = 1;
                verifyEqual(expectedIndex, field->index());
            }
            else if (fieldCount == 2)
            {
                verifyTrue(Protocol::MessageFieldModel::Requiredness::optional == field->requiredness());
                verifyEqual("bool", field->fieldType());
                verifyEqual("bOne", field->name());
                unsigned int expectedIndex = 2;
                verifyEqual(expectedIndex, field->index());
            }
            else if (fieldCount == 3)
            {
                verifyTrue(Protocol::MessageFieldModel::Requiredness::repeated == field->requiredness());
                verifyEqual("int32", field->fieldType());
                verifyEqual("iOne", field->name());
                unsigned int expectedIndex = 3;
                verifyEqual(expectedIndex, field->index());
            }
            fieldBegin++;
        }
        verifyEqual(3, fieldCount);
        messageBegin++;
    }
    verifyEqual(1, messageCount);
}

SCENARIO( MessageFieldParser, "Parsing/Normal", "unit", "MessageFieldParser can parse message field with qualified type." )
{
    shared_ptr<Protocol::ProtoModel> model;

    Protocol::ProtoParser parser("MessageFieldQualified.proto");
    model = parser.parse();

    int messageCount = 0;
    auto messageBegin = model->messages()->cbegin();
    auto messageEnd = model->messages()->cend();
    while (messageBegin != messageEnd)
    {
        messageCount++;
        auto message = *messageBegin;
        verifyEqual("messageOne", message->name());

        int fieldCount = 0;
        auto fieldBegin = message->fields()->cbegin();
        auto fieldEnd = message->fields()->cend();
        while (fieldBegin != fieldEnd)
        {
            fieldCount++;
            auto field = *fieldBegin;
            verifyTrue(Protocol::MessageFieldModel::Requiredness::required == field->requiredness());
            verifyEqual("Abc.Simple", field->fieldType());
            verifyEqual("sOne", field->name());
            unsigned int expectedIndex = 1;
            verifyEqual(expectedIndex, field->index());
            fieldBegin++;
        }
        verifyEqual(1, fieldCount);
        messageBegin++;
    }
    verifyEqual(1, messageCount);
}

SCENARIO( MessageFieldParser, "Parsing/Normal", "unit", "MessageFieldParser can parse multiple nested messages with fields." )
{
    shared_ptr<Protocol::ProtoModel> model;

    Protocol::ProtoParser parser("MessageFieldMultiple.proto");
    model = parser.parse();

    int messageCount = 0;
    auto messageBegin = model->messages()->cbegin();
    auto messageEnd = model->messages()->cend();
    while (messageBegin != messageEnd)
    {
        messageCount++;
        auto messageOne = *messageBegin;
        verifyEqual("messageOne", messageOne->name());

        int messageOneFieldCount = 0;
        auto messageOneFieldBegin = messageOne->fields()->cbegin();
        auto messageOneFieldEnd = messageOne->fields()->cend();
        while (messageOneFieldBegin != messageOneFieldEnd)
        {
            messageOneFieldCount++;
            auto field = *messageOneFieldBegin;
            if (messageOneFieldCount == 1)
            {
                verifyEqual("sOne", field->name());
            }
            else
            {
                verifyEqual("bOne", field->name());
            }
            messageOneFieldBegin++;
        }

        int messageOneMessageCount = 0;
        auto messageOneMessageBegin = messageOne->messages()->cbegin();
        auto messageOneMessageEnd = messageOne->messages()->cend();
        while (messageOneMessageBegin != messageOneMessageEnd)
        {
            messageOneMessageCount++;
            auto messageTwo = *messageOneMessageBegin;
            verifyEqual("messageTwo", messageTwo->name());

            int messageTwoFieldCount = 0;
            auto messageTwoFieldBegin = messageTwo->fields()->cbegin();
            auto messageTwoFieldEnd = messageTwo->fields()->cend();
            while (messageTwoFieldBegin != messageTwoFieldEnd)
            {
                messageTwoFieldCount++;
                auto field = *messageTwoFieldBegin;
                verifyEqual("sTwo", field->name());
                messageTwoFieldBegin++;
            }
            verifyEqual(1, messageTwoFieldCount);
            messageOneMessageBegin++;
        }
        verifyEqual(2, messageOneFieldCount);
        verifyEqual(1, messageOneMessageCount);
        messageBegin++;
    }
    verifyEqual(1, messageCount);
}
