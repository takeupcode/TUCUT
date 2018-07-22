//
//  ImportParserScenarios.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 10/12/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../ProtoParser.h"
#include "../ImportParser.h"

using namespace std;
using namespace TUCUT;

SCENARIO( ImportParser, "Construction/Normal", "unit", "ImportParser can be constructed." )
{
    Protocol::ImportParser parser;
}

SCENARIO( ImportParser, "Parsing/Normal", "unit", "ImportParser can parse no imports." )
{
    shared_ptr<Protocol::ProtoModel> model;

    Protocol::ProtoParser parser("ImportNone.proto");
    model = parser.parse();

    unsigned long expectedSize = 1;
    VERIFY_EQUAL(expectedSize, model->publicEnumTypes()->size());
    VERIFY_EQUAL(expectedSize, model->publicMessageTypes()->size());

    expectedSize = 0;
    VERIFY_EQUAL(expectedSize, model->privateEnumTypes()->size());
    VERIFY_EQUAL(expectedSize, model->privateMessageTypes()->size());
}

SCENARIO( ImportParser, "Parsing/Normal", "unit", "ImportParser can parse private import." )
{
    shared_ptr<Protocol::ProtoModel> model;

    Protocol::ProtoParser parser("ImportPrivate.proto");
    model = parser.parse();

    unsigned long expectedSize = 1;
    VERIFY_EQUAL(expectedSize, model->publicEnumTypes()->size());
    VERIFY_EQUAL(expectedSize, model->publicMessageTypes()->size());

    expectedSize = 4;
    VERIFY_EQUAL(expectedSize, model->privateEnumTypes()->size());

    expectedSize = 3;
    VERIFY_EQUAL(expectedSize, model->privateMessageTypes()->size());
}

SCENARIO( ImportParser, "Parsing/Normal", "unit", "ImportParser can parse public import." )
{
    shared_ptr<Protocol::ProtoModel> model;

    Protocol::ProtoParser parser("ImportPublic.proto");
    model = parser.parse();

    unsigned long expectedSize = 5;
    VERIFY_EQUAL(expectedSize, model->publicEnumTypes()->size());

    expectedSize = 3;
    VERIFY_EQUAL(expectedSize, model->publicMessageTypes()->size());

    expectedSize = 0;
    VERIFY_EQUAL(expectedSize, model->privateEnumTypes()->size());

    expectedSize = 1;
    VERIFY_EQUAL(expectedSize, model->privateMessageTypes()->size());
}
