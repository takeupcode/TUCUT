//  Input.h
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2023-04-01.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_TUI_Input_h
#define TUCUT_TUI_Input_h

#include "../Event/MessageQueue.h"
#include "Event.h"
#include "Terminal.h"

#include <atomic>
#include <ostream>
#include <sstream>
#include <string>

namespace TUCUT::TUI
{
  class Input
  {
  public:
    Input (
      Terminal & terminal);

    void handleTimeout ();
    void accept (std::string const & utf8);

    void clearError ();

    void expectCursorPositionReport ();

    operator bool () const;
    Input & operator >> (int & i);
    Input & operator >> (unsigned int & ui);
    Input & operator >> (double & d);
    Input & operator >> (std::string & str);

  private:
    std::stringstream bufferedRead ();

    Terminal & mTerminal;
    std::ostream & mOutput;
    Event::MessageQueue<Event> mMessages;
    bool mSuccess = true;
    std::atomic<bool> mCursorPositionReportExpected = false;
  };
} // namespace TUCUT::TUI

#endif // TUCUT_TUI_Input_h
