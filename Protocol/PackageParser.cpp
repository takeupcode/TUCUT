//
//  PackageParser.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 9/26/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <stdexcept>

#include "PackageParser.h"
#include "InvalidProtoException.h"

using namespace std;
using namespace TUCUT;

Protocol::PackageParser::PackageParser ()
{ }

bool Protocol::PackageParser::parse (TokenReader::iterator current, TokenReader::iterator end, bool, std::shared_ptr<ProtoModel> model)
{
    if (current != end && *current == "package")
    {
        // Move to the package name.
        ++current;
        if (current == end || current->empty())
        {
            throw InvalidProtoException(current.line(), current.column(), "Expected package name.");
        }
        string packageName = *current;

        // Move to the semicolon or further package names.
        ++current;
        if (current == end)
        {
            throw InvalidProtoException(current.line(), current.column(), "Expected ; character or further package names.");
        }
        while (*current != ";")
        {
            if (*current != ".")
            {
                throw InvalidProtoException(current.line(), current.column(), "Expected ; or . character.");
            }
            packageName += ".";

            // Move to the next package name.
            ++current;
            if (current == end || current->empty())
            {
                throw InvalidProtoException(current.line(), current.column(), "Expected package name.");
            }
            packageName += *current;

            // Move to the semicolon or further package names.
            ++current;
        }
        model->setPackage(packageName);

        return true;
    }
    return false;
}
