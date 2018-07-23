//
//  SimpleTestEntry.cpp
//  SimpleTestExtension
//
//  Created by Wahid Tanner on 6/12/14.
//  Copyright © 2014 Take Up Code. All rights reserved.
//

#include <string>

#include "SimpleTestEntry.h"
#include "SimpleTestClass.h"

using namespace std;
using namespace TUCUT;
using namespace Extensions;

Extension::ExtensionManager * gpExtensionManager = nullptr;

int tucutGetExtensionProtocolVersion ()
{
    return 1;
}

char * tucutGetExtensionAddress ()
{
    return gpExtensionManager->marshal("com.takeupcode.simpletestextension");
}

char * tucutSendMessage (const char * message)
{
    const string msg = message;
    string result = "";

    if (msg == "test")
    {
        SimpleTestClass target;
        result = target.process(msg).data();
    }
    else
    {
        result = "SimpleTestExtension failed to recognize message";
    }

    return gpExtensionManager->marshal(result);
}

void tucutSetExtensionManager (TUCUT::Extension::ExtensionManager * pExtensionManager)
{
    gpExtensionManager = pExtensionManager;
}
