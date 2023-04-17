//  Prompt.cpp
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-01.
//  Copyright © Take Up Code, Inc.
//
#include "Prompt.h"

#include "Terminal.h"

#include <iomanip>
#include <limits>
#include <stdexcept>

TUCUT::TUI::Prompt::Prompt (
  Terminal & terminal)
: mTerminal(terminal),
  mOutput(terminal.output()),
  mInput(terminal.input())
{ }

bool TUCUT::TUI::Prompt::promptYesOrNo (
  std::string const & prompt)
{
  mOutput << prompt << " y/n: ";
  mTerminal.resetGraphics();
  CursorShow cursor(mTerminal);

  while (true)
  {
    std::string input;
    mInput >> input;

    char ch {};
    if (not input.empty())
    {
      ch = input[0];
    }

    if (ch == 'y' || ch == 'Y')
    {
      return true;
    }
    else if (ch == 'n' || ch == 'N')
    {
      return false;
    }
    else
    {
      mOutput << "\nPlease enter y or n: ";
    }
  }
}

int TUCUT::TUI::Prompt::promptNumber (
  std::string const & prompt,
  int minimum,
  int maximum)
{
  mOutput << prompt;
  mTerminal.resetGraphics();
  CursorShow cursor(mTerminal);

  while (true)
  {
    int input;
    while (!(mInput >> input))
    {
      mInput.clearError();
      mOutput << "\nPlease enter a valid number: ";
    }

    if (input >= minimum && input <= maximum)
    {
      return input;
    }

    mOutput << "\nPlease enter a number between "
      << minimum << " and " << maximum << ": ";
  }
}

char TUCUT::TUI::Prompt::promptLetter (
  std::string const & prompt,
  char minimum,
  char maximum,
  bool makeUpperCase)
{
  mOutput << prompt;
  mTerminal.resetGraphics();
  CursorShow cursor(mTerminal);

  char minimumLower;
  char minimumUpper;
  if (minimum >= 'a' && minimum <= 'z')
  {
    minimumLower = minimum;
    minimumUpper = toupper(minimum);
  }
  else if (minimum >= 'A' && minimum <= 'Z')
  {
    minimumLower = tolower(minimum);
    minimumUpper = minimum;
  }
  else
  {
    throw std::logic_error(
      "minimum must be a valid letter between a-z.");
  }

  char maximumLower;
  char maximumUpper;
  if (maximum >= 'a' && maximum <= 'z')
  {
    maximumLower = maximum;
    maximumUpper = toupper(maximum);
  }
  else if (maximum >= 'A' && maximum <= 'Z')
  {
    maximumLower = tolower(maximum);
    maximumUpper = maximum;
  }
  else
  {
    throw std::logic_error(
      "maximum must be a valid letter between a-z.");
  }

  while (true)
  {
    std::string input;
    mInput >> input;

    char ch {};
    if (not input.empty())
    {
      ch = input[0];
    }

    if ((ch >= minimumLower && ch <= maximumLower) ||
    (ch >= minimumUpper && ch <= maximumUpper))
    {
      if (makeUpperCase)
      {
        ch = toupper(ch);
      }

      return ch;
    }

    mOutput << "\nPlease enter a letter between "
      << minimumLower << " and " << maximumLower << ": ";
  }
}

std::string TUCUT::TUI::Prompt::promptText (
  std::string const & prompt,
  bool makeUpperCase)
{
  mOutput << prompt;
  mTerminal.resetGraphics();
  CursorShow cursor(mTerminal);

  std::string input;
  mInput >> input;

  if (!makeUpperCase)
  {
    return input;
  }

  for (char & letter: input)
  {
    if (letter >= 'a' && letter <= 'z')
    {
      letter = toupper(letter);
    }
  }

  return input;
}

int TUCUT::TUI::Prompt::promptChoice (
  std::string const & prompt,
  std::vector<std::string> const & choices)
{
  int i = 0;
  for (auto & choice: choices)
  {
    mOutput << std::setw(3) << i++ << ": "
      << choice << std::endl;
  }
  mOutput << prompt;
  mTerminal.resetGraphics();
  CursorShow cursor(mTerminal);

  while (true)
  {
    unsigned int input;
    while (!(mInput >> input))
    {
      mInput.clearError();
      mOutput << "\nPlease enter a valid number: ";
    }

    if (input < choices.size())
    {
      return input;
    }

    mOutput << "\nPlease enter a number between "
      << 0 << " and " << (choices.size() - 1) << ": ";
  }
}
