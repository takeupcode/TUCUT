//  DisplayBox.cpp
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2018-08-02.
//  Copyright © Take Up Code, Inc.
//
#include "DisplayBox.h"

#include <sstream>
#include <stdexcept>

#include "Button.h"

using namespace TUCUT;

std::string const TUI::DisplayBox::moveCenterUpButtonName =
  "moveCenterUpButton";
std::string const TUI::DisplayBox::moveCenterDownButtonName =
  "moveCenterDownButton";
std::string const TUI::DisplayBox::moveCenterLeftButtonName =
  "moveCenterLeftButton";
std::string const TUI::DisplayBox::moveCenterRightButtonName =
  "moveCenterRightButton";

TUI::DisplayBox::DisplayBox (std::string const & name,
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
  int scrollMarginLeft)
: Control(name,
    x,
    y,
    width,
    height,
    foreColor,
    backColor,
    foreColor,
    backColor,
    foreColor,
    backColor,
    true), // The border must be enabled in case the
    // center controls are allowed.
  mClicked(new ClickedEvent(ClickedEventId)),
  mScrollChanged(new ScrollChangedEvent(ScrollChangedEventId)),
  mBeforeCenterChanged(new BeforeCenterChangedEvent(
    BeforeCenterChangedEventId)),
  mAfterCenterChanged(new AfterCenterChangedEvent(
    AfterCenterChangedEventId)),
  mClickedColumn(0),
  mClickedLine(0),
  mScrollColumn(0),
  mScrollLine(0),
  mCenterColumn(0),
  mCenterLine(0),
  mContentWidth(contentWidth),
  mContentHeight(contentHeight),
  mScrollMarginTop(scrollMarginTop),
  mScrollMarginRight(scrollMarginRight),
  mScrollMarginBottom(scrollMarginBottom),
  mScrollMarginLeft(scrollMarginLeft),
  mCenterSymbol(centerSymbol),
  mAutoScrolling(autoScrolling),
  mAllowCenterControls(allowCenterControls),
  mShowClickLocation(false)
{
  mMinWidth = MinWidth;
  if (width < mMinWidth)
  {
    mWidth = mMinWidth;
  }

  mMinHeight = MinHeight;
  if (height < mMinHeight)
  {
    mHeight = mMinHeight;
  }

  mMinContentWidth = MinContentWidth;
  if (contentWidth < mMinContentWidth)
  {
    mContentWidth = mMinContentWidth;
  }

  mMinContentHeight = MinContentHeight;
  if (contentHeight < mMinContentHeight)
  {
    mContentHeight = mMinContentHeight;
  }

  if (scrollMarginTop < 0 ||
    scrollMarginTop >= clientHeight() / 2)
  {
    throw std::out_of_range(
      "scrollMarginTop must be less than half"
      " the client height.");
  }

  if (scrollMarginRight < 0 ||
    scrollMarginRight >= textClientWidth() / 2)
  {
    throw std::out_of_range(
      "scrollMarginRight must be less than half"
      " the client width.");
  }

  if (scrollMarginBottom < 0 ||
    scrollMarginBottom >= clientHeight() / 2)
  {
    throw std::out_of_range(
      "scrollMarginBottom must be less than half"
      " the client height.");
  }

  if (scrollMarginLeft < 0 ||
    scrollMarginLeft >= textClientWidth() / 2)
  {
    throw std::out_of_range(
      "scrollMarginLeft must be less than half"
      " the client width.");
  }

  setFillClientArea(false);

  for (int i = 0; i < mContentHeight; ++i)
  {
    mContent.push_back(std::string(mContentWidth, ' '));
  }
}

