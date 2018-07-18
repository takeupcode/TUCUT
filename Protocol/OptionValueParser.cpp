//
//  OptionValueParser.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 10/9/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <memory>
#include <stdexcept>

#include "OptionModel.h"
#include "OptionValueParser.h"
#include "InvalidProtoException.h"

using namespace std;
using namespace TUCUT;

Protocol::OptionValueParser::OptionValueParser ()
{ }

bool Protocol::OptionValueParser::parse (TokenReader::iterator current, TokenReader::iterator end, bool firstChance, std::shared_ptr<ProtoModel> model)
{
    if (firstChance)
    {
        // This is a second chance parser.
        return false;
    }
    // Get the option name.
    if (current == end || current->empty())
    {
        throw InvalidProtoException(current.line(), current.column(), "Expected option name.");
    }
    string name = *current;

    // Move to the equal.
    ++current;
    if (current == end || *current != "=")
    {
        throw InvalidProtoException(current.line(), current.column(), "Expected = character.");
    }

    // Move to the option value.
    ++current;
    if (current == end || current->empty())
    {
        throw InvalidProtoException(current.line(), current.column(), "Expected option value.");
    }
    string value = "";
    if (*current == "\"")
    {
        ++current;
        if (current == end || current->empty())
        {
            throw InvalidProtoException(current.line(), current.column(), "Expected option value.");
        }
        value = *current;

        // Make sure there is a terminating quote.
        ++current;
        if (current == end || current->empty() || *current != "\"")
        {
            throw InvalidProtoException(current.line(), current.column(), "Expected ending quote character.");
        }
        // Move to the next token to be consistent with how we look for floating point values.
        ++current;
    }
    else
    {
        value = *current;
        // Either move to the terminating character or add to the value if we find a dot. This is not
        // like qualified type names where there can be multiple dots. Here, a dot is intended to be used
        // for a floating point value so there should only be one.
        ++current;
        if (current != end && *current == ".")
        {
            value += ".";
            ++current;
            if (current == end || current->empty())
            {
                throw InvalidProtoException(current.line(), current.column(), "Expected additional value.");
            }
            value += *current;
            // Move to the next token to be consistent with what happens if we do not find a dot.
            ++current;
        }
    }

    shared_ptr<OptionModel> option(new OptionModel(name, value));
    model->addOption(current, option);

    // This parser is designed to be used by either the OptionSingleParser or the OptionGroupParser and
    // does not verify the terminating character because there could be multiple options. It does have to
    // move to the terminating character in order to check if there is a dot.
    return true;
}
