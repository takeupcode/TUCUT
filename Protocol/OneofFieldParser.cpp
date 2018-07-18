//
//  OneofFieldParser.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 10/5/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "ParserManager.h"
#include "MessageFieldModel.h"
#include "OneofFieldParser.h"
#include "InvalidProtoException.h"

using namespace std;
using namespace TUCUT;

Protocol::OneofFieldParser::OneofFieldParser ()
{
}

bool Protocol::OneofFieldParser::parse (TokenReader::iterator current, TokenReader::iterator end, bool firstChance, shared_ptr<ProtoModel> model)
{
    if (firstChance)
    {
        // This is a second chance parser.
        return false;
    }
    if (current != end)
    {
        // Get the field type.
        if (current->empty())
        {
            throw InvalidProtoException(current.line(), current.column(), "Expected field type.");
        }
        string fieldType = *current;
        // Either move to the name or keep adding to the type if we find a dot.
        ++current;
        while (current != end && *current == ".")
        {
            fieldType += ".";
            ++current;
            if (current == end || current->empty())
            {
                throw InvalidProtoException(current.line(), current.column(), "Expected additional field type.");
            }
            fieldType += *current;
            ++current;
        }

        // Get the field name.
        if (current == end || current->empty())
        {
            throw InvalidProtoException(current.line(), current.column(), "Expected field name.");
        }
        string name = *current;

        // Move to the equal.
        ++current;
        if (current == end || *current != "=")
        {
            throw InvalidProtoException(current.line(), current.column(), "Expected = character.");
        }

        // Move to the field index.
        ++current;
        if (current == end || current->empty())
        {
            throw InvalidProtoException(current.line(), current.column(), "Expected field index.");
        }
        unsigned int index = stoi(*current);

        shared_ptr<MessageFieldModel> field(new MessageFieldModel(MessageFieldModel::Requiredness::optional, fieldType, name, index));
        model->addField(current, field);

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
            for (auto & parser: *parserMgr->parsers("oneofField"))
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
                for (auto & parser: *parserMgr->parsers("oneofField"))
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
        model->completeField();

        return true;
    }
    return false;
}
