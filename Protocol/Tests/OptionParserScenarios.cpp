//
//  OptionParserScenarios.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 10/11/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../ProtoParser.h"
#include "../OptionGroupParser.h"
#include "../OptionSingleParser.h"
#include "../OptionValueParser.h"

using namespace std;
using namespace TUCUT;

SCENARIO( OptionParser, "Construction/Normal", "unit,protocol", "OptionParser can be constructed." )
{
    Protocol::OptionGroupParser groupParser;
    Protocol::OptionSingleParser singleParser;
    Protocol::OptionValueParser valueParser;
}

SCENARIO( OptionParser, "Parsing/Normal", "unit,protocol", "OptionParser can parse enum option." )
{
    shared_ptr<Protocol::ProtoModel> model;
    Protocol::ProtoParser parser("Messages/OptionEnum.proto");
    model = parser.parse();

    int enumCount = 0;
    auto enumBegin = model->enums()->cbegin();
    auto enumEnd = model->enums()->cend();
    while (enumBegin != enumEnd)
    {
        enumCount++;
        auto enumeration = *enumBegin;
        VERIFY_EQUAL("enumOne", enumeration->name());

        int optionCount = 0;
        auto optionBegin = enumeration->options()->cbegin();
        auto optionEnd = enumeration->options()->cend();
        while (optionBegin != optionEnd)
        {
            optionCount++;
            auto option = *optionBegin;
            VERIFY_EQUAL("optionOne", option->name());
            VERIFY_EQUAL("true", option->value());
            optionBegin++;
        }
        VERIFY_EQUAL(1, optionCount);
        enumBegin++;
    }
    VERIFY_EQUAL(1, enumCount);
}

SCENARIO( OptionParser, "Parsing/Normal", "unit,protocol", "OptionParser can parse enum value option." )
{
    shared_ptr<Protocol::ProtoModel> model;
    Protocol::ProtoParser parser("Messages/OptionEnumValue.proto");
    model = parser.parse();

    int enumCount = 0;
    auto enumBegin = model->enums()->cbegin();
    auto enumEnd = model->enums()->cend();
    while (enumBegin != enumEnd)
    {
        enumCount++;
        auto enumeration = *enumBegin;
        VERIFY_EQUAL("enumOne", enumeration->name());

        int valueCount = 0;
        auto valueBegin = enumeration->enumValues()->cbegin();
        auto valueEnd = enumeration->enumValues()->cend();
        while (valueBegin != valueEnd)
        {
            valueCount++;
            auto value = *valueBegin;
            unsigned int expectedIndex = 0;
            if (valueCount == 1)
            {
                VERIFY_EQUAL("empty", value->name());
                expectedIndex = 0;
                VERIFY_EQUAL(expectedIndex, value->value());

                int optionCount = 0;
                auto optionBegin = value->options()->cbegin();
                auto optionEnd = value->options()->cend();
                while (optionBegin != optionEnd)
                {
                    optionCount++;
                    auto option = *optionBegin;
                    VERIFY_EQUAL("optionOne", option->name());
                    VERIFY_EQUAL("true", option->value());
                    optionBegin++;
                }
                VERIFY_EQUAL(1, optionCount);
            }
            else if (valueCount == 2)
            {
                VERIFY_EQUAL("full", value->name());
                expectedIndex = 1;
                VERIFY_EQUAL(expectedIndex, value->value());
            }
            valueBegin++;
        }
        VERIFY_EQUAL(2, valueCount);
        enumBegin++;
    }
    VERIFY_EQUAL(1, enumCount);
}

SCENARIO( OptionParser, "Parsing/Normal", "unit,protocol", "OptionParser can parse message option." )
{
    shared_ptr<Protocol::ProtoModel> model;
    Protocol::ProtoParser parser("Messages/OptionMessage.proto");
    model = parser.parse();

    int messageCount = 0;
    auto messageBegin = model->messages()->cbegin();
    auto MessageEnd = model->messages()->cend();
    while (messageBegin != MessageEnd)
    {
        messageCount++;
        auto message = *messageBegin;
        VERIFY_EQUAL("messageOne", message->name());

        int optionCount = 0;
        auto optionBegin = message->options()->cbegin();
        auto optionEnd = message->options()->cend();
        while (optionBegin != optionEnd)
        {
            optionCount++;
            auto option = *optionBegin;
            VERIFY_EQUAL("optionOne", option->name());
            VERIFY_EQUAL("true", option->value());
            optionBegin++;
        }
        VERIFY_EQUAL(1, optionCount);
        messageBegin++;
    }
    VERIFY_EQUAL(1, messageCount);
}

