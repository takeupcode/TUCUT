//
//  OptionSingleParser.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 10/9/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <memory>
#include <stdexcept>

#include "ParserManager.h"
#include "OptionSingleParser.h"
#include "InvalidProtoException.h"

using namespace std;
using namespace TUCUT;

Protocol::OptionSingleParser::OptionSingleParser ()
{ }

bool Protocol::OptionSingleParser::parse (TokenReader::iterator current, TokenReader::iterator end, bool, std::shared_ptr<ProtoModel> model)
{
    if (current != end && *current == "option")
    {
        // Process the contents.
        ParserManager * parserMgr = ParserManager::instance();
        bool parserFound = false;
        ++current;
        for (auto & parser: *parserMgr->parsers("option"))
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
            for (auto & parser: *parserMgr->parsers("option"))
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

        // Get the semicolon.
        if (current == end || *current != ";")
        {
            throw InvalidProtoException(current.line(), current.column(), "Expected ; character.");
        }

        return true;
    }
    return false;
}
