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

SCENARIO( CodeGeneratorManager, "Construction/Normal", "unit,protocol", "CodeGeneratorManager can be constructed." )
{
    Protocol::CodeGeneratorManager * pManager = Protocol::CodeGeneratorManager::instance();

    VERIFY_TRUE(pManager != nullptr);
}

SCENARIO( CodeGeneratorManager, "Construction/Normal", "unit,protocol", "CodeGeneratorManager cannot construct unknown generators." )
{
    Protocol::CodeGeneratorManager * pManager = Protocol::CodeGeneratorManager::instance();

    auto generator = pManager->generator("");
    VERIFY_TRUE(generator == nullptr);

    generator = pManager->generator("unknown");
    VERIFY_TRUE(generator == nullptr);
}

SCENARIO( CodeGeneratorManager, "Construction/Normal", "unit,protocol", "CodeGeneratorManager can construct CPP generator." )
{
    Protocol::CodeGeneratorManager * pManager = Protocol::CodeGeneratorManager::instance();

    auto generator = pManager->generator("CPlusPlus");
    VERIFY_TRUE(generator != nullptr);
}
