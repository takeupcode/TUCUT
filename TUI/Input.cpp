#include "Input.h"

namespace
{
  template<class... Ts>
  struct overloaded : Ts...
  {
    using Ts::operator()...;
  };
}

TUCUT::TUI::Input::Input (
  Terminal & terminal)
: mTerminal(terminal),
  mOutput(terminal.output())
{ }

void TUCUT::TUI::Input::handleTimeout ()
{
  static std::string etx {KeyCodes::EndOfText};
  // We accept an end of text character instead of
  // directly posting a timeout event because it is
  // possible for a timeout to result in an escape
  // non-printing character event being posted if a
  // single escape character is waiting in the escape
  // sequence when there is no more input.
  accept(etx);
}

void TUCUT::TUI::Input::accept (
  std::string const & utf8)
{
  // utf8 contains one or more code units that make
  // up a single Unicode code point. We need to post
  // normal characters as a character event and parse
  // escape codes into other events. Note that a
  // simple escape followed by a normal character
  // represents the alt key pressed together with the
  // character.

  // This string will remain between calls and will
  // accumulate any partial escape sequences until a
  // complete escape sequence can be handled.
  static std::string escapeSequence;

  // Uncomment for debugging.
  //if (utf8[0] != KeyCodes::EndOfText)
  //  mOutput << static_cast<int>(utf8[0]) << "\n";

  if (utf8[0] == KeyCodes::EndOfText)
  {
    // We use end of text as a signal that the input
    // is temporarily empty. When we get a timeout
    // while waiting for input, we post an end of text
    // character. If there is a single escape character
    // sitting in the escape sequence, the timeout is
    // our signal to treat it as a normal escape
    // character. Otherwise, the end of text will cause
    // its own event to be posted so that an app
    // can periodically do other work.
    if (escapeSequence.length() == 1)
    {
      // An escape with nothing following should result
      // in an escape non-printing character event. If
      // there is already a single escape char in the
      // escape sequence, add another escape char which
      // will pass through as a non-printing character.
      escapeSequence += KeyCodes::EscapeChar;
    }
  }
  else if (utf8[0] == KeyCodes::EscapeChar)
  {
    // Check for a single escape already in which case
    // we end up appending this second escape below.
    // Two escapes will be treated as a single escape
    // non-printing character event.
    if (escapeSequence.length() != 1)
    {
      // If we get another escape before the previous
      // escape sequence is complete, start over again
      // with a new escape sequence. Only do this for
      // escape sequences that have progressed past the
      // initial escape character.
      escapeSequence = KeyCodes::EscapeChar;
      return;
    }
  }
  else if (utf8[0] == KeyCodes::CancelChar ||
    utf8[0] == KeyCodes::SubstituteChar)
  {
    // Cancel and substitute characters abort an
    // escape sequence.
    escapeSequence.clear();
    return;
  }

  // If we've started an escape sequence, keep going
  // until it's finished.
  if (not escapeSequence.empty())
  {
    // Keep adding characters to the escape sequence
    // until we find a complete sequence. We don't
    // add end of text characters and we ignore null.
    if (utf8[0] == KeyCodes::NullChar)
    {
      return;
    }
    bool endOfText = false;
    if (utf8[0] == KeyCodes::EndOfText)
    {
      endOfText = true;
    }
    else
    {
      escapeSequence += utf8[0];
    }
    Event event = parseEscapeSequence(escapeSequence,
      endOfText);
    std::visit(overloaded
      {
        [] (NoEvent &)
        { }, // Ignore and try again later.

        [this] (DropEscapeEvent &)
        {
          // Uncomment to display dropped event data.
          //mOutput << arg.to_string();

          escapeSequence.clear();
        },

        [this] (auto & arg)
        {
          escapeSequence.clear();
          mMessages.post(arg);
        }
      },
      event);
    return;
  }

  // Modify certain characters.
  std::string modified = utf8;
  if (modified[0] == KeyCodes::EnterChar)
  {
    // Change enter key presses to newline characters.
    modified[0] = KeyCodes::NewlineChar;
  }
  else if (modified[0] == KeyCodes::DeleteChar)
  {
    // We get a delete code when the backspace key is
    // pressed so put it back to backspace.
    modified[0] = KeyCodes::BackspaceChar;
  }

  Event event;
  if (modified[0] == KeyCodes::EndOfText)
  {
    event = TimeoutEvent
    { };
  }
  else if (modified[0] < KeyCodes::SpaceChar ||
    modified[0] == KeyCodes::DeleteChar)
  {
    event = NonPrintingCharacterEvent
    {
      .mKey = modified[0],
      .mKeyModifier = KeyModifiers::None
    };
  }
  else
  {
    event = CharacterEvent
    {
      .mUtf8 = modified,
      .mKeyModifier = KeyModifiers::None
    };
  }
  mMessages.post(event);
}

void TUCUT::TUI::Input::clearError ()
{
  mSuccess = true;
}

TUCUT::TUI::Input::operator bool () const
{
  return mSuccess;
}

TUCUT::TUI::Input & TUCUT::TUI::Input::operator >> (
  int & i)
{
  if (not mSuccess)
  {
    return *this;
  }

  auto ss = bufferedRead();
  int test;
  if (ss >> test)
  {
    i = test;
  }
  else
  {
    mSuccess = false;
  }
  return *this;
}

TUCUT::TUI::Input & TUCUT::TUI::Input::operator >> (
  unsigned int & ui)
{
  if (not mSuccess)
  {
    return *this;
  }

  auto ss = bufferedRead();
  unsigned int test;
  if (ss >> test)
  {
    ui = test;
  }
  else
  {
    mSuccess = false;
  }
  return *this;
}

TUCUT::TUI::Input & TUCUT::TUI::Input::operator >> (
  double & d)
{
  if (not mSuccess)
  {
    return *this;
  }

  auto ss = bufferedRead();
  double test;
  if (ss >> test)
  {
    d = test;
  }
  else
  {
    mSuccess = false;
  }
  return *this;
}

TUCUT::TUI::Input & TUCUT::TUI::Input::operator >> (
  std::string & str)
{
  if (not mSuccess)
  {
    return *this;
  }

  auto ss = bufferedRead();
  str = ss.str();
  return *this;
}

std::stringstream TUCUT::TUI::Input::bufferedRead ()
{
  std::stringstream ss;
  while (true)
  {
    Event event;
    if (not mMessages.get(event))
    {
      ss.clear();
      return ss;
    }

    std::string utf8;
    std::visit(overloaded
      {
        [&utf8] (CharacterEvent & arg)
        {
          utf8 = arg.mUtf8;
        },

        [&utf8] (NonPrintingCharacterEvent & arg)
        {
          if (arg.mKey == KeyCodes::BackspaceChar ||
            arg.mKey == KeyCodes::NewlineChar)
          {
            utf8 = std::string(1, arg.mKey);
          }
        },

        [] (auto &)
        { } // Ignore all other events.
      },
      event);

    if (utf8 == std::string(1, KeyCodes::NewlineChar))
    {
      break;
    }
    else if (utf8 == std::string(1, KeyCodes::BackspaceChar))
    {
      if (ss.str().empty())
      {
        continue;
      }
      mTerminal.moveCursorBack(1);
      mOutput << " ";
      mTerminal.moveCursorBack(1);

      std::string current(ss.str());
      current.pop_back();
      ss.str(current);
      ss.seekp(0, ss.end);
    }
    else
    {
      mOutput << utf8;
      ss << utf8;
    }
  }
  return ss;
}
