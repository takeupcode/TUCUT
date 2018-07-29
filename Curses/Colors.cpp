//
//  Colors.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/2/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#include "Colors.h"

#include <curses.h>
#include <stdexcept>

namespace TUCUT {
namespace Curses {

void Colors::initializeColorPairs()
{
    use_default_colors();
    
    if (can_change_color())
    {
        // Initialize as many color pairs as possible
        for (int foreColor = 0; foreColor < colorCount; ++foreColor)
        {
            for (int backColor = 0; backColor < colorCount; ++backColor)
            {
                int i = (foreColor * colorCount) + backColor + 1;
                if (i >= COLOR_PAIRS)
                {
                    // Stop initializing pairs if we reach the limit.
                    return;
                }
                init_pair(i, foreColor, backColor);
            }
        }
    }
}

int Colors::colorPairIndex (int foreColor, int backColor)
{
    if (foreColor < 0 || foreColor >= fullColorCount)
    {
        throw std::out_of_range("foreColor out of range.");
    }
    if (!useBrightColors && foreColor >= basicColorCount)
    {
        foreColor -= basicColorCount;
    }
    
    if (backColor < 0 || backColor >= fullColorCount)
    {
        throw std::out_of_range("backColor out of range.");
    }
    if (!useBrightColors && backColor >= basicColorCount)
    {
        backColor -= basicColorCount;
    }
    
    int i = (foreColor * colorCount) + backColor + 1;
    if (i >= COLOR_PAIRS)
    {
        // Use the default color pair if we exceed the max.
        return 0;
    }
    
    return i;
}

} // namespace Curses
} // namespace TUCUT
