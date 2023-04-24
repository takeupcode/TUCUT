//  Window.cpp
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-01.
//  Copyright © Take Up Code, Inc.
//
#include "Window.h"

#include "../TUI/Application.h"
#include "Control.h"

#include <stdexcept>

using namespace TUCUT;

TUI::Window::Window (
  std::string const & name,
  int x,
  int y,
  int width,
  int height,
  int clientForeColor,
  int clientBackColor,
  int borderForeColor,
  int borderBackColor,
  int focusForeColor,
  int focusBackColor,
  bool border)
: mName(name),
  mX(x),
  mY(y),
  mWidth(width),
  mHeight(height),
  mMinWidth(border ? 3 : 1),
  mMinHeight(border ? 3 : 1),
  mAnchorTop(-1),
  mAnchorRight(-1),
  mAnchorBottom(-1),
  mAnchorLeft(-1),
  mClientForeColor(clientForeColor),
  mClientBackColor(clientBackColor),
  mBorderForeColor(borderForeColor),
  mBorderBackColor(borderBackColor),
  mFocusForeColor(focusForeColor),
  mFocusBackColor(focusBackColor),
  mParent(nullptr),
  mBorder(border),
  mHasFocus(false),
  mIsDirectFocusPossible(true),
  mHasDirectFocus(false),
  mFillClientArea(true),
  mWantTab(false),
  mWantEnter(false),
  mDefaultEnter(false),
  mDefaultEscape(false),
  mVisibleState(VisibleState::shown),
  mEnableState(EnableState::enabled)
{ }

void TUI::Window::initialize ()
{ }

std::shared_ptr<TUI::Window>
TUI::Window::createSharedWindow (
  std::string const & name,
  int x,
  int y,
  int width,
  int height,
  int clientForeColor,
  int clientBackColor,
  int borderForeColor,
  int borderBackColor,
  int focusForeColor,
  int focusBackColor,
  bool border)
{
  auto result = std::shared_ptr<Window>(new Window(
    name, x, y, width, height,
    clientForeColor, clientBackColor,
    borderForeColor, borderBackColor,
    focusForeColor, focusBackColor,
    border));

  result->initialize();

  return result;
}

std::shared_ptr<TUI::Window> TUI::Window::getSharedWindow ()
{
  return shared_from_this();
}

void TUI::Window::processInput (WindowSystem * ws)
{
  Event event;
  if (not getEvent(event))
  {
    return;
  }
  std::visit(overloaded
    {
      [this] (NonPrintingCharacterEvent & arg)
      {
        if (arg.mKey == KeyCodes::TabChar)
        {
          Window * control = findFocus();
          if (control && control->wantTab())
          {
            control->onNonPrintingKeyPress(ws, arg);
          }
          else if (not advanceFocus())
          {
            // If we couldn't advance the focus,
            // start the cycle over again.
            if (not setFocus(true))
            {
              // If no window can accept direct focus,
              // set regular focus to this window.
              mHasFocus = true;
            }
          }
        }
        else if (arg.mKey == KeyCodes::NewlineChar)
        {
          Window * control = findFocus();
          if (control && control->wantEnter())
          {
            control->onNonPrintingKeyPress(ws, arg);
            return;
          }

          control = findDefaultEnter();
          if (control)
          {
            control->onNonPrintingKeyPress(ws, arg);
            return;
          }
        }
        else if (arg.mKey == KeyCodes::EscapeChar)
        {
          Window * control = findDefaultEscape();
          if (control)
          {
            control->onNonPrintingKeyPress(ws, arg);
            return;
          }
        }
      },

      [this] (CharacterEvent & arg)
      {
        Window * control = findFocus();
        if (control)
        {
          control->onKeyPress(ws, arg);
        }
      },

      [this] (ExtendedCharacterEvent & arg)
      {
        Window * control = findFocus();
        if (control)
        {
          control->onExtendedKeyPress(ws, arg);
        }
      },

      [this] (MouseEvent & arg)
      {
        Window * control = findWindow(arg.mX, arg.mY);
        if (control)
        {
          setFocus(control);
          control->onMouseEvent(ws, arg);
        }
      },

      [this] (auto &)
      { } // Ignore everything else.
    },
    event);
}