void TUI::DisplayBox::initialize ()
{
  Control::initialize();

  if (not mAllowCenterControls)
  {
    return;
  }

  Color foreDimBlack(
    TextLayer::Foreground,
    Palette::ColorsTrue,
    0, 0, 0);
  Color backDimWhite(
    TextLayer::Background,
    Palette::ColorsTrue,
    198, 198, 198);

  mMoveCenterLeftButton = Button::createSharedButton(
    moveCenterLeftButtonName,
    "<", 0, 0, 1, 1,
    foreDimBlack,
    backDimWhite,
    foreDimBlack,
    backDimWhite);
  mMoveCenterLeftButton->clicked()->connect(name(),
    getSharedDisplayBox());
  mMoveCenterLeftButton->setIsDirectFocusPossible(false);
  mMoveCenterLeftButton->setAnchorTop(2);
  mMoveCenterLeftButton->setAnchorRight(0);
  addControl(mMoveCenterLeftButton);

  mMoveCenterRightButton = Button::createSharedButton(
    moveCenterRightButtonName,
    ">", 0, 0, 1, 1,
    foreDimBlack,
    backDimWhite,
    foreDimBlack,
    backDimWhite);
  mMoveCenterRightButton->clicked()->connect(name(),
    getSharedDisplayBox());
  mMoveCenterRightButton->setIsDirectFocusPossible(false);
  mMoveCenterRightButton->setAnchorTop(3);
  mMoveCenterRightButton->setAnchorRight(0);
  addControl(mMoveCenterRightButton);

  mMoveCenterUpButton = Button::createSharedButton(
    moveCenterUpButtonName,
    "+", 0, 0, 1, 1,
    foreDimBlack,
    backDimWhite,
    foreDimBlack,
    backDimWhite);
  mMoveCenterUpButton->clicked()->connect(name(),
    getSharedDisplayBox());
  mMoveCenterUpButton->setIsDirectFocusPossible(false);
  mMoveCenterUpButton->setAnchorTop(0);
  mMoveCenterUpButton->setAnchorRight(0);
  addControl(mMoveCenterUpButton);

  mMoveCenterDownButton = Button::createSharedButton(
    moveCenterDownButtonName,
    "-", 0, 0, 1, 1,
    foreDimBlack,
    backDimWhite,
    foreDimBlack,
    backDimWhite);
  mMoveCenterDownButton->clicked()->connect(name(),
    getSharedDisplayBox());
  mMoveCenterDownButton->setIsDirectFocusPossible(false);
  mMoveCenterDownButton->setAnchorTop(1);
  mMoveCenterDownButton->setAnchorRight(0);
  addControl(mMoveCenterDownButton);
}

std::shared_ptr<DisplayBox>
TUI::DisplayBox::createSharedDisplayBox (
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
  bool autoScrolling,
  bool allowCenterControls,
  int scrollMarginTop,
  int scrollMarginRight,
  int scrollMarginBottom,
  int scrollMarginLeft)
{
  auto result = std::shared_ptr<DisplayBox>(new DisplayBox(
    name,
    centerSymbol,
    x,
    y,
    width,
    height,
    contentWidth,
    contentHeight,
    foreColor,
    backColor,
    autoScrolling,
    allowCenterControls,
    scrollMarginTop,
    scrollMarginRight,
    scrollMarginBottom,
    scrollMarginLeft));

  result->initialize();

  return result;
}

std::shared_ptr<DisplayBox>
TUI::DisplayBox::getSharedDisplayBox ()
{
  return std::static_pointer_cast<DisplayBox>(
    shared_from_this());
}

bool TUI::DisplayBox::onExtendedKeyPress (WindowSystem * ws,
  ExtendedCharacterEvent const & event)
{
  if (enableState() != Window::EnableState::Enabled)
  {
    return false;
  }

  if (not mAllowCenterControls)
  {
    if (parent())
    {
      return parent()->onExtendedKeyPress(ws, event);
    }
    return true;
  }

  if (event.mKey == ExtendedKeys::ArrowUp)
  {
    handleMoveCenterUp(ws);
  }
  else if (event.mKey == ExtendedKeys::ArrowDown)
  {
    handleMoveCenterDown(ws);
  }
  else if (event.mKey == ExtendedKeys::ArrowRight)
  {
    handleMoveCenterRight(ws);
  }
  else if (event.mKey == ExtendedKeys::ArrowLeft)
  {
    handleMoveCenterLeft(ws);
  }
  else if (parent())
  {
    return parent()->onExtendedKeyPress(ws, event);
  }

  return true;
}

void TUI::DisplayBox::onMouseEvent (WindowSystem * ws,
  MouseEvent const & event)
{
  if (enableState() != Window::EnableState::Enabled)
  {
    return;
  }

  if (event.mAction == MouseActions::ButtonPressed &&
    event.mButton == MouseButtons::Left)
  {
    int worldX = worldX();
    int worldY = worldY();

    // Don't move the cursor if the click is in the
    // non-client area.
    if (border() &&
      (event.mX == worldX ||
      event.mX == worldX + width() - 1 ||
      event.mY == worldY ||
      event.mY == worldY + height() - 1))
    {
      return;
    }

    int column = event.mX - worldX - clientX() + mScrollColumn;
    int line = event.mY - worldY - clientY() + mScrollLine;

    if (column >= mContentWidth)
    {
      column = mContentWidth - 1;
    }

    if (line >= mContentHeight)
    {
      line = mContentHeight - 1;
    }

    if (mClickedColumn != column || mClickedLine != line)
    {
      mClickedColumn = column;
      mClickedLine = line;
    }

    handleClicked(ws, mClickedColumn, mClickedLine);
  }
}

