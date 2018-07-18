//
//  EnumValueParser.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 10/6/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <memory>
#include <stdexcept>

#include "ParserManager.h"
#include "EnumValueModel.h"
#include "EnumValueParser.h"
#include "InvalidProtoException.h"

using namespace std;
using namespace TUCUT;

Protocol::EnumValueParser::EnumValueParser ()
{ }

bool Protocol::EnumValueParser::parse (TokenReader::iterator current, TokenReader::iterator end, bool firstChance, std::shared_ptr<ProtoModel> model)
{
    if (firstChance)
    {
        // This is a second chance parser.
        return false;
    }
    if (current != end)
    {
        // Get the value name.
        if (current->empty())
        {
            throw InvalidProtoException(current.line(), current.column(), "Expected enum value name.");
        }
        string name = *current;

        // Move to the equal.
        ++current;
        if (current == end || *current != "=")
        {
            throw InvalidProtoException(current.line(), current.column(), "Expected = character.");
        }

        // Move to the value value.
        ++current;
        if (current == end || current->empty())
        {
            throw InvalidProtoException(current.line(), current.column(), "Expected enum value value.");
        }
        unsigned int index = stoi(*current);

        shared_ptr<EnumValueModel> value(new EnumValueModel(name, index));
        model->addEnumValue(current, value);

        // Move to the semicolon or inline options.
        ParserManager * parserMgr = ParserManager::instance();
        ++current;
        if (current == end)
        {
            throw InvalidProtoException(current.line(), current.column(), "Expected ; or [ character.");
        }
        if (*current != ";")
        {
            bool parserFound = false;
            for (auto & parser: *parserMgr->parsers("enumValue"))
            {
                if (parser->parse(current, end, true, model))
                {
                    parserFound = true;
                    break;
                }
            }
            if (!parserFound)
            {
                // Try again for the second chance parsers.
                for (auto & parser: *parserMgr->parsers("enumValue"))
                {
                    if (parser->parse(current, end, false, model))
                    {
                        parserFound = true;
                        break;
                    }
                }
                if (!parserFound)
                {
                    throw InvalidProtoException(current.line(), current.column(), "Unexpected option content found.");
                }
            }

            // Move to the semicolon.
            ++current;
            if (current == end || *current != ";")
            {
                throw InvalidProtoException(current.line(), current.column(), "Expected ; character.");
            }
        }
        model->completeEnumValue();

        return true;
    }
    return false;
}
