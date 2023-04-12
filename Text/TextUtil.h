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
#include <string_view>
#include <vector>

namespace TUCUT::Text
{
  struct TextUtil
  {
    static bool isWhitespace (char c);

    static std::vector<std::string> splitString (
      std::string const & src,
      char delimiter);

    static size_t replaceAll (
      std::string & src,
      std::string_view searchValue,
      std::string_view replaceValue);
  };
} // namespace TUCUT::Text

#endif // TUCUT_Text_TextUtil_h
