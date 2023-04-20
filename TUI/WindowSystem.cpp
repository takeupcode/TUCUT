//  WindowSystem.cpp
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-10-26.
//  Copyright © Take Up Code, Inc.
//
#include "WindowSystem.h"

#include "Colors.h"
#include "Window.h"

#include <curses.h>

using namespace TUCUT;

std::string const TUI::WindowSystem::defaultToken =
  "WindowSystem";

std::shared_ptr<TUI::WindowSystem>
TUI::WindowSystem::getSharedWindowSystem ()
{
  return std::static_pointer_cast<WindowSystem>(
    shared_from_this());
}

TUI::WindowSystem::WindowSystem (
  std::string const & token,
  int identity)
: System(token, identity),
  mScreenMaxX(0), mScreenMaxY(0),
  mMinScreenWidth(0), mMinScreenHeight(0),
  mMaxScreenWidth(80), mMaxScreenHeight(40),
  mNextWindow(nullptr), mCurrentWindow(nullptr)
{ }

void TUI::WindowSystem::addWindow(
  std::shared_ptr<Window> const & window)
{
  mWindows.push_back(window);
}

void TUI::WindowSystem::addWindow(
  std::shared_ptr<Window> && window)
{
  mWindows.push_back(std::move(window));
}

void TUI::WindowSystem::selectNextWindow(
  std::string const & name)
{
  for (auto & win: mWindows)
  {
    if (win->name() == name)
    {
      mNextWindow = win.get();
      break;
    }
  }
}

int TUI::WindowSystem::screenWidth () const
{
  return mScreenMaxX + 1;
}

int TUI::WindowSystem::screenHeight () const
{
  return mScreenMaxY + 1;
}

int TUI::WindowSystem::minScreenWidth () const
{
  return mMinScreenWidth;
}

int TUI::WindowSystem::minScreenHeight () const
{
  return mMinScreenHeight;
}

void TUI::WindowSystem::setMinScreenDimensions (
  int width, int height)
{
  mMinScreenWidth = width;
  mMinScreenHeight = height;
}

int TUI::WindowSystem::maxScreenWidth () const
{
  return mMaxScreenWidth;
}

int TUI::WindowSystem::maxScreenHeight () const
{
  return mMaxScreenHeight;
}

void TUI::WindowSystem::setMaxScreenDimensions (
  int width, int height)
{
  mMaxScreenHeight = height;
  mMaxScreenWidth = width;
}

void TUI::WindowSystem::initialize ()
{
  System::initialize();

  mTerminal.moveCursor(1'000, 1'000);
  mTerminal.reportCursorPosition(mScreenMaxX, mScreenMaxY);
  mTerminal.moveCursor(0, 0);
}

void TUI::WindowSystem::handleInput ()
{
  if (mNextWindow)
  {
    // Switch current window at the beginning of the loop.
    mCurrentWindow = mNextWindow;
    mNextWindow = nullptr;
  }

  if (not mCurrentWindow)
  {
    return;
  }

  mCurrentWindow->processInput(this);
}

void TUI::WindowSystem::update (ECS::TimeResolution elapsedTime)
{
  if (not mCurrentWindow)
  {
    return;
  }

  mCurrentWindow->update(elapsedTime);
}

void TUI::WindowSystem::render ()
{
  if (not mCurrentWindow)
  {
    return;
  }

  mCurrentWindow->draw();
}

int TUI::WindowSystem::clampWidthBounds (int width) const
{
  if (width < mMinScreenWidth)
  {
    return mMinScreenWidth;
  }

  if (width > mMaxScreenWidth)
  {
    return mMaxScreenWidth;
  }

  return width;
}

int TUI::WindowSystem::clampHeightBounds (int height) const
{
  if (height < mMinScreenHeight)
  {
    return mMinScreenHeight;
  }

  if (height > mMaxScreenHeight)
  {
    return mMaxScreenHeight;
  }

  return height;
}
