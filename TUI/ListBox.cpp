//
//  ListBox.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/24/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#include "ListBox.h"

#include <sstream>
#include <stdexcept>

#include "Button.h"
#include "Colors.h"
#include "ConsoleManager.h"
#include "Justification.h"

namespace TUCUT {
namespace Curses {

const std::string ListBox::windowName = "parent";
const std::string ListBox::moveSelectionUpButtonName = "moveUpButton";
const std::string ListBox::moveSelectionDownButtonName = "moveDownButton";

ListBox::ListBox (const std::string & name, const std::vector<std::string> & items, int y, int x, int height, int width, int foreColor, int backColor, int selectionForeColor, int selectionBackColor)
: Control(name, y, x, height, width, foreColor, backColor, foreColor, backColor),
  mSelectionChanged(new SelectionChangedEvent(SelectionChangedEventId)),
  mSelectionForeColor(selectionForeColor), mSelectionBackColor(selectionBackColor),
  mScrollItem(0), mSelectionItem(0)
{
    if (height < 4)
    {
        throw std::out_of_range("height cannot be less than 4.");
    }
    if (width < 3)
    {
        throw std::out_of_range("width cannot be less than 3.");
    }
    
    mMinHeight = 4;
    mMinWidth = 3;
    
    setFillClientArea(false);
    
    appendItems(items);
}

void ListBox::initialize ()
{
    Control::initialize();
    
    mMoveSelectionUpButton = Button::createSharedButton(moveSelectionUpButtonName, "+", 0, 0, 1, 1, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE);
    mMoveSelectionUpButton->clicked()->connect(windowName, getSharedListBox());
    mMoveSelectionUpButton->setIsDirectFocusPossible(false);
    addControl(mMoveSelectionUpButton);
    
    mMoveSelectionDownButton = Button::createSharedButton(moveSelectionDownButtonName, "-", 0, 0, 1, 1, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE);
    mMoveSelectionDownButton->clicked()->connect(windowName, getSharedListBox());
    mMoveSelectionDownButton->setIsDirectFocusPossible(false);
    addControl(mMoveSelectionDownButton);
    
    mMoveSelectionUpButton->setAnchorTop(0);
    mMoveSelectionUpButton->setAnchorRight(0);
    
    mMoveSelectionDownButton->setAnchorTop(1);
    mMoveSelectionDownButton->setAnchorRight(0);
}

std::shared_ptr<ListBox> ListBox::createSharedListBox (const std::string & name, const std::vector<std::string> & items, int y, int x, int height, int width, int foreColor, int backColor, int selectionForeColor, int selectionBackColor)
{
    auto result = std::shared_ptr<ListBox>(new ListBox(name, items, y, x, height, width, foreColor, backColor, selectionForeColor, selectionBackColor));
    
    result->initialize();
    
    return result;
}

std::shared_ptr<ListBox> ListBox::getSharedListBox ()
{
    return std::static_pointer_cast<ListBox>(shared_from_this());
}

bool ListBox::onKeyPress (WindowSystem * ws, int key)
{
    if (enableState() != Window::EnableState::enabled)
    {
        return false;
    }
    
    switch (key)
    {
        case KEY_UP:
        case KEY_RIGHT:
            moveSelectionUp();
            break;
            
        case KEY_DOWN:
        case KEY_LEFT:
            moveSelectionDown();
            break;
            
        default:
            if (parent())
            {
                return parent()->onKeyPress(ws, key);
            }
            break;
    }
    
    return true;
}

void ListBox::onMouseEvent (WindowSystem * ws, short id, int y, int x, mmask_t buttonState)
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
        int item = winY + mScrollItem;
        
        if (item >= (static_cast<int>(mItems.size())))
        {
            item = static_cast<int>(mItems.size()) - 1;
        }
        
        mSelectionItem = item;
        ensureSelectionIsVisible();
    }
}

