//  TextBox.h
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-18.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_TUI_TextBox_h
#define TUCUT_TUI_TextBox_h

#include "../Notify/EventPublisher.h"
#include "../Notify/EventSubscriber.h"
#include "Control.h"
#include "Event.h"

#include <string>
#include <vector>

namespace TUCUT::TUI
{
  class Button;

  class TextBox : public Control,
    public Notify::EventSubscriber<WindowSystem *, Button *>
  {
  public:
    static int const TextChangedEventId = 1;

    using TextChangedEvent = Notify::EventPublisher<
      WindowSystem *, TextBox *>;

    static std::shared_ptr<TextBox> createSharedTextBox (
      std::string const & name,
      std::string const & text,
      int x,
      int y,
      int width,
      int height,
      Color const & foreColor,
      Color const & backColor,
      bool multiline = false);

    std::shared_ptr<TextBox> getSharedTextBox ();

    bool onKeyPress (WindowSystem * ws,
      CharacterEvent const & event) override;

    bool onNonPrintingKeyPress (WindowSystem * ws,
      NonPrintingCharacterEvent const & event) override;

    bool onExtendedKeyPress (WindowSystem * ws,
      ExtendedCharacterEvent const & event) override;

    void onMouseEvent (WindowSystem * ws,
      MouseEvent const & event) override;

    void onDrawClient (WindowSystem * ws) const override;

    void onResize () override;

    int textClientWidth () const;

    void setMinWidth (int width) override;

    void setMinHeight (int height) override;

    bool isMultiline () const;

    std::string text () const;

    void setText (std::string const & text);

    void appendLines (std::string const & text);

    void insertLines (std::string const & text);

    TextChangedEvent * textChanged ();

  protected:
    TextBox (std::string const & name,
      std::string const & text,
      int x,
      int y,
      int width,
      int height,
      Color const & foreColor,
      Color const & backColor,
      bool multiline);

    void initialize () override;

  private:
    void notify (int id, WindowSystem * ws,
      Button * button) override;

    void handleTextChange (WindowSystem * ws);

    void moveCursorUp ();
    void moveCursorDown ();
    void moveCursorLeft ();
    void moveCursorRight ();
    void breakLineAtCursor ();
    bool removeCharAtCursor ();
    bool addCharAtCursor (int key);

    void placeCursorClosestToDesiredColumn ();
    void ensureCursorIsVisible ();

    static std::string const windowName;
    static std::string const moveCursorUpButtonName;
    static std::string const moveCursorDownButtonName;
    static std::string const moveCursorLeftButtonName;
    static std::string const moveCursorRightButtonName;

    std::vector<std::string> mText;
    std::unique_ptr<TextChangedEvent> mTextChanged;
    std::shared_ptr<Button> mMoveCursorUpButton;
    std::shared_ptr<Button> mMoveCursorDownButton;
    std::shared_ptr<Button> mMoveCursorLeftButton;
    std::shared_ptr<Button> mMoveCursorRightButton;
    int mScrollLine;
    int mScrollColumn;
    int mCursorLine;
    int mCursorColumn;
    int mDesiredColumn;
    bool mMultiline;
  };
} // namespace TUCUT::TUI

#endif // TUCUT_TUI_TextBox_h
