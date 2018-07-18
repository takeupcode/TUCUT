//
//  FileManager.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/24/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#ifndef TUCUT_File_FileManager_h
#define TUCUT_File_FileManager_h

#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

namespace TUCUT {
namespace File {

class FileManager
{
public:
    static std::vector<char> readBytes (const std::string & fileName);
    
    static std::vector<std::string> readLines (const std::string & fileName);
    
    template <typename F, typename... Ts>
    static void processLines (const std::string & fileName, F && func, Ts &&... params)
    {
        std::ifstream fs;
        fs.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            fs.open(fileName);
        }
        catch (std::system_error & ex)
        {
            std::string message = "Could not open ";
            message += fileName;
            message += "\r\nError: ";
            message += ex.code().message();
            throw std::runtime_error(message);
        }
        
        std::string line;
        while (getline(fs, line))
        {
            func(std::move(line), std::forward<Ts>(params)...);
        }
        
        fs.close();
    }
};
    
} // namespace File
} // namespace TUCUT

#endif // TUCUT_File_FileManager_h
