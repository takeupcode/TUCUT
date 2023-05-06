//  Glyph.h
//  TUCUT/Text (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2023-05-05.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_Text_Glyph_h
#define TUCUT_Text_Glyph_h

#include <string>

namespace TUCUT::Text
{
  std::string substr (
    std::string const & utf8,
    size_t pos,
    size_t length);

  std::string replace (
    std::string const & utf8,
    std::string const & text,
    size_t pos,
    size_t length);

  std::string truncate (
    std::string const & utf8,
    size_t length);
} // namespace TUCUT::Text

#endif // TUCUT_Text_Glyph_h
