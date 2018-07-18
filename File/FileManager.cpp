//
//  FileManager.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/24/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#include "FileManager.h"

#include <fstream>
#include <stdexcept>

namespace TUCUT {
namespace File {

std::vector<char> FileManager::readBytes (const std::string & fileName)
{
    std::ifstream fs(fileName, std::ios_base::binary);
    if (fs.fail())
    {
        std::string message = "Could not open ";
        message += fileName;
        throw std::runtime_error(message);
    }
    
    fs.seekg(std::ios::end);
    auto length = fs.tellg();
    
    std::vector<char> content;
    content.reserve(length);
    
    fs.seekg(std::ios::beg);
    fs.read(&content[0], length);
    
    fs.close();
    
    return content;
}

std::vector<std::string> FileManager::readLines (const std::string & fileName)
{
    std::vector<std::string> content;
    
    auto storeLine = [&content](std::string && line)
    {
        content.push_back(std::move(line));
    };
    
    processLines(fileName, storeLine);
    
    return content;
}

} // namespace File
} // namespace TUCUT