void TUI::Window::update (ECS::TimeResolution)
{ }

void TUI::Window::draw (WindowSystem * ws) const
{
  if (mBorder)
  {
    drawBorder(ws,
      0, 0, mWidth, mHeight,
      mBorderForeColor, mBorderBackColor);
  }

  if (mFillClientArea)
  {
    fillRect(ws,
      clientX(), clientY(), clientHeight(), clientWidth(),
      " ",
      mClientForeColor, mClientBackColor);
  }

  drawClient();
  drawNonClient();

  for (auto const & control: mControls)
  {
    control->draw();
  }
}

void TUI::Window::drawText (WindowSystem * ws,
  int x,
  int y,
  std::string const & utf8) const
{
  drawText(ws, x, y, 1, 1, utf8);
}

void TUI::Window::drawText (WindowSystem * ws,
  int x,
  int y,
  int width,
  int height,
  std::string const & utf8) const
{
  int maxX;
  int maxY;
  if (not ws->getMaxWindowCoordinates(this, maxX, maxY))
  {
    return;
  }

  auto & terminal = ws->terminal();
  auto & output = terminal.output();
  for (int currentY = y;
    currentY <= maxY && currentY - y < height;
    ++currentY)
  {
    for (int currentX = x;
      currentX <= maxX && currentX - x < width;
      ++currentX)
    {
      terminal.moveCursor(
        currentX + worldX(), currentY + worldY());
      output << utf8;
    }
  }
}

void TUI::Window::drawBorder (WindowSystem * ws,
  int x,
  int y,
  int width,
  int height,
  Color const & foreColor,
  Color const & backColor) const
{
  int maxX;
  int maxY;
  if (not ws->getMaxWindowCoordinates(this, maxX, maxY))
  {
    return;
  }
  if (x > maxX || y > maxY ||
    width < 2 || height < 2)
  {
    return;
  }

  std::string hLine;
  for (int i = 0;
    i < width - 2 && x + i + 1 <= maxX;
    ++i)
  {
    hLine += "─";
  }
  if (not hLine.empty())
  {
    hLine = foreColor(backColor(hLine));
  }

  std::string vLine = foreColor(backColor("│"));

  std::string ulCorner = foreColor(backColor("┌"));
  std::string urCorner = foreColor(backColor("┐"));
  std::string llCorner = foreColor(backColor("└"));
  std::string lrCorner = foreColor(backColor("┘"));

  drawText(x, y, ulCorner);
  if (not hLine.empty())
  {
    drawText(x + 1, y, hLine);
  }
  drawText(x + width - 1, y, urCorner);

  for (int currentY = y + 1;
    currentY < y + height && currentY <= maxY;
    ++currentY)
  {
    drawText(x, currentY, vLine);
    drawText(x + width - 1, currentY, vLine);
  }

  drawText(x, y + height - 1, llCorner);
  if (not hLine.empty())
  {
    drawText(x + 1, y + height - 1, hLine);
  }
  drawText(x + width - 1, y + height - 1, lrCorner);
}

void TUI::Window::fillRect (WindowSystem * ws,
  int x,
  int y,
  int width,
  int height,
  std::string const & utf8,
  Color const & foreColor,
  Color const & backColor) const
{
  int maxX;
  int maxY;
  if (not ws->getMaxWindowCoordinates(this, maxX, maxY))
  {
    return;
  }
  if (x > maxX || y > maxY ||
    width == 0 || height == 0)
  {
    return;
  }

  std::string row;
  for (int i = 0;
    i < width && x + i <= maxX;
    ++i)
  {
    row += utf8;
  }
  if (not row.empty())
  {
    row = foreColor(backColor(row));
  }

  drawText(x, y, 1, height, row);
}

bool TUI::Window::onKeyPress (WindowSystem *, Event const &)
{
  return false;
}

void TUI::Window::onMouseEvent (WindowSystem *, Event const &)
{ }

void TUI::Window::onDrawClient (WindowSystem *) const
{ }

void TUI::Window::onDrawNonClient (WindowSystem *) const
{ }

void TUI::Window::onResize ()
{ }

