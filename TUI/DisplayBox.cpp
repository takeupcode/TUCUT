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
#include "Colors.h"
#include "ConsoleManager.h"
#include "Justification.h"

namespace TUCUT {
namespace Curses {

std::string const DisplayBox::windowName = "parent";
std::string const DisplayBox::moveCenterUpButtonName = "moveCenterUpButton";
std::string const DisplayBox::moveCenterDownButtonName = "moveCenterDownButton";
std::string const DisplayBox::moveCenterLeftButtonName = "moveCenterLeftButton";
std::string const DisplayBox::moveCenterRightButtonName = "moveCenterRightButton";

DisplayBox::DisplayBox (std::string const & name,
  char centerChar,
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
    backColor),
  mClicked(new ClickedEvent(ClickedEventId)),
  mScrollChanged(new ScrollChangedEvent(ScrollChangedEventId)),
  mBeforeCenterChanged(new BeforeCenterChangedEvent(BeforeCenterChangedEventId)),
  mAfterCenterChanged(new AfterCenterChangedEvent(AfterCenterChangedEventId)),
  mClickedLine(0),
  mClickedColumn(0),
  mScrollLine(0),
  mScrollColumn(0),
  mCenterLine(0),
  mCenterColumn(0),
  mContentHeight(contentHeight),
  mContentWidth(contentWidth),
  mScrollMarginTop(scrollMarginTop),
  mScrollMarginRight(scrollMarginRight),
  mScrollMarginBottom(scrollMarginBottom),
  mScrollMarginLeft(scrollMarginLeft),
  mCenterChar(centerChar),
  mAutoScrolling(autoScrolling),
  mAllowCenterControls(allowCenterControls),
  mShowClickLocation(false)
{
    if (height < 4)
    {
        throw std::out_of_range("height cannot be less than 4.");
    }
    if (width < 4)
    {
        throw std::out_of_range("width cannot be less than 4.");
    }
    if (contentHeight < 1)
    {
        throw std::out_of_range("content height cannot be less than 1.");
    }
    if (contentWidth < 1)
    {
        throw std::out_of_range("content width cannot be less than 1.");
    }
    if (scrollMarginTop < 0 || scrollMarginTop >= clientHeight() / 2)
    {
        throw std::out_of_range("scrollMarginTop must be less than half the window height.");
    }
    if (scrollMarginRight < 0 || scrollMarginRight >= textClientWidth() / 2)
    {
        throw std::out_of_range("scrollMarginRight must be less than half the window width.");
    }
    if (scrollMarginBottom < 0 || scrollMarginBottom >= clientHeight() / 2)
    {
        throw std::out_of_range("scrollMarginBottom must be less than half the window height.");
    }
    if (scrollMarginLeft < 0 || scrollMarginLeft >= textClientWidth() / 2)
    {
        throw std::out_of_range("scrollMarginLeft must be less than half the window width.");
    }

    mMinHeight = 4;
    mMinWidth = 4;

    setFillClientArea(false);

    for (int i = 0; i < mContentHeight; i++)
    {
        mContent.push_back(std::string(mContentWidth, ' '));
    }
}

void DisplayBox::initialize ()
{
    Control::initialize();

    if (mAllowCenterControls)
    {
        mMoveCenterLeftButton = Button::createSharedButton(moveCenterLeftButtonName, "<", 0, 0, 1, 1, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE);
        mMoveCenterLeftButton->clicked()->connect(windowName, getSharedDisplayBox());
        mMoveCenterLeftButton->setIsDirectFocusPossible(false);
        addControl(mMoveCenterLeftButton);

        mMoveCenterRightButton = Button::createSharedButton(moveCenterRightButtonName, ">", 0, 0, 1, 1, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE);
        mMoveCenterRightButton->clicked()->connect(windowName, getSharedDisplayBox());
        mMoveCenterRightButton->setIsDirectFocusPossible(false);
        addControl(mMoveCenterRightButton);

        mMoveCenterUpButton = Button::createSharedButton(moveCenterUpButtonName, "+", 0, 0, 1, 1, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE);
        mMoveCenterUpButton->clicked()->connect(windowName, getSharedDisplayBox());
        mMoveCenterUpButton->setIsDirectFocusPossible(false);
        addControl(mMoveCenterUpButton);

        mMoveCenterDownButton = Button::createSharedButton(moveCenterDownButtonName, "-", 0, 0, 1, 1, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE);
        mMoveCenterDownButton->clicked()->connect(windowName, getSharedDisplayBox());
        mMoveCenterDownButton->setIsDirectFocusPossible(false);
        addControl(mMoveCenterDownButton);

        mMoveCenterUpButton->setAnchorTop(0);
        mMoveCenterUpButton->setAnchorRight(0);

        mMoveCenterDownButton->setAnchorTop(1);
        mMoveCenterDownButton->setAnchorRight(0);

        mMoveCenterLeftButton->setAnchorTop(2);
        mMoveCenterLeftButton->setAnchorRight(0);

        mMoveCenterRightButton->setAnchorTop(3);
        mMoveCenterRightButton->setAnchorRight(0);
    }
}

std::shared_ptr<DisplayBox>
DisplayBox::createSharedDisplayBox (
  std::string const & name,
  char centerChar,
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
    centerChar,
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

std::shared_ptr<DisplayBox> DisplayBox::getSharedDisplayBox ()
{
    return std::static_pointer_cast<DisplayBox>(shared_from_this());
}

bool DisplayBox::onKeyPress (WindowSystem * ws, int key)
{
    if (enableState() != Window::EnableState::enabled)
    {
        return false;
    }

    if (not mAllowCenterControls)
    {
        if (parent())
        {
            return parent()->onKeyPress(ws, key);
        }
    }
    else
    {
        switch (key)
        {
            case KEY_UP:
                handleMoveCenterUp(ws);
                break;

            case KEY_DOWN:
                handleMoveCenterDown(ws);
                break;

            case KEY_LEFT:
                handleMoveCenterLeft(ws);
                break;

            case KEY_RIGHT:
                handleMoveCenterRight(ws);
                break;

            default:
                if (parent())
                {
                    return parent()->onKeyPress(ws, key);
                }
                break;
        }
    }

    return true;
}

void DisplayBox::onMouseEvent (WindowSystem * ws, short id, int y, int x, mmask_t buttonState)
{
    if (enableState() != Window::EnableState::enabled)
    {
        return;
    }

    if (buttonState & BUTTON1_CLICKED)
    {
        int winY = y - clientY();
        int winX = x - clientX();

        // Don't move the cursor if the click is in the non-client area.
        if (winX == 0 ||
            winX > textClientWidth())
        {
            return;
        }
        int line = winY + mScrollLine;
        int column = winX + mScrollColumn - 1; // Subtract one for the focus marker.

        if (line >= mContentHeight)
        {
            line = mContentHeight - 1;
        }

        if (column >= mContentWidth)
        {
            column = mContentWidth - 1;
        }

        if (mClickedLine != line || mClickedColumn != column)
        {
            mClickedLine = line;
            mClickedColumn = column;
        }

        handleClicked(ws, mClickedLine, mClickedColumn);
    }
}

void DisplayBox::onDrawClient () const
{
    if (visibleState() != Window::VisibleState::shown)
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

        std::string lineText = mContent[i + mScrollLine].substr(mScrollColumn, textClientWidth());
        if (mCenterChar && mCenterLine == (i + mScrollLine) && mCenterColumn >= mScrollColumn)
        {
            lineText[mCenterColumn - mScrollColumn] = mCenterChar;
        }

        if (mShowClickLocation && (mClickedLine >= mScrollLine) && (mClickedColumn >= mScrollColumn))
        {
            ConsoleManager::printMessage(*this, i, 1, textClientWidth(), lineText, clientForeColor(), clientBackColor(), Justification::Horizontal::left, true, mClickedLine - mScrollLine, mClickedColumn - mScrollColumn + 1);
        }
        else
        {
            ConsoleManager::printMessage(*this, i, 1, textClientWidth(), lineText, clientForeColor(), clientBackColor(), Justification::Horizontal::left, true);
        }
    }
    for (; i < clientHeight(); ++i)
    {
        ConsoleManager::printMessage(*this, i, 1, textClientWidth(), " ", clientForeColor(), clientBackColor(), Justification::Horizontal::left, true);
    }
}

int DisplayBox::textClientWidth () const
{
    // This method accounts for the area used by the scrolling buttons and focus marker.
    return clientWidth() - 2;
}

void DisplayBox::setMinHeight (int height)
{
    if (height < 4)
    {
        throw std::out_of_range("height cannot be less than 4.");
    }

    mMinHeight = height;
}

void DisplayBox::setMinWidth (int width)
{
    if (width < 4)
    {
        throw std::out_of_range("width cannot be less than 4.");
    }

    mMinWidth = width;
}

void DisplayBox::verifyY (int y) const
{
    if (y < 0 || y >= mContentHeight)
    {
        throw std::out_of_range("y must be less than content height.");
    }
}

void DisplayBox::verifyX (int x) const
{
    if (x < 0 || x >= mContentWidth)
    {
        throw std::out_of_range("x must be less than content width.");
    }
}

void DisplayBox::verifyYX (int y, int x) const
{
    verifyY(y);
    verifyX(x);
}

char DisplayBox::symbol (int y, int x) const
{
    verifyYX(y, x);

    return mContent[y][x];
}

void DisplayBox::setSymbol (char symbol, int y, int x)
{
    verifyYX(y, x);

    mContent[y][x] = symbol;
}

void DisplayBox::setSymbols (std::string const & symbols, int y)
{
    verifyY(y);

    if (mContentWidth != static_cast<int>(symbols.size()))
    {
        throw std::out_of_range("symbols width must equal content width.");
    }

    mContent[y] = symbols;
}

DisplayBox::ClickedEvent * DisplayBox::clicked ()
{
    return mClicked.get();
}

DisplayBox::ScrollChangedEvent * DisplayBox::scrollChanged ()
{
    return mScrollChanged.get();
}

DisplayBox::BeforeCenterChangedEvent * DisplayBox::beforeCenterChanged ()
{
    return mBeforeCenterChanged.get();
}

DisplayBox::AfterCenterChangedEvent * DisplayBox::afterCenterChanged ()
{
    return mAfterCenterChanged.get();
}

void DisplayBox::notify (int id, WindowSystem * ws, Button * button)
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

void DisplayBox::handleClicked (WindowSystem * ws, int y, int x)
{
    mClicked->signal(ws, this, y, x);
}

void DisplayBox::handleScrollChanged (WindowSystem * ws, int y, int x)
{
    mScrollChanged->signal(ws, this, y, x);
}

void DisplayBox::handleBeforeCenterChanged (WindowSystem * ws, int y, int x, bool & cancel)
{
    mBeforeCenterChanged->signal(ws, this, y, x, cancel);
}

void DisplayBox::handleAfterCenterChanged (WindowSystem * ws, int y, int x)
{
    mAfterCenterChanged->signal(ws, this, y, x);
}

void DisplayBox::handleMoveCenterUp (WindowSystem * ws)
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

void DisplayBox::handleMoveCenterDown (WindowSystem * ws)
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

void DisplayBox::handleMoveCenterLeft (WindowSystem * ws)
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

void DisplayBox::handleMoveCenterRight (WindowSystem * ws)
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

bool DisplayBox::isClickLocationShown () const
{
    return mShowClickLocation;
}

void DisplayBox::showClickLocation (bool show)
{
    mShowClickLocation = show;
}

int DisplayBox::getClickedY () const
{
    return mClickedLine;
}

int DisplayBox::getClickedX () const
{
    return mClickedColumn;
}

int DisplayBox::getScrollY () const
{
    return mScrollLine;
}

int DisplayBox::getScrollX () const
{
    return mScrollColumn;
}

bool DisplayBox::scrollUp ()
{
    if ((mContentHeight - mScrollLine) > clientHeight())
    {
        ++mScrollLine;

        return true;
    }

    return false;
}

bool DisplayBox::scrollDown ()
{
    if (mScrollLine > 0)
    {
        --mScrollLine;

        return true;
    }

    return false;
}

bool DisplayBox::scrollLeft ()
{
    if ((mContentWidth - mScrollColumn) > textClientWidth())
    {
        ++mScrollColumn;

        return true;
    }

    return false;
}

bool DisplayBox::scrollRight ()
{
    if (mScrollColumn > 0)
    {
        --mScrollColumn;

        return true;
    }

    return false;
}

void DisplayBox::ensurePointIsVisible (int y, int x)
{
    verifyYX(y, x);

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

void DisplayBox::ensureCenterIsVisible ()
{
    ensurePointIsVisible(mCenterLine, mCenterColumn);
}

int DisplayBox::getCenterY () const
{
    return mCenterLine;
}

int DisplayBox::getCenterX () const
{
    return mCenterColumn;
}

void DisplayBox::setCenter (int y, int x)
{
    verifyYX(y, x);

    mCenterLine = y;
    mCenterColumn = x;
}

bool DisplayBox::canMoveCenterUp ()
{
    return mCenterLine > 0;
}

bool DisplayBox::canMoveCenterDown ()
{
    return mCenterLine < (mContentHeight - 1);
}

bool DisplayBox::canMoveCenterLeft ()
{
    return mCenterColumn > 0;
}

bool DisplayBox::canMoveCenterRight ()
{
    return mCenterColumn < (mContentWidth - 1);
}

bool DisplayBox::moveCenterUp ()
{
    if (canMoveCenterUp())
    {
        --mCenterLine;

        return true;
    }

    return false;
}

bool DisplayBox::moveCenterDown ()
{
    if (canMoveCenterDown())
    {
        ++mCenterLine;

        return true;
    }

    return false;
}

bool DisplayBox::moveCenterLeft ()
{
    if (canMoveCenterLeft())
    {
        --mCenterColumn;

        return true;
    }

    return false;
}

bool DisplayBox::moveCenterRight ()
{
    if (canMoveCenterRight())
    {
        ++mCenterColumn;

        return true;
    }

    return false;
}

} // namespace Curses
} // namespace TUCUT
