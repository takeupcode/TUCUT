//  Justification.h
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-16.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_Curses_Justification_h
#define TUCUT_Curses_Justification_h

namespace TUCUT {
namespace Curses {

struct Justification
{
    enum class Horizontal
    {
        left,
        center,
        right
    };

    enum class Vertical
    {
        top,
        center,
        bottom
    };
};

} // namespace Curses
} // namespace TUCUT

#endif // TUCUT_Curses_Justification_h
