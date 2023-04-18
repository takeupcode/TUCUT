//  Event.cpp
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2023-04-04.
//  Copyright © Take Up Code, Inc.
//
#include "Event.h"

#include <sstream>

using namespace TUCUT;

TUI::DropEscapeEvent::DropEscapeEvent (
  std::string const & sequence)
: mUtf8(sequence)
{ }

TUI::DropEscapeEvent::DropEscapeEvent (
  std::vector<std::optional<int>> const & parameters)
{
  for (auto const & opt: parameters)
  {
    int i = opt.has_value() ? opt.value() : 0;
    mUtf8.push_back(static_cast<char>(i));
  }
}

std::string TUI::DropEscapeEvent::to_string () const
{
  std::stringstream ss;
  ss << "Dropped sequence: [ ";
  for (char ch: mUtf8)
  {
    ss << static_cast<int>(ch) << " ";
  }
  ss << "]\n";
  return ss.str();
}

TUI::Event TUI::parseEscapeSequence (
  std::string const & sequence,
  bool endOfText,
  bool cursorPositionReportExpected)
{
  if (sequence.empty())
  {
    return NoEvent {};
  }

  if (sequence[0] != KeyCodes::EscapeChar)
  {
    return DropEscapeEvent(sequence);
  }

  // We don't handle DCS (P) or OSC (]) sequences or
  // other sequences in the C1 set. The condition for
  // an Alt key is a little complicated because we
  // need to handle the case of an Alt-[. Normally,
  // ESC [ is the beginning of a CSI sequence. But
  // the two characters ESC [ can exist by themselves
  // with nothing following and should represent an
  // Alt-[. We use endOfText to tell if anything else
  // will be arriving or not.
  if (sequence.length() == 2 &&
    (sequence[1] != '[' ||
    (sequence[1] == '[' && endOfText)))
  {
    return parseAltKey(sequence[1]);
  }

  return parseCSI(sequence, cursorPositionReportExpected);
}

TUI::Event TUI::parseAltKey (
  char code)
{
  Event event = NoEvent {};

  if (code < KeyCodes::SpaceChar ||
    code == KeyCodes::DeleteChar)
  {
    event = NonPrintingCharacterEvent
    {
      .mKey = code,
      .mKeyModifier = KeyModifiers::Alt
    };
    if (code == KeyCodes::EscapeChar)
    {
      // A double escape results in an escape
      // non-printing character event without the
      // Alt modifier.
      std::get<NonPrintingCharacterEvent>(
        event).mKeyModifier = KeyModifiers::None;
    }
  }
  else
  {
    event = CharacterEvent
    {
      .mUtf8 = std::string(1, code),
      .mKeyModifier = KeyModifiers::Alt
    };
  }
  return event;
}

TUI::Event TUI::parseCSI (std::string const & sequence,
  bool cursorPositionReportExpected)
{
  Event event = NoEvent {};

  // As long as there are at least 3 characters,
  // continue and assume the first two are ESC [.
  if (sequence.length() < 3)
  {
    return event;
  }

  std::vector<std::optional<int>> parameters;
  int digitParameter {};
  int explicitParameterCount {};
  bool digitFound = false;
  bool semicolonLast = false;
  unsigned int i = 2; // We already know the first two.
  for (; i < sequence.length(); ++i)
  {
    if (sequence[i] < KeyCodes::CSITermBegin ||
      sequence[i] > KeyCodes::CSITermEnd)
    {
      // Keep going until we reach the end and
      // gather all the parameters.
      if (sequence[i] == KeyCodes::SpaceChar)
      {
        continue;
      }
      else if (sequence[i] == KeyCodes::SemicolonChar)
      {
        semicolonLast = true;
        // For every semicolon, add whatever parameter
        // we've already found in the digits or a
        // nullopt for a default value.
        if (digitFound)
        {
          parameters.push_back(digitParameter);
          digitParameter = 0;
          ++explicitParameterCount;
          digitFound = false;
        }
        else
        {
          parameters.push_back(std::nullopt);
        }
        continue;
      }

      semicolonLast = false;
      if (sequence[i] >= '0' && sequence[i] <= '9')
      {
        digitFound = true;
        digitParameter *= 10;
        digitParameter += sequence[i] - '0';
      }
      else
      {
        if (digitFound)
        {
          // It's an error to mix digits with other chars.
          event = DropEscapeEvent(sequence);
          break;
        }
        ++explicitParameterCount;
        parameters.push_back(sequence[i]);
      }
      continue;
    }

    if (digitFound || semicolonLast)
    {
      if (digitFound)
      {
        parameters.push_back(digitParameter);
        ++explicitParameterCount;
      }
      else
      {
        parameters.push_back(std::nullopt);
      }
    }

    switch (sequence[i])
    {
    case KeyCodes::TildeChar:
      if (explicitParameterCount == 0 ||
        not parameters[0].has_value())
      {
        // A vt CSI needs the first parameter to be
        // explicit. We don't add the terminating
        // character to the parameters because it's
        // always ~.
        return DropEscapeEvent(sequence);
      }
      return parseVtCSI(parameters);

    default:
      // Any other terminating character is an xterm
      // sequence and we need to add the terminating
      // character to the parameters.
      parameters.push_back(sequence[i]);
      return parseXtermCSI(parameters,
        cursorPositionReportExpected);
    }
  }

  return event;
}

