//
//  TextUtil.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/17/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Text_TextUtil_h
#define TUCUT_Text_TextUtil_h

#include <string>
#include <vector>

namespace TUCUT {
namespace Text {

struct TextUtil
{
    static bool isWhitespace (char c);

    static std::vector<std::string> splitString(const std::string & src, char delimiter);
};
    
} // namespace Text
} // namespace TUCUT

#endif // TUCUT_Text_TextUtil_h
