#include "Terminal.h"

#include "../Text/Encoding.h"
#include "Input.h"

#include <array>
#include <iostream>
#include <limits>

namespace
{
  struct RGB final
  {
    unsigned char mRed;
    unsigned char mGreen;
    unsigned char mBlue;
  };

  // Define RGB values for the basic colors.
  // There are 8 dim and 8 bright colors.
  // These are not the real color values displayed in
  // the terminal. The terminal is free to use its own
  // colors. These are the values that we will use to
  // select the nearest color index given any RGB color.
  std::array<RGB, 16> ColorValues16 {{
    // dim colors
    {  0,   0,   0}, {135,   0,   0}, {  0, 135,   0},
    {135, 135,   0}, {  0,   0, 135}, {135,   0, 135},
    {  0, 135, 135}, {192, 192, 192},
    // bright colors
    {135, 135, 135}, {255,   0,   0}, {  0, 255,   0},
    {255, 255,   0}, {  0,   0, 255}, {255,   0, 255},
    {  0, 255, 255}, {255, 255, 255}
  }};

  // When using the 256 palette, we'll actually select
  // from these 240 colors because most of the basic colors
  // are duplicates anyway. Only {192, 192, 192} is missing.
  // These are not the real color values displayed in
  // the terminal. The terminal is free to use its own
  // colors. These are the values that we will use to
  // select the nearest color index given any RGB color.
  std::array<RGB, 240> ColorValues240 {{
    {  0,   0,   0}, {  0,   0,  95}, {  0,   0, 135},
    {  0,   0, 175}, {  0,   0, 215}, {  0,   0, 255},
    {  0,  95,   0}, {  0,  95,  95}, {  0,  95, 135},
    {  0,  95, 175}, {  0,  95, 215}, {  0,  95, 255},
    {  0, 135,   0}, {  0, 135,  95}, {  0, 135, 135},
    {  0, 135, 175}, {  0, 135, 215}, {  0, 135, 255},
    {  0, 175,   0}, {  0, 175,  95}, {  0, 175, 135},
    {  0, 175, 175}, {  0, 175, 215}, {  0, 175, 255},
    {  0, 215,   0}, {  0, 215,  95}, {  0, 215, 135},
    {  0, 215, 175}, {  0, 215, 215}, {  0, 215, 255},
    {  0, 255,   0}, {  0, 255,  95}, {  0, 255, 135},
    {  0, 255, 175}, {  0, 255, 215}, {  0, 255, 255},

    { 95,   0,   0}, { 95,   0,  95}, { 95,   0, 135},
    { 95,   0, 175}, { 95,   0, 215}, { 95,   0, 255},
    { 95,  95,   0}, { 95,  95,  95}, { 95,  95, 135},
    { 95,  95, 175}, { 95,  95, 215}, { 95,  95, 255},
    { 95, 135,   0}, { 95, 135,  95}, { 95, 135, 135},
    { 95, 135, 175}, { 95, 135, 215}, { 95, 135, 255},
    { 95, 175,   0}, { 95, 175,  95}, { 95, 175, 135},
    { 95, 175, 175}, { 95, 175, 215}, { 95, 175, 255},
    { 95, 215,   0}, { 95, 215,  95}, { 95, 215, 135},
    { 95, 215, 175}, { 95, 215, 215}, { 95, 215, 255},
    { 95, 255,   0}, { 95, 255,  95}, { 95, 255, 135},
    { 95, 255, 175}, { 95, 255, 215}, { 95, 255, 255},

    {135,   0,   0}, {135,   0,  95}, {135,   0, 135},
    {135,   0, 175}, {135,   0, 215}, {135,   0, 255},
    {135,  95,   0}, {135,  95,  95}, {135,  95, 135},
    {135,  95, 175}, {135,  95, 215}, {135,  95, 255},
    {135, 135,   0}, {135, 135,  95}, {135, 135, 135},
    {135, 135, 175}, {135, 135, 215}, {135, 135, 255},
    {135, 175,   0}, {135, 175,  95}, {135, 175, 135},
    {135, 175, 175}, {135, 175, 215}, {135, 175, 255},
    {135, 215,   0}, {135, 215,  95}, {135, 215, 135},
    {135, 215, 175}, {135, 215, 215}, {135, 215, 255},
    {135, 255,   0}, {135, 255,  95}, {135, 255, 135},
    {135, 255, 175}, {135, 255, 215}, {135, 255, 255},

    {175,   0,   0}, {175,   0,  95}, {175,   0, 135},
    {175,   0, 175}, {175,   0, 215}, {175,   0, 255},
    {175,  95,   0}, {175,  95,  95}, {175,  95, 135},
    {175,  95, 175}, {175,  95, 215}, {175,  95, 255},
    {175, 135,   0}, {175, 135,  95}, {175, 135, 135},
    {175, 135, 175}, {175, 135, 215}, {175, 135, 255},
    {175, 175,   0}, {175, 175,  95}, {175, 175, 135},
    {175, 175, 175}, {175, 175, 215}, {175, 175, 255},
    {175, 215,   0}, {175, 215,  95}, {175, 215, 135},
    {175, 215, 175}, {175, 215, 215}, {175, 215, 255},
    {175, 255,   0}, {175, 255,  95}, {175, 255, 135},
    {175, 255, 175}, {175, 255, 215}, {175, 255, 255},

    {215,   0,   0}, {215,   0,  95}, {215,   0, 135},
    {215,   0, 175}, {215,   0, 215}, {215,   0, 255},
    {215,  95,   0}, {215,  95,  95}, {215,  95, 135},
    {215,  95, 175}, {215,  95, 215}, {215,  95, 255},
    {215, 135,   0}, {215, 135,  95}, {215, 135, 135},
    {215, 135, 175}, {215, 135, 215}, {215, 135, 255},
    {215, 175,   0}, {215, 175,  95}, {215, 175, 135},
    {215, 175, 175}, {215, 175, 215}, {215, 175, 255},
    {215, 215,   0}, {215, 215,  95}, {215, 215, 135},
    {215, 215, 175}, {215, 215, 215}, {215, 215, 255},
    {215, 255,   0}, {215, 255,  95}, {215, 255, 135},
    {215, 255, 175}, {215, 255, 215}, {215, 255, 255},

    {255,   0,   0}, {255,   0,  95}, {255,   0, 135},
    {255,   0, 175}, {255,   0, 215}, {255,   0, 255},
    {255,  95,   0}, {255,  95,  95}, {255,  95, 135},
    {255,  95, 175}, {255,  95, 215}, {255,  95, 255},
    {255, 135,   0}, {255, 135,  95}, {255, 135, 135},
    {255, 135, 175}, {255, 135, 215}, {255, 135, 255},
    {255, 175,   0}, {255, 175,  95}, {255, 175, 135},
    {255, 175, 175}, {255, 175, 215}, {255, 175, 255},
    {255, 215,   0}, {255, 215,  95}, {255, 215, 135},
    {255, 215, 175}, {255, 215, 215}, {255, 215, 255},
    {255, 255,   0}, {255, 255,  95}, {255, 255, 135},
    {255, 255, 175}, {255, 255, 215}, {255, 255, 255},

    {  8,   8,   8}, { 18,  18,  18}, { 28,  28,  28},
    { 38,  38,  38}, { 48,  48,  48}, { 58,  58,  58},
    { 68,  68,  68}, { 78,  78,  78}, { 88,  88,  88},
    { 98,  98,  98}, {108, 108, 108}, {118, 118, 118},
    {128, 128, 128}, {138, 138, 138}, {148, 148, 148},
    {158, 158, 158}, {168, 168, 168}, {178, 178, 178},
    {188, 188, 188}, {198, 198, 198}, {208, 208, 208},
    {218, 218, 218}, {228, 228, 228}, {238, 238, 238}
  }};

