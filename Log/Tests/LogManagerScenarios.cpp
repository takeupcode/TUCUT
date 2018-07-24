//
//  LogManagerScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 7/23/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <algorithm>
#include <string>

#include "../../Test/Test.h"

#include "../LogManager.h"
#include "../../File/FileManager.h"

#include <boost/filesystem/operations.hpp>

using namespace std;
using namespace TUCUT;

SCENARIO( Log, "Construction/Singleton", "unit,log", "Log manager instances are the same." )
{
    Log::LogManager * pLogMgr1 = Log::LogManager::instance();
    Log::LogManager * pLogMgr2 = Log::LogManager::instance();
    
    VERIFY_TRUE(pLogMgr1 != nullptr);
    VERIFY_SAME(pLogMgr1, pLogMgr2);
}

SCENARIO( Log, "Operation/Normal", "unit,log", "Log manager can log." )
{
    Log::LogManager::initialize("logs", "testlogging");
    
    string debuggingStr = "debugging";
    string informingStr = "informing";
    TUCUTLOG(Debug, debuggingStr);
    TUCUTLOG(Info, informingStr);
    
    Log::LogManager * pLogMgr = Log::LogManager::instance();
    auto result = File::FileManager::readLines(pLogMgr->logFileName());
    
    VERIFY_TRUE(search(begin(result[0]), end(result[0]), begin(debuggingStr), end(debuggingStr)) != end(result[0]));
    VERIFY_TRUE(search(begin(result[1]), end(result[1]), begin(informingStr), end(informingStr)) != end(result[1]));
    
    boost::filesystem::remove(pLogMgr->logFileName());
}
