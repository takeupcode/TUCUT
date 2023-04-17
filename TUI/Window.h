//  Window.h
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-01.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_TUI_Window_h
#define TUCUT_TUI_Window_h

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
      int y,
      int x,
      int height,
      int width,
      int clientForeColor,
      int clientBackColor,
      int borderForeColor,
      int borderBackColor,
      int focusForeColor,
      int focusBackColor,
      bool border);

    std::shared_ptr<Window> getSharedWindow ();

    virtual void processInput (WindowSystem * ws,
      Event const & event);

    virtual void update ();

    void draw () const;

    virtual bool onKeyPress (WindowSystem * ws, int key);

    virtual void onMouseEvent (WindowSystem * ws, short id, int y, int x, mmask_t buttonState);

    virtual void onDrawClient () const;

    virtual void onDrawNonClient () const;

    virtual void onResize ();

    const std::string & name () const;

    virtual int y () const;

    virtual int clientY () const;

    virtual void setY (int y);

    virtual int x () const;

    virtual int clientX () const;

    virtual void setX (int x);

    virtual void move (int y, int x);

    virtual int height () const;

    virtual int minHeight () const;

    virtual int clientHeight () const;

    virtual void setHeight (int height);

    virtual void setMinHeight (int height);

    virtual int width () const;

    virtual int minWidth () const;

    virtual int clientWidth () const;

    virtual void setWidth (int width);

    virtual void setMinWidth (int width);

    virtual void resize (int height, int width);

    virtual void moveAndResize (int y, int x, int height, int width);

    int anchorTop () const;

    void setAnchorTop (int anchor);

    int anchorBottom () const;

    void setAnchorBottom (int anchor);

    int anchorLeft () const;

    void setAnchorLeft (int anchor);

    int anchorRight () const;

    void setAnchorRight (int anchor);

    void setAnchorsAll (int anchor);

    void setAnchorsAll (int top, int bottom, int left, int right);

    void setAnchorsTopBottom (int top, int bottom);

    void setAnchorsLeftRight (int left, int right);

    virtual bool hasBorder () const;

    virtual void setBorder (bool border);

    int clientForeColor () const;

    void setClientForeColor (int color);

    int clientBackColor () const;

    void setClientBackColor (int color);

    int borderForeColor () const;

    void setBorderForeColor (int color);

    int borderBackColor () const;

    void setBorderBackColor (int color);

    int focusForeColor () const;

    void setFocusForeColor (int color);

    int focusBackColor () const;

    void setFocusBackColor (int color);

    void addControl(const std::shared_ptr<Window> & control);

    void addControl(std::shared_ptr<Window> && control);

    Window * findWindow (int y, int x);

    Window * findFocus ();

    virtual bool canHaveDirectFocus () const;

    virtual bool hasDirectFocus () const;

    virtual void setIsDirectFocusPossible (bool value);

    virtual bool setFocus (bool focus);

    virtual bool setFocus (int y, int x);

    virtual bool advanceFocus ();

    Window * parent () const;

    void setParent (Window * parent);

    virtual bool wantEnter () const;

    virtual void setWantEnter (bool value);

    virtual VisibleState visibleState () const;

    virtual void setVisibleState (VisibleState value);

    virtual EnableState enableState () const;

    virtual void setEnableState (EnableState value);

    virtual void drawInsideBorder () const;

protected:
    Window (const std::string & name, int y, int x, int height, int width, int clientForeColor, int clientBackColor, int borderForeColor, int borderBackColor, int focusForeColor, int focusBackColor, bool border);

    virtual void initialize ();

    void setFillClientArea (bool value);

    void createWindows ();

    void destroyWindows ();

    void anchorWindow (Window * win);

    void setNonClientColor () const;

    WINDOW * mClientCursesWindow;
    std::unique_ptr<Window> mBorderWindow;
    std::string mName;
    int mY;
    int mX;
    int mHeight;
    int mWidth;
    int mMinHeight;
    int mMinWidth;
    int mAnchorTop;
    int mAnchorBottom;
    int mAnchorLeft;
    int mAnchorRight;
    int mClientForeColor;
    int mClientBackColor;
    int mBorderForeColor;
    int mBorderBackColor;
    int mFocusForeColor;
    int mFocusBackColor;
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

  private:
    Window (Terminal & terminal);

    Terminal & mTerminal;
    std::ostream & mOutput;
  };
} // namespace TUCUT::TUI

#endif // TUCUT_TUI_Window_h
