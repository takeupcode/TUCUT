//
//  TextUtil.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/17/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#include "TextUtil.h"

#include <locale>
#include <sstream>

namespace TUCUT {
namespace Text {

bool TextUtil::isWhitespace (char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

std::vector<std::string> TextUtil::splitString (const std::string & src, char delimiter)
{
    std::stringstream ss(src);
    std::string element;
    std::vector<std::string> result;
    
    while (std::getline(ss, element, delimiter))
    {
        result.push_back(element);
    }
    
    if (src.empty() || src[src.size() - 1] == delimiter)
    {
        result.push_back("");
    }
    
    return result;
}
    
std::string TextUtil::narrowString (const std::wstring & src)
{
    std::locale loc;
    std::vector<char> narrowCharBuf(src.size());
    std::use_facet<std::ctype<wchar_t>>(loc).narrow(
        src.data(),
        src.data() + src.size(),
        '?',
        narrowCharBuf.data());
    std::string narrowString = narrowCharBuf.data();
    return narrowString;
}

} // namespace Text
} // namespace TUCUT
