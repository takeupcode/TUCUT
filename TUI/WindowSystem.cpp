//  WindowSystem.cpp
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-10-26.
//  Copyright © Take Up Code, Inc.
//
#include "WindowSystem.h"

#include "Window.h"

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
  mMaxScreenWidth = width;
  mMaxScreenHeight = height;
}

// Figure out if the screen or the window has the smallest
// max x and y. Whichever is smallest is the max x and y
// that will be visible. Translate the max x and y back
// into window coordinates. Return false if the window
// is off the screen.
bool TUI::WindowSystem::getMaxWindowCoordinates (
  Window const * win, int & x, int & y)
{
  int worldX = win->worldX();
  int worldY = win->worldY();
  if (worldX >= mMaxScreenWidth ||
    worldY >= mMaxScreenHeight)
  {
    return false;
  }

  int maxWorldX = worldX + win->width() - 1;
  int maxWorldY = worldY + win->height() - 1;

  int maxX = (maxWorldX < mMaxScreenWidth) ?
    maxWorldX : (mMaxScreenWidth - 1);
  int maxY = (maxWorldY < mMaxScreenHeight) ?
    maxWorldY : (mMaxScreenHeight - 1);

  x = maxX - worldX;
  y = maxY - worldY;

  return true;
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
