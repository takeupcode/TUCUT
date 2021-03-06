//
//  TextBox.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/18/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Curses_TextBox_h
#define TUCUT_Curses_TextBox_h

#include <string>
#include <vector>

#include "../Event/EventPublisher.h"
#include "../Event/EventSubscriber.h"
#include "Control.h"

namespace TUCUT {
namespace Curses {

class Button;

class TextBox : public Control, public Event::EventSubscriber<WindowSystem *, Button *>
{
public:
    const static int TextChangedEventId = 1;
    
    using TextChangedEvent = Event::EventPublisher<WindowSystem *, TextBox *>;
    
    static std::shared_ptr<TextBox> createSharedTextBox (const std::string & name, const std::string & text, int y, int x, int height, int width, int foreColor, int backColor, bool multiline = false);
    
    std::shared_ptr<TextBox> getSharedTextBox ();
    
    bool onKeyPress (WindowSystem * ws, int key) override;
    
    void onMouseEvent (WindowSystem * ws, short id, int y, int x, mmask_t buttonState) override;
    
    void onDrawClient () const override;
    
    void onResize () override;
    
    int textClientWidth () const;
    
    void setMinHeight (int height) override;
    
    void setMinWidth (int width) override;
    
    bool isMultiline () const;
    
    std::string text () const;
    
    void setText (const std::string & text);
    
    void appendLines (const std::string & text);
    
    void insertLines (const std::string & text);
    
    TextChangedEvent * textChanged ();

protected:
    TextBox (const std::string & name, const std::string & text, int y, int x, int height, int width, int foreColor, int backColor, bool multiline);
    
    void initialize () override;

private:
    void notify (int id, WindowSystem * ws, Button * button) override;
    
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
    
    static const std::string windowName;
    static const std::string moveCursorUpButtonName;
    static const std::string moveCursorDownButtonName;
    static const std::string moveCursorLeftButtonName;
    static const std::string moveCursorRightButtonName;
    
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
    
} // namespace Curses
} // namespace TUCUT

#endif // TUCUT_Curses_TextBox_h