  unsigned int selectIndexFromPalette (
    auto beginRGB,
    auto endRGB,
    unsigned char red,
    unsigned char green,
    unsigned char blue)
  {
    unsigned int bestIndex {};
    unsigned int shortestDistanceSquared =
      std::numeric_limits<unsigned int>::max();
    for (unsigned int i = 0; beginRGB != endRGB; ++beginRGB)
    {
      int const redDelta = beginRGB->mRed - red;
      int const greenDelta = beginRGB->mGreen - green;
      int const blueDelta = beginRGB->mBlue - blue;
      unsigned int const distanceSquared =
        static_cast<unsigned int>(
          redDelta * redDelta +
          greenDelta * greenDelta +
          blueDelta * blueDelta);
      if (distanceSquared < shortestDistanceSquared)
      {
        bestIndex = i;
        shortestDistanceSquared = distanceSquared;
      }
      ++i;
    }

    return bestIndex;
  }

  unsigned int selectIndexFromPalette16 (
    unsigned char red,
    unsigned char green,
    unsigned char blue)
  {
    return selectIndexFromPalette(
      ColorValues16.begin(),
      ColorValues16.end(),
      red, green, blue);
  }

  unsigned int selectColor16Code (
    TUCUT::TUI::TextLayer layer,
    unsigned char red,
    unsigned char green,
    unsigned char blue)
  {
    constexpr int ForeDimBegin       = 30;
    constexpr int BackDimBegin       = 40;
    constexpr int ForeBrightBegin    = 90;
    constexpr int BackBrightBegin   = 100;

    unsigned int code;
    auto nearestIndex =
      selectIndexFromPalette16(red, green, blue);
    if (nearestIndex < 8)
    {
      unsigned int codeBegin = ForeDimBegin;
      if (layer == TUCUT::TUI::TextLayer::Background)
      {
        codeBegin = BackDimBegin;
      }
      code = codeBegin + nearestIndex;
    }
    else
    {
      unsigned int codeBegin = ForeBrightBegin;
      if (layer == TUCUT::TUI::TextLayer::Background)
      {
        codeBegin = BackBrightBegin;
      }
      // The colors are treated as two groups of 8 dim
      // and 8 bright colors. The nearestIndex however
      // is a full index of 0-15. Since we already
      // know that we are dealing with the 8 bright
      // colors, adjust the index to 0-7 so we can
      // choose the correct bright color from the 8
      // bright colors.
      nearestIndex -= 8;
      code = codeBegin + nearestIndex;
    }
    return code;
  }