std::string const & TUI::Window::name () const
{
  return mName;
}

int TUI::Window::x () const
{
  return mX;
}

int TUI::Window::worldX () const
{
  if (mParent == nullptr)
  {
    return mX;
  }

  return mX + mParent->worldX();
}

int TUI::Window::clientX () const
{
  return mBorder ? 1 : 0;
}

void TUI::Window::setX (int x)
{
  if (x < 0)
  {
    throw std::out_of_range("x cannot be less than 0.");
  }

  if (mX != x)
  {
    mX = x;
    onResize();
  }
}

int TUI::Window::y () const
{
  return mY;
}

int TUI::Window::worldY () const
{
  if (mParent == nullptr)
  {
    return mY;
  }

  return mY + mParent->worldY();
}

int TUI::Window::clientY () const
{
  return mBorder ? 1 : 0;
}

void TUI::Window::setY (int y)
{
  if (y < 0)
  {
    throw std::out_of_range("y cannot be less than 0.");
  }

  if (mY != y)
  {
    mY = y;
    onResize();
  }
}

void TUI::Window::move (int x, int y)
{
  if (x < 0 || y < 0)
  {
    throw std::out_of_range("x and y cannot be less than 0.");
  }

  if (mX != x || mY != y)
  {
    mX = x;
    mY = y;
    onResize();
  }
}

int TUI::Window::width () const
{
  return mWidth;
}

int TUI::Window::clientWidth () const
{
  return mBorder ? mWidth - 2 : mWidth;
}

int TUI::Window::minWidth () const
{
  return mMinWidth;
}

void TUI::Window::setWidth (int width)
{
  if (mWidth != width)
  {
    mWidth = width;
    if (mWidth < mMinWidth)
    {
      mWidth = mMinWidth;
    }
    onResize();
  }
}

void TUI::Window::setMinWidth (int width)
{
  if (mBorder)
  {
    if (width < 3)
    {
      throw std::out_of_range(
        "width cannot be less than 3 when using a border.");
    }
  }
  else
  {
    if (width < 1)
    {
      throw std::out_of_range("width cannot be less than 1.");
    }
  }

  mMinWidth = width;
}

int TUI::Window::height () const
{
  return mHeight;
}

int TUI::Window::clientHeight () const
{
  return mBorder ? mHeight - 2 : mHeight;
}

int TUI::Window::minHeight () const
{
  return mMinHeight;
}

void TUI::Window::setHeight (int height)
{
  if (mHeight != height)
  {
    mHeight = height;
    if (mHeight < mMinHeight)
    {
      mHeight = mMinHeight;
    }
    onResize();
  }
}

void TUI::Window::setMinHeight (int height)
{
  if (mBorder)
  {
    if (height < 3)
    {
      throw std::out_of_range(
        "height cannot be less than 3 when using a border.");
    }
  }
  else
  {
    if (height < 1)
    {
      throw std::out_of_range("height cannot be less than 1.");
    }
  }

  mMinHeight = height;
}

void TUI::Window::resize (int width, int height)
{
  if (mWidth != width || mHeight != height)
  {
    setWidth(width);
    setHeight(height);
    onResize();
  }
}

void TUI::Window::moveAndResize (int x, int y,
  int width, int height)
{
  if (x < 0 || y < 0)
  {
    throw std::out_of_range("x and y cannot be less than 0.");
  }

  if (mBorder)
  {
    if (mHeight < 3 || mWidth < 3)
    {
      throw std::out_of_range(
        "height or width cannot be less than 3"
        " when using a border.");
    }
  }
  else
  {
    if (mHeight < 1 || mWidth < 1)
    {
      throw std::out_of_range(
        "height or width cannot be less than 1.");
    }
  }

  if (mX != x || mY != y ||
    mWidth != width || mHeight != height)
  {
    mX = x;
    mY = y;
    setWidth(width);
    setHeight(height);
    onResize();
  }
}

int TUI::Window::anchorTop () const
{
  return mAnchorTop;
}

void TUI::Window::setAnchorTop (int anchor)
{
  mAnchorTop = anchor;
}

int TUI::Window::anchorRight () const
{
  return mAnchorRight;
}

