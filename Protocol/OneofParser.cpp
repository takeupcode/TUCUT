//
//  OneofParser.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 10/5/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "ParserManager.h"
#include "OneofModel.h"
#include "OneofParser.h"
#include "InvalidProtoException.h"

using namespace std;
using namespace TUCUT;

Protocol::OneofParser::OneofParser ()
{
}

bool Protocol::OneofParser::parse (TokenReader::iterator current, TokenReader::iterator end, bool, shared_ptr<ProtoModel> model)
{
    if (current != end && *current == "oneof")
    {
        // Move to the oneof name.
        ++current;
        if (current == end || current->empty())
        {
            throw InvalidProtoException(current.line(), current.column(), "Expected oneof name.");
        }
        shared_ptr<OneofModel> oneof(new OneofModel(*current));
        model->addOneof(current, oneof);

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
            for (auto & parser: *parserMgr->parsers("oneof"))
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
                for (auto & parser: *parserMgr->parsers("oneof"))
                {
                    if (parser->parse(current, end, false, model))
                    {
                        parserFound = true;
                        break;
                    }
                }
                if (!parserFound)
                {
                    throw InvalidProtoException(current.line(), current.column(), "Unexpected oneof content found.");
                }
            }
            ++current;
        }
        if (!closingBraceFound)
        {
            // We reached the end of the file without finding the closing brace.
            throw InvalidProtoException(current.line(), current.column(), "Expected } character or field definition.");
        }
        model->completeOneof();

        return true;
    }
    return false;
}
