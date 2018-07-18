//
//  CodeGeneratorManagerScenarios.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 10/18/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../CodeGeneratorManager.h"

using namespace std;
using namespace TUCUT;

SCENARIO( CodeGeneratorManager, "Construction/Normal", "CodeGeneratorManager can be constructed." )
{
    Protocol::CodeGeneratorManager * pManager = Protocol::CodeGeneratorManager::instance();

    verifyTrue(pManager != nullptr);
}

SCENARIO( CodeGeneratorManager, "Construction/Normal", "CodeGeneratorManager cannot construct unknown generators." )
{
    Protocol::CodeGeneratorManager * pManager = Protocol::CodeGeneratorManager::instance();

    auto generator = pManager->generator("");
    verifyTrue(generator == nullptr);

    generator = pManager->generator("unknown");
    verifyTrue(generator == nullptr);
}

SCENARIO( CodeGeneratorManager, "Construction/Normal", "CodeGeneratorManager can construct CPP generator." )
{
    Protocol::CodeGeneratorManager * pManager = Protocol::CodeGeneratorManager::instance();

    auto generator = pManager->generator("CPlusPlus");
    verifyTrue(generator != nullptr);
}