void TUI::Window::setAnchorRight (int anchor)
{
  mAnchorRight = anchor;
}

int TUI::Window::anchorBottom () const
{
  return mAnchorBottom;
}

void TUI::Window::setAnchorBottom (int anchor)
{
  mAnchorBottom = anchor;
}

int TUI::Window::anchorLeft () const
{
  return mAnchorLeft;
}

void TUI::Window::setAnchorLeft (int anchor)
{
  mAnchorLeft = anchor;
}

void TUI::Window::setAnchorsAll (int anchor)
{
  mAnchorTop = anchor;
  mAnchorRight = anchor;
  mAnchorBottom = anchor;
  mAnchorLeft = anchor;
}

void TUI::Window::setAnchorsAll (int top, int right, int bottom, int left)
{
  mAnchorTop = top;
  mAnchorRight = right;
  mAnchorBottom = bottom;
  mAnchorLeft = left;
}

void TUI::Window::setAnchorsTopBottom (int top, int bottom)
{
  mAnchorTop = top;
  mAnchorBottom = bottom;
}

void TUI::Window::setAnchorsLeftRight (int left, int right)
{
  mAnchorLeft = left;
  mAnchorRight = right;
}

bool TUI::Window::hasBorder () const
{
  return mBorder;
}

void TUI::Window::setBorder (bool border)
{
  if (mBorder != border)
  {
    mBorder = border;
    onResize();
  }
}

TUI::Color TUI::Window::clientForeColor () const
{
  return mClientForeColor;
}

void TUI::Window::setClientForeColor (TUI::Color const & color)
{
  mClientForeColor = color;
}

TUI::Color TUI::Window::clientBackColor () const
{
  return mClientBackColor;
}

void TUI::Window::setClientBackColor (TUI::Color const & color)
{
  mClientBackColor = color;
}

TUI::Color TUI::Window::borderForeColor () const
{
  return mBorderForeColor;
}

void TUI::Window::setBorderForeColor (TUI::Color const & color)
{
  mBorderForeColor = color;
}

TUI::Color TUI::Window::borderBackColor () const
{
  return mBorderBackColor;
}

void TUI::Window::setBorderBackColor (TUI::Color const & color)
{
  mBorderBackColor = color;
}

TUI::Color TUI::Window::focusForeColor () const
{
  return mFocusForeColor;
}

void TUI::Window::setFocusForeColor (TUI::Color const & color)
{
  mFocusForeColor = color;
}

TUI::Color TUI::Window::focusBackColor () const
{
  return mFocusBackColor;
}

void TUI::Window::setFocusBackColor (TUI::Color const & color)
{
  mFocusBackColor = color;
}

void TUI::Window::addControl (
  std::shared_ptr<Window> const & control)
{
  control->setParent(this);

  anchorWindow(control.get());

  mControls.push_back(control);
}

void TUI::Window::addControl (
  std::shared_ptr<Window> && control)
{
  control->setParent(this);

  anchorWindow(control.get());

  mControls.push_back(std::move(control));
}

TUI::Window * TUI::Window::findWindow (int worldX, int worldY)
{
  if (worldX >= worldX() && worldX < (worldX() + mWidth)) &&
      worldY >= worldY() && worldY < (worldY() + mHeight)
  {
    for (auto & control: mControls)
    {
      Window * result = control->findWindow(worldX, worldY);
      if (result)
      {
        return result;
      }
    }

    return this;
  }

  return nullptr;
}

TUI::Window * TUI::Window::findFocus ()
{
  if (not mHasFocus)
  {
    // This window and none of its control windows have
    // the focus.
    return nullptr;
  }

  if (mHasDirectFocus)
  {
    return this;
  }

  for (auto & control: mControls)
  {
    Window * result = control->findFocus();
    if (result)
    {
      return result;
    }
  }

  return nullptr;
}

TUI::Window * TUI::Window::findDefaultEnter ()
{
  for (auto & control: mControls)
  {
    if (control->defaultEnter())
    {
      return control.get();
    }
  }

  return nullptr;
}

TUI::Window * TUI::Window::findDefaultEscape ()
{
  for (auto & control: mControls)
  {
    if (control->defaultEscape())
    {
      return control.get();
    }
  }

  return nullptr;
}

