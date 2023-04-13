//
//  TextUtil.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/17/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//
#include "TextUtil.h"

#include <sstream>

bool TUCUT::Text::TextUtil::isWhitespace (char c)
{
  return c == ' ' || c == '\t' || c == '\n';
}

std::vector<std::string> TUCUT::Text::TextUtil::splitString (
  std::string const & src,
  char delimiter)
{
  std::stringstream ss(src);
  std::string element;
  std::vector<std::string> result;

  while (std::getline(ss, element, delimiter))
  {
    result.push_back(element);
  }

  if (src.empty() || src[src.size() - 1] == delimiter)
  {
    result.push_back("");
  }

  return result;
}

size_t TUCUT::Text::TextUtil::replaceAll (
  std::string & src,
  std::string_view searchValue,
  std::string_view replaceValue)
{
  size_t count {};
  if (searchValue.length() == 0)
  {
    return count;
  }

  for (std::string::size_type currentPos {};
    std::string::npos !=
      (currentPos = src.find(searchValue, currentPos));
    currentPos += replaceValue.length(), ++count)
  {
    src.replace(currentPos, searchValue.length(), replaceValue);
  }

  return count;
}