TUI::Event TUI::parseVtCSI (
  std::vector<std::optional<int>> const & parameters)
{
  Event event = DropEscapeEvent(parameters);
  if (parameters.empty())
  {
    return event;
  }

  int modifier {};
  if (parameters.size() == 2 && parameters[1].has_value())
  {
    modifier = parameters[1].value();
    modifier -= 1;
  }

  // We make sure that the first parameter is present and
  // contains an actual value before calling this method.
  switch (parameters[0].value())
  {
  case 1:
  case 7:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::Home,
      .mKeyModifier = modifier
    };
    break;

  case 2:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::Insert,
      .mKeyModifier = modifier
    };
    break;

  case 3:
    event = NonPrintingCharacterEvent
    {
      .mKey = KeyCodes::DeleteChar,
      .mKeyModifier = modifier
    };
    break;

  case 4:
  case 8:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::End,
      .mKeyModifier = modifier
    };
    break;

  case 5:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::PageUp,
      .mKeyModifier = modifier
    };
    break;

  case 6:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::PageDown,
      .mKeyModifier = modifier
    };
    break;

  case 11:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::F1,
      .mKeyModifier = modifier
    };
    break;

  case 12:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::F2,
      .mKeyModifier = modifier
    };
    break;

  case 13:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::F3,
      .mKeyModifier = modifier
    };
    break;

  case 14:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::F4,
      .mKeyModifier = modifier
    };
    break;

  case 15:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::F5,
      .mKeyModifier = modifier
    };
    break;

  case 17:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::F6,
      .mKeyModifier = modifier
    };
    break;

  case 18:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::F7,
      .mKeyModifier = modifier
    };
    break;

  case 19:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::F8,
      .mKeyModifier = modifier
    };
    break;

  case 20:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::F9,
      .mKeyModifier = modifier
    };
    break;

  case 21:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::F10,
      .mKeyModifier = modifier
    };
    break;

  case 23:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::F11,
      .mKeyModifier = modifier
    };
    break;

  case 24:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::F12,
      .mKeyModifier = modifier
    };
    break;
  }

  return event;
}

