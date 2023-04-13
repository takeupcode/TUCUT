#ifndef TUCUT_TUI_Terminal_h
#define TUCUT_TUI_Terminal_h

#include <istream>
#include <memory>
#include <ostream>
#include <string>
#include <thread>
#include <vector>

#if defined(_WIN32) // Begin platform specific includes

// Windows
#ifndef UNICODE
#error Must be compiled with UNICODE and _UNICODE
#endif
#ifndef _UNICODE
#error Must be compiled with UNICODE and _UNICODE
#endif
#define DEFINE_CONSOLEV2_PROPERTIES
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#else

// Mac and Linux
#include <sys/select.h>
#include <termios.h>
#include <unistd.h>

#endif // End platform specific includes

namespace TUCUT::TUI
{
  enum class TextLayer
  {
    Foreground,
    Background
  };

  enum class Palette
  {
    Colors2,   // Uses foreground and background colors.
    Colors16,  // Uses 8 dim and 8 bright colors.
    Colors256, // Will really only use 240 colors.
    ColorsTrue // Uses about 16 million RGB values directly.
  };

  class Color
  {
  public:
    Color () = default;

    Color (TextLayer layer,
      Palette palette,
      unsigned char red,
      unsigned char green,
      unsigned char blue);

    std::string operator () (std::string const & content);

    void changeColor (TextLayer layer,
      Palette palette,
      unsigned char red,
      unsigned char green,
      unsigned char blue);

    std::string const & escSequence () const
    {
      return mEscSequence;
    }

  private:
    std::string mEscSequence;
  };

  std::ostream & operator << (std::ostream & out,
    Color const & color);

  class Input;

  class Terminal final
  {
  public:
    Terminal (bool useAlternateScreen = true);
    ~Terminal ();
    Terminal (Terminal const & src) = delete;
    Terminal (Terminal && src) = delete;

    Terminal & operator = (Terminal const & rhs) = delete;
    Terminal & operator = (Terminal && rhs) = delete;

    std::ostream & output ();
    Input & input ();

    void resetGraphics ();
    void useDefaultForeground ();
    void useDefaultBackground ();

    void underlineOn ();
    void underlineOff ();

    void blinkOn ();
    void blinkOff ();

    void moveCursor (unsigned int row, unsigned int column);
    void moveCursorUp (unsigned int lines);
    void moveCursorDown (unsigned int lines);
    void moveCursorForward (unsigned int columns);
    void moveCursorBack (unsigned int columns);

    bool showCursor ();
    bool hideCursor ();

    void clearScreen ();

  private:
    void setup ();
    void teardown ();

    void useAlternateScreen ();
    void useMainScreen ();

    std::ostream & mOutput;
    std::unique_ptr<Input> mInput;
    std::jthread mInputThread;
    bool mUseAlternateScreen;
    bool mCursorShown;

#if defined(_WIN32)
    DWORD mOutMode = 0;
    DWORD mInMode = 0;
#else
    struct termios mTerm;
#endif
  };

  class CursorShow final
  {
  public:
    CursorShow (Terminal & terminal);
    ~CursorShow ();

  private:
    Terminal & mTerminal;
    bool mCursorPreviouslyShown;
  };

  class CursorHide final
  {
  public:
    CursorHide (Terminal & terminal);
    ~CursorHide ();

  private:
    Terminal & mTerminal;
    bool mCursorPreviouslyShown;
  };
} // namespace TUCUT::TUI

#endif // TUCUT_TUI_Terminal_h
