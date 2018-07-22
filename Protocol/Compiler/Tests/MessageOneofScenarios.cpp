//
//  MessageOneofScenarios.cpp
//  Protocol
//
//  Created by Wahid Tanner on 12/30/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../../Test/Test.h"

#include "../../Tests/Messages/Generated/MessageOneof.protocol.h"

using namespace std;
using namespace TUCUT;

SCENARIO( MessageOneof, "Serialization/Normal", "unit", "Generated class can be serialized with oneof." )
{
    MessageOneof originalMessage;
    string stringValue = "managed";

    originalMessage.setSOne(stringValue);

    string serialized = originalMessage.serialize();

    MessageOneof parsedMessage;
    parsedMessage.parse(serialized.data());

    VERIFY_TRUE(parsedMessage.hasSOne());
    VERIFY_FALSE(parsedMessage.hasBOne());
    VERIFY_FALSE(parsedMessage.hasIOne());

    VERIFY_EQUAL(stringValue, parsedMessage.sOne());
}