void ListBox::onDrawClient () const
{
    if (visibleState() != Window::VisibleState::shown)
    {
        return;
    }
    
    int i = 0;
    for (; i < clientHeight(); ++i)
    {
        if (i + mScrollItem >= static_cast<int>(mItems.size()))
        {
            break;
        }
        
        std::string itemText = mItems[i + mScrollItem].substr(0, textClientWidth());
        
        if (hasDirectFocus() && mSelectionItem == i + mScrollItem)
        {
            ConsoleManager::printMessage(*this, i, 1, textClientWidth(), itemText, selectionForeColor(), selectionBackColor(), Justification::Horizontal::left, true);
        }
        else
        {
            ConsoleManager::printMessage(*this, i, 1, textClientWidth(), itemText, clientForeColor(), clientBackColor(), Justification::Horizontal::left, true);
        }
    }
    for (; i < clientHeight(); ++i)
    {
        ConsoleManager::printMessage(*this, i, 1, textClientWidth(), " ", clientForeColor(), clientBackColor(), Justification::Horizontal::left, true);
    }
}

void ListBox::onResize ()
{
    ensureSelectionIsVisible();
}

int ListBox::textClientWidth () const
{
    // This method accounts for the area used by the scrolling buttons and focus marker.
    return clientWidth() - 2;
}

void ListBox::setMinHeight (int height)
{
    if (height < 4)
    {
        throw std::out_of_range("height cannot be less than 4.");
    }
    
    mMinHeight = height;
}

void ListBox::setMinWidth (int width)
{
    if (width < 3)
    {
        throw std::out_of_range("width cannot be less than 3.");
    }
    
    mMinWidth = width;
}

int ListBox::selectionForeColor () const
{
    return mSelectionForeColor;
}

void ListBox::setSelectionForeColor (int color)
{
    mSelectionForeColor = color;
}

int ListBox::selectionBackColor () const
{
    return mSelectionBackColor;
}

void ListBox::setSelectionBackColor (int color)
{
    mSelectionBackColor = color;
}

int ListBox::size () const
{
    return static_cast<int>(mItems.size());
}

int ListBox::selection () const
{
    return mSelectionItem;
}

std::string ListBox::text (int index) const
{
    if (index > static_cast<int>(mItems.size()))
    {
        throw std::out_of_range("index out of range.");
    }
    
    return mItems[index];
}

void ListBox::setText (int index, const std::string & text)
{
    if (index > static_cast<int>(mItems.size()))
    {
        throw std::out_of_range("index out of range.");
    }
    
    mItems[index] = text;
}

void ListBox::appendItems (const std::vector<std::string> & items)
{
    insertItems(static_cast<int>(mItems.size()), items);
}

void ListBox::insertItems (int index, const std::vector<std::string> & items)
{
    if (index > static_cast<int>(mItems.size()))
    {
        throw std::out_of_range("index out of range.");
    }
    
    mItems.reserve(mItems.size() + items.size());
    mItems.insert(mItems.end() + index, items.begin(), items.end());
}

ListBox::SelectionChangedEvent * ListBox::selectionChanged ()
{
    return mSelectionChanged.get();
}

void ListBox::notify (int id, WindowSystem * ws, Button * button)
{
    if (id != Button::ClickedEventId)
    {
        return;
    }
    
    if (button->name() == moveSelectionUpButtonName)
    {
        moveSelectionUp();
    }
    else if (button->name() == moveSelectionDownButtonName)
    {
        moveSelectionDown();
    }
}

void ListBox::handleSelectionChange (WindowSystem * ws)
{
    mSelectionChanged->signal(ws, this);
}

void ListBox::moveSelectionUp ()
{
    if (mSelectionItem > 0)
    {
        --mSelectionItem;
        
        ensureSelectionIsVisible();
    }
}

void ListBox::moveSelectionDown ()
{
    if (mSelectionItem < (static_cast<int>(mItems.size()) - 1))
    {
        ++mSelectionItem;
        
        ensureSelectionIsVisible();
    }
}

void ListBox::ensureSelectionIsVisible ()
{
    if (mSelectionItem < mScrollItem)
    {
        mScrollItem = mSelectionItem;
    }
    else if (mSelectionItem >= mScrollItem + clientHeight())
    {
        mScrollItem = mSelectionItem - clientHeight() + 1;
    }
}

} // namespace Curses
} // namespace TUCUT
