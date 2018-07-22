//
//  ProtoParserScenarios.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 9/24/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../ProtoParser.h"

using namespace std;
using namespace TUCUT;

SCENARIO( ProtoParser, "Construction/Normal", "unit,protocol", "ProtoParser can be constructed." )
{
    Protocol::ProtoParser parser("Package.proto");
}
