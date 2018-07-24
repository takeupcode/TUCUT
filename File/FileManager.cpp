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
    if (!fs.is_open())
    {
        std::string message = "Could not open ";
        message += fileName;
        throw std::runtime_error(message);
    }
    
    fs.seekg(0, std::ios::end);
    auto length = fs.tellg();
    
    std::vector<char> content;
    content.reserve(length);
    
    fs.seekg(0, std::ios::beg);
    content.insert(content.begin(),
       std::istream_iterator<char>(fs),
       std::istream_iterator<char>());
    
    if (fs.bad())
    {
        std::string message = "Could not read ";
        message += fileName;
        throw std::runtime_error(message);
    }

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

void FileManager::writeBytes (const std::string & fileName, const std::vector<char> & bytes)
{
    std::ofstream fs(fileName, std::ios_base::trunc | std::ios_base::binary);
    if (!fs.is_open())
    {
        std::string message = "Could not open ";
        message += fileName;
        throw std::runtime_error(message);
    }
    
    fs.write(&bytes[0], bytes.size());
    
    if (fs.bad())
    {
        std::string message = "Could not write ";
        message += fileName;
        throw std::runtime_error(message);
    }
    
    fs.close();
}

void FileManager::writeLines (const std::string & fileName, const std::vector<std::string> lines)
{
    std::ofstream fs(fileName, std::ios_base::trunc);
    if (!fs.is_open())
    {
        std::string message = "Could not open ";
        message += fileName;
        throw std::runtime_error(message);
    }
    
    for (auto & line: lines)
    {
        fs << line << '\n';
    }
    
    if (fs.bad())
    {
        std::string message = "Could not write ";
        message += fileName;
        throw std::runtime_error(message);
    }
    
    fs.close();
}

} // namespace File
} // namespace TUCUT
