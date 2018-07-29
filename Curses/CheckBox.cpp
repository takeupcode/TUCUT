//
//  CheckBox.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/24/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#include "CheckBox.h"

#include <stdexcept>

#include "ConsoleManager.h"
#include "GameManager.h"
#include "Justification.h"

namespace TUCUT {
namespace Curses {

CheckBox::CheckBox (const std::string & name, const std::string & text, int y, int x, int height, int width, int foreColor, int backColor, int focusForeColor, int focusBackColor)
: Control(name, y, x, height, width, foreColor, backColor, focusForeColor, focusBackColor),
mText(text), mClicked(new ClickedEvent())
{
    if (width < 6)
    {
        throw std::out_of_range("width cannot be less than 6.");
    }
    
    setFillClientArea(false);
}

std::shared_ptr<CheckBox> CheckBox::createSharedCheckBox (const std::string & name, const std::string & text, int y, int x, int height, int width, int foreColor, int backColor, int focusForeColor, int focusBackColor)
{
    return std::shared_ptr<CheckBox>(new CheckBox(name, text, y, x, height, width, foreColor, backColor, focusForeColor, focusBackColor));
}

std::shared_ptr<CheckBox> CheckBox::getSharedCheckBox ()
{
    return std::static_pointer_cast<CheckBox>(shared_from_this());
}

bool CheckBox::onKeyPress (GameManager * gm, int key)
{
    if (enableState() != Window::EnableState::enabled)
    {
        return false;
    }
    
    switch (key)
    {
        case 32: // Space
        case 10: // Enter
            handleClick(gm);
            break;
            
        default:
            if (parent())
            {
                return parent()->onKeyPress(gm, key);
            }
            return false;
    }
    
    return true;
}

void CheckBox::onMouseEvent (GameManager * gm, short id, int y, int x, mmask_t buttonState)
{
    if (enableState() != Window::EnableState::enabled)
    {
        return;
    }
    
    if (buttonState & BUTTON1_CLICKED)
    {
        handleClick(gm);
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

void CheckBox::handleClick (GameManager * gm)
{
    mIsChecked = !mIsChecked;
    
    mClicked->signal(gm, this);
}

CheckBox::ClickedEvent * CheckBox::clicked ()
{
    return mClicked.get();
}

} // namespace Curses
} // namespace TUCUT
