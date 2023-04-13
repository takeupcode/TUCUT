#ifndef TUCUT_TUI_Input_h
#define TUCUT_TUI_Input_h

#include "Event.h"
#include "MessageQueue.h"
#include "Terminal.h"

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

    operator bool () const;
    Input & operator >> (int & i);
    Input & operator >> (unsigned int & ui);
    Input & operator >> (double & d);
    Input & operator >> (std::string & str);

  private:
    std::stringstream bufferedRead ();

    Terminal & mTerminal;
    std::ostream & mOutput;
    MessageQueue<Event> mMessages;
    bool mSuccess = true;
  };
} // namespace TUCUT::TUI

#endif // TUCUT_TUI_Input_h
