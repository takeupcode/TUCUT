//
//  TextUtil.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/17/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#include "TextUtil.h"

#include <sstream>

namespace TUCUT {
namespace Text {

bool TextUtil::isWhitespace (char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

std::vector<std::string> TextUtil::splitString(const std::string & src, char delimiter)
{
    std::stringstream ss(src);
    std::string element;
    std::vector<std::string> result;
    
    while (std::getline(ss, element, delimiter))
    {
        result.push_back(element);
    }
    
    return result;
}

} // namespace Text
} // namespace TUCUT