bool TUI::Window::canHaveDirectFocus () const
{
  return mIsDirectFocusPossible &&
    mVisibleState == VisibleState::Shown &&
    mEnableState != EnableState::Disabled;
}

bool TUI::Window::hasDirectFocus () const
{
  return mHasDirectFocus;
}

void TUI::Window::setIsDirectFocusPossible (bool value)
{
  mIsDirectFocusPossible = value;
}

bool TUI::Window::setFocus (bool focus)
{
  // If focus is false, then this method will clear the focus
  // from this window and all control windows.
  // If focus is true, then this method will try to set the
  // focus to the first control window descendent. And if
  // there are no control windows that can accept the focus,
  // then this window will try to accept direct focus.
  if (mVisibleState != VisibleState::Shown ||
    mEnableState == EnableState::Disabled)
  {
    focus = false;
  }

  bool foundDirectFocus = false;
  for (auto & control: mControls)
  {
    if (not foundDirectFocus)
    {
      // This works for both clearing as well as setting focus.
      foundDirectFocus = control->setFocus(focus);
    }
    else
    {
      // We can't exit the loop early. Once we set the first
      // focus, we clear any other focus that might exist.
      control->setFocus(false);
    }
  }

  if (foundDirectFocus)
  {
    mHasFocus = true;
    mHasDirectFocus = false;
  }
  else if (canHaveDirectFocus())
  {
    mHasFocus = focus;
    mHasDirectFocus = focus;
  }
  else
  {
    mHasFocus = false;
    mHasDirectFocus = false;
  }

  return mHasFocus;
}

bool TUI::Window::setFocus (int worldX, int worldY)
{
  if (mVisibleState != VisibleState::Shown ||
    mEnableState == EnableState::Disabled)
  {
    setFocus(false);
    return false;
  }

  bool foundDirectFocus = false;

  if (worldX >= worldX() && worldX < (worldX() + mWidth)) &&
      worldY >= worldY() && worldY < (worldY() + mHeight)
  {
    for (auto & control: mControls)
    {
      if (not foundDirectFocus)
      {
        foundDirectFocus = control->setFocus(worldX, worldY);
      }
      else
      {
        // We can't exit the loop early. Once we set the first
        // focus, we clear any other focus that might exist.
        // We don't handle overlapping windows.
        control->setFocus(false);
      }
    }

    if (foundDirectFocus)
    {
      mHasFocus = true;
      mHasDirectFocus = false;
    }
    else
    {
      if (canHaveDirectFocus())
      {
        // No child can have direct focus but this window can.
        mHasFocus = true;
        mHasDirectFocus = true;
        foundDirectFocus = true;
      }
      else
      {
        // No child could be found to take direct focus and
        // this window also cannot take direct focus.
        mHasFocus = false;
        mHasDirectFocus = false;
      }
    }
  }
  else
  {
    // The coordinates are outside this window so it and
    // its children cannot have focus.
    if (mHasFocus)
    {
      setFocus(false);
    }
  }

  return foundDirectFocus;
}

bool TUI::Window::advanceFocus ()
{
  if (mVisibleState != VisibleState::Shown ||
    mEnableState == EnableState::Disabled)
  {
    return false;
  }

  if (mHasDirectFocus)
  {
    // The parent window gets focus last. So if we have
    // the focus, then we can't advance any more.
    mHasFocus = false;
    mHasDirectFocus = false;
    return false;
  }
  else if (mHasFocus)
  {
    // One of the child windows has focus. Find it and
    // then advance.
    bool foundFirstFocusControl = false;
    for (auto & control: mControls)
    {
      if (not foundFirstFocusControl)
      {
        if (control->mHasFocus)
        {
          // We found the first control with focus. Give
          // it the first chance to advance.
          foundFirstFocusControl = true;
          if (control->advanceFocus())
          {
            return true;
          }
        }
      }
      else
      {
        // Now we try each control until one can accept
        // the focus.
        if (control->advanceFocus())
        {
          return true;
        }
      }
    }

    // We went through all the child controls with no
    // further advancement.
    if (canHaveDirectFocus())
    {
      mHasDirectFocus = true;
      return true;
    }
    else
    {
      mHasFocus = false;
      return false;
    }
  }
  else
  {
    // Since we did not yet have focus, set the focus to
    // the first available window or to this window if
    // necessary and allowed.
    return setFocus(true);
  }
}