TUI::Event TUI::parseXtermCSI (
  std::vector<std::optional<int>> const & parameters,
  bool cursorPositionReportExpected)
{
  Event event = DropEscapeEvent(parameters);
  if (parameters.empty())
  {
    return event;
  }

  int modifier {};
  if (parameters.size() > 1 &&
    parameters[parameters.size() - 2].has_value())
  {
    modifier = parameters[parameters.size() - 2].value();
    modifier -= 1;
  }

  char code {};
  if (parameters[parameters.size() - 1].has_value())
  {
    code = parameters[parameters.size() - 1].value();
  }

  switch (code)
  {
  case KeyCodes::AChar:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::ArrowUp,
      .mKeyModifier = modifier
    };
    break;

  case KeyCodes::BChar:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::ArrowDown,
      .mKeyModifier = modifier
    };
    break;

  case KeyCodes::CChar:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::ArrowRight,
      .mKeyModifier = modifier
    };
    break;

  case KeyCodes::DChar:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::ArrowLeft,
      .mKeyModifier = modifier
    };
    break;

  case KeyCodes::FChar:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::End,
      .mKeyModifier = modifier
    };
    break;

  case KeyCodes::GChar:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::Keypad5,
      .mKeyModifier = modifier
    };
    break;

  case KeyCodes::HChar:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::Home,
      .mKeyModifier = modifier
    };
    break;

  case KeyCodes::MChar:
  case KeyCodes::mChar:
    return parseMouseCSI(parameters);
    break;

  case KeyCodes::PChar:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::F1,
      .mKeyModifier = modifier
    };
    break;

  case KeyCodes::QChar:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::F2,
      .mKeyModifier = modifier
    };
    break;

  case KeyCodes::RChar:
    if (cursorPositionReportExpected)
    {
      return parseCursorPositionCSI(parameters);
    }
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::F3,
      .mKeyModifier = modifier
    };
    break;

  case KeyCodes::SChar:
    event = ExtendedCharacterEvent
    {
      .mKey = ExtendedKeys::F4,
      .mKeyModifier = modifier
    };
    break;
  }

  return event;
}

TUI::Event TUI::parseMouseCSI (
  std::vector<std::optional<int>> const & parameters)
{
  Event event = DropEscapeEvent(parameters);

  // There should be 5 parameters.
  // 0 - '>' which appears to be unused
  // 1 - bitmask for buttons and action
  // 2 - x coordinate
  // 3 - y coordinate
  // 4 - either 'M' or 'm' where 'm' appears to be
  //     used for moving. However, a bit in the
  //     bitmask also appears to identify moving.
  if (parameters.size() < 5 ||
    not parameters[1].has_value() ||
    not parameters[2].has_value() ||
    not parameters[3].has_value())
  {
    return event;
  }

  int paramBits = parameters[1].value();
  int paramX = parameters[2].value();
  int paramY = parameters[3].value();

  constexpr int buttonMask         = 0b0000'0011;
  constexpr int modifierMask       = 0b0001'1100;
  constexpr int movingMask         = 0b0010'0000;
  constexpr int wheelMask          = 0b0100'0000;
  constexpr int wheelDirectionMask = 0b0000'0001;

  MouseButtons button {};
  switch (paramBits & buttonMask)
  {
  case 0:
    button = MouseButtons::Left;
    break;
  case 1:
    button = MouseButtons::Middle;
    break;
  case 2:
    button = MouseButtons::Right;
    break;
  case 3:
    button = MouseButtons::None;
    break;
  }

  int modifier = (paramBits & modifierMask) >> 2;
  bool moving = paramBits & movingMask;
  bool wheelTurning = paramBits & wheelMask;
  bool wheelTurningUp = paramBits & wheelDirectionMask;

  MouseActions action {};
  if (moving)
  {
    action = MouseActions::MouseMove;
  }
  else if (wheelTurning && wheelTurningUp)
  {
    action = MouseActions::WheelUp;
  }
  else if (wheelTurning)
  {
    action = MouseActions::WheelDown;
  }
  else
  {
    action = MouseActions::ButtonPressed;
  }

  event = MouseEvent
  {
    .mButton = button,
    .mAction = action,
    .mKeyModifier = modifier,
    .mX = paramX,
    .mY = paramY
  };

  return event;
}

TUI::Event TUI::parseCursorPositionCSI (
  std::vector<std::optional<int>> const & parameters)
{
  Event event = DropEscapeEvent(parameters);

  // There should be 2 parameters.
  // 0 - row or y
  // 1 - column or x
  if (parameters.size() != 2)
  {
    return event;
  }

  int paramY = parameters[0].value();
  int paramX = parameters[1].value();
  event = CursorPositionEvent
  {
    .mX = paramX,
    .mY = paramY
  };

  return event;
}
