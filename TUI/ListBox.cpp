//  ListBox.cpp
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-24.
//  Copyright © Take Up Code, Inc.
//
#include "ListBox.h"

#include <sstream>
#include <stdexcept>

#include "Button.h"
#include "Colors.h"
#include "ConsoleManager.h"
#include "Justification.h"

using namespace TUCUT;

std::string const TUI::ListBox::windowName = "parent";
std::string const TUI::ListBox::moveSelectionUpButtonName = "moveUpButton";
std::string const TUI::ListBox::moveSelectionDownButtonName = "moveDownButton";

TUI::ListBox::ListBox (std::string const & name,
  std::vector<std::string> const & items,
  int x,
  int y,
  int width,
  int height,
  Color const & foreColor,
  Color const & backColor,
  Color const & selectionForeColor,
  Color const & selectionBackColor)
: Control(name,
    x,
    y,
    width,
    height,
    foreColor,
    backColor,
    foreColor,
    backColor),
  mSelectionChanged(new SelectionChangedEvent(SelectionChangedEventId)),
  mSelectionForeColor(selectionForeColor),
  mSelectionBackColor(selectionBackColor),
  mScrollItem(0),
  mSelectionItem(0)
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

void TUI::ListBox::initialize ()
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

std::shared_ptr<ListBox> TUI::ListBox::createSharedListBox (
  std::string const & name,
  std::vector<std::string> const & items,
  int x,
  int y,
  int width,
  int height,
  Color const & foreColor,
  Color const & backColor,
  Color const & selectionForeColor,
  Color const & selectionBackColor)
{
  auto result = std::shared_ptr<ListBox>(new ListBox(
    name,
    items,
    x,
    y,
    width,
    height,
    foreColor,
    backColor,
    selectionForeColor,
    selectionBackColor));

  result->initialize();

  return result;
}

std::shared_ptr<ListBox> TUI::ListBox::getSharedListBox ()
{
    return std::static_pointer_cast<ListBox>(shared_from_this());
}

bool TUI::ListBox::onKeyPress (WindowSystem * ws, int key)
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

void TUI::ListBox::onMouseEvent (WindowSystem * ws, short id, int y, int x, mmask_t buttonState)
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

void TUI::ListBox::onDrawClient () const
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

void TUI::ListBox::onResize ()
{
    ensureSelectionIsVisible();
}

int TUI::ListBox::textClientWidth () const
{
    // This method accounts for the area used by the scrolling buttons and focus marker.
    return clientWidth() - 2;
}

void TUI::ListBox::setMinHeight (int height)
{
    if (height < 4)
    {
        throw std::out_of_range("height cannot be less than 4.");
    }

    mMinHeight = height;
}

void TUI::ListBox::setMinWidth (int width)
{
    if (width < 3)
    {
        throw std::out_of_range("width cannot be less than 3.");
    }

    mMinWidth = width;
}

Color TUI::ListBox::selectionForeColor () const
{
    return mSelectionForeColor;
}

void TUI::ListBox::setSelectionForeColor (Color const & color)
{
    mSelectionForeColor = color;
}

Color TUI::ListBox::selectionBackColor () const
{
    return mSelectionBackColor;
}

void TUI::ListBox::setSelectionBackColor (Color const & color)
{
    mSelectionBackColor = color;
}

int TUI::ListBox::size () const
{
    return static_cast<int>(mItems.size());
}

int TUI::ListBox::selection () const
{
    return mSelectionItem;
}

std::string TUI::ListBox::text (int index) const
{
    if (index > static_cast<int>(mItems.size()))
    {
        throw std::out_of_range("index out of range.");
    }

    return mItems[index];
}

void TUI::ListBox::setText (int index, std::string const & text)
{
    if (index > static_cast<int>(mItems.size()))
    {
        throw std::out_of_range("index out of range.");
    }

    mItems[index] = text;
}

void TUI::ListBox::appendItems (std::vector<std::string> const & items)
{
    insertItems(static_cast<int>(mItems.size()), items);
}

void TUI::ListBox::insertItems (int index, std::vector<std::string> const & items)
{
    if (index > static_cast<int>(mItems.size()))
    {
        throw std::out_of_range("index out of range.");
    }

    mItems.reserve(mItems.size() + items.size());
    mItems.insert(mItems.end() + index, items.begin(), items.end());
}

TUI::ListBox::SelectionChangedEvent * TUI::ListBox::selectionChanged ()
{
    return mSelectionChanged.get();
}

void TUI::ListBox::notify (int id, WindowSystem * ws, Button * button)
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

void TUI::ListBox::handleSelectionChange (WindowSystem * ws)
{
    mSelectionChanged->signal(ws, this);
}

void TUI::ListBox::moveSelectionUp ()
{
    if (mSelectionItem > 0)
    {
        --mSelectionItem;

        ensureSelectionIsVisible();
    }
}

void TUI::ListBox::moveSelectionDown ()
{
    if (mSelectionItem < (static_cast<int>(mItems.size()) - 1))
    {
        ++mSelectionItem;

        ensureSelectionIsVisible();
    }
}

void TUI::ListBox::ensureSelectionIsVisible ()
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
