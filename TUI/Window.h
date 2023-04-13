#ifndef TUCUT_TUI_Window_h
#define TUCUT_TUI_Window_h

#include "Event.h"
#include "Terminal.h"

#include <memory>
#include <string>

namespace TUCUT::TUI
{
  class Window : public std::enable_shared_from_this<Window>
  {
  public:
    enum class VisibleState
    {
      Collapsed,
      Hidden,
      Shown
    };

    enum class EnableState
    {
      Disabled,
      Readonly,
      Enabled
    };

    virtual ~Window ();

    static std::shared_ptr<Window> createSharedWindow (
      std::string const & name,
      int y,
      int x,
      int height,
      int width,
      int clientForeColor,
      int clientBackColor,
      int borderForeColor,
      int borderBackColor,
      int focusForeColor,
      int focusBackColor,
      bool border);

    std::shared_ptr<Window> getSharedWindow ();

    virtual void processInput (Event const & event);

    void draw () const;

  private:
    Window (Terminal & terminal);

    Terminal & mTerminal;
    std::ostream & mOutput;
  };
} // namespace TUCUT::TUI

#endif // TUCUT_TUI_Window_h
