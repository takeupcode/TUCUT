//  Prompt.h
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-01.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_TUI_Prompt_h
#define TUCUT_TUI_Prompt_h

#include "Input.h"
#include "Terminal.h"

#include <istream>
#include <ostream>
#include <string>
#include <vector>

namespace TUCUT::TUI
{
  class Prompt
  {
  public:
    Prompt (
      Terminal & terminal);

    bool promptYesOrNo (
      std::string const & prompt);

    int promptNumber (
      std::string const & prompt,
      int minimum = 0,
      int maximum = 9);

    char promptLetter (
      std::string const & prompt,
      char minimum = 'a',
      char maximum = 'z',
      bool makeUpperCase = false);

    std::string promptText (
      std::string const & prompt,
      bool makeUpperCase = false);

    int promptChoice (
      std::string const & prompt,
      std::vector<std::string> const & choices);

  private:
    Terminal & mTerminal;
    std::ostream & mOutput;
    Input & mInput;
  };
} // namespace TUCUT::TUI

#endif // TUCUT_TUI_Prompt_h
