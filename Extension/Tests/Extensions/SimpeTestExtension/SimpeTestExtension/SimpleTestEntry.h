//
//  SimpleTestEntry.h
//  SimpleTestExtension
//
//  Created by Wahid Tanner on 6/12/14.
//  Copyright © 2014 Take Up Code. All rights reserved.
//

#ifndef SimpleTestExtension_SimpleTestEntry_h
#define SimpleTestExtension_SimpleTestEntry_h

#include "../../../../ExtensionManager.h"

extern TUCUT::Extension::ExtensionManager * gpExtensionManager;

extern "C"
{
    int tucutGetExtensionProtocolVersion ();
    char * tucutGetExtensionAddress ();
    char * tucutSendMessage (const char * message);
    void tucutSetExtensionManager (TUCUT::Extension::ExtensionManager * pExtensionManager);
}

#endif // SimpleTestExtension_SimpleTestEntry_h
