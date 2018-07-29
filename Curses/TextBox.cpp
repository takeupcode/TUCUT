//
//  TextBox.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/18/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#include "TextBox.h"

#include <sstream>
#include <stdexcept>

#include "Button.h"
#include "Colors.h"
#include "ConsoleManager.h"
#include "Justification.h"

namespace TUCUT {
namespace Curses {

const std::string TextBox::windowName = "parent";
const std::string TextBox::moveCursorUpButtonName = "moveUpButton";
const std::string TextBox::moveCursorDownButtonName = "moveDownButton";
const std::string TextBox::moveCursorLeftButtonName = "moveLeftButton";
const std::string TextBox::moveCursorRightButtonName = "moveRightButton";

TextBox::TextBox (const std::string & name, const std::string & text, int y, int x, int height, int width, int foreColor, int backColor, bool multiline)
: Control(name, y, x, height, width, foreColor, backColor, foreColor, backColor),
  mTextChanged(new TextChangedEvent()),
  mScrollLine(0), mScrollColumn(0), mCursorLine(0), mCursorColumn(0), mDesiredColumn(0), mMultiline(multiline)
{
    if (multiline)
    {
        if (height < 4)
        {
            throw std::out_of_range("height cannot be less than 4 when using multi-line.");
        }
        if (width < 3)
        {
            throw std::out_of_range("width cannot be less than 3 when using multi-line.");
        }
        
        mMinHeight = 4;
        mMinWidth = 3;
    }
    else
    {
        if (height != 1)
        {
            throw std::out_of_range("height must be 1 when using single-line.");
        }
        if (width < 5)
        {
            throw std::out_of_range("width cannot be less than 5 when using single-line.");
        }
        
        mMinHeight = 1;
        mMinWidth = 5;
    }
    
    setFillClientArea(false);
    
    setText(text);
}

void TextBox::initialize ()
{
    Control::initialize();
    
    mMoveCursorLeftButton = Button::createSharedButton(moveCursorLeftButtonName, "<", 0, 0, 1, 1, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE);
    mMoveCursorLeftButton->clicked()->connect(windowName, getSharedTextBox());
    mMoveCursorLeftButton->setIsDirectFocusPossible(false);
    
    mMoveCursorRightButton = Button::createSharedButton(moveCursorRightButtonName, ">", 0, 0, 1, 1, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE);
    mMoveCursorRightButton->clicked()->connect(windowName, getSharedTextBox());
    mMoveCursorRightButton->setIsDirectFocusPossible(false);
    
    if (mMultiline)
    {
        mMoveCursorUpButton = Button::createSharedButton(moveCursorUpButtonName, "+", 0, 0, 1, 1, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE);
        mMoveCursorUpButton->clicked()->connect(windowName, getSharedTextBox());
        mMoveCursorUpButton->setIsDirectFocusPossible(false);
        addControl(mMoveCursorUpButton);
        
        mMoveCursorDownButton = Button::createSharedButton(moveCursorDownButtonName, "-", 0, 0, 1, 1, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE);
        mMoveCursorDownButton->clicked()->connect(windowName, getSharedTextBox());
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
    else
    {
        mMoveCursorLeftButton->setAnchorTop(0);
        mMoveCursorLeftButton->setAnchorRight(2);
        
        mMoveCursorRightButton->setAnchorTop(0);
        mMoveCursorRightButton->setAnchorRight(1);
    }
    
    addControl(mMoveCursorLeftButton);
    addControl(mMoveCursorRightButton);
}

std::shared_ptr<TextBox> TextBox::createSharedTextBox (const std::string & name, const std::string & text, int y, int x, int height, int width, int foreColor, int backColor, bool multiline)
{
    auto result = std::shared_ptr<TextBox>(new TextBox(name, text, y, x, height, width, foreColor, backColor, multiline));
    
    result->initialize();
    
    return result;
}

std::shared_ptr<TextBox> TextBox::getSharedTextBox ()
{
    return std::static_pointer_cast<TextBox>(shared_from_this());
}

bool TextBox::onKeyPress (GameManager * gm, int key)
{
    if (enableState() != Window::EnableState::enabled)
    {
        return false;
    }
    
    switch (key)
    {
    case 10: // Enter
    case KEY_ENTER:
        breakLineAtCursor();
        handleTextChange(gm);
        break;
    
    case 127: // Delete
        if (removeCharAtCursor())
        {
            handleTextChange(gm);
        }
        break;
        
    case 8: // Backspace
    case KEY_DC:
    case KEY_BACKSPACE:
        if (mCursorColumn > 0)
        {
            mDesiredColumn = --mCursorColumn;
            
            if (removeCharAtCursor())
            {
                handleTextChange(gm);
            }
            
            ensureCursorIsVisible();
        }
        else if (mCursorLine > 0)
        {
            --mCursorLine;
            mDesiredColumn = mCursorColumn = static_cast<int>(mText[mCursorLine].size());
            
            if (removeCharAtCursor())
            {
                handleTextChange(gm);
            }
            
            ensureCursorIsVisible();
        }
        break;
            
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
        if (addCharAtCursor(key))
        {
            handleTextChange(gm);
        }
        else if (parent())
        {
            return parent()->onKeyPress(gm, key);
        }
        break;
    }
    
    return true;
}

void TextBox::onMouseEvent (GameManager * gm, short id, int y, int x, mmask_t buttonState)
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
        if (line >= (static_cast<int>(mText.size())))
        {
            line = static_cast<int>(mText.size()) - 1;
            goToMaxColumn = true;
        }
        
        if (goToMaxColumn ||
            column > (static_cast<int>(mText[line].size())))
        {
            column = static_cast<int>(mText[line].size());
        }
        
        mCursorLine = line;
        mCursorColumn = column;
        mDesiredColumn = column;
        ensureCursorIsVisible();
    }
}

void TextBox::onDrawClient () const
{
    if (visibleState() != Window::VisibleState::shown)
    {
        return;
    }
    
    if (isMultiline())
    {
        int i = 0;
        for (; i < clientHeight(); ++i)
        {
            if (i + mScrollLine >= static_cast<int>(mText.size()))
            {
                break;
            }
            
            std::string lineText = "";
            if (mScrollColumn < static_cast<int>(mText[i + mScrollLine].size()))
            {
                lineText = mText[i + mScrollLine].substr(mScrollColumn, textClientWidth());
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
    else
    {
        int vertCenter = clientHeight() / 2;
        std::string lineText = "";
        if (mScrollColumn < static_cast<int>(mText[0].size()))
        {
            lineText = mText[0].substr(mScrollColumn, textClientWidth());
        }
        ConsoleManager::printMessage(*this, vertCenter, 0, textClientWidth(), lineText, clientForeColor(), clientBackColor(), Justification::Horizontal::left, true, vertCenter, mCursorColumn - mScrollColumn);
    }
}

void TextBox::onResize ()
{
    ensureCursorIsVisible();
}

int TextBox::textClientWidth () const
{
    // This method accounts for the area used by the scrolling buttons and focus marker.
    if (mMultiline)
    {
        // If multi-line, then all the scrolling buttons are in the rightmost column with the right focus marker.
        return clientWidth() - 2;
    }
    
    // For single-line, the focus marker occupies the last column followed by the left and right scrolling buttons.
    return clientWidth() - 4;
}

void TextBox::setMinHeight (int height)
{
    if (mMultiline)
    {
        if (height < 4)
        {
            throw std::out_of_range("height cannot be less than 4 when using multi-line.");
        }
    }
    else
    {
        if (height != 1)
        {
            throw std::out_of_range("height must be 1 when using single-line.");
        }
    }
    
    mMinHeight = height;
}

void TextBox::setMinWidth (int width)
{
    if (mMultiline)
    {
        if (width < 3)
        {
            throw std::out_of_range("width cannot be less than 3 when using multi-line.");
        }
    }
    else
    {
        if (width < 5)
        {
            throw std::out_of_range("width cannot be less than 5 when using single-line.");
        }
    }
    
    mMinWidth = width;
}

bool TextBox::isMultiline () const
{
    return mMultiline;
}

std::string TextBox::text () const
{
    std::ostringstream ss;
    
    bool firstLine = true;
    for (const auto & line: mText)
    {
        if (!firstLine)
        {
            ss << "\n";
        }
        
        ss << line;
        firstLine = false;
    }
    
    return ss.str();
}

void TextBox::setText (const std::string & text)
{
    mText.clear();
    
    mCursorLine = 0;
    mDesiredColumn = mCursorColumn = 0;
    
    insertLines(text);
    
    if (mText.empty())
    {
        mText.push_back("");
    }
    
    ensureCursorIsVisible();
}

void TextBox::appendLines (const std::string & text)
{
    mCursorLine = static_cast<int>(mText.size());
    
    insertLines(text);
    
    mCursorLine = static_cast<int>(mText.size()) - 1;
    
    ensureCursorIsVisible();
}

void TextBox::insertLines (const std::string & text)
{
    std::istringstream ss(text);
    std::string line;
    
    int i = mCursorLine;
    while (std::getline(ss, line))
    {
        mText.insert(mText.begin() + i, std::move(line));
        
        ++i;
    }
}

TextBox::TextChangedEvent * TextBox::textChanged ()
{
    return mTextChanged.get();
}

void TextBox::notify (GameManager * gm, const Button * button)
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

void TextBox::handleTextChange (GameManager * gm) const
{
    mTextChanged->signal(gm, this);
}

void TextBox::moveCursorUp ()
{
    if (mCursorLine > 0)
    {
        --mCursorLine;
        
        placeCursorClosestToDesiredColumn();
        ensureCursorIsVisible();
    }
}

void TextBox::moveCursorDown ()
{
    if (mCursorLine < (static_cast<int>(mText.size()) - 1))
    {
        ++mCursorLine;
        
        placeCursorClosestToDesiredColumn();
        ensureCursorIsVisible();
    }
}

void TextBox::moveCursorLeft ()
{
    if (mCursorColumn > 0)
    {
        --mCursorColumn;
        
        mDesiredColumn = mCursorColumn;
        ensureCursorIsVisible();
    }
    else if (mCursorLine > 0)
    {
        --mCursorLine;
        mCursorColumn = static_cast<int>(mText[mCursorLine].size());
        
        mDesiredColumn = mCursorColumn;
        ensureCursorIsVisible();
    }
}

void TextBox::moveCursorRight ()
{
    if (mCursorColumn < (static_cast<int>(mText[mCursorLine].size())))
    {
        ++mCursorColumn;
        
        mDesiredColumn = mCursorColumn;
        ensureCursorIsVisible();
    }
    else if (mCursorLine < (static_cast<int>(mText.size()) - 1))
    {
        ++mCursorLine;
        mCursorColumn = 0;
        
        mDesiredColumn = mCursorColumn;
        ensureCursorIsVisible();
    }
}

void TextBox::breakLineAtCursor ()
{
    std::string currentText = mText[mCursorLine].substr(0, mCursorColumn);
    std::string nextText = mText[mCursorLine].substr(mCursorColumn, mText[mCursorLine].size());
    
    mText[mCursorLine] = currentText;
    mText.insert(mText.begin() + mCursorLine + 1, nextText);
    
    ++mCursorLine;
    mDesiredColumn = mCursorColumn = 0;
    ensureCursorIsVisible();
}

bool TextBox::removeCharAtCursor ()
{
    if (mCursorColumn == static_cast<int>(mText[mCursorLine].size()) &&
        mCursorLine < static_cast<int>(mText.size()) - 1)
    {
        mText[mCursorLine] = mText[mCursorLine] + mText[mCursorLine + 1];
        mText.erase(mText.begin() + mCursorLine + 1);
        
        return true;
    }
    else if (mCursorColumn < static_cast<int>(mText[mCursorLine].size()))
    {
        mText[mCursorLine].erase(mText[mCursorLine].begin() + mCursorColumn);
        
        return true;
    }
    
    return false;
}

bool TextBox::addCharAtCursor (int key)
{
    if (key < 32 || key > 126)
    {
        return false;
    }
    
    mText[mCursorLine].insert(mText[mCursorLine].begin() + mCursorColumn, static_cast<char>(key));
    
    mDesiredColumn = ++mCursorColumn;
    ensureCursorIsVisible();
    
    return true;
}

void TextBox::placeCursorClosestToDesiredColumn ()
{
    if (mDesiredColumn > static_cast<int>(mText[mCursorLine].size()))
    {
        mCursorColumn = static_cast<int>(mText[mCursorLine].size());
    }
    else
    {
        mCursorColumn = mDesiredColumn;
    }
}

void TextBox::ensureCursorIsVisible ()
{
    if (mCursorLine < mScrollLine)
    {
        mScrollLine = mCursorLine;
    }
    else if (mCursorLine >= mScrollLine + clientHeight())
    {
        mScrollLine = mCursorLine - clientHeight() + 1;
    }
    
    if (mCursorColumn < mScrollColumn)
    {
        mScrollColumn = mCursorColumn;
    }
    else if (mCursorColumn >= mScrollColumn + textClientWidth())
    {
        mScrollColumn = mCursorColumn - textClientWidth() + 1;
    }
}

} // namespace Curses
} // namespace TUCUT
