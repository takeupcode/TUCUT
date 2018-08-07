//
//  DisplayBox.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 8/2/18.
//  Copyright © 2018 Take Up Code. All rights reserved.
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
        
const std::string DisplayBox::windowName = "parent";
const std::string DisplayBox::moveCenterUpButtonName = "moveCenterUpButton";
const std::string DisplayBox::moveCenterDownButtonName = "moveCenterDownButton";
const std::string DisplayBox::moveCenterLeftButtonName = "moveCenterLeftButton";
const std::string DisplayBox::moveCenterRightButtonName = "moveCenterRightButton";

DisplayBox::DisplayBox (const std::string & name, int y, int x, int height, int width, int contentHeight, int contentWidth, int foreColor, int backColor, bool autoScrolling, bool allowCenterControls, bool showClickLocation)
: Control(name, y, x, height, width, foreColor, backColor, foreColor, backColor),
  mClicked(new ClickedEvent(ClickedEventId)),
  mScrollChanged(new ScrollChangedEvent(ScrollChangedEventId)),
  mCenterChanged(new CenterChangedEvent(CenterChangedEventId)),
  mClickedLine(0), mClickedColumn(0),
  mScrollLine(0), mScrollColumn(0),
  mCenterLine(0), mCenterColumn(0),
  mContentHeight(contentHeight), mContentWidth(contentWidth),
  mAutoScrolling(autoScrolling), mAllowCenterControls(allowCenterControls),
  mShowClickLocation(showClickLocation), mIsClickLocationCurrent(false)
{
    if (height < 4)
    {
        throw std::out_of_range("height cannot be less than 4.");
    }
    if (width < 3)
    {
        throw std::out_of_range("width cannot be less than 3.");
    }
    if (contentHeight < 1)
    {
        throw std::out_of_range("content height cannot be less than 1.");
    }
    if (contentWidth < 1)
    {
        throw std::out_of_range("content width cannot be less than 1.");
    }

    mMinHeight = 4;
    mMinWidth = 3;
    
    setFillClientArea(false);
    
    std::string columnMarkers;
    for (int i = 0; i < mContentWidth; i++)
    {
        columnMarkers += '0' + i % 10;
    }

    for (int i = 0; i < mContentHeight; i++)
    {
        if (i % 2)
        {
            mContent.push_back(columnMarkers);
        }
        else
        {
            mContent.push_back(std::string(mContentWidth, '0' + i % 10));
        }
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

std::shared_ptr<DisplayBox> DisplayBox::createSharedDisplayBox (const std::string & name, int y, int x, int height, int width, int contentHeight, int contentWidth, int foreColor, int backColor, bool autoScrolling, bool allowCenterControls, bool showClickLocation)
{
    auto result = std::shared_ptr<DisplayBox>(new DisplayBox(name, y, x, height, width, contentHeight, contentWidth, foreColor, backColor, autoScrolling, allowCenterControls, showClickLocation));
    
    result->initialize();
    
    return result;
}

std::shared_ptr<DisplayBox> DisplayBox::getSharedDisplayBox ()
{
    return std::static_pointer_cast<DisplayBox>(shared_from_this());
}

bool DisplayBox::onKeyPress (GameManager * gm, int key)
{
    if (enableState() != Window::EnableState::enabled)
    {
        return false;
    }

    if (!mAllowCenterControls)
    {
        if (parent())
        {
            return parent()->onKeyPress(gm, key);
        }
    }
    else
    {
        bool scrollMoved = false;
        bool centerMoved = false;

        switch (key)
        {
            case KEY_UP:
                if (mAutoScrolling)
                {
                    scrollMoved = scrollDown();
                }
                centerMoved = moveCenterUp();
                break;
                
            case KEY_DOWN:
                if (mAutoScrolling)
                {
                    scrollMoved = scrollUp();
                }
                centerMoved = moveCenterDown();
                break;
                
            case KEY_LEFT:
                if (mAutoScrolling)
                {
                    scrollMoved = scrollRight();
                }
                centerMoved = moveCenterLeft();
                break;
                
            case KEY_RIGHT:
                if (mAutoScrolling)
                {
                    scrollMoved = scrollLeft();
                }
                centerMoved = moveCenterRight();
                break;
                
            default:
                if (parent())
                {
                    return parent()->onKeyPress(gm, key);
                }
                break;
        }
        
        if (scrollMoved)
        {
            handleScrollChanged(gm, mScrollLine, mScrollColumn);
        }
        if (centerMoved)
        {
            handleCenterChanged(gm, mCenterLine, mCenterColumn);
        }
    }
    
    return true;
}

void DisplayBox::onMouseEvent (GameManager * gm, short id, int y, int x, mmask_t buttonState)
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

        mIsClickLocationCurrent = true;
        handleClicked(gm, mClickedLine, mClickedColumn);
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
        
        if (hasDirectFocus() && mShowClickLocation && mIsClickLocationCurrent)
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
    if (width < 3)
    {
        throw std::out_of_range("width cannot be less than 3.");
    }
    
    mMinWidth = width;
}

char DisplayBox::symbol (int y, int x) const
{
    return mContent[y][x];
}

void DisplayBox::setSymbol (char symbol, int y, int x)
{
    mContent[y][x] = symbol;
}

DisplayBox::ClickedEvent * DisplayBox::clicked ()
{
    return mClicked.get();
}

DisplayBox::ScrollChangedEvent * DisplayBox::scrollChanged ()
{
    return mScrollChanged.get();
}

DisplayBox::CenterChangedEvent * DisplayBox::centerChanged ()
{
    return mCenterChanged.get();
}

void DisplayBox::notify (int id, GameManager * gm, const Button * button)
{
    if (id != Button::ClickedEventId)
    {
        return;
    }
    
    bool scrollMoved = false;
    bool centerMoved = false;
    
    if (button->name() == moveCenterUpButtonName)
    {
        if (mAutoScrolling)
        {
            scrollMoved = scrollDown();
        }
        centerMoved = moveCenterUp();
    }
    else if (button->name() == moveCenterDownButtonName)
    {
        if (mAutoScrolling)
        {
            scrollMoved = scrollUp();
        }
        centerMoved = moveCenterDown();
    }
    else if (button->name() == moveCenterLeftButtonName)
    {
        if (mAutoScrolling)
        {
            scrollMoved = scrollRight();
        }
        centerMoved = moveCenterLeft();
    }
    else if (button->name() == moveCenterRightButtonName)
    {
        if (mAutoScrolling)
        {
            scrollMoved = scrollLeft();
        }
        centerMoved = moveCenterRight();
    }
    
    if (scrollMoved)
    {
        handleScrollChanged(gm, mScrollLine, mScrollColumn);
    }
    if (centerMoved)
    {
        handleCenterChanged(gm, mCenterLine, mCenterColumn);
    }
}

void DisplayBox::handleClicked (GameManager * gm, int y, int x) const
{
    mClicked->signal(gm, this, y, x);
}

void DisplayBox::handleScrollChanged (GameManager * gm, int y, int x) const
{
    mScrollChanged->signal(gm, this, y, x);
}

void DisplayBox::handleCenterChanged (GameManager * gm, int y, int x) const
{
    mCenterChanged->signal(gm, this, y, x);
}

bool DisplayBox::isClickLocationCurrent () const
{
    return mIsClickLocationCurrent;
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
        
        mIsClickLocationCurrent = false;
        return true;
    }
    
    return false;
}

