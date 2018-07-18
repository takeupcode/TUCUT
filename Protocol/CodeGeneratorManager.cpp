//
//  CodeGeneratorManager.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 10/17/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include "CodeGeneratorManager.h"
#include "CodeGeneratorCPP.h"

using namespace std;
using namespace TUCUT;

Protocol::CodeGeneratorManager::CodeGeneratorManager ()
{
    mGeneratorMap.emplace("CPlusPlus", shared_ptr<const CodeGeneratorInterface>(new CodeGeneratorCPP()));
}

Protocol::CodeGeneratorManager::~CodeGeneratorManager ()
{
}

Protocol::CodeGeneratorManager * Protocol::CodeGeneratorManager::instance ()
{
    static CodeGeneratorManager * singleton = nullptr;
    if (singleton == nullptr)
    {
        singleton = new CodeGeneratorManager();
    }

    return singleton;
}

const Protocol::CodeGeneratorManager::SPCodeGeneratorInterface Protocol::CodeGeneratorManager::generator (const std::string & language) const
{
    SPCodeGeneratorInterface generator = nullptr;
    auto generatorIter = mGeneratorMap.find(language);
    if (generatorIter != mGeneratorMap.end())
    {
        generator = generatorIter->second;
    }

    return generator;
}
