//
//  WindowSystem.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/26/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#include "WindowSystem.h"

#include <curses.h>

#include "Colors.h"
#include "CursesUtil.h"
#include "ConsoleManager.h"
#include "Window.h"

namespace TUCUT {
namespace Curses {

const std::string WindowSystem::defaultToken = "WindowSystem";

std::shared_ptr<WindowSystem> WindowSystem::getSharedWindowSystem ()
{
    return std::static_pointer_cast<WindowSystem>(shared_from_this());
}

WindowSystem::WindowSystem (const std::string & token, int identity)
: GameSystem(token, identity), mScreenMaxX(0), mScreenMaxY(0),
  mMinScreenWidth(0), mMinScreenHeight(0), mMaxScreenWidth(80), mMaxScreenHeight(40),
  mNextWindow(nullptr), mCurrentWindow(nullptr)
{ }

WindowSystem::~WindowSystem ()
{
    deinitialize();
}

void WindowSystem::addWindow(const std::shared_ptr<Window> & window)
{
    mWindows.push_back(window);
}

void WindowSystem::addWindow(std::shared_ptr<Window> && window)
{
    mWindows.push_back(std::move(window));
}

void WindowSystem::selectNextWindow(const std::string & name)
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

int WindowSystem::screenWidth () const
{
    return mScreenMaxX + 1;
}

int WindowSystem::screenHeight () const
{
    return mScreenMaxY + 1;
}

int WindowSystem::minScreenWidth () const
{
    return mMinScreenWidth;
}

int WindowSystem::minScreenHeight () const
{
    return mMinScreenHeight;
}

void WindowSystem::setMinScreenDimensions (int height, int width)
{
    mMinScreenHeight = height;
    mMinScreenWidth = width;
}

int WindowSystem::maxScreenWidth () const
{
    return mMaxScreenWidth;
}

int WindowSystem::maxScreenHeight () const
{
    return mMaxScreenHeight;
}

void WindowSystem::setMaxScreenDimensions (int height, int width)
{
    mMaxScreenHeight = height;
    mMaxScreenWidth = width;
}

void WindowSystem::initialize ()
{
    GameSystem::initialize();

    initscr();
    start_color();
    raw();
    noecho();
    curs_set(0);
    nodelay(stdscr, true);
    keypad(stdscr, true);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, nullptr);
    Colors::initializeColorPairs();

    CursesUtil::getScreenMaxYX(mScreenMaxY, mScreenMaxX);
}

void WindowSystem::deinitialize ()
{
    endwin();
}
    
void WindowSystem::update (Game::TimeResolution elapsedTime)
{
    if (mNextWindow)
    {
        // Switch current window at the beginning of the loop.
        mCurrentWindow = mNextWindow;
        mNextWindow = nullptr;
    }
    if (!mCurrentWindow)
    {
        return;
    }
    
    CursesUtil::getScreenMaxYX(mScreenMaxY, mScreenMaxX);
    
    mCurrentWindow->resize(checkHeightBounds(screenHeight()), checkWidthBounds(screenWidth()));
    
    mCurrentWindow->processInput(this);
    
    mCurrentWindow->draw();
    
    doupdate();
}
    
int WindowSystem::checkHeightBounds (int height) const
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

int WindowSystem::checkWidthBounds (int width) const
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

} // namespace Curses
} // namespace TUCUT
