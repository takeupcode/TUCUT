#ifndef TUCUT_Text_Encoding_h
#define TUCUT_Text_Encoding_h

#include <string>

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
