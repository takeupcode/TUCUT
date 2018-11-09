//
//  FileManagerScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 7/23/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../FileManager.h"

using namespace std;
using namespace TUCUT;

SCENARIO( File, "Operation/Normal", "unit,file", "File manager can read and write bytes." )
{
    string fileName = "./test_bytes";
    
    vector<char> content {'a','\0','b'};
    
    File::FileManager::writeBytes(fileName, content);
    auto result = File::FileManager::readBytes(fileName);
    
    VERIFY_EQUAL(content.size(), result.size());
    VERIFY_EQUAL(content[0], result[0]);
    VERIFY_EQUAL(content[1], result[1]);
    VERIFY_EQUAL(content[2], result[2]);
}

SCENARIO( File, "Operation/Normal", "unit,file", "File manager can read and write lines." )
{
    string fileName = "./test_lines";
    
    vector<string> content {"one", "two", "three"};
    
    File::FileManager::writeLines(fileName, content);
    auto result = File::FileManager::readLines(fileName);
    
    VERIFY_EQUAL(content.size(), result.size());
    VERIFY_EQUAL(content[0], result[0]);
    VERIFY_EQUAL(content[1], result[1]);
    VERIFY_EQUAL(content[2], result[2]);
}