  unsigned int selectIndexFromPalette256 (
    unsigned char red,
    unsigned char green,
    unsigned char blue)
  {
    auto nearestIndex = selectIndexFromPalette(
      ColorValues240.begin(),
      ColorValues240.end(),
      red, green, blue);
    // Adjust the index because the 240 values should
    // start after the 16 basic values.
    nearestIndex += 16;
    return nearestIndex;
  }

  class EscSequenceBuilder final
  {
  public:
    static std::string resetGraphics ();
    static std::string useDefaultForeground ();
    static std::string useDefaultBackground ();

    static std::string setNearestColor (
      TUCUT::TUI::TextLayer layer,
      TUCUT::TUI::Palette palette,
      unsigned char red,
      unsigned char green,
      unsigned char blue);

    static std::string underlineOn ();
    static std::string underlineOff ();

    static std::string blinkOn ();
    static std::string blinkOff ();

    static std::string moveCursor (unsigned int row,
      unsigned int column);
    static std::string moveCursorUp (unsigned int lines);
    static std::string moveCursorDown (unsigned int lines);
    static std::string moveCursorForward (unsigned int lines);
    static std::string moveCursorBack (unsigned int lines);

    static std::string showCursor ();
    static std::string hideCursor ();

    static std::string clearScreen ();

    static std::string useAlternateScreen ();
    static std::string useMainScreen ();

  private:
    static std::string setDisplayAttributes (
      std::vector<std::string> const & attrs);

    static std::string buildCSI (
      std::vector<std::string> const & attrs,
      std::string const & endCSI);
  };
}

std::string EscSequenceBuilder::resetGraphics ()
{
  return setDisplayAttributes({"0"});
}

std::string EscSequenceBuilder::useDefaultForeground ()
{
  return setDisplayAttributes({"39"});
}

std::string EscSequenceBuilder::useDefaultBackground ()
{
  return setDisplayAttributes({"49"});
}

