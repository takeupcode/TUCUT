//
//  Justification.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/16/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
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
