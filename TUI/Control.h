//
//  Control.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/24/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Curses_Control_h
#define TUCUT_Curses_Control_h

#include "Window.h"

namespace TUCUT {
namespace Curses {

class Control : public Window
{
public:
    void onDrawNonClient () const override;
    
protected:
    Control (const std::string & name, int y, int x, int height, int width, int clientForeColor, int clientBackColor, int focusForeColor, int focusBackColor);
};
    
} // namespace Curses
} // namespace TUCUT

#endif // TUCUT_Curses_Control_h
