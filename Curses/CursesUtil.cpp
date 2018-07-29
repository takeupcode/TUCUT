//
//  CursesUtil.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/7/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#include "CursesUtil.h"

#include <curses.h>

namespace TUCUT {
namespace Curses {

void CursesUtil::getScreenMaxYX (int & y, int & x)
{
    getmaxyx(stdscr, y, x);
    // For some reason, these values come back too big.
    --y;
    --x;
}

} // namespace Curses
} // namespace TUCUT
