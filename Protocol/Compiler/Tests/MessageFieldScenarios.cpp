//
//  MessageFieldScenarios.cpp
//  Protocol
//
//  Created by Wahid Tanner on 12/25/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iterator>
#include <iomanip>

#include "../../../Test/Test.h"

#include "../../Tests/Messages/Generated/MessageField.protocol.h"

using namespace std;
using namespace TUCUT;

SCENARIO( MessageField, "Serialization/Normal", "unit", "Generated class can be serialized." )
{
    MessageOne originalMessage;
    string stringValue = "managed";

    originalMessage.setSOne(stringValue);
    originalMessage.addIOne(42);

    string serialized = originalMessage.serialize();

    ostringstream result;
    result << hex;
    copy(serialized.begin(), serialized.end(), ostream_iterator<unsigned int>(result, " "));
    cout << "serialized message: " << result.str() << endl;

    MessageOne parsedMessage;
    parsedMessage.parse(serialized.data());

    VERIFY_TRUE(parsedMessage.hasSOne());
    VERIFY_FALSE(parsedMessage.hasBOne());
    VERIFY_TRUE(parsedMessage.sizeIOne() == 1);

    VERIFY_EQUAL(stringValue, parsedMessage.sOne());
    VERIFY_EQUAL(42, parsedMessage.iOne(0));
}
