//  Control.h
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-24.
//  Copyright © Take Up Code, Inc.
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
    Control (std::string const & name, int y, int x, int height, int width, int clientForeColor, int clientBackColor, int focusForeColor, int focusBackColor);
};

} // namespace Curses
} // namespace TUCUT

#endif // TUCUT_Curses_Control_h
