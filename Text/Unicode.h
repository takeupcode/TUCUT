//  Unicode.h
//  TUCUT/Text (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2023-05-06.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_Text_Unicode_h
#define TUCUT_Text_Unicode_h

namespace TUCUT::Text
{
  // Control characters need to be handled separately
  // because they have special meanings. For example,
  // they can start escape sequences or add new lines.
  bool isControlCharacter (uint32_t character);

  // Combining characters are meant to be displayed in
  // the same position and on top of base characters.
  bool isCombiningCharacter (uint32_t character);

  // A base character is one that can have other combining
  // characters attached to it.
  bool isBaseCharacter (uint32_t character);

  // A square character is sometimes called a double-width
  // character or a full-width character. It takes up
  // more space than a normal character because a normal
  // character is rectangular in shape and more narrow
  // than tall.
  bool isSquareCharacter (uint32_t character);
} // namespace TUCUT::Text

#endif // TUCUT_Text_Unicode_h
