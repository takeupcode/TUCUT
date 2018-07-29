//
//  Colors.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/2/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Curses_Colors_h
#define TUCUT_Curses_Colors_h

namespace TUCUT {
namespace Curses {

class Colors
{
public:
    static constexpr bool useBrightColors = true;
    static constexpr int basicColorCount = 8;
    static constexpr int fullColorCount = basicColorCount * 2;
    static constexpr int colorCount = useBrightColors ? fullColorCount : basicColorCount;

    // Define basic colors which will always be available.
    static constexpr int COLOR_DIM_BLACK      = 0;
    static constexpr int COLOR_DIM_RED        = 1;
    static constexpr int COLOR_DIM_GREEN      = 2;
    static constexpr int COLOR_DIM_YELLOW     = 3;
    static constexpr int COLOR_DIM_BLUE       = 4;
    static constexpr int COLOR_DIM_MAGENTA    = 5;
    static constexpr int COLOR_DIM_CYAN       = 6;
    static constexpr int COLOR_DIM_WHITE      = 7;
    
    // Define bright colors which might get converted to basic colors.
    static constexpr int COLOR_BRIGHT_BLACK   = COLOR_DIM_BLACK   + basicColorCount;
    static constexpr int COLOR_BRIGHT_RED     = COLOR_DIM_RED     + basicColorCount;
    static constexpr int COLOR_BRIGHT_GREEN   = COLOR_DIM_GREEN   + basicColorCount;
    static constexpr int COLOR_BRIGHT_YELLOW  = COLOR_DIM_YELLOW  + basicColorCount;
    static constexpr int COLOR_BRIGHT_BLUE    = COLOR_DIM_BLUE    + basicColorCount;
    static constexpr int COLOR_BRIGHT_MAGENTA = COLOR_DIM_MAGENTA + basicColorCount;
    static constexpr int COLOR_BRIGHT_CYAN    = COLOR_DIM_CYAN    + basicColorCount;
    static constexpr int COLOR_BRIGHT_WHITE   = COLOR_DIM_WHITE   + basicColorCount;

    static void initializeColorPairs();
    
    static int colorPairIndex (int foreColor, int backColor);
};
    
} // namespace Curses
} // namespace TUCUT

#endif // TUCUT_Curses_Colors_h
