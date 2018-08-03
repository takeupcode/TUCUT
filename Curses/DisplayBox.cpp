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
const std::string DisplayBox::moveCursorUpButtonName = "moveUpButton";
const std::string DisplayBox::moveCursorDownButtonName = "moveDownButton";
const std::string DisplayBox::moveCursorLeftButtonName = "moveLeftButton";
const std::string DisplayBox::moveCursorRightButtonName = "moveRightButton";

DisplayBox::DisplayBox (const std::string & name, int y, int x, int height, int width, int contentHeight, int contentWidth, int foreColor, int backColor, bool allowCursor, bool wrapContent)
: Control(name, y, x, height, width, foreColor, backColor, foreColor, backColor),
mClicked(new ClickedEvent()),
mScrollLine(0), mScrollColumn(0), mCursorLine(0), mCursorColumn(0),
mContentHeight(contentHeight), mContentWidth(contentWidth), mAllowCursor(allowCursor), mWrapContent(wrapContent)
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
    
    for (int i = 0; i < mContentHeight; i++)
    {
        mContent.push_back(std::string(' ', mContentWidth));
    }
}

void DisplayBox::initialize ()
{
    Control::initialize();
    
    if (mAllowCursor)
    {
        mMoveCursorLeftButton = Button::createSharedButton(moveCursorLeftButtonName, "<", 0, 0, 1, 1, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE);
        mMoveCursorLeftButton->clicked()->connect(windowName, getSharedDisplayBox());
        mMoveCursorLeftButton->setIsDirectFocusPossible(false);
        addControl(mMoveCursorLeftButton);

        mMoveCursorRightButton = Button::createSharedButton(moveCursorRightButtonName, ">", 0, 0, 1, 1, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE);
        mMoveCursorRightButton->clicked()->connect(windowName, getSharedDisplayBox());
        mMoveCursorRightButton->setIsDirectFocusPossible(false);
        addControl(mMoveCursorRightButton);

        mMoveCursorUpButton = Button::createSharedButton(moveCursorUpButtonName, "+", 0, 0, 1, 1, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE);
        mMoveCursorUpButton->clicked()->connect(windowName, getSharedDisplayBox());
        mMoveCursorUpButton->setIsDirectFocusPossible(false);
        addControl(mMoveCursorUpButton);
        
        mMoveCursorDownButton = Button::createSharedButton(moveCursorDownButtonName, "-", 0, 0, 1, 1, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE);
        mMoveCursorDownButton->clicked()->connect(windowName, getSharedDisplayBox());
        mMoveCursorDownButton->setIsDirectFocusPossible(false);
        addControl(mMoveCursorDownButton);
        
        mMoveCursorUpButton->setAnchorTop(0);
        mMoveCursorUpButton->setAnchorRight(0);
        
        mMoveCursorDownButton->setAnchorTop(1);
        mMoveCursorDownButton->setAnchorRight(0);
        
        mMoveCursorLeftButton->setAnchorTop(2);
        mMoveCursorLeftButton->setAnchorRight(0);
        
        mMoveCursorRightButton->setAnchorTop(3);
        mMoveCursorRightButton->setAnchorRight(0);
    }
}

std::shared_ptr<DisplayBox> DisplayBox::createSharedDisplayBox (const std::string & name, int y, int x, int height, int width, int contentHeight, int contentWidth, int foreColor, int backColor, bool allowCursor, bool wrapContent)
{
    auto result = std::shared_ptr<DisplayBox>(new DisplayBox(name, y, x, height, width, contentHeight, contentWidth, foreColor, backColor, allowCursor, wrapContent));
    
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

    if (!mAllowCursor)
    {
        if (parent())
        {
            return parent()->onKeyPress(gm, key);
        }
    }
    else
    {
        switch (key)
        {
            case KEY_UP:
                moveCursorUp();
                break;
                
            case KEY_DOWN:
                moveCursorDown();
                break;
                
            case KEY_LEFT:
                moveCursorLeft();
                break;
                
            case KEY_RIGHT:
                moveCursorRight();
                break;
                
            default:
                if (parent())
                {
                    return parent()->onKeyPress(gm, key);
                }
                break;
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
        
        bool goToMaxColumn = false;
        if (line >= (static_cast<int>(mContent.size())))
        {
            line = static_cast<int>(mContent.size()) - 1;
            goToMaxColumn = true;
        }
        
        if (goToMaxColumn ||
            column > (static_cast<int>(mContent[line].size())))
        {
            column = static_cast<int>(mContent[line].size());
        }
        
        mCursorLine = line;
        mCursorColumn = column;
        
        handleClick(gm, mCursorLine, mCursorColumn);
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
        if (i + mScrollLine >= static_cast<int>(mContent.size()))
        {
            break;
        }
        
        std::string lineText = "";
        if (mScrollColumn < static_cast<int>(mContent[i + mScrollLine].size()))
        {
            lineText = mContent[i + mScrollLine].substr(mScrollColumn, textClientWidth());
        }
        
        if (hasDirectFocus())
        {
            ConsoleManager::printMessage(*this, i, 1, textClientWidth(), lineText, clientForeColor(), clientBackColor(), Justification::Horizontal::left, true, mCursorLine - mScrollLine, mCursorColumn - mScrollColumn + 1);
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

void DisplayBox::notify (GameManager * gm, const Button * button)
{
    if (button->name() == moveCursorUpButtonName)
    {
        moveCursorUp();
    }
    else if (button->name() == moveCursorDownButtonName)
    {
        moveCursorDown();
    }
    else if (button->name() == moveCursorLeftButtonName)
    {
        moveCursorLeft();
    }
    else if (button->name() == moveCursorRightButtonName)
    {
        moveCursorRight();
    }
}

void DisplayBox::handleClick (GameManager * gm, int y, int x) const
{
    mClicked->signal(gm, this, y, x);
}

void DisplayBox::moveCursorUp ()
{
    if (mCursorLine > mScrollLine)
    {
        --mCursorLine;
    }
}

void DisplayBox::moveCursorDown ()
{
    if (mCursorLine < (mContentHeight - mScrollLine - 1))
    {
        ++mCursorLine;
    }
}

void DisplayBox::moveCursorLeft ()
{
    if (mCursorColumn > mScrollColumn)
    {
        --mCursorColumn;
    }
}

void DisplayBox::moveCursorRight ()
{
    if (mCursorColumn < (mContentWidth - mScrollColumn - 1))
    {
        ++mCursorColumn;
    }
}
    
} // namespace Curses
} // namespace TUCUT