SCENARIO( OptionParser, "Parsing/Normal", "unit,protocol", "OptionParser can parse message field option." )
{
    shared_ptr<Protocol::ProtoModel> model;
    Protocol::ProtoParser parser("Messages/OptionMessageField.proto");
    model = parser.parse();

    int messageCount = 0;
    auto messageBegin = model->messages()->cbegin();
    auto MessageEnd = model->messages()->cend();
    while (messageBegin != MessageEnd)
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
            unsigned int expectedIndex = 0;
            if (fieldCount == 1)
            {
                VERIFY_EQUAL("sOne", field->name());
                expectedIndex = 1;
                VERIFY_EQUAL(expectedIndex, field->index());

                int optionCount = 0;
                auto optionBegin = field->options()->cbegin();
                auto optionEnd = field->options()->cend();
                while (optionBegin != optionEnd)
                {
                    optionCount++;
                    auto option = *optionBegin;
                    VERIFY_EQUAL("optionOne", option->name());
                    VERIFY_EQUAL("true", option->value());
                    optionBegin++;
                }
                VERIFY_EQUAL(1, optionCount);
            }
            else if (fieldCount == 2)
            {
                VERIFY_EQUAL("bOne", field->name());
                expectedIndex = 2;
                VERIFY_EQUAL(expectedIndex, field->index());
            }
            fieldBegin++;
        }
        VERIFY_EQUAL(2, fieldCount);
        messageBegin++;
    }
    VERIFY_EQUAL(1, messageCount);
}

SCENARIO( OptionParser, "Parsing/Normal", "unit,protocol", "OptionParser can parse oneof option." )
{
    shared_ptr<Protocol::ProtoModel> model;
    Protocol::ProtoParser parser("Messages/OptionOneof.proto");
    model = parser.parse();

    int messageCount = 0;
    auto messageBegin = model->messages()->cbegin();
    auto MessageEnd = model->messages()->cend();
    while (messageBegin != MessageEnd)
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

            int optionCount = 0;
            auto optionBegin = oneof->options()->cbegin();
            auto optionEnd = oneof->options()->cend();
            while (optionBegin != optionEnd)
            {
                optionCount++;
                auto option = *optionBegin;
                VERIFY_EQUAL("optionOne", option->name());
                VERIFY_EQUAL("true", option->value());
                optionBegin++;
            }
            VERIFY_EQUAL(1, optionCount);
            oneofBegin++;
        }
        VERIFY_EQUAL(1, oneofCount);
        messageBegin++;
    }
    VERIFY_EQUAL(1, messageCount);
}

SCENARIO( OptionParser, "Parsing/Normal", "unit,protocol", "OptionParser can parse oneof field option." )
{
    shared_ptr<Protocol::ProtoModel> model;
    Protocol::ProtoParser parser("Messages/OptionOneofField.proto");
    model = parser.parse();

    int messageCount = 0;
    auto messageBegin = model->messages()->cbegin();
    auto MessageEnd = model->messages()->cend();
    while (messageBegin != MessageEnd)
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
                unsigned int expectedIndex = 0;
                VERIFY_EQUAL("sOne", field->name());
                expectedIndex = 1;
                VERIFY_EQUAL(expectedIndex, field->index());

                int optionCount = 0;
                auto optionBegin = field->options()->cbegin();
                auto optionEnd = field->options()->cend();
                while (optionBegin != optionEnd)
                {
                    optionCount++;
                    auto option = *optionBegin;
                    VERIFY_EQUAL("optionOne", option->name());
                    VERIFY_EQUAL("true", option->value());
                    optionBegin++;
                }
                VERIFY_EQUAL(1, optionCount);
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

SCENARIO( OptionParser, "Parsing/Normal", "unit,protocol", "OptionParser can parse proto option." )
{
    shared_ptr<Protocol::ProtoModel> model;
    Protocol::ProtoParser parser("Messages/OptionProto.proto");
    model = parser.parse();

    int optionCount = 0;
    auto optionBegin = model->options()->cbegin();
    auto optionEnd = model->options()->cend();
    while (optionBegin != optionEnd)
    {
        optionCount++;
        auto option = *optionBegin;
        VERIFY_EQUAL("optionOne", option->name());
        VERIFY_EQUAL("true", option->value());
        optionBegin++;
    }
    VERIFY_EQUAL(1, optionCount);
}

SCENARIO( OptionParser, "Parsing/Normal", "unit,protocol", "OptionParser can parse floating point option value." )
{
    shared_ptr<Protocol::ProtoModel> model;
    Protocol::ProtoParser parser("Messages/OptionValueFloat.proto");
    model = parser.parse();

    int optionCount = 0;
    auto optionBegin = model->options()->cbegin();
    auto optionEnd = model->options()->cend();
    while (optionBegin != optionEnd)
    {
        optionCount++;
        auto option = *optionBegin;
        VERIFY_EQUAL("optionOne", option->name());
        VERIFY_EQUAL("3.14", option->value());
        optionBegin++;
    }
    VERIFY_EQUAL(1, optionCount);
}

SCENARIO( OptionParser, "Parsing/Normal", "unit,protocol", "OptionParser can parse string option value." )
{
    shared_ptr<Protocol::ProtoModel> model;
    Protocol::ProtoParser parser("Messages/OptionValueString.proto");
    model = parser.parse();

    int optionCount = 0;
    auto optionBegin = model->options()->cbegin();
    auto optionEnd = model->options()->cend();
    while (optionBegin != optionEnd)
    {
        optionCount++;
        auto option = *optionBegin;
        VERIFY_EQUAL("optionOne", option->name());
        VERIFY_EQUAL("This is a string option value.", option->value());
        optionBegin++;
    }
    VERIFY_EQUAL(1, optionCount);
}
