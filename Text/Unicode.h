//  Unicode.h
//  TUCUT/Text (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2023-05-06.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_Text_Unicode_h
#define TUCUT_Text_Unicode_h

#include <string>
#include <vector>

namespace TUCUT::Text
{
  size_t getGlyphsWidth (std::string const & utf8);

  std::vector<std::string> getGlyphs (std::string const & utf8);
} // namespace TUCUT::Text

#endif // TUCUT_Text_Unicode_h
