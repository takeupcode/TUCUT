//  CheckBox.cpp
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-24.
//  Copyright © Take Up Code, Inc.
//
#include "CheckBox.h"

#include <stdexcept>

#include "ConsoleManager.h"
#include "WindowSystem.h"
#include "Justification.h"

namespace TUCUT {
namespace Curses {

CheckBox::CheckBox (const std::string & name, const std::string & text, int y, int x, int height, int width, int foreColor, int backColor, int focusForeColor, int focusBackColor)
: Control(name, y, x, height, width, foreColor, backColor, focusForeColor, focusBackColor),
mText(text), mClicked(new ClickedEvent(ClickedEventId))
{
    if (width < 6)
    {
        throw std::out_of_range("width cannot be less than 6.");
    }

    setFillClientArea(false);
}

void CheckBox::initialize ()
{
    Control::initialize();
}

std::shared_ptr<CheckBox> CheckBox::createSharedCheckBox (const std::string & name, const std::string & text, int y, int x, int height, int width, int foreColor, int backColor, int focusForeColor, int focusBackColor)
{
    auto result = std::shared_ptr<CheckBox>(new CheckBox(name, text, y, x, height, width, foreColor, backColor, focusForeColor, focusBackColor));

    result->initialize();

    return result;
}

std::shared_ptr<CheckBox> CheckBox::getSharedCheckBox ()
{
    return std::static_pointer_cast<CheckBox>(shared_from_this());
}

bool CheckBox::onKeyPress (WindowSystem * ws, int key)
{
    if (enableState() != Window::EnableState::enabled)
    {
        return false;
    }

    switch (key)
    {
        case 32: // Space
        case 10: // Enter
            handleClick(ws);
            break;

        default:
            if (parent())
            {
                return parent()->onKeyPress(ws, key);
            }
            return false;
    }

    return true;
}

void CheckBox::onMouseEvent (WindowSystem * ws, short id, int y, int x, mmask_t buttonState)
{
    if (enableState() != Window::EnableState::enabled)
    {
        return;
    }

    if (buttonState & BUTTON1_CLICKED)
    {
        handleClick(ws);
    }
}

void CheckBox::onDrawClient () const
{
    if (visibleState() != Window::VisibleState::shown)
    {
        return;
    }

    cchar_t check = {0, L'\u25A3'};
    cchar_t uncheck = {0, L'\u25A1'};

    int vertCenter = height() / 2;

    if (hasDirectFocus())
    {
        ConsoleManager::printMessage(*this, vertCenter, 1, 3, "   ", focusForeColor(), focusBackColor(), Justification::Horizontal::left, false);
        mvwadd_wch(cursesWindow(), vertCenter, 2, mIsChecked ? &check : &uncheck);
        ConsoleManager::printMessage(*this, vertCenter, 4, width() - 5, mText, focusForeColor(), focusBackColor(), Justification::Horizontal::left, true);
    }
    else
    {
        ConsoleManager::printMessage(*this, vertCenter, 1, 3, "   ", clientForeColor(), clientBackColor(), Justification::Horizontal::left, false);
        mvwadd_wch(cursesWindow(), vertCenter, 2, mIsChecked ? &check : &uncheck);
        ConsoleManager::printMessage(*this, vertCenter, 4, width() - 5, mText, clientForeColor(), clientBackColor(), Justification::Horizontal::left, true);
    }
}

bool CheckBox::isChecked () const
{
    return mIsChecked;
}

void CheckBox::setIsChecked (bool value)
{
    mIsChecked = value;
}

void CheckBox::handleClick (WindowSystem * ws)
{
    mIsChecked = !mIsChecked;

    mClicked->signal(ws, this);
}

CheckBox::ClickedEvent * CheckBox::clicked ()
{
    return mClicked.get();
}

} // namespace Curses
} // namespace TUCUT
