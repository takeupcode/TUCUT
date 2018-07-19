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

SCENARIO( PackageParser, "Construction/Normal", "unit", "PackageParser can be constructed." )
{
    Protocol::PackageParser parser;
}

SCENARIO( PackageParser, "Parsing/Normal", "unit", "PackageParser can parse package." )
{
    shared_ptr<Protocol::ProtoModel> model;
    string package = "TUCUT.Protocol";

    Protocol::ProtoParser parser("Package.proto");
    model = parser.parse();

    verifyEqual(package, model->package());
}

SCENARIO( PackageParser, "Parsing/Normal", "unit", "PackageParser can parse multiple packages." )
{
    shared_ptr<Protocol::ProtoModel> model;
    string package = "TUCUT.Protocol";

    Protocol::ProtoParser parser("PackageRedefined.proto");
    model = parser.parse();

    verifyEqual(package, model->package());
}
