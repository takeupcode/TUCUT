//  Button.cpp
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-05.
//  Copyright © Take Up Code, Inc.
//
#include "Button.h"

#include "WindowSystem.h"

using namespace TUCUT;

TUI::Button::Button (std::string const & name,
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
    foreColor,
    backColor,
    focusForeColor,
    focusBackColor,
    false),
  mText(text),
  mClicked(new ClickedEvent(ClickedEventId))
{
  setFillClientArea(false);
}

std::shared_ptr<Button> TUI::Button::createSharedButton (
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

std::shared_ptr<Button> TUI::Button::getSharedButton ()
{
  return std::static_pointer_cast<Button>(shared_from_this());
}

bool TUI::Button::onKeyPress (WindowSystem * ws,
  CharacterEvent const & event)
{
  if (enableState() != Window::EnableState::Enabled)
  {
    return false;
  }

  if (event.mUtf8 == " ")
  {
    handleClick(ws);
    return true;
  }

  if (parent())
  {
    return parent()->onKeyPress(ws, event);
  }

  return false;
}

bool TUI::Button::onNonPrintingKeyPress (WindowSystem * ws,
  NonPrintingCharacterEvent const & event)
{
  if (enableState() != Window::EnableState::Enabled)
  {
    return false;
  }

  if (event.mKey == KeyCodes::NewlineChar)
  {
    handleClick(ws);
    return true;
  }

  if (parent())
  {
    return parent()->onNonPrintingKeyPress(ws, event);
  }

  return false;
}

void TUI::Button::onMouseEvent (WindowSystem * ws,
  MouseEvent const & event)
{
  if (enableState() != Window::EnableState::Enabled)
  {
    return;
  }

  if (event.mAction == MouseActions::ButtonPressed &&
    event.mButton == MouseButtons::Left)
  {
    handleClick(ws);
  }
}

void TUI::Button::onDrawClient (WindowSystem * ws) const
{
  if (visibleState() != Window::VisibleState::Shown)
  {
    return;
  }

  int vertCenter = height() / 2;

  drawText(ws,
    0,
    vertCenter,
    width(),
    mText,
    hasDirectFocus() ? focusForeColor() : clientForeColor(),
    hasDirectFocus() ? focusBackColor() : clientBackColor(),
    " ",
    Justification::Horizontal::Center);
}

void TUI::Button::handleClick (WindowSystem * ws)
{
  mClicked->signal(ws, this);
}

TUI::Button::ClickedEvent * TUI::Button::clicked ()
{
  return mClicked.get();
}