void TUI::DisplayBox::onDrawClient (WindowSystem * ws) const
{
  if (visibleState() != Window::VisibleState::Shown)
  {
    return;
  }

  int i = 0;
  for (; i < clientHeight(); ++i)
  {
    if (i + mScrollLine >= mContentHeight)
    {
      break;
    }

    std::string lineText = Text::substr(
      mContent[i + mScrollLine],
      mScrollColumn, clientWidth());
    if (not mCenterSymbol.empty() &&
      mCenterLine == (i + mScrollLine) &&
      mCenterColumn >= mScrollColumn)
    {
      Text::replace(lineText,
        mCenterSymbol,
        mCenterColumn - mScrollColumn,
        1);
    }

    if (mShowClickLocation &&
      mClickedLine >= mScrollLine &&
      mClickedColumn >= mScrollColumn)
    {
      drawText(ws,
        clientX(),
        clientY() + i,
        clientWidth(),
        lineText,
        clientForeColor(),
        clientBackColor(),
        "",
        Justification::Horizontal::Left,
        mClickedColumn - mScrollColumn + clientX(),
        mClickedLine - mScrollLine + clientY());
    }
    else
    {
      drawText(ws,
        clientX(),
        clientY() + i,
        clientWidth(),
        lineText,
        clientForeColor(),
        clientBackColor());
    }
  }
  for (; i < clientHeight(); ++i)
  {
    drawText(ws,
      clientX(),
      clientY() + i,
      clientWidth(),
      lineText,
      clientForeColor(),
      clientBackColor(),
      " ");
  }
}

void TUI::DisplayBox::setMinWidth (int width)
{
  if (width < MinWidth)
  {
    return;
  }

  Control::setMinWidth(width);
}

void TUI::DisplayBox::setMinHeight (int height)
{
  if (height < MinHeight)
  {
    return;
  }

  Control::setMinHeight(height);
}

void TUI::DisplayBox::setBorder (bool border)
{
  if (mAllowCenterControls)
  {
    // The border cannot be changed if the controls are
    // allowed.
    return;
  }

  Control::setBorder(border);
}

void TUI::DisplayBox::verifyX (int x) const
{
  if (x < 0 || x >= mContentWidth)
  {
    throw std::out_of_range(
      "x must be less than content width.");
  }
}

void TUI::DisplayBox::verifyY (int y) const
{
  if (y < 0 || y >= mContentHeight)
  {
    throw std::out_of_range(
      "y must be less than content height.");
  }
}

void TUI::DisplayBox::verifyXY (int x, int y) const
{
  verifyX(x);
  verifyY(y);
}

std::string TUI::DisplayBox::symbol (int x, int y) const
{
  verifyXY(x, y);

  return Text::substr(mContent[y], x, 1);
}

void TUI::DisplayBox::setSymbol (std::string const & symbol,
  int x, int y)
{
  verifyXY(x, y);

  mContent[y] = Text::replace(mContent[y], symbol, x, 1);
}

void TUI::DisplayBox::setSymbols (std::string const & symbols,
  int y)
{
  verifyY(y);

  if (mContentWidth != static_cast<int>(
    Text::countCodePoints(symbols)))
  {
    throw std::out_of_range(
      "symbols width must equal content width.");
  }

  mContent[y] = symbols;
}

TUI::DisplayBox::ClickedEvent * TUI::DisplayBox::clicked ()
{
  return mClicked.get();
}

TUI::DisplayBox::ScrollChangedEvent *
TUI::DisplayBox::scrollChanged ()
{
  return mScrollChanged.get();
}

TUI::DisplayBox::BeforeCenterChangedEvent *
TUI::DisplayBox::beforeCenterChanged ()
{
  return mBeforeCenterChanged.get();
}

TUI::DisplayBox::AfterCenterChangedEvent *
TUI::DisplayBox::afterCenterChanged ()
{
  return mAfterCenterChanged.get();
}