std::string EscSequenceBuilder::setNearestColor (
  TUCUT::TUI::TextLayer layer,
  TUCUT::TUI::Palette palette,
  unsigned char red,
  unsigned char green,
  unsigned char blue)
{
  if (palette == TUCUT::TUI::Palette::Colors16)
  {
    std::string code = std::to_string(
      selectColor16Code(layer, red, green, blue));
    return setDisplayAttributes({code});
  }

  if (palette == TUCUT::TUI::Palette::Colors256 ||
    palette == TUCUT::TUI::Palette::ColorsTrue)
  {
    std::string code;
    if (layer == TUCUT::TUI::TextLayer::Background)
    {
      code = "48";
    }
    else
    {
      code = "38";
    }

    std::string mode;
    if (palette == TUCUT::TUI::Palette::Colors256)
    {
      mode = "5";
      std::string index = std::to_string(
        selectIndexFromPalette256(red, green, blue));
      return setDisplayAttributes({code, mode, index});
    }

    mode = "2";
    return setDisplayAttributes({code, mode,
      std::to_string(red),
      std::to_string(green),
      std::to_string(blue)});
  }

  return "";
}

std::string EscSequenceBuilder::underlineOn ()
{
  return setDisplayAttributes({"4"});
}

std::string EscSequenceBuilder::underlineOff ()
{
  return setDisplayAttributes({"24"});
}

std::string EscSequenceBuilder::blinkOn ()
{
  return setDisplayAttributes({"5"});
}

std::string EscSequenceBuilder::blinkOff ()
{
  return setDisplayAttributes({"25"});
}

std::string EscSequenceBuilder::moveCursor (
  unsigned int row,
  unsigned int column)
{
  return buildCSI(
    {std::to_string(row), std::to_string(column)}, "H");
}

std::string EscSequenceBuilder::moveCursorUp (
  unsigned int lines)
{
  return buildCSI({std::to_string(lines)}, "A");
}

std::string EscSequenceBuilder::moveCursorDown (
  unsigned int lines)
{
  return buildCSI({std::to_string(lines)}, "B");
}

std::string EscSequenceBuilder::moveCursorForward (
  unsigned int columns)
{
  return buildCSI({std::to_string(columns)}, "C");
}

std::string EscSequenceBuilder::moveCursorBack (
  unsigned int columns)
{
  return buildCSI({std::to_string(columns)}, "D");
}

std::string EscSequenceBuilder::showCursor ()
{
  return buildCSI({}, "?25h");
}

std::string EscSequenceBuilder::hideCursor ()
{
  return buildCSI({}, "?25l");
}

std::string EscSequenceBuilder::clearScreen ()
{
  return buildCSI({}, "2J");
}

std::string EscSequenceBuilder::useAlternateScreen ()
{
  return buildCSI({}, "?1049h");
}

std::string EscSequenceBuilder::useMainScreen ()
{
  return buildCSI({}, "?1049l");
}

std::string EscSequenceBuilder::setDisplayAttributes (
  std::vector<std::string> const & attrs)
{
  return buildCSI(attrs, "m");
}

std::string EscSequenceBuilder::buildCSI (
  std::vector<std::string> const & attrs,
  std::string const & endCSI)
{
  constexpr auto beginCSI = "\x1b[";
  constexpr auto delimiter = ";";

  std::string result = beginCSI;
  if (not attrs.empty())
  {
    result += attrs[0];
    for (std::size_t i = 1; i < attrs.size(); ++i)
    {
      result += delimiter;
      result += attrs[i];
    }
  }
  result += endCSI;
  return result;
}

TUCUT::TUI::Color::Color (TextLayer layer,
  Palette palette,
  unsigned char red,
  unsigned char green,
  unsigned char blue)
: mEscSequence(EscSequenceBuilder::setNearestColor(
    layer, palette, red, green, blue))
{ }

std::string TUCUT::TUI::Color::operator () (
  std::string const & content)
{
  return mEscSequence + content;
}

void TUCUT::TUI::Color::changeColor (TextLayer layer,
  Palette palette,
  unsigned char red,
  unsigned char green,
  unsigned char blue)
{
  mEscSequence = EscSequenceBuilder::setNearestColor(
    layer, palette, red, green, blue);
}

std::ostream & TUCUT::TUI::operator << (
  std::ostream & out,
  Color const & color)
{
  out << color.escSequence();
  return out;
}