Window * TUI::Window::parent () const
{
  return mParent;
}

void TUI::Window::setParent (Window * parent)
{
  mParent = parent;
}

bool TUI::Window::wantTab () const
{
  return mWantTab;
}

void TUI::Window::setWantTab (bool value)
{
  mWantTab = value;
}

bool TUI::Window::wantEnter () const
{
  return mWantEnter;
}

void TUI::Window::setWantEnter (bool value)
{
  mWantEnter = value;
}

bool TUI::Window::defaultEnter () const
{
  return mDefaultEnter;
}

void TUI::Window::setDefaultEnter (bool value)
{
  mDefaultEnter = value;
}

bool TUI::Window::defaultEscape () const
{
  return mDefaultEscape;
}

void TUI::Window::setDefaultEscape (bool value)
{
  mDefaultEscape = value;
}

TUI::Window::VisibleState TUI::Window::visibleState () const
{
  return mVisibleState;
}

void TUI::Window::setVisibleState (VisibleState value)
{
  mVisibleState = value;
  if (mParent)
  {
    mParent->onResize();
  }
}

TUI::Window::EnableState TUI::Window::enableState () const
{
  return mEnableState;
}

void TUI::Window::setEnableState (EnableState value)
{
  mEnableState = value;
}

void TUI::Window::setFillClientArea (bool value)
{
  mFillClientArea = value;
}

void TUI::Window::createWindows ()
{
  if (mY < 0 || mX < 0)
  {
    throw std::out_of_range("y or x cannot be less than 0.");
  }

  if (mBorder)
  {
    if (mHeight < 3 || mWidth < 3)
    {
      throw std::out_of_range(
        "height or width cannot be less than 3"
        " when using a border.");
    }
  }
  else
  {
    if (mHeight < 1 || mWidth < 1)
    {
      throw std::out_of_range(
        "height or width cannot be less than 1.");
    }
  }

  for (auto const & control: mControls)
  {
    anchorWindow(control.get());

    control->createWindows();
  }
}

void TUI::Window::anchorWindow (Window * win)
{
  int newLeft = win->x();
  int newRight = win->x() + win->width();
  int newTop = win->y();
  int newBottom = win->y() + win->height();

  if (win->anchorLeft() != -1 && win->anchorRight() != -1)
  {
    newLeft = clientX() + win->anchorLeft();
    newRight = clientX() + clientWidth() -
      win->anchorRight(); // This is one past the right column.
    if (newRight <= newLeft + win->minWidth())
    {
      newRight = newLeft + win->minWidth();
    }
  }
  else if (win->anchorLeft() != -1)
  {
    newLeft = clientX() + win->anchorLeft();
    newRight = newLeft + win->width();
  }
  else if (win->anchorRight() != -1)
  {
    newRight = clientX() + clientWidth() -
      win->anchorRight(); // This is one past the right column.
    newLeft = newRight - win->width();
    if (newLeft < 0)
    {
      newLeft = 0;
      newRight = win->width();
    }
  }

  if (win->anchorTop() != -1 && win->anchorBottom() != -1)
  {
    newTop = clientY() + win->anchorTop();
    newBottom = clientY() + clientHeight() -
      win->anchorBottom(); // This is one past the bottom row.
    if (newBottom <= newTop + win->minHeight())
    {
      newBottom = newTop+ win->minHeight();
    }
  }
  else if (win->anchorTop() != -1)
  {
    newTop = clientY() + win->anchorTop();
    newBottom = newTop + win->height();
  }
  else if (win->anchorBottom() != -1)
  {
    newBottom = clientY() + clientHeight() -
      win->anchorBottom(); // This is one past the bottom row.
    newTop = newBottom - win->height();
    if (newTop < 0)
    {
      newTop = 0;
      newBottom = win->height();
    }
  }

  win->moveAndResize(newLeft, newTop,
    newRight - newLeft, newBottom - newTop);
}
