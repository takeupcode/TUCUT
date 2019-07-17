//
//  OptionGroupParser.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 10/10/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <memory>
#include <stdexcept>

#include "ParserManager.h"
#include "OptionGroupParser.h"
#include "InvalidProtoException.h"

using namespace std;
using namespace TUCUT;

Protocol::OptionGroupParser::OptionGroupParser ()
{ }

bool Protocol::OptionGroupParser::parse (TokenReader::iterator current, TokenReader::iterator end, bool, std::shared_ptr<ProtoModel> model)
{
    if (current != end && *current == "[")
    {
        // Process the contents.
        ParserManager * parserMgr = ParserManager::instance();
        bool optionExpected = true;
        while (current != end)
        {
            ++current;
            bool parserFound = false;
            for (auto & parser: *parserMgr->parsers("option"))
            {
                if (parser->parse(current, end, true, model))
                {
                    optionExpected = false;
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
                        optionExpected = false;
                        parserFound = true;
                        break;
                    }
                }
                if (!parserFound)
                {
                    throw InvalidProtoException(current.line(), current.column(), "Unexpected option content found.");
                }
            }

            // Check for either the end of the group or another expected option.
            if (current != end && *current == "]")
            {
                break;
            }
            else if (current != end && *current == ",")
            {
                optionExpected = true;
            }
            else
            {
                throw InvalidProtoException(current.line(), current.column(), "Expected , or ] character.");
            }
        }
        if (optionExpected)
        {
            // We reached the end of the file without finding the next option.
            throw InvalidProtoException(current.line(), current.column(), "Expected ] character or option value definition.");
        }

        return true;
    }
    return false;
}
