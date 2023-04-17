//  Event.h
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2023-04-04.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_TUI_Event_h
#define TUCUT_TUI_Event_h

#include <optional>
#include <string>
#include <variant>
#include <vector>

namespace TUCUT::TUI
{
  namespace KeyCodes
  {
    constexpr char NullChar       =   0;
    constexpr char EndOfText      =   3;
    constexpr char BackspaceChar  =   8;
    constexpr char NewlineChar    =  10;
    constexpr char EnterChar      =  13;
    constexpr char CancelChar     =  24;
    constexpr char SubstituteChar =  26;
    constexpr char EscapeChar     =  27;
    constexpr char SpaceChar      =  32;
    constexpr char SemicolonChar  =  59;
    constexpr char CSITermBegin   =  64;
    constexpr char AChar          =  65;
    constexpr char BChar          =  66;
    constexpr char CChar          =  67;
    constexpr char DChar          =  68;
    constexpr char FChar          =  70;
    constexpr char GChar          =  71;
    constexpr char HChar          =  72;
    constexpr char MChar          =  77;
    constexpr char PChar          =  80;
    constexpr char QChar          =  81;
    constexpr char RChar          =  82;
    constexpr char SChar          =  83;
    constexpr char mChar          = 109;
    constexpr char CSITermEnd     = 126;
    constexpr char TildeChar      = 126;
    constexpr char DeleteChar     = 127;
  }

  namespace KeyModifiers
  {
    constexpr int None  = 0;
    constexpr int Shift = 1;
    constexpr int Alt   = 2;
    constexpr int Ctrl  = 4;
    constexpr int Meta  = 8;
  }

  enum class ExtendedKeys
  {
    Insert,
    Home,
    End,
    Keypad5,
    PageUp,
    PageDown,
    ArrowUp,
    ArrowDown,
    ArrowRight,
    ArrowLeft,
    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    F10,
    F11,
    F12
  };

  enum class MouseButtons
  {
    None,
    Left,
    Middle,
    Right
  };

  enum class MouseActions
  {
    ButtonPressed,
    WheelUp,
    WheelDown,
    MouseMove
  };

  // This event type is used to represent an escape
  // sequence that is not yet complete. Code waiting
  // for input will not see this event.
  struct NoEvent
  { };

  // This event type is used to represent an escape
  // sequence that is not valid or should be dropped.
  // Code waiting for input will not see this event.
  // The UTF8 sequence is used only for debugging.
  struct DropEscapeEvent
  {
    DropEscapeEvent (std::string const & sequence);
    DropEscapeEvent (
      std::vector<std::optional<int>> const & parameters);

    std::string to_string () const;

    std::string mUtf8;
  };

  // This event type is used when there is no input so
  // that an app can perform other tasks.
  struct TimeoutEvent
  { };

  struct CharacterEvent
  {
    std::string mUtf8;
    int mKeyModifier;
  };

  struct NonPrintingCharacterEvent
  {
    char mKey; // 0-31, 127
    int mKeyModifier;
  };

  struct ExtendedCharacterEvent
  {
    ExtendedKeys mKey;
    int mKeyModifier;
  };

  struct MouseEvent
  {
    MouseButtons mButton;
    MouseActions mAction;
    int mKeyModifier;
    int mX;
    int mY;
  };

  using Event = std::variant<
    NoEvent,
    DropEscapeEvent,
    TimeoutEvent,
    CharacterEvent,
    NonPrintingCharacterEvent,
    ExtendedCharacterEvent,
    MouseEvent>;

  Event parseEscapeSequence (
    std::string const & sequence,
    bool endOfText);

  Event parseAltKey (
    char code);

  Event parseCSI (
    std::string const & sequence);

  Event parseVtCSI (
    std::vector<std::optional<int>> const & parameters);

  Event parseXtermCSI (
    std::vector<std::optional<int>> const & parameters);

  Event parseMouseCSI (
    std::vector<std::optional<int>> const & parameters);
} // namespace TUCUT::TUI

#endif // TUCUT_TUI_Event_h
