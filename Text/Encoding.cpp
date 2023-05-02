//  Encoding.cpp
//  TUCUT/Text (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2023-04-01.
//  Copyright © Take Up Code, Inc.
//
#include "Encoding.h"

using namespace TUCUT;

std::string Text::truncate (
  std::string const & utf8,
  size_t length)
{
  size_t count {};
  size_t index {};
  while (count < length)
  {
    size_t current = getCodePointSize(utf8, index);
    if (current == 0)
    {
      // If the current code point is invalid or the
      // index is past the end of the string, break
      // and return what we have so far.
      break;
    }

    ++count;
    index += current;
  }

  return utf8.substr(0, index);
}

size_t Text::countCodePoints (
  std::string const & utf8)
{
  size_t count {};
  size_t index {};
  while (true)
  {
    size_t current = getCodePointSize(utf8, index);
    if (current == 0)
    {
      // If the current code point is invalid or the
      // index is past the end of the string, break
      // and return what we have counted so far.
      break;
    }

    ++count;
    index += current;
  }

  return count;
}

size_t Text::getCodePointSize (
  std::string const & utf8,
  size_t index)
{
  if (index >= utf8.size())
  {
    return 0;
  }

  uint8_t const unit0 = utf8[index];
  // If the msb of the leading code unit is 0, then
  // the code point is a single code unit.
  if ((unit0 & 0b1000'0000) == 0b0000'0000)
  {
    return 1;
  }

  // If the leading code unit begins with 110, then
  // the code point consists of two code units.
  if ((unit0 & 0b1110'0000) == 0b1100'0000)
  {
    // Make sure there's enough room for the trailing
    // code units.
    if (index + 1 >= utf8.size())
    {
      return 0;
    }
    // And make sure the trailing code units are correct.
    uint8_t const unit1 = utf8[index + 1];
    if ((unit1 & 0b1100'0000) != 0b1000'0000)
    {
      return 0;
    }
    return 2;
  }

  // If the leading code unit begins with 1110, then
  // the code point consists of three code units.
  if ((unit0 & 0b1111'0000) == 0b1110'0000)
  {
    // Make sure there's enough room for the trailing
    // code units.
    if (index + 2 >= utf8.size())
    {
      return 0;
    }
    // And make sure the trailing code units are correct.
    uint8_t const unit1 = utf8[index + 1];
    uint8_t const unit2 = utf8[index + 2];
    if ((unit1 & 0b1100'0000) != 0b1000'0000 ||
      (unit2 & 0b1100'0000) != 0b1000'0000)
    {
      return 0;
    }
    return 3;
  }

  // If the leading code unit begins with 11110, then
  // the code point consists of four code units.
  if ((unit0 & 0b1111'1000) == 0b1111'0000)
  {
    // Make sure there's enough room for the trailing
    // code units.
    if (index + 3 >= utf8.size())
    {
      return 0;
    }
    // And make sure the trailing code units are correct.
    uint8_t const unit1 = utf8[index + 1];
    uint8_t const unit2 = utf8[index + 2];
    uint8_t const unit3 = utf8[index + 3];
    if ((unit1 & 0b1100'0000) != 0b1000'0000 ||
      (unit2 & 0b1100'0000) != 0b1000'0000 ||
      (unit3 & 0b1100'0000) != 0b1000'0000)
    {
      return 0;
    }
    return 4;
  }

  // Anything else is a malformed code point and we
  // return zero.
  return 0;
}

std::string Text::getCodePointAt (
  std::string const & utf8,
  size_t & index)
{
  size_t size = getCodePointSize(utf8, index);
  if (size == 0)
  {
    return "";
  }

  std::string codePoint = utf8.substr(index, size);
  index += size;

  return codePoint;
}

std::string Text::setCodePoint (
  std::string const & utf8,
  std::string const & point,
  size_t pos)
{
  size_t total = countCodePoints(utf8);
  if (pos >= total)
  {
    return utf8;
  }

  size_t count {};
  size_t index {};
  while (count < pos)
  {
    size_t currentSize = getCodePointSize(utf8, index);
    if (currentSize == 0)
    {
      // If the current code point is invalid or the
      // index is past the end of the string, return
      // the original string.
      return utf8;
    }

    ++count;
    index += currentSize;
  }

  std::string result = utf8.substr(0, index);
  result += point;
  size_t posSize = getCodePointSize(utf8, index);
  result += utf8.substr(index + posSize);
  return result;
}

Text::CodePointResult Text::getCodePoint (
  std::string const & utf8,
  size_t & index,
  uint32_t & point)
{
  if (index >= utf8.size())
  {
    return CodePointResult::OutOfRange;
  }

  uint8_t const unit0 = utf8[index];
  if ((unit0 & 0b1100'0000) == 0b1000'0000)
  {
    // All utf8 code points must either begin with
    // 0 or 11. If the code unit begins with 10,
    // then the code unit is a trailing code unit.
    return CodePointResult::Trailing;
  }

  // If the msb of the leading code unit is 0, then
  // the code point is a single code unit.
  if ((unit0 & 0b1000'0000) == 0b0000'0000)
  {
    point = unit0;
    ++index;
    return CodePointResult::Success;
  }

  // If the leading code unit begins with 110, then
  // the code point consists of two code units.
  if ((unit0 & 0b1110'0000) == 0b1100'0000)
  {
    if (index + 1 >= utf8.size())
    {
      return CodePointResult::Incomplete;
    }
    uint8_t const unit1 = utf8[index + 1];
    // All trailing code units must begin with 10.
    if ((unit1 & 0b1100'0000) != 0b1000'0000)
    {
      return CodePointResult::Malformed;
    }
    point = 0;
    point += unit0 & 0b0001'1111;
    point <<= 6;
    point += unit1 & 0b0011'1111;
    index += 2;
    return CodePointResult::Success;
  }

  // If the leading code unit begins with 1110, then
  // the code point consists of three code units.
  if ((unit0 & 0b1111'0000) == 0b1110'0000)
  {
    if (index + 2 >= utf8.size())
    {
      return CodePointResult::Incomplete;
    }
    uint8_t const unit1 = utf8[index + 1];
    uint8_t const unit2 = utf8[index + 2];
    // All trailing code units must begin with 10.
    if ((unit1 & 0b1100'0000) != 0b1000'0000 ||
      (unit2 & 0b1100'0000) != 0b1000'0000)
    {
      return CodePointResult::Malformed;
    }
    point = 0;
    point += unit0 & 0b0000'1111;
    point <<= 6;
    point += unit1 & 0b0011'1111;
    point <<= 6;
    point += unit2 & 0b0011'1111;
    index += 3;
    return CodePointResult::Success;
  }

  // If the leading code unit begins with 11110, then
  // the code point consists of four code units.
  if ((unit0 & 0b1111'1000) == 0b1111'0000)
  {
    if (index + 3 >= utf8.size())
    {
      return CodePointResult::Incomplete;
    }
    uint8_t const unit1 = utf8[index + 1];
    uint8_t const unit2 = utf8[index + 2];
    uint8_t const unit3 = utf8[index + 3];
    // All trailing code units must begin with 10.
    if ((unit1 & 0b1100'0000) != 0b1000'0000 ||
      (unit2 & 0b1100'0000) != 0b1000'0000 ||
      (unit3 & 0b1100'0000) != 0b1000'0000)
    {
      return CodePointResult::Malformed;
    }
    point = 0;
    point += unit0 & 0b0000'0111;
    point <<= 6;
    point += unit1 & 0b0011'1111;
    point <<= 6;
    point += unit2 & 0b0011'1111;
    point <<= 6;
    point += unit3 & 0b0011'1111;
    index += 4;
    return CodePointResult::Success;
  }

  return CodePointResult::Unsupported;
}

Text::CodePointResult Text::getCodePoint (
  std::wstring const & utf16or32,
  size_t & index,
  uint32_t & point)
{
  if (index >= utf16or32.size())
  {
    return CodePointResult::OutOfRange;
  }

  // If a wchar_t is 4 bytes, then the wstring
  // is actually UTF32 encoded already.
  if constexpr (sizeof(wchar_t) == 4)
  {
    point = utf16or32[index];
    ++index;
    return CodePointResult::Success;
  }
  // Otherwise, the wstring is UTF16 encoded. Keep
  // the following code in an else block so that the
  // compiler can properly discard the unused path.
  else
  {
    uint32_t const unit0 = utf16or32[index];

    // If the first code unit meets the following
    // criteria, then the code point is a single code
    // unit.
    if (unit0 < 0xd800 || unit0 > 0xdfff)
    {
      point = unit0;
      ++index;
      return CodePointResult::Success;
    }

    // Make sure the first code unit isn't a trailing
    // code unit.
    if (unit0 > 0xdbff)
    {
      return CodePointResult::Trailing;
    }

    // Otherwise, the code point needs two code units.
    // Make sure we do have another code unit to read.
    if (index + 1 >= utf16or32.size())
    {
      return CodePointResult::Incomplete;
    }

    uint32_t const unit1 = utf16or32[index + 1];

    // Make sure the second code unit is a trailing
    // code unit.
    if (unit1 < 0xdc00 || unit1 > 0xdfff)
    {
      return CodePointResult::Malformed;
    }

    point = ((unit0 & 0x3ff) << 10) + (unit1 & 0x3ff) + 0x10000;
    index += 2;
    return CodePointResult::Success;
  }
}

std::string Text::to_string (
  std::wstring const & utf16or32,
  std::wstring & remainder)
{
  std::string utf8;
  size_t index {};
  uint32_t point {};
  auto result = getCodePoint(utf16or32, index, point);
  while (result == CodePointResult::Success)
  {
    // 7 significant digits or less fits in a single
    // code unit. The code unit will have the msb
    // clear to signal a single code unit.
    // 0xxx'xxxx
    if (point <= 0b0111'1111)
    {
      uint8_t const unit0 = point;
      utf8.push_back(unit0);
    }
    // 11 significant digits or less fits in two
    // code units. The leading code unit will begin
    // with 110 and the trailing code unit will begin
    // with 10.
    // 110x'xxxx 10xx'xxxx
    else if (point <= 0b0111'1111'1111)
    {
      uint8_t const unit1 = point & 0b0011'1111;
      point >>= 6;
      uint8_t const unit0 = point;
      utf8.push_back(0b1100'0000 + unit0);
      utf8.push_back(0b1000'0000 + unit1);
    }
    // 16 significant digits or less fits in three
    // code units. The leading code unit will begin
    // with 1110 and the trailing code units will
    // both begin with 10.
    // 1110'xxxx 10xx'xxxx 10xx'xxxx
    else if (point <= 0b1111'1111'1111'1111)
    {
      uint8_t const unit2 = point & 0b0011'1111;
      point >>= 6;
      uint8_t const unit1 = point & 0b0011'1111;
      point >>= 6;
      uint8_t const unit0 = point;
      utf8.push_back(0b1110'0000 + unit0);
      utf8.push_back(0b1000'0000 + unit1);
      utf8.push_back(0b1000'0000 + unit2);
    }
    // 21 significant digits or less fits in four
    // code units. The leading code unit will begin
    // with 11110 and the trailing code units will
    // all begin with 10.
    // 1111'0xxx 10xx'xxxx 10xx'xxxx 10xx'xxxx
    else if (point <= 0b0001'1111'1111'1111'1111'1111)
    {
      uint8_t const unit3 = point & 0b0011'1111;
      point >>= 6;
      uint8_t const unit2 = point & 0b0011'1111;
      point >>= 6;
      uint8_t const unit1 = point & 0b0011'1111;
      point >>= 6;
      uint8_t const unit0 = point;
      utf8.push_back(0b1111'0000 + unit0);
      utf8.push_back(0b1000'0000 + unit1);
      utf8.push_back(0b1000'0000 + unit2);
      utf8.push_back(0b1000'0000 + unit3);
    }

    result = getCodePoint(utf16or32, index, point);
  }

  if (result == CodePointResult::Incomplete)
  {
    remainder = utf16or32.substr(index);
  }
  else
  {
    remainder.clear();
  }

  return utf8;
}

std::wstring Text::to_wstring (
  std::string const & utf8,
  std::string & remainder)
{
  std::wstring utf16or32;
  size_t index {};
  uint32_t point {};
  auto result = getCodePoint(utf8, index, point);
  while (result == CodePointResult::Success)
  {
    // If a wchar_t is 4 bytes, then the wstring
    // will be UTF32 encoded.
    if constexpr (sizeof(wchar_t) == 4)
    {
      utf16or32.push_back(point);
    }
    // Otherwise, the wstring is UTF16 encoded. Keep
    // the following code in an else block so that the
    // compiler can properly discard the unused path.
    else
    {
      // If the code point meets the following criteria,
      // then it will be encoded with a single code unit.
      if (point < 0xd800 ||
        (point > 0xdfff && point < 0x10000))
      {
        uint16_t const unit0 = point;
        utf16or32.push_back(unit0);
      }
      // Otherwise, it needs two code units.
      else
      {
        point -= 0x010000;
        uint16_t const unit0 = (((point << 12) >> 22) + 0xd800);
        uint16_t const unit1 = (((point << 22) >> 22) + 0xdc00);
        utf16or32.push_back(unit0);
        utf16or32.push_back(unit1);
      }
    }

    result = getCodePoint(utf8, index, point);
  }

  if (result == CodePointResult::Incomplete)
  {
    remainder = utf8.substr(index);
  }
  else
  {
    remainder.clear();
  }

  return utf16or32;
}
