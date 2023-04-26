//  Button.cpp
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-05.
//  Copyright © Take Up Code, Inc.
//
#include "Button.h"

#include "ConsoleManager.h"
#include "WindowSystem.h"
#include "Justification.h"

namespace TUCUT {
namespace Curses {

Button::Button (std::string const & name,
  std::string const & text,
  int x,
  int y,
  int width,
  int height,
  Color const & foreColor,
  Color const & backColor,
  Color const & focusForeColor,
  Color const & focusBackColor)
: Control(name,
  x,
  y,
  width,
  height,
  foreColor,
  backColor,
  focusForeColor,
  focusBackColor),
  mText(text),
  mClicked(new ClickedEvent(ClickedEventId))
{
  setFillClientArea(false);
}

void Button::initialize ()
{
  Control::initialize();
}

std::shared_ptr<Button> Button::createSharedButton (
  std::string const & name,
  std::string const & text,
  int x,
  int y,
  int width,
  int height,
  Color const & foreColor,
  Color const & backColor,
  Color const & focusForeColor,
  Color const & focusBackColor)
{
  auto result = std::shared_ptr<Button>(new Button(
    name,
    text,
    x,
    y,
    width,
    height,
    foreColor,
    backColor,
    focusForeColor,
    focusBackColor));

  result->initialize();

  return result;
}

std::shared_ptr<Button> Button::getSharedButton ()
{
    return std::static_pointer_cast<Button>(shared_from_this());
}

bool Button::onKeyPress (WindowSystem * ws, int key)
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

void Button::onMouseEvent (WindowSystem * ws, short id, int y, int x, mmask_t buttonState)
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

void Button::handleClick (WindowSystem * ws)
{
    mClicked->signal(ws, this);
}

Button::ClickedEvent * Button::clicked ()
{
    return mClicked.get();
}

} // namespace Curses
} // namespace TUCUT
