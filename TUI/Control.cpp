//  Control.cpp
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-24.
//  Copyright © Take Up Code, Inc.
//
#include "Control.h"

using namespace TUCUT;

TUI::Control::Control (std::string const & name,
  int x,
  int y,
  int width,
  int height,
  Color const & clientForeColor,
  Color const & clientBackColor,
  Color const & focusForeColor,
  Color const & focusBackColor)
: Window(name,
  x,
  y,
  width,
  height,
  clientForeColor,
  clientBackColor,
  clientForeColor,
  clientBackColor,
  focusForeColor,
  focusBackColor,
  false)
{ }

void TUI::Control::onDrawNonClient () const
{
  if (visibleState() != Window::VisibleState::shown)
  {
    return;
  }

  if (clientWidth() < 3)
  {
    return;
  }

  std::string focusMarker = hasDirectFocus() ? "│" : " ";
  focusMarker = focusForeColor(focusBackColor(focusMarker));

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
