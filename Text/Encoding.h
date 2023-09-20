//  Encoding.h
//  TUCUT/Text (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2023-04-01.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_Text_Encoding_h
#define TUCUT_Text_Encoding_h

#include <string>
#include <vector>

namespace TUCUT::Text
{
  enum class CodePointResult
  {
    Success,    // The code point was successfully read.
    Trailing,   // Code points must be read from their start.
    OutOfRange, // Attempt to start reading past the string end.
    Incomplete, // String ended with incomplete code point.
    Malformed,  // An invalid code unit was found.
    Unsupported // Code point with more than 4 code units.
  };

  size_t countCodePoints (
    std::string const & utf8);

  size_t getCodePointSize (
    std::string const & utf8,
    size_t index),

  std::string getCodePoint (
    std::string const & utf8,
    size_t & index);

  CodePointResult getCodePoint (
    std::string const & utf8,
    size_t & index,
    uint32_t & point);

  CodePointResult getCodePoint (
    std::wstring const & utf16or32,
    size_t & index,
    uint32_t & point);

  std::string to_string (
    std::wstring const & utf16or32,
    std::wstring & remainder);

  std::wstring to_wstring (
    std::string const & utf8,
    std::string & remainder);
} // namespace TUCUT::Text

#endif // TUCUT_Text_Encoding_h
