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
  Color const & borderForeColor,
  Color const & borderBackColor,
  Color const & focusForeColor,
  Color const & focusBackColor,
  bool border)
: Window(name,
  x,
  y,
  width,
  height,
  clientForeColor,
  clientBackColor,
  borderForeColor,
  borderBackColor,
  focusForeColor,
  focusBackColor,
  border)
{ }

void TUI::Control::onDrawNonClient (WindowSystem * ws) const
{
  if (visibleState() != Window::VisibleState::Shown ||
    not border() ||
    not hasDirectFocus())
  {
    return;
  }

  std::string focusMarker = u8"\u25B7";
  focusMarker = borderForeColor(borderBackColor(focusMarker));
  drawTiledText(ws, 0, 0, 1, height(), focusMarker);
}
