//  TextUtil.h
//  TUCUT/Text (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-17.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_Text_TextUtil_h
#define TUCUT_Text_TextUtil_h

#include <string>
#include <string_view>
#include <vector>

namespace TUCUT::Text
{
  std::string to_string (
    std::string const & src);

  bool isWhitespace (char c);

  std::vector<std::string> splitString (
    std::string const & src,
    char delimiter);

  size_t replaceAll (
    std::string & src,
    std::string_view searchValue,
    std::string_view replaceValue);
} // namespace TUCUT::Text

#endif // TUCUT_Text_TextUtil_h
