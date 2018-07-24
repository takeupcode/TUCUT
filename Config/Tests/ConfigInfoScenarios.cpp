//
//  ConfigInfoScenarios.cpp
//  TestTUCUT
//
//  Created by Abdul Wahid Tanner on 7/24/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>

#include "../../Test/Test.h"

#include "../ConfigInfo.h"
#include "../../File/FileManager.h"

#include <boost/filesystem/operations.hpp>

using namespace std;
using namespace TUCUT;

SCENARIO( Config, "Operation/Normal", "unit,config", "Config info can read properties." )
{
    string fileName = "test_config";
    
    vector<string> content {
        "# Define a type called nest with some single and multiple values.",
        "item:nest=\"beehive\"; name=\"Beehive\"; location=\"tree\",\"log\";",
        "item:nest=\"birdnest\"; name=\"Bird nest\"; location=\"tree\",\"grass\";"
    };
    
    File::FileManager::writeLines(fileName, content);
    
    Config::ConfigInfo config;
    config.load(fileName);
    
    VERIFY_EQUAL(1, static_cast<int>(config.getPropertySize("nest", "beehive", "name")));
    VERIFY_EQUAL(2, static_cast<int>(config.getPropertySize("nest", "beehive", "location")));
    VERIFY_EQUAL(1, static_cast<int>(config.getPropertySize("nest", "birdnest", "name")));
    VERIFY_EQUAL(2, static_cast<int>(config.getPropertySize("nest", "birdnest", "location")));

    VERIFY_EQUAL("Beehive", config.getProperty("nest", "beehive", "name", 0));
    VERIFY_EQUAL("tree", config.getProperty("nest", "beehive", "location", 0));
    VERIFY_EQUAL("log", config.getProperty("nest", "beehive", "location", 1));

    VERIFY_EQUAL("Bird nest", config.getProperty("nest", "birdnest", "name", 0));
    VERIFY_EQUAL("tree", config.getProperty("nest", "birdnest", "location", 0));
    VERIFY_EQUAL("grass", config.getProperty("nest", "birdnest", "location", 1));

    boost::filesystem::remove(fileName);
}
