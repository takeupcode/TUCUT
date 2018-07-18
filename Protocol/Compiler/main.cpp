//
//  main.cpp
//  TUCUT
//
//  Created by Wahid Tanner on 12/27/14.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#include <string>
#include <iostream>
#include <vector>

#include "../CodeGeneratorManager.h"
#include "../ProtoParser.h"

using namespace std;
using namespace TUCUT;

int main(int argc, const char ** argv)
{
    const string version = "1.1";

    vector<string> args(argv + 1, argv + argc);
    string outputPath;
    string projectName;
    string protoFile;

    bool displayUsage = false;
    bool outputPathExpected = false;
    bool projectNameExpected = false;
    bool generateCommonClasses = false;
    bool argumentError = false;

    for (auto & arg: args)
    {
        if (arg == "-h")
        {
            displayUsage = true;
            break;
        }
        else if (arg == "-c")
        {
            if (generateCommonClasses || outputPathExpected || projectNameExpected)
            {
                displayUsage = true;
                argumentError = true;
                break;
            }
            generateCommonClasses = true;
            continue;
        }
        else if (arg == "-o")
        {
            if (!outputPath.empty() || outputPathExpected || projectNameExpected)
            {
                displayUsage = true;
                argumentError = true;
                break;
            }
            outputPathExpected = true;
            continue;
        }
        else if (arg == "-p")
        {
            if (!projectName.empty() || outputPathExpected || projectNameExpected)
            {
                displayUsage = true;
                argumentError = true;
                break;
            }
            projectNameExpected = true;
            continue;
        }

        if (outputPathExpected)
        {
            outputPath = arg;
            outputPathExpected = false;
        }
        else if (projectNameExpected)
        {
            projectName = arg;
            projectNameExpected = false;
        }
        else
        {
            if (!protoFile.empty())
            {
                displayUsage = true;
                argumentError = true;
                break;
            }
            protoFile = arg;
        }
    }

    if (outputPathExpected || projectNameExpected)
    {
        displayUsage = true;
        argumentError = true;
    }

    if (!generateCommonClasses && protoFile.empty())
    {
        displayUsage = true;
        argumentError = true;
    }

    if (displayUsage)
    {
        cout << "TUCUT ProtocolCompiler version " << version << endl;
        cout << "Usage: ProtocolCompiler [-h] [-c] [-o path] [-p project] [file]" << endl;
        cout << "    Display usage: -h" << endl;
        cout << "    Generate common classes: -c" << endl;
        cout << "    Specify output path: -o path" << endl;
        cout << "    Specify project name used in include files: -p project" << endl;
        cout << "Either common classes, a file, or both must be specified." << endl;
        return argumentError ? 1 : 0;
    }

    if (outputPath.empty())
    {
        outputPath = ".";
    }

    Protocol::CodeGeneratorManager * pManager = Protocol::CodeGeneratorManager::instance();
    auto generator = pManager->generator("CPlusPlus");
    shared_ptr<Protocol::ProtoModel> model;

    if (!protoFile.empty())
    {
        Protocol::ProtoParser parser(protoFile);
        model = parser.parse();
    }

    generator->generateCode(outputPath, model.get(), projectName, generateCommonClasses);

    cout << "ProtocolCompiler version " << version << " completed successfully." << endl;
    return 0;
}
