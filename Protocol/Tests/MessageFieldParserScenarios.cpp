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
        VERIFY_EQUAL("messageOne", message->name());

        int fieldCount = 0;
        auto fieldBegin = message->fields()->cbegin();
        auto fieldEnd = message->fields()->cend();
        while (fieldBegin != fieldEnd)
        {
            fieldCount++;
            auto field = *fieldBegin;
            if (fieldCount == 1)
            {
                VERIFY_TRUE(Protocol::MessageFieldModel::Requiredness::required == field->requiredness());
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
                VERIFY_TRUE(Protocol::MessageFieldModel::Requiredness::repeated == field->requiredness());
                VERIFY_EQUAL("int32", field->fieldType());
                VERIFY_EQUAL("iOne", field->name());
                unsigned int expectedIndex = 3;
                VERIFY_EQUAL(expectedIndex, field->index());
            }
            fieldBegin++;
        }
        VERIFY_EQUAL(3, fieldCount);
        messageBegin++;
    }
    VERIFY_EQUAL(1, messageCount);
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
        VERIFY_EQUAL("messageOne", message->name());

        int fieldCount = 0;
        auto fieldBegin = message->fields()->cbegin();
        auto fieldEnd = message->fields()->cend();
        while (fieldBegin != fieldEnd)
        {
            fieldCount++;
            auto field = *fieldBegin;
            VERIFY_TRUE(Protocol::MessageFieldModel::Requiredness::required == field->requiredness());
            VERIFY_EQUAL("Abc.Simple", field->fieldType());
            VERIFY_EQUAL("sOne", field->name());
            unsigned int expectedIndex = 1;
            VERIFY_EQUAL(expectedIndex, field->index());
            fieldBegin++;
        }
        VERIFY_EQUAL(1, fieldCount);
        messageBegin++;
    }
    VERIFY_EQUAL(1, messageCount);
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
        VERIFY_EQUAL("messageOne", messageOne->name());

        int messageOneFieldCount = 0;
        auto messageOneFieldBegin = messageOne->fields()->cbegin();
        auto messageOneFieldEnd = messageOne->fields()->cend();
        while (messageOneFieldBegin != messageOneFieldEnd)
        {
            messageOneFieldCount++;
            auto field = *messageOneFieldBegin;
            if (messageOneFieldCount == 1)
            {
                VERIFY_EQUAL("sOne", field->name());
            }
            else
            {
                VERIFY_EQUAL("bOne", field->name());
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
            VERIFY_EQUAL("messageTwo", messageTwo->name());

            int messageTwoFieldCount = 0;
            auto messageTwoFieldBegin = messageTwo->fields()->cbegin();
            auto messageTwoFieldEnd = messageTwo->fields()->cend();
            while (messageTwoFieldBegin != messageTwoFieldEnd)
            {
                messageTwoFieldCount++;
                auto field = *messageTwoFieldBegin;
                VERIFY_EQUAL("sTwo", field->name());
                messageTwoFieldBegin++;
            }
            VERIFY_EQUAL(1, messageTwoFieldCount);
            messageOneMessageBegin++;
        }
        VERIFY_EQUAL(2, messageOneFieldCount);
        VERIFY_EQUAL(1, messageOneMessageCount);
        messageBegin++;
    }
    VERIFY_EQUAL(1, messageCount);
}