// The cursor is assumed to be visible so that the
// setup method can hide it.
TUCUT::TUI::Terminal::Terminal (bool useAlternateScreen)
: mOutput(std::cout),
  mUseAlternateScreen(useAlternateScreen),
  mCursorShown(true)
{
  mInput = std::make_unique<Input>(*this);
  setup();
}

TUCUT::TUI::Terminal::~Terminal ()
{
  teardown();
}

std::ostream & TUCUT::TUI::Terminal::output ()
{
  return mOutput;
}

TUCUT::TUI::Input & TUCUT::TUI::Terminal::input ()
{
  return *mInput;
}

void TUCUT::TUI::Terminal::resetGraphics ()
{
  std::cout << EscSequenceBuilder::resetGraphics();
}

void TUCUT::TUI::Terminal::useDefaultForeground ()
{
  std::cout << EscSequenceBuilder::useDefaultForeground();
}

void TUCUT::TUI::Terminal::useDefaultBackground ()
{
  std::cout << EscSequenceBuilder::useDefaultBackground();
}

void TUCUT::TUI::Terminal::underlineOn ()
{
  std::cout << EscSequenceBuilder::underlineOn();
}

void TUCUT::TUI::Terminal::underlineOff ()
{
  std::cout << EscSequenceBuilder::underlineOff();
}

void TUCUT::TUI::Terminal::blinkOn ()
{
  std::cout << EscSequenceBuilder::blinkOn();
}

void TUCUT::TUI::Terminal::blinkOff ()
{
  std::cout << EscSequenceBuilder::blinkOff();
}

void TUCUT::TUI::Terminal::moveCursor (
  unsigned int row,
  unsigned int column)
{
  std::cout << EscSequenceBuilder::moveCursor(row, column);
}

void TUCUT::TUI::Terminal::moveCursorUp (
  unsigned int lines)
{
  std::cout << EscSequenceBuilder::moveCursorUp(lines);
}

void TUCUT::TUI::Terminal::moveCursorDown (
  unsigned int lines)
{
  std::cout << EscSequenceBuilder::moveCursorDown(lines);
}

void TUCUT::TUI::Terminal::moveCursorForward (
  unsigned int columns)
{
  std::cout << EscSequenceBuilder::moveCursorForward(columns);
}

void TUCUT::TUI::Terminal::moveCursorBack (
  unsigned int columns)
{
  std::cout << EscSequenceBuilder::moveCursorBack(columns);
}

bool TUCUT::TUI::Terminal::showCursor ()
{
  bool previous = mCursorShown;
  if (not mCursorShown)
  {
    std::cout << EscSequenceBuilder::showCursor();
    mCursorShown = true;
  }
  return previous;
}

bool TUCUT::TUI::Terminal::hideCursor ()
{
  bool previous = mCursorShown;
  if (mCursorShown)
  {
    std::cout << EscSequenceBuilder::hideCursor();
    mCursorShown = false;
  }
  return previous;
}

void TUCUT::TUI::Terminal::clearScreen ()
{
  std::cout << EscSequenceBuilder::clearScreen();
}

void onKeyboardEvent(KEY_EVENT_RECORD record,
  TUCUT::TUI::Terminal * terminal)
{
  // This string will remain between calls and will
  // accumulate any partial code units until a complete
  // character can be handled.
  static std::wstring buffer;

  if (not record.bKeyDown)
  {
      return;
  }
  auto chWide = record.uChar.UnicodeChar;
  buffer += chWide;
  std::string utf8 = TUCUT::Text::to_string(buffer, buffer);
  if (not utf8.empty())
  {
    // Give the input a single Unicode character as a
    // UTF8 string.
    terminal->input().accept(utf8);
  }
}

