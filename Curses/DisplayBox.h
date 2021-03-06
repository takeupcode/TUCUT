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

class DisplayBox : public Control, public Event::EventSubscriber<WindowSystem *, Button *>
{
public:
    const static int ClickedEventId = 1;
    const static int ScrollChangedEventId = 2;
    const static int BeforeCenterChangedEventId = 3;
    const static int AfterCenterChangedEventId = 4;

    using ClickedEvent = Event::EventPublisher<WindowSystem *, DisplayBox *, int, int>;
    using ScrollChangedEvent = Event::EventPublisher<WindowSystem *, DisplayBox *, int, int>;
    using BeforeCenterChangedEvent = Event::EventPublisher<WindowSystem *, DisplayBox *, int, int, bool &>;
    using AfterCenterChangedEvent = Event::EventPublisher<WindowSystem *, DisplayBox *, int, int>;

    static std::shared_ptr<DisplayBox> createSharedDisplayBox (const std::string & name, char centerChar, int y, int x, int height, int width, int contentHeight, int contentWidth, int foreColor, int backColor, bool autoScrolling = false, bool allowCenterControls = false, int scrollMarginTop = 0, int scrollMarginRight = 0, int scrollMarginBottom = 0, int scrollMarginLeft = 0);
    
    std::shared_ptr<DisplayBox> getSharedDisplayBox ();
    
    bool onKeyPress (WindowSystem * ws, int key) override;
    
    void onMouseEvent (WindowSystem * ws, short id, int y, int x, mmask_t buttonState) override;
    
    void onDrawClient () const override;
    
    int textClientWidth () const;
    
    void setMinHeight (int height) override;
    
    void setMinWidth (int width) override;
    
    char symbol (int y, int x) const;
    
    void setSymbol (char symbol, int y, int x);
    
    void setSymbols (const std::string & symbols, int y);

    bool isClickLocationShown () const;
    void showClickLocation (bool show);
    
    int getClickedY () const;
    int getClickedX () const;

    int getScrollY () const;
    int getScrollX () const;
    
    bool scrollUp ();
    bool scrollDown ();
    bool scrollLeft ();
    bool scrollRight ();
    
    void ensurePointIsVisible (int y, int x);
    void ensureCenterIsVisible ();

    int getCenterY () const;
    int getCenterX () const;
    
    void setCenter (int y, int x);

    bool moveCenterUp ();
    bool moveCenterDown ();
    bool moveCenterLeft ();
    bool moveCenterRight ();

    ClickedEvent * clicked ();
    
    ScrollChangedEvent * scrollChanged ();
    
    BeforeCenterChangedEvent * beforeCenterChanged ();
    
    AfterCenterChangedEvent * afterCenterChanged ();

protected:
    DisplayBox (const std::string & name, char centerChar, int y, int x, int height, int width, int contentHeight, int contentWidth, int foreColor, int backColor, bool autoScrolling, bool allowCenterControls, int scrollMarginTop, int scrollMarginRight, int scrollMarginBottom, int scrollMarginLeft);
    
    void initialize () override;
    
private:
    void notify (int id, WindowSystem * ws, Button * button) override;
    
    void handleClicked (WindowSystem * ws, int y, int x);
    
    void handleScrollChanged (WindowSystem * ws, int y, int x);
    
    void handleBeforeCenterChanged (WindowSystem * ws, int y, int x, bool & cancel);
    
    void handleAfterCenterChanged (WindowSystem * ws, int y, int x);
    
    void verifyY (int y) const;
    void verifyX (int x) const;
    void verifyYX (int y, int x) const;

    bool canMoveCenterUp ();
    bool canMoveCenterDown ();
    bool canMoveCenterLeft ();
    bool canMoveCenterRight ();

    void handleMoveCenterUp (WindowSystem * ws);
    void handleMoveCenterDown (WindowSystem * ws);
    void handleMoveCenterLeft (WindowSystem * ws);
    void handleMoveCenterRight (WindowSystem * ws);

    static const std::string windowName;
    static const std::string moveCenterUpButtonName;
    static const std::string moveCenterDownButtonName;
    static const std::string moveCenterLeftButtonName;
    static const std::string moveCenterRightButtonName;

    std::vector<std::string> mContent;
    std::unique_ptr<ClickedEvent> mClicked;
    std::unique_ptr<ScrollChangedEvent> mScrollChanged;
    std::unique_ptr<BeforeCenterChangedEvent> mBeforeCenterChanged;
    std::unique_ptr<AfterCenterChangedEvent> mAfterCenterChanged;
    std::shared_ptr<Button> mMoveCenterUpButton;
    std::shared_ptr<Button> mMoveCenterDownButton;
    std::shared_ptr<Button> mMoveCenterLeftButton;
    std::shared_ptr<Button> mMoveCenterRightButton;
    int mClickedLine;
    int mClickedColumn;
    int mScrollLine;
    int mScrollColumn;
    int mCenterLine;
    int mCenterColumn;
    int mContentHeight;
    int mContentWidth;
    int mScrollMarginTop;
    int mScrollMarginRight;
    int mScrollMarginBottom;
    int mScrollMarginLeft;
    char mCenterChar;
    bool mAutoScrolling;
    bool mAllowCenterControls;
    bool mShowClickLocation;
};
        
} // namespace Curses
} // namespace TUCUT

#endif // TUCUT_Curses_DisplayBox_h
