#include "TextUtil.h"

#include <sstream>

std::string TUCUT::Text::to_string (
  std::string const & src)
{
  return src;
}

bool TUCUT::Text::isWhitespace (char c)
{
  return c == ' ' || c == '\t' || c == '\n';
}

std::vector<std::string> TUCUT::Text::splitString (
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

size_t TUCUT::Text::replaceAll (
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
