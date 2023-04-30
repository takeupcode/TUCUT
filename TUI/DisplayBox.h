//  DisplayBox.h
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-08-02.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_TUI_DisplayBox_h
#define TUCUT_TUI_DisplayBox_h

#include "../Notify/EventPublisher.h"
#include "../Notify/EventSubscriber.h"
#include "Control.h"
#include "Event.h"

#include <vector>

namespace TUCUT::TUI
{
  class Button;

  class DisplayBox : public Control,
    public Notify::EventSubscriber<WindowSystem *, Button *>
  {
  public:
    static int const ClickedEventId = 1;
    static int const ScrollChangedEventId = 2;
    static int const BeforeCenterChangedEventId = 3;
    static int const AfterCenterChangedEventId = 4;

    using ClickedEvent = Notify::EventPublisher<
      WindowSystem *, DisplayBox *, int, int>;
    using ScrollChangedEvent = Notify::EventPublisher<
      WindowSystem *, DisplayBox *, int, int>;
    using BeforeCenterChangedEvent = Notify::EventPublisher<
      WindowSystem *, DisplayBox *, int, int, bool &>;
    using AfterCenterChangedEvent = Notify::EventPublisher<
      WindowSystem *, DisplayBox *, int, int>;

    static std::shared_ptr<DisplayBox> createSharedDisplayBox (
      std::string const & name,
      std::string const & centerSymbol,
      int x,
      int y,
      int width,
      int height,
      int contentWidth,
      int contentHeight,
      Color const & foreColor,
      Color const & backColor,
      bool autoScrolling = false,
      bool allowCenterControls = false,
      int scrollMarginTop = 0,
      int scrollMarginRight = 0,
      int scrollMarginBottom = 0,
      int scrollMarginLeft = 0);

    std::shared_ptr<DisplayBox> getSharedDisplayBox ();

    bool onExtendedKeyPress (WindowSystem * ws,
      ExtendedCharacterEvent const & event) override;

    void onMouseEvent (WindowSystem * ws,
      MouseEvent const & event) override;

    void onDrawClient (WindowSystem * ws) const override;

    int textClientWidth () const;

    void setMinWidth (int width) override;

    void setMinHeight (int height) override;

    std::string symbol (int x, int y) const;

    void setSymbol (std::string const & symbol, int x, int y);

    void setSymbols (std::string const & symbols, int y);

    bool isClickLocationShown () const;
    void showClickLocation (bool show);

    int getClickedX () const;
    int getClickedY () const;

    int getScrollX () const;
    int getScrollY () const;

    bool scrollUp ();
    bool scrollDown ();
    bool scrollLeft ();
    bool scrollRight ();

    void ensurePointIsVisible (int x, int y);
    void ensureCenterIsVisible ();

    int getCenterX () const;
    int getCenterY () const;

    void setCenter (int x, int y);

    bool moveCenterUp ();
    bool moveCenterDown ();
    bool moveCenterLeft ();
    bool moveCenterRight ();

    ClickedEvent * clicked ();

    ScrollChangedEvent * scrollChanged ();

    BeforeCenterChangedEvent * beforeCenterChanged ();

    AfterCenterChangedEvent * afterCenterChanged ();

  protected:
    DisplayBox (std::string const & name,
      std::string const & centerSymbol,
      int x,
      int y,
      int width,
      int height,
      int contentWidth,
      int contentHeight,
      Color const & foreColor,
      Color const & backColor,
      bool autoScrolling,
      bool allowCenterControls,
      int scrollMarginTop,
      int scrollMarginRight,
      int scrollMarginBottom,
      int scrollMarginLeft);

    void initialize () override;

  private:
    void notify (int id, WindowSystem * ws,
      Button * button) override;

    void handleClicked (WindowSystem * ws,
      int x, int y);

    void handleScrollChanged (WindowSystem * ws,
      int x, int y);

    void handleBeforeCenterChanged (WindowSystem * ws,
      int x, int y, bool & cancel);

    void handleAfterCenterChanged (WindowSystem * ws,
      int x, int y);

    void verifyX (int x) const;
    void verifyY (int y) const;
    void verifyXY (int x, int y) const;

    bool canMoveCenterUp ();
    bool canMoveCenterDown ();
    bool canMoveCenterLeft ();
    bool canMoveCenterRight ();

    void handleMoveCenterUp (WindowSystem * ws);
    void handleMoveCenterDown (WindowSystem * ws);
    void handleMoveCenterLeft (WindowSystem * ws);
    void handleMoveCenterRight (WindowSystem * ws);

    static std::string const moveCenterUpButtonName;
    static std::string const moveCenterDownButtonName;
    static std::string const moveCenterLeftButtonName;
    static std::string const moveCenterRightButtonName;

    std::vector<std::string> mContent;
    std::unique_ptr<ClickedEvent> mClicked;
    std::unique_ptr<ScrollChangedEvent> mScrollChanged;
    std::unique_ptr<BeforeCenterChangedEvent>
      mBeforeCenterChanged;
    std::unique_ptr<AfterCenterChangedEvent>
      mAfterCenterChanged;
    std::shared_ptr<Button> mMoveCenterUpButton;
    std::shared_ptr<Button> mMoveCenterDownButton;
    std::shared_ptr<Button> mMoveCenterLeftButton;
    std::shared_ptr<Button> mMoveCenterRightButton;
    int mClickedColumn;
    int mClickedLine;
    int mScrollColumn;
    int mScrollLine;
    int mCenterColumn;
    int mCenterLine;
    int mContentWidth;
    int mContentHeight;
    int mScrollMarginTop;
    int mScrollMarginRight;
    int mScrollMarginBottom;
    int mScrollMarginLeft;
    std::string mCenterSymbol;
    bool mAutoScrolling;
    bool mAllowCenterControls;
    bool mShowClickLocation;
  };
} // namespace TUCUT::TUI

#endif // TUCUT_TUI_DisplayBox_h
