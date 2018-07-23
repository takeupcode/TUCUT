//
//  ExtensionScenarios.cpp
//  TestTUCUT
//
//  Created by Wahid Tanner on 8/15/14.
//  Copyright © 2014 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../ExtensionManager.h"

using namespace std;
using namespace TUCUT;

SCENARIO( Extension, "Construction/Singleton", "unit,extension", "Extension manager instances are the same." )
{
    Extension::ExtensionManager * pExtMgr1 = Extension::ExtensionManager::instance();
    Extension::ExtensionManager * pExtMgr2 = Extension::ExtensionManager::instance();

    VERIFY_TRUE(pExtMgr1 != nullptr);
    VERIFY_SAME(pExtMgr1, pExtMgr2);
}

SCENARIO( Extension, "Operation/Normal", "unit,extension", "Extension manager can send message and receive reply." )
{
    Extension::ExtensionManager * pExtMgr = Extension::ExtensionManager::instance();
    
    pExtMgr->loadAll("Extensions");
    
    string result = pExtMgr->sendMessage("com.takeupcode.simpletestextension", "test");
    VERIFY_EQUAL("Success from SimpleTestClass: test", result);
}