void inputProc (std::stop_token stopToken,
  TUCUT::TUI::Terminal * terminal)
{
  if (not terminal)
  {
    return;
  }

  auto stdinHandle = GetStdHandle(STD_INPUT_HANDLE);
  constexpr int timeout_ms = 20;
  DWORD inputRecordsReadCount;
  constexpr DWORD inputRecordsBufferSize = 128;
  INPUT_RECORD inputRecordsBuffer[inputRecordsBufferSize];

  while (true)
  {
    if (stopToken.stop_requested())
    {
      return;
    }

    auto waitResult = WaitForSingleObject(stdinHandle,
      timeout_ms);
    if (waitResult == WAIT_TIMEOUT)
    {
      terminal->input().handleTimeout();
      continue;
    }

    ReadConsoleInput(stdinHandle, inputRecordsBuffer,
      inputRecordsBufferSize, &inputRecordsReadCount);
    for (DWORD i = 0; i < inputRecordsReadCount; ++i)
    {
      switch(inputRecordsBuffer[i].EventType)
      {
      case KEY_EVENT:
        onKeyboardEvent(inputRecordsBuffer[i].Event.KeyEvent,
          terminal);
        break;

      case MOUSE_EVENT:
        break;

      case WINDOW_BUFFER_SIZE_EVENT:
        break;

      case FOCUS_EVENT:
      case MENU_EVENT:
          break;

      default:
        break;
      }
    }
  }
}

void TUCUT::TUI::Terminal::setup ()
{
#if defined(_WIN32)
  // Get the current stdout and stdin modes and make sure
  // that the modes will be restored when this app exits.
  auto stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  auto stdinHandle = GetStdHandle(STD_INPUT_HANDLE);

  DWORD outMode = 0;
  DWORD inMode = 0;
  GetConsoleMode(stdoutHandle, &outMode);
  GetConsoleMode(stdinHandle, &inMode);
  mOutMode = outMode;
  mInMode = inMode;

  outMode |= ENABLE_PROCESSED_OUTPUT;
  outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
  outMode |= DISABLE_NEWLINE_AUTO_RETURN;
  outMode |= ENABLE_LVB_GRID_WORLDWIDE;

  inMode &= ~ENABLE_LINE_INPUT;
  inMode &= ~ENABLE_ECHO_INPUT;
  inMode &= ~ENABLE_INSERT_MODE;
  inMode &= ~ENABLE_QUICK_EDIT_MODE;
  inMode |= ENABLE_PROCESSED_INPUT;
  inMode |= ENABLE_WINDOW_INPUT;
  inMode |= ENABLE_MOUSE_INPUT;
  inMode |= ENABLE_VIRTUAL_TERMINAL_INPUT;

  SetConsoleMode(stdoutHandle, outMode);
  SetConsoleMode(stdinHandle, inMode);
#else
  struct termios terminal;
  tcgetattr(STDIN_FILENO, &terminal);
  mTerm = terminal;

  terminal.c_lflag &= ~ICANON;
  terminal.c_lflag &= ~ECHO;
  terminal.c_cc[VMIN] = 0;
  terminal.c_cc[VTIME] = 0;

  tcsetattr(STDIN_FILENO, TCSANOW, &terminal);
#endif

  if (mUseAlternateScreen)
  {
    useAlternateScreen();
  }
  hideCursor();

  mInputThread = std::jthread(inputProc, this);
}

void TUCUT::TUI::Terminal::teardown ()
{
#if defined(_WIN32)
  auto stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  auto stdinHandle = GetStdHandle(STD_INPUT_HANDLE);

  SetConsoleMode(stdoutHandle, mOutMode);
  SetConsoleMode(stdinHandle, mInMode);
#else
  tcsetattr(STDIN_FILENO, TCSANOW, &mTerm);
#endif

  if (mUseAlternateScreen)
  {
    useMainScreen();
  }
  showCursor();
}

void TUCUT::TUI::Terminal::useAlternateScreen ()
{
  std::cout << EscSequenceBuilder::useAlternateScreen();
}
void TUCUT::TUI::Terminal::useMainScreen ()
{
  std::cout << EscSequenceBuilder::useMainScreen();
}

TUCUT::TUI::CursorShow::CursorShow (Terminal & terminal)
: mTerminal(terminal)
{
  mCursorPreviouslyShown = mTerminal.showCursor();
}

TUCUT::TUI::CursorShow::~CursorShow ()
{
  if (not mCursorPreviouslyShown)
  {
    mTerminal.hideCursor();
  }
}

TUCUT::TUI::CursorHide::CursorHide (Terminal & terminal)
: mTerminal(terminal)
{
  mCursorPreviouslyShown = mTerminal.hideCursor();
}

TUCUT::TUI::CursorHide::~CursorHide ()
{
  if (mCursorPreviouslyShown)
  {
    mTerminal.showCursor();
  }
}