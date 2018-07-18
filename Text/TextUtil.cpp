//
//  TextUtil.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/17/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#include "TextUtil.h"

namespace TUCUT {
namespace Text {

bool TextUtil::isWhitespace (char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

} // namespace Text
} // namespace TUCUT
