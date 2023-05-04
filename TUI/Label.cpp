//  Label.cpp
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-11.
//  Copyright © Take Up Code, Inc.
//
#include "Label.h"

using namespace TUCUT;

TUI::Label::Label (std::string const & name,
  std::string const & text,
  int x,
  int y,
  int width,
  int height,
  Color const & foreColor,
  Color const & backColor,
  Justification::Horizontal horizontal,
  Justification::Vertical vertical,
  bool multiline)
: Control(name,
    x,
    y,
    width,
    height,
    foreColor,
    backColor,
    foreColor,
    backColor),
  mText(text),
  mHorizontal(horizontal),
  mVertical(vertical),
  mMultiline(multiline)
{
  setIsDirectFocusPossible(false);

  setFillClientArea(false);
}

std::shared_ptr<Label> TUI::Label::createSharedLabel (
  std::string const & name,
  std::string const & text,
  int x,
  int y,
  int width,
  int height,
  Color const & foreColor,
  Color const & backColor,
  Justification::Horizontal horizontal,
  Justification::Vertical vertical,
  bool multiline)
{
  auto result = std::shared_ptr<Label>(new Label(
    name,
    text,
    x,
    y,
    width,
    height,
    foreColor,
    backColor,
    horizontal,
    vertical,
    multiline));

  result->initialize();

  return result;
}

std::shared_ptr<Label> TUI::Label::getSharedLabel ()
{
  return std::static_pointer_cast<Label>(shared_from_this());
}

void TUI::Label::onDrawClient (WindowSystem * ws) const
{
  if (visibleState() != Window::VisibleState::Shown)
  {
    return;
  }

  if (isMultiline())
  {
    std::vector<ConsoleManager::LineBreakpoint> lineBreakPoints =
      ConsoleManager::calculateLineBreakpoints (mText, clientWidth());
    int margin = 0;
    switch (mVerticalJustification)
    {
    case Justification::Vertical::top:
      margin = 0;
      break;

    case Justification::Vertical::center:
      margin = (clientHeight() - static_cast<int>(lineBreakPoints.size())) / 2;
      break;

    case Justification::Vertical::bottom:
      margin = clientHeight() - static_cast<int>(lineBreakPoints.size());
      break;
    }
    if (margin < 0)
    {
      margin = 0;
    }

    int i = 0;
    for (; i < margin; ++i)
    {
      ConsoleManager::printMessage(*this, i, 0, clientWidth(), " ", clientForeColor(), clientBackColor(),
        Justification::Horizontal::left, true);
    }
    for (auto & breakpoint: lineBreakPoints)
    {
      std::string lineText = mText.substr(breakpoint.beginIndex, breakpoint.endIndex - breakpoint.beginIndex + 1);
      ConsoleManager::printMessage(*this, i, 0, clientWidth(), lineText, clientForeColor(), clientBackColor(),
        mHorizontalJustification, true);
      ++i;
    }
    for (; i < clientHeight(); ++i)
    {
      ConsoleManager::printMessage(*this, i, 0, clientWidth(), " ", clientForeColor(), clientBackColor(),
        Justification::Horizontal::left, true);
    }
  }
  else
  {
    int vertCenter = clientHeight() / 2;
    ConsoleManager::printMessage(*this, vertCenter, 0, clientWidth(), mText, clientForeColor(), clientBackColor(),
      mHorizontalJustification, true);
  }
}

bool TUI::Label::isMultiline () const
{
  return mMultiline;
}

void TUI::Label::setMultiline (bool multiline)
{
  mMultiline = multiline;
}

std::string TUI::Label::text () const
{
  return mText;
}

void TUI::Label::setText (std::string const & text)
{
  mText = text;
}
