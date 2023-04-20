//  Window.h
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-01.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_TUI_Window_h
#define TUCUT_TUI_Window_h

#include "../ECS/ApplicationTime.h"
#include "Event.h"
#include "Terminal.h"

#include <memory>
#include <string>

namespace TUCUT::TUI
{
  class WindowSystem;

  class Window : public std::enable_shared_from_this<Window>
  {
  public:
    enum class VisibleState
    {
      Collapsed,
      Hidden,
      Shown
    };

    enum class EnableState
    {
      Disabled,
      Readonly,
      Enabled
    };

    virtual ~Window ();

    static std::shared_ptr<Window> createSharedWindow (
      std::string const & name,
      int x,
      int y,
      int width,
      int height,
      Color const & clientForeColor,
      Color const & clientBackColor,
      Color const & borderForeColor,
      Color const & borderBackColor,
      Color const & focusForeColor,
      Color const & focusBackColor,
      bool border);

    std::shared_ptr<Window> getSharedWindow ();

    virtual void processInput (WindowSystem * ws);

    virtual void update (ECS::TimeResolution elapsedTime);

    void draw (WindowSystem * ws) const;

    virtual bool onKeyPress (WindowSystem * ws,
      Event const & event);

    virtual void onMouseEvent (WindowSystem * ws,
      Event const & event);

    virtual void onDrawClient (WindowSystem * ws) const;

    virtual void onDrawNonClient (WindowSystem * ws) const;

    virtual void onResize ();

    std::string const & name () const;

    virtual int x () const;

    virtual int clientX () const;

    virtual void setX (int x);

    virtual int y () const;

    virtual int clientY () const;

    virtual void setY (int y);

    virtual void move (int x, int y);

    virtual int width () const;

    virtual int minWidth () const;

    virtual int clientWidth () const;

    virtual void setWidth (int width);

    virtual void setMinWidth (int width);

    virtual int height () const;

    virtual int minHeight () const;

    virtual int clientHeight () const;

    virtual void setHeight (int height);

    virtual void setMinHeight (int height);

    virtual void resize (int width, int height);

    virtual void moveAndResize (int x, int y, int width, int height);

    int anchorTop () const;

    void setAnchorTop (int anchor);

    int anchorRight () const;

    void setAnchorRight (int anchor);

    int anchorBottom () const;

    void setAnchorBottom (int anchor);

    int anchorLeft () const;

    void setAnchorLeft (int anchor);

    void setAnchorsAll (int anchor);

    void setAnchorsAll (int top, int right, int bottom, int left);

    void setAnchorsTopBottom (int top, int bottom);

    void setAnchorsLeftRight (int left, int right);

    virtual bool hasBorder () const;

    virtual void setBorder (bool border);

    Color clientForeColor () const;

    void setClientForeColor (Color const & color);

    Color clientBackColor () const;

    void setClientBackColor (Color const & color);

    Color borderForeColor () const;

    void setBorderForeColor (Color const & color);

    Color borderBackColor () const;

    void setBorderBackColor (Color const & color);

    Color focusForeColor () const;

    void setFocusForeColor (Color const & color);

    Color focusBackColor () const;

    void setFocusBackColor (Color const & color);

    void addControl(std::shared_ptr<Window> const & control);

    void addControl(std::shared_ptr<Window> && control);

    Window * findWindow (int x, int y);

    Window * findFocus ();

    virtual bool canHaveDirectFocus () const;

    virtual bool hasDirectFocus () const;

    virtual void setIsDirectFocusPossible (bool value);

    virtual bool setFocus (bool focus);

    virtual bool setFocus (int x, int y);

    virtual bool advanceFocus ();

    Window * parent () const;

    void setParent (Window * parent);

    virtual bool wantEnter () const;

    virtual void setWantEnter (bool value);

    virtual VisibleState visibleState () const;

    virtual void setVisibleState (VisibleState value);

    virtual EnableState enableState () const;

    virtual void setEnableState (EnableState value);

protected:
    Window (
      std::string const & name,
      int x,
      int y,
      int width,
      int height,
      Color const & clientForeColor,
      Color const & clientBackColor,
      Color const & borderForeColor,
      Color const & borderBackColor,
      Color const & focusForeColor,
      Color const & focusBackColor,
      bool border);

    virtual void initialize ();

    void setFillClientArea (bool value);

    void createWindows ();

    void destroyWindows ();

    void anchorWindow (Window * win);

    std::string mName;
    int mX;
    int mY;
    int mWidth;
    int mHeight;
    int mMinWidth;
    int mMinHeight;
    int mAnchorTop;
    int mAnchorRight;
    int mAnchorBottom;
    int mAnchorLeft;
    Color mClientForeColor;
    Color mClientBackColor;
    Color mBorderForeColor;
    Color mBorderBackColor;
    Color mFocusForeColor;
    Color mFocusBackColor;
    std::vector<std::shared_ptr<Window>> mControls;
    Window * mParent;
    bool mBorder;
    bool mHasFocus;
    bool mIsDirectFocusPossible;
    bool mHasDirectFocus;
    bool mFillClientArea;
    bool mWantEnter;
    VisibleState mVisibleState;
    EnableState mEnableState;
  };
} // namespace TUCUT::TUI

#endif // TUCUT_TUI_Window_h