void TUI::DisplayBox::notify (int id, WindowSystem * ws, Button * button)
{
    if (id != Button::ClickedEventId)
    {
        return;
    }

    if (button->name() == moveCenterUpButtonName)
    {
        handleMoveCenterUp(ws);
    }
    else if (button->name() == moveCenterDownButtonName)
    {
        handleMoveCenterDown(ws);
    }
    else if (button->name() == moveCenterLeftButtonName)
    {
        handleMoveCenterLeft(ws);
    }
    else if (button->name() == moveCenterRightButtonName)
    {
        handleMoveCenterRight(ws);
    }
}

void TUI::DisplayBox::handleClicked (WindowSystem * ws, int x, int y)
{
    mClicked->signal(ws, this, x, y);
}

void TUI::DisplayBox::handleScrollChanged (WindowSystem * ws, int x, int y)
{
    mScrollChanged->signal(ws, this, x, y);
}

void TUI::DisplayBox::handleBeforeCenterChanged (WindowSystem * ws, int x, int y, bool & cancel)
{
    mBeforeCenterChanged->signal(ws, this, x, y, cancel);
}

void TUI::DisplayBox::handleAfterCenterChanged (WindowSystem * ws, int x, int y)
{
    mAfterCenterChanged->signal(ws, this, x, y);
}

void TUI::DisplayBox::handleMoveCenterUp (WindowSystem * ws)
{
    if (canMoveCenterUp())
    {
        bool cancel = false;

        handleBeforeCenterChanged(ws, getCenterY() - 1, getCenterX(), cancel);
        if (cancel)
        {
            return;
        }
    }
    else
    {
        return;
    }

    bool centerMoved = moveCenterUp();

    bool scrollMoved = false;
    if (centerMoved && mAutoScrolling)
    {
        int scrollPoint = mScrollMarginTop;
        if (mCenterLine < mScrollLine || (mCenterLine - mScrollLine) < scrollPoint)
        {
            scrollMoved = scrollDown();
        }
    }

    if (centerMoved)
    {
        handleAfterCenterChanged(ws, mCenterLine, mCenterColumn);
    }
    if (scrollMoved)
    {
        handleScrollChanged(ws, mScrollLine, mScrollColumn);
    }
}

void TUI::DisplayBox::handleMoveCenterDown (WindowSystem * ws)
{
    if (canMoveCenterDown())
    {
        bool cancel = false;

        handleBeforeCenterChanged(ws, getCenterY() + 1, getCenterX(), cancel);
        if (cancel)
        {
            return;
        }
    }
    else
    {
        return;
    }

    bool centerMoved = moveCenterDown();

    bool scrollMoved = false;
    if (centerMoved && mAutoScrolling)
    {
        int scrollPoint = clientHeight() - mScrollMarginBottom;
        if (mCenterLine > (mScrollLine + scrollPoint - 1))
        {
            scrollMoved = scrollUp();
        }
    }

    if (centerMoved)
    {
        handleAfterCenterChanged(ws, mCenterLine, mCenterColumn);
    }
    if (scrollMoved)
    {
        handleScrollChanged(ws, mScrollLine, mScrollColumn);
    }
}

void TUI::DisplayBox::handleMoveCenterLeft (WindowSystem * ws)
{
    if (canMoveCenterLeft())
    {
        bool cancel = false;

        handleBeforeCenterChanged(ws, getCenterY(), getCenterX() - 1, cancel);
        if (cancel)
        {
            return;
        }
    }
    else
    {
        return;
    }

    bool centerMoved = moveCenterLeft();

    bool scrollMoved = false;
    if (centerMoved && mAutoScrolling)
    {
        int scrollPoint = mScrollMarginLeft;
        if (mCenterColumn < mScrollColumn || (mCenterColumn - mScrollColumn) < scrollPoint)
        {
            scrollMoved = scrollRight();
        }
    }

    if (centerMoved)
    {
        handleAfterCenterChanged(ws, mCenterLine, mCenterColumn);
    }
    if (scrollMoved)
    {
        handleScrollChanged(ws, mScrollLine, mScrollColumn);
    }
}

void TUI::DisplayBox::handleMoveCenterRight (WindowSystem * ws)
{
    if (canMoveCenterRight())
    {
        bool cancel = false;

        handleBeforeCenterChanged(ws, getCenterY(), getCenterX() + 1, cancel);
        if (cancel)
        {
            return;
        }
    }
    else
    {
        return;
    }

    bool centerMoved = moveCenterRight();

    bool scrollMoved = false;
    if (centerMoved && mAutoScrolling)
    {
        int scrollPoint = textClientWidth() - mScrollMarginRight;
        if (mCenterColumn > (mScrollColumn + scrollPoint - 1))
        {
            scrollMoved = scrollLeft();
        }
    }

    if (centerMoved)
    {
        handleAfterCenterChanged(ws, mCenterLine, mCenterColumn);
    }
    if (scrollMoved)
    {
        handleScrollChanged(ws, mScrollLine, mScrollColumn);
    }
}

