//
//  DisplayBox.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 8/2/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Curses_DisplayBox_h
#define TUCUT_Curses_DisplayBox_h

#include <string>
#include <vector>

#include "../Event/EventPublisher.h"
#include "../Event/EventSubscriber.h"
#include "Control.h"

namespace TUCUT {
namespace Curses {

class Button;

class DisplayBox : public Control, public Event::EventSubscriber<GameManager *, const Button *>
{
public:
    const static int ClickedEventId = 1;
    const static int ScrollChangedEventId = 2;
    const static int CursorChangedEventId = 3;

    using ClickedEvent = Event::EventPublisher<GameManager *, const DisplayBox *, int, int>;
    using ScrollChangedEvent = Event::EventPublisher<GameManager *, const DisplayBox *, int, int>;
    using CursorChangedEvent = Event::EventPublisher<GameManager *, const DisplayBox *, int, int>;

    static std::shared_ptr<DisplayBox> createSharedDisplayBox (const std::string & name, int y, int x, int height, int width, int contentHeight, int contentWidth, int foreColor, int backColor, bool allowScrolling = false, bool allowCursor = false);
    
    std::shared_ptr<DisplayBox> getSharedDisplayBox ();
    
    bool onKeyPress (GameManager * gm, int key) override;
    
    void onMouseEvent (GameManager * gm, short id, int y, int x, mmask_t buttonState) override;
    
    void onDrawClient () const override;
    
    int textClientWidth () const;
    
    void setMinHeight (int height) override;
    
    void setMinWidth (int width) override;
    
    char symbol (int y, int x) const;
    
    void setSymbol (char symbol, int y, int x);

    int getScrollY () const;
    int getScrollX () const;
    
    bool scrollUp ();
    bool scrollDown ();
    bool scrollLeft ();
    bool scrollRight ();

    int getCursorY () const;
    int getCursorX () const;

    bool moveCursorUp ();
    bool moveCursorDown ();
    bool moveCursorLeft ();
    bool moveCursorRight ();

    ClickedEvent * clicked ();
    
    ScrollChangedEvent * scrollChanged ();
    
    CursorChangedEvent * cursorChanged ();

protected:
    DisplayBox (const std::string & name, int y, int x, int height, int width, int contentHeight, int contentWidth, int foreColor, int backColor, bool allowScrolling, bool allowCursor);
    
    void initialize () override;
    
private:
    void notify (int id, GameManager * gm, const Button * button) override;
    
    void handleClicked (GameManager * gm, int y, int x) const;
    
    void handleScrollChanged (GameManager * gm, int y, int x) const;
    
    void handleCursorChanged (GameManager * gm, int y, int x) const;

    static const std::string windowName;
    static const std::string scrollUpButtonName;
    static const std::string scrollDownButtonName;
    static const std::string scrollLeftButtonName;
    static const std::string scrollRightButtonName;
    static const std::string moveCursorUpButtonName;
    static const std::string moveCursorDownButtonName;
    static const std::string moveCursorLeftButtonName;
    static const std::string moveCursorRightButtonName;

    std::vector<std::string> mContent;
    std::unique_ptr<ClickedEvent> mClicked;
    std::unique_ptr<ScrollChangedEvent> mScrollChanged;
    std::unique_ptr<CursorChangedEvent> mCursorChanged;
    std::shared_ptr<Button> mScrollUpButton;
    std::shared_ptr<Button> mScrollDownButton;
    std::shared_ptr<Button> mScrollLeftButton;
    std::shared_ptr<Button> mScrollRightButton;
    std::shared_ptr<Button> mMoveCursorUpButton;
    std::shared_ptr<Button> mMoveCursorDownButton;
    std::shared_ptr<Button> mMoveCursorLeftButton;
    std::shared_ptr<Button> mMoveCursorRightButton;
    int mScrollLine;
    int mScrollColumn;
    int mCursorLine;
    int mCursorColumn;
    int mContentHeight;
    int mContentWidth;
    bool mAllowScrolling;
    bool mAllowCursor;
};
        
} // namespace Curses
} // namespace TUCUT

#endif // TUCUT_Curses_DisplayBox_h
