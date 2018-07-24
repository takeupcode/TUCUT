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
        std::ifstream fs(fileName);
        if (!fs.is_open())
        {
            std::string message = "Could not open ";
            message += fileName;
            throw std::runtime_error(message);
        }
        
        std::string line;
        while (getline(fs, line))
        {
            func(std::move(line), std::forward<Ts>(params)...);
        }
        
        if (fs.bad())
        {
            std::string message = "Could not read ";
            message += fileName;
            throw std::runtime_error(message);
        }
        
        fs.close();
    }
};
    
} // namespace File
} // namespace TUCUT

#endif // TUCUT_File_FileManager_h
