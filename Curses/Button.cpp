//
//  Button.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/5/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#include "Button.h"

#include "ConsoleManager.h"
#include "GameManager.h"
#include "Justification.h"

namespace TUCUT {
namespace Curses {

Button::Button (const std::string & name, const std::string & text, int y, int x, int height, int width, int foreColor, int backColor, int focusForeColor, int focusBackColor)
: Control(name, y, x, height, width, foreColor, backColor, focusForeColor, focusBackColor),
  mText(text), mClicked(new ClickedEvent())
{
    setFillClientArea(false);
}

void Button::initialize ()
{
    Control::initialize();
}

std::shared_ptr<Button> Button::createSharedButton (const std::string & name, const std::string & text, int y, int x, int height, int width, int foreColor, int backColor, int focusForeColor, int focusBackColor)
{
    auto result = std::shared_ptr<Button>(new Button(name, text, y, x, height, width, foreColor, backColor, focusForeColor, focusBackColor));
    
    result->initialize();
    
    return result;
}

std::shared_ptr<Button> Button::getSharedButton ()
{
    return std::static_pointer_cast<Button>(shared_from_this());
}
    
bool Button::onKeyPress (GameManager * gm, int key)
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

void Button::onMouseEvent (GameManager * gm, short id, int y, int x, mmask_t buttonState)
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

void Button::onDrawClient () const
{
    if (visibleState() != Window::VisibleState::shown)
    {
        return;
    }
    
    int vertCenter = height() / 2;
    
    if (hasDirectFocus())
    {
        ConsoleManager::printMessage(*this, vertCenter, 0, width(), mText, focusForeColor(), focusBackColor(), Justification::Horizontal::center, true);
    }
    else
    {
        ConsoleManager::printMessage(*this, vertCenter, 0, width(), mText, clientForeColor(), clientBackColor(), Justification::Horizontal::center, true);
    }
}

void Button::handleClick (GameManager * gm) const
{
    mClicked->signal(gm, this);
}

Button::ClickedEvent * Button::clicked ()
{
    return mClicked.get();
}

} // namespace Curses
} // namespace TUCUT
