//
//  PackageParserScenarios.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 9/27/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../ProtoParser.h"
#include "../PackageParser.h"

using namespace std;
using namespace TUCUT;

SCENARIO( PackageParser, "Construction/Normal", "unit,protocol", "PackageParser can be constructed." )
{
    Protocol::PackageParser parser;
}

SCENARIO( PackageParser, "Parsing/Normal", "unit,protocol", "PackageParser can parse package." )
{
    shared_ptr<Protocol::ProtoModel> model;
    string package = "TUCUT.Protocol";

    Protocol::ProtoParser parser("Messages/Package.proto");
    model = parser.parse();

    VERIFY_EQUAL(package, model->package());
}

SCENARIO( PackageParser, "Parsing/Normal", "unit,protocol", "PackageParser can parse multiple packages." )
{
    shared_ptr<Protocol::ProtoModel> model;
    string package = "TUCUT.Protocol";

    Protocol::ProtoParser parser("Messages/PackageRedefined.proto");
    model = parser.parse();

    VERIFY_EQUAL(package, model->package());
}
