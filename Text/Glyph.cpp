//  Glyph.cpp
//  TUCUT/Text (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2023-05-05.
//  Copyright © Take Up Code, Inc.
//
#include "Glyph.h"

using namespace TUCUT;

std::string Text::substr (
  std::string const & utf8,
  size_t pos,
  size_t length)
{
  size_t utf8Pos1 {};
  size_t count {};
  while (count < pos)
  {
    size_t size = getCodePointSize(utf8, utf8Pos1);
    if (size == 0)
    {
      // If the current code point is invalid or the
      // index is past the end of the string, return
      // an empty string.
      return "";
    }

    ++count;
    utf8Pos1 += size;
  }

  size_t utf8Length {};
  size_t utf8Pos2 = utf8Pos1;
  count = 0;
  while (count < length)
  {
    size_t size = getCodePointSize(utf8, utf8Pos2);
    if (size == 0)
    {
      // If the current code point is invalid or the
      // index is past the end of the string, break
      // and return what we have so far.
      break;
    }

    ++count;
    utf8Length += size;
    utf8Pos2 += size;
  }

  return utf8.substr(utf8Pos1, utf8Length);
}

std::string Text::replace (
  std::string const & utf8,
  std::string const & text,
  size_t pos,
  size_t length)
{
  size_t total = countCodePoints(utf8);
  if (pos >= total)
  {
    return utf8;
  }

  size_t utf8Pos1 {};
  size_t count {};
  while (count < pos)
  {
    size_t currentSize = getCodePointSize(utf8, utf8Pos1);
    if (currentSize == 0)
    {
      // If the current code point is invalid or the
      // index is past the end of the string, return
      // the original string.
      return utf8;
    }

    ++count;
    utf8Pos1 += currentSize;
  }

  std::string result = utf8.substr(0, utf8Pos1);
  result += text;

  size_t utf8Pos2 = utf8Pos1;
  count = 0;
  while (count < length)
  {
    size_t size = getCodePointSize(utf8, utf8Pos2);
    if (size == 0)
    {
      // If the current code point is invalid or the
      // index is past the end of the string, break
      // and return what we have so far.
      break;
    }

    ++count;
    utf8Pos2 += size;
  }

  result += utf8.substr(utf8Pos2);
  return result;
}

std::string Text::truncate (
  std::string const & utf8,
  size_t length)
{
  size_t utf8Pos {};
  size_t count {};
  while (count < length)
  {
    size_t size = getCodePointSize(utf8, utf8Pos);
    if (size == 0)
    {
      // If the current code point is invalid or the
      // index is past the end of the string, break
      // and return what we have so far.
      break;
    }

    ++count;
    utf8Pos += size;
  }

  return utf8.substr(0, utf8Pos);
}
