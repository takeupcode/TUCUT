//
//  MessageEmptyScenarios.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 12/20/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../../Test/Test.h"

#include "../../Tests/Messages/Generated/Message.protocol.h"

using namespace std;
using namespace TUCUT;

SCENARIO( MessageEmpty, "Generation/Normal", "unit", "Generated class can be constructed." )
{
    Empty message;
}
