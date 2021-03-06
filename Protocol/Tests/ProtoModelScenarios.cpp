//
//  ProtoModelScenarios.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 9/24/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../ProtoModel.h"

using namespace std;
using namespace TUCUT;

SCENARIO( ProtoModel, "Construction/Normal", "unit,protocol", "ProtoModel can be constructed." )
{
    Protocol::ProtoModel model("Messages/Empty.proto");

    VERIFY_EQUAL("", model.package());
}

SCENARIO( ProtoModel, "Operation/Properties", "unit,protocol", "ProtoModel knows current package." )
{
    Protocol::ProtoModel model("Messages/Empty.proto");
    string package = "TUCUT.Protocol";

    model.setPackage(package);
    VERIFY_EQUAL(package, model.package());
}
