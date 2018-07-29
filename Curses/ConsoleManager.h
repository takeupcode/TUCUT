//
//  ConsoleManager.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/25/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Curses_ConsoleManager_h
#define TUCUT_Curses_ConsoleManager_h

#define _XOPEN_SOURCE_EXTENDED 1 // To get cchar_t
#include <curses.h>

#include <string>
#include <vector>

#include "Justification.h"

namespace TUCUT {
namespace Curses {

class Window;

class ConsoleManager
{
    enum class PrintState
    {
        normal,
        needForeColor,
        needBackColor,
        needEndOfColor
    };
    
public:
    struct LineBreakpoint
    {
        int beginIndex;
        int endIndex;
        
        void setDefaultValues ();
    };
    
    static bool promptYesOrNo (const Window & win, const std::string & prompt, int foreColor, int backColor, int errorForeColor, int errorBackColor, Justification::Horizontal justification = Justification::Horizontal::left, Justification::Horizontal errorJustification = Justification::Horizontal::left, bool fillSpace = false);
    
    static bool promptYesOrNo (const Window & win, int y, int x, int width, int errorY, int errorX, int errorWidth, const std::string & prompt, int foreColor, int backColor, int errorForeColor, int errorBackColor, Justification::Horizontal justification = Justification::Horizontal::left, Justification::Horizontal errorJustification = Justification::Horizontal::left, bool fillSpace = false);
    
    static int promptNumber (const Window & win, const std::string & prompt, int minimum, int maximum, int foreColor, int backColor, int errorForeColor, int errorBackColor, Justification::Horizontal justification = Justification::Horizontal::left, Justification::Horizontal errorJustification = Justification::Horizontal::left, bool fillSpace = false);
    
    static int promptNumber (const Window & win, int y, int x, int width, int errorY, int errorX, int errorWidth, const std::string & prompt, int minimum, int maximum, int foreColor, int backColor, int errorForeColor, int errorBackColor, Justification::Horizontal justification = Justification::Horizontal::left, Justification::Horizontal errorJustification = Justification::Horizontal::left, bool fillSpace = false);
    
    static char promptLetter (const Window & win, const std::string & prompt, char minimum, char maximum, int foreColor, int backColor, int errorForeColor, int errorBackColor, Justification::Horizontal justification = Justification::Horizontal::left, Justification::Horizontal errorJustification = Justification::Horizontal::left, bool fillSpace = false, bool enforceUpperCase = false);
    
    static char promptLetter (const Window & win, int y, int x, int width, int errorY, int errorX, int errorWidth, const std::string & prompt, char minimum, char maximum, int foreColor, int backColor, int errorForeColor, int errorBackColor, Justification::Horizontal justification = Justification::Horizontal::left, Justification::Horizontal errorJustification = Justification::Horizontal::left, bool fillSpace = false, bool enforceUpperCase = false);
    
    static void promptPause (const Window & win, const std::string & prompt, int foreColor, int backColor, Justification::Horizontal justification = Justification::Horizontal::left, bool fillSpace = false);
    
    static void promptPause (const Window & win, int y, int x, int width, const std::string & prompt, int foreColor, int backColor, Justification::Horizontal justification = Justification::Horizontal::left, bool fillSpace = false);
    
    static void printMessage (const Window & win, const std::string & msg, int foreColor, int backColor, Justification::Horizontal justification = Justification::Horizontal::left, bool fillSpace = false, int cursorY = -1, int cursorX = -1);
    
    static void printMessage (const Window & win, int y, int x, int width, const std::string & msg, int foreColor, int backColor, Justification::Horizontal justification = Justification::Horizontal::left, bool fillSpace = false, int cursorY = -1, int cursorX = -1);
    
    static void printMessage (const Window & win, int y, int x, const std::string & msg, int cursorY = -1, int cursorX = -1);
    
    static void drawBox (const Window & win, int y, int x, int height, int width, int foreColor, int backColor);
    
    static void fillRect (const Window & win, int y, int x, int height, int width, int foreColor, int backColor);
    
    static std::vector<LineBreakpoint> calculateLineBreakpoints (const std::string & text, int width);
    
private:
    static bool charToColor (char c, int & color);
    
    static bool getMaxWinBounds (const Window & win, int & y, int & x);
};
    
} // namespace Curses
} // namespace TUCUT

#endif // TUCUT_Curses_ConsoleManager_h