bool TUI::DisplayBox::isClickLocationShown () const
{
    return mShowClickLocation;
}

void TUI::DisplayBox::showClickLocation (bool show)
{
    mShowClickLocation = show;
}

int TUI::DisplayBox::getClickedY () const
{
    return mClickedLine;
}

int TUI::DisplayBox::getClickedX () const
{
    return mClickedColumn;
}

int TUI::DisplayBox::getScrollY () const
{
    return mScrollLine;
}

int TUI::DisplayBox::getScrollX () const
{
    return mScrollColumn;
}

bool TUI::DisplayBox::scrollUp ()
{
    if ((mContentHeight - mScrollLine) > clientHeight())
    {
        ++mScrollLine;

        return true;
    }

    return false;
}

bool TUI::DisplayBox::scrollDown ()
{
    if (mScrollLine > 0)
    {
        --mScrollLine;

        return true;
    }

    return false;
}

bool TUI::DisplayBox::scrollLeft ()
{
    if ((mContentWidth - mScrollColumn) > textClientWidth())
    {
        ++mScrollColumn;

        return true;
    }

    return false;
}

bool TUI::DisplayBox::scrollRight ()
{
    if (mScrollColumn > 0)
    {
        --mScrollColumn;

        return true;
    }

    return false;
}

void TUI::DisplayBox::ensurePointIsVisible (int x, int y)
{
    verifyXY(x, y);

    if (y < mScrollLine + mScrollMarginTop)
    {
        mScrollLine = y - mScrollMarginTop;
        if (mScrollLine < 0)
        {
            mScrollLine = 0;
        }
    }
    else if (y >= mScrollLine + clientHeight() - mScrollMarginBottom)
    {
        mScrollLine = y - clientHeight() + 1 + mScrollMarginBottom;
        if ((mScrollLine + clientHeight()) > mContentHeight)
        {
            mScrollLine = mContentHeight - clientHeight();
        }
    }

    if (x < mScrollColumn + mScrollMarginLeft)
    {
        mScrollColumn = x - mScrollMarginLeft;
        if (mScrollColumn < 0)
        {
            mScrollColumn = 0;
        }
    }
    else if (x >= mScrollColumn + textClientWidth() - mScrollMarginRight)
    {
        mScrollColumn = x - textClientWidth() + 1 + mScrollMarginRight;
        if ((mScrollColumn + textClientWidth()) > mContentWidth)
        {
            mScrollColumn = mContentWidth - textClientWidth();
        }
    }
}

void TUI::DisplayBox::ensureCenterIsVisible ()
{
    ensurePointIsVisible(mCenterLine, mCenterColumn);
}

int TUI::DisplayBox::getCenterY () const
{
    return mCenterLine;
}

int TUI::DisplayBox::getCenterX () const
{
    return mCenterColumn;
}

void TUI::DisplayBox::setCenter (int x, int y)
{
    verifyXY(x, y);

    mCenterLine = y;
    mCenterColumn = x;
}

bool TUI::DisplayBox::canMoveCenterUp ()
{
    return mCenterLine > 0;
}

bool TUI::DisplayBox::canMoveCenterDown ()
{
    return mCenterLine < (mContentHeight - 1);
}

bool TUI::DisplayBox::canMoveCenterLeft ()
{
    return mCenterColumn > 0;
}

bool TUI::DisplayBox::canMoveCenterRight ()
{
    return mCenterColumn < (mContentWidth - 1);
}

bool TUI::DisplayBox::moveCenterUp ()
{
    if (canMoveCenterUp())
    {
        --mCenterLine;

        return true;
    }

    return false;
}

bool TUI::DisplayBox::moveCenterDown ()
{
    if (canMoveCenterDown())
    {
        ++mCenterLine;

        return true;
    }

    return false;
}

bool TUI::DisplayBox::moveCenterLeft ()
{
    if (canMoveCenterLeft())
    {
        --mCenterColumn;

        return true;
    }

    return false;
}

bool TUI::DisplayBox::moveCenterRight ()
{
    if (canMoveCenterRight())
    {
        ++mCenterColumn;

        return true;
    }

    return false;
}
