//
//  GameManager.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/26/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#include "GameManager.h"

#include <chrono>
#include <curses.h>
#include <thread>

#include "Colors.h"
#include "CursesUtil.h"
#include "ConsoleManager.h"
#include "Window.h"

namespace TUCUT {
namespace Curses {

const GameManager::TimeResolution GameManager::FixedFrameTime =
    GameManager::TimeResolution(GameManager::TimeResolution::period::den / GameManager::FramesPerSecond);

GameManager::GameManager ()
: mScreenMaxX(0), mScreenMaxY(0),
  mMinScreenWidth(0), mMinScreenHeight(0), mMaxScreenWidth(80), mMaxScreenHeight(40),
  mNextWindow(nullptr), mCurrentWindow(nullptr), mElapsed(0), mFixedFrameTotal(0), mExit(false)
{ }

GameManager::~GameManager ()
{
    deinitialize();
}

void GameManager::play ()
{
    loop();
}

void GameManager::exit ()
{
    mExit = true;
}

void GameManager::addWindow(const std::shared_ptr<Window> & window)
{
    mWindows.push_back(window);
}

void GameManager::addWindow(std::shared_ptr<Window> && window)
{
    mWindows.push_back(std::move(window));
}

void GameManager::selectNextWindow(const std::string & name)
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

int GameManager::screenWidth () const
{
    return mScreenMaxX + 1;
}

int GameManager::screenHeight () const
{
    return mScreenMaxY + 1;
}

int GameManager::minScreenWidth () const
{
    return mMinScreenWidth;
}

int GameManager::minScreenHeight () const
{
    return mMinScreenHeight;
}

void GameManager::setMinScreenDimensions (int height, int width)
{
    mMinScreenHeight = height;
    mMinScreenWidth = width;
}

int GameManager::maxScreenWidth () const
{
    return mMaxScreenWidth;
}

int GameManager::maxScreenHeight () const
{
    return mMaxScreenHeight;
}

void GameManager::setMaxScreenDimensions (int height, int width)
{
    mMaxScreenHeight = height;
    mMaxScreenWidth = width;
}

void GameManager::initialize ()
{
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

void GameManager::deinitialize ()
{
    endwin();
}

void GameManager::loop ()
{
    mLastTime = TimeClock::now();
    
    while (!mExit)
    {
        if (isFixedFrameReady())
        {
            if (mNextWindow)
            {
                // Switch current window at the beginning of the loop.
                mCurrentWindow = mNextWindow;
                mNextWindow = nullptr;
            }
            if (!mCurrentWindow)
            {
                break;
            }
            
            CursesUtil::getScreenMaxYX(mScreenMaxY, mScreenMaxX);
            
            mCurrentWindow->resize(checkHeightBounds(screenHeight()), checkWidthBounds(screenWidth()));
            
            mCurrentWindow->processInput(this);
            
            mCurrentWindow->draw();
            
            doupdate();
            
            completeFixedFrame();
        }
        else
        {
            waitForNextFixedFrame();
        }
        restartClock();
    }
}

int GameManager::checkHeightBounds (int height) const
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

int GameManager::checkWidthBounds (int width) const
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

GameManager::TimeResolution GameManager::elapsed () const
{
    return mElapsed;
}

void GameManager::restartClock ()
{
    auto currentTime = TimeClock::now();
    mElapsed = std::chrono::duration_cast<TimeResolution>(currentTime - mLastTime);
    mFixedFrameTotal += mElapsed;
    mLastTime = currentTime;
}

bool GameManager::isFixedFrameReady () const
{
    return mFixedFrameTotal > FixedFrameTime;
}

void GameManager::completeFixedFrame ()
{
    mFixedFrameTotal -= FixedFrameTime;
}

void GameManager::waitForNextFixedFrame ()
{
    auto waitDuration = FixedFrameTime - mFixedFrameTotal;
    if (waitDuration > waitDuration.zero())
    {
        std::this_thread::sleep_for(std::chrono::duration_cast<std::chrono::milliseconds>(waitDuration));
    }
}

} // namespace Curses
} // namespace TUCUT
