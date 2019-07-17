//
//  EnumParser.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 9/30/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "ParserManager.h"
#include "EnumModel.h"
#include "EnumParser.h"
#include "InvalidProtoException.h"

using namespace std;
using namespace TUCUT;

Protocol::EnumParser::EnumParser ()
{
}

bool Protocol::EnumParser::parse (TokenReader::iterator current, TokenReader::iterator end, bool, shared_ptr<ProtoModel> model)
{
    if (current != end && *current == "enum")
    {
        // Move to the enum name.
        ++current;
        if (current == end || current->empty())
        {
            throw InvalidProtoException(current.line(), current.column(), "Expected enum name.");
        }
        shared_ptr<EnumModel> enumeration(new EnumModel(*current));
        model->addEnum(current, enumeration);

        // Move to the opening brace.
        ++current;
        if (current == end || *current != "{")
        {
            throw InvalidProtoException(current.line(), current.column(), "Expected { character.");
        }

        // Process the contents.
        ParserManager * parserMgr = ParserManager::instance();
        bool closingBraceFound = false;
        ++current;
        while (current != end)
        {
            if (*current == "}")
            {
                closingBraceFound = true;
                break;
            }

            bool parserFound = false;
            for (auto & parser: *parserMgr->parsers("enum"))
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
                for (auto & parser: *parserMgr->parsers("enum"))
                {
                    if (parser->parse(current, end, false, model))
                    {
                        parserFound = true;
                        break;
                    }
                }
                if (!parserFound)
                {
                    throw InvalidProtoException(current.line(), current.column(), "Unexpected enum content found.");
                }
            }
            ++current;
        }
        if (!closingBraceFound)
        {
            // We reached the end of the file without finding the closing brace.
            throw InvalidProtoException(current.line(), current.column(), "Expected } character or enum value definition.");
        }
        model->completeEnum();

        return true;
    }
    return false;
}
