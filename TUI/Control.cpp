//
//  Control.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/24/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#include "Control.h"

namespace TUCUT {
namespace Curses {

Control::Control (const std::string & name, int y, int x, int height, int width, int clientForeColor, int clientBackColor, int focusForeColor, int focusBackColor)
: Window(name, y, x, height, width, clientForeColor, clientBackColor, clientForeColor, clientBackColor, focusForeColor, focusBackColor, false)
{ }

void Control::onDrawNonClient () const
{
    if (visibleState() != Window::VisibleState::shown)
    {
        return;
    }
    
    if (clientWidth() < 3)
    {
        return;
    }
    
    chtype focusMarker = hasDirectFocus() ? ACS_VLINE : ' ';
    
    setNonClientColor();
    for (int i = 0; i < clientHeight(); ++i)
    {
        mvwaddch(cursesWindow(), i, 0, focusMarker);
        if (wantEnter())
        {
            cchar_t ch = {0, L'\u25B7'};
            wadd_wch(cursesWindow(), &ch);
        }
        mvwaddch(cursesWindow(), i, clientWidth() - 1, focusMarker);
    }
}

} // namespace Curses
} // namespace TUCUT
