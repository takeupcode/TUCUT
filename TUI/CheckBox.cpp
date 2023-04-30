//  CheckBox.cpp
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-24.
//  Copyright © Take Up Code, Inc.
//
#include "CheckBox.h"

#include "WindowSystem.h"

using namespace TUCUT;

TUI::CheckBox::CheckBox (std::string const & name,
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

std::shared_ptr<CheckBox> TUI::CheckBox::createSharedCheckBox (
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
  auto result = std::shared_ptr<CheckBox>(new CheckBox(
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

std::shared_ptr<CheckBox> TUI::CheckBox::getSharedCheckBox ()
{
  return std::static_pointer_cast<CheckBox>(shared_from_this());
}

bool TUI::CheckBox::onKeyPress (WindowSystem * ws,
  CharacterEvent const & event)
{
  if (enableState() != Window::EnableState::enabled)
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

bool TUI::CheckBox::onNonPrintingKeyPress (WindowSystem * ws,
  NonPrintingCharacterEvent const & event)
{
  if (enableState() != Window::EnableState::enabled)
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

void TUI::CheckBox::onMouseEvent (WindowSystem * ws,
  MouseEvent const & event)
{
  if (enableState() != Window::EnableState::enabled)
  {
    return;
  }

  if (event.mAction == MouseActions::ButtonPressed &&
    event.mButton == MouseButtons::Left)
  {
    handleClick(ws);
  }
}

void TUI::CheckBox::onDrawClient (WindowSystem * ws) const
{
  if (visibleState() != Window::VisibleState::Shown)
  {
    return;
  }

  int vertCenter = height() / 2;

  std::string check = mIsChecked ? u8"\u25A3 " : u8"\u25A1 ";
  drawText(ws,
    0,
    vertCenter,
    2,
    check,
    hasDirectFocus() ? focusForeColor() : clientForeColor(),
    hasDirectFocus() ? focusBackColor() : clientBackColor());

  if (width() < 3)
  {
    return;
  }

  drawText(ws,
    2,
    vertCenter,
    width() - 2,
    mText,
    hasDirectFocus() ? focusForeColor() : clientForeColor(),
    hasDirectFocus() ? focusBackColor() : clientBackColor());
}

bool TUI::CheckBox::isChecked () const
{
  return mIsChecked;
}

void TUI::CheckBox::setIsChecked (bool value)
{
  mIsChecked = value;
}

void TUI::CheckBox::handleClick (WindowSystem * ws)
{
  mIsChecked = not mIsChecked;

  mClicked->signal(ws, this);
}

TUI::CheckBox::ClickedEvent * TUI::CheckBox::clicked ()
{
  return mClicked.get();
}