bool DisplayBox::scrollDown ()
{
    if (mScrollLine > 0)
    {
        --mScrollLine;
        
        mIsClickLocationCurrent = false;
        return true;
    }

    return false;
}

bool DisplayBox::scrollLeft ()
{
    if ((mContentWidth - mScrollColumn) > textClientWidth())
    {
        ++mScrollColumn;
        
        mIsClickLocationCurrent = false;
        return true;
    }
    
    return false;
}

bool DisplayBox::scrollRight ()
{
    if (mScrollColumn > 0)
    {
        --mScrollColumn;
        
        mIsClickLocationCurrent = false;
        return true;
    }

    return false;
}

int DisplayBox::getCenterY () const
{
    return mCenterLine;
}

int DisplayBox::getCenterX () const
{
    return mCenterColumn;
}

bool DisplayBox::moveCenterUp ()
{
    if (mCenterLine > 0)
    {
        --mCenterLine;
        
        mIsClickLocationCurrent = false;
        return true;
    }
    
    return false;
}

bool DisplayBox::moveCenterDown ()
{
    if (mCenterLine < (mContentHeight - 1))
    {
        ++mCenterLine;
        
        mIsClickLocationCurrent = false;
        return true;
    }
    
    return false;
}

bool DisplayBox::moveCenterLeft ()
{
    if (mCenterColumn > 0)
    {
        --mCenterColumn;
        
        mIsClickLocationCurrent = false;
        return true;
    }
    
    return false;
}

bool DisplayBox::moveCenterRight ()
{
    if (mCenterColumn < (mContentWidth - 1))
    {
        ++mCenterColumn;
        
        mIsClickLocationCurrent = false;
        return true;
    }
    
    return false;
}

} // namespace Curses
} // namespace TUCUT
