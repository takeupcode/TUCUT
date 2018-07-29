//
//  ConsoleManager.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/25/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#include "ConsoleManager.h"

#include <stdexcept>
#include <sstream>
#include <stdexcept>
#include <string>

#include "Colors.h"
#include "CursesUtil.h"
#include "Window.h"
#include "../Text/TextUtil.h"

namespace TUCUT {
namespace Curses {

bool ConsoleManager::getMaxWinBounds (const Window & win, int & y, int & x)
{
    // Figure out if the screen or the window has the smallest max y and x.
    // Whichever is smallest is the max y and x that will be visible.
    // Translate the max y and x back into window client coordinates.
    // And return false if the window is off the screen.
    int maxScreenY;
    int maxScreenX;
    CursesUtil::getScreenMaxYX(maxScreenY, maxScreenX);
    
    if (win.clientY() > maxScreenY || win.clientX() > maxScreenX)
    {
        return false;
    }
    
    int maxWinY = win.clientY() + win.clientHeight() - 1;
    int maxWinX = win.clientX() + win.clientWidth() - 1;
    
    int resultY = (maxWinY <= maxScreenY) ? maxWinY : maxScreenY;
    int resultX = (maxWinX <= maxScreenX) ? maxWinX : maxScreenX;
    
    y = resultY - win.clientY();
    x = resultX - win.clientX();
    
    return true;
}

bool ConsoleManager::promptYesOrNo (const Window & win, const std::string & prompt, int foreColor, int backColor, int errorForeColor, int errorBackColor, Justification::Horizontal justification, Justification::Horizontal errorJustification, bool fillSpace)
{
    WINDOW * cursesWin = win.cursesWindow();
    
    int currentY;
    int currentX;
    getyx(cursesWin, currentY, currentX);
    
    int width = win.clientWidth() - currentX;
    
    int errorY = currentY + 1;
    int errorX = currentX;
    
    return promptYesOrNo(win, currentY, currentX, width, errorY, errorX, width, prompt, foreColor, backColor, errorForeColor, errorBackColor, justification, errorJustification, fillSpace);
}

bool ConsoleManager::promptYesOrNo (const Window & win, int y, int x, int width, int errorY, int errorX, int errorWidth, const std::string & prompt, int foreColor, int backColor, int errorForeColor, int errorBackColor, Justification::Horizontal justification, Justification::Horizontal errorJustification, bool fillSpace)
{
    WINDOW * cursesWin = win.cursesWindow();
    
    echo();
    nodelay(cursesWin, false);
    
    while (true)
    {
        printMessage(win, y, x, width, prompt, foreColor, backColor, justification, fillSpace);
        wrefresh(cursesWin);
        
        char input = static_cast<char>(wgetch(cursesWin));
        clrtoeol();
        
        if (input == 'y' || input == 'Y')
        {
            noecho();
            nodelay(cursesWin, true);
            
            return true;
        }
        else if (input == 'n' || input == 'N')
        {
            noecho();
            nodelay(cursesWin, true);
            
            return false;
        }
        else
        {
            std::stringstream ss;
            ss << "Please enter y or n.";
            printMessage(win, errorY, errorX, errorWidth, ss.str(), errorForeColor, errorBackColor, errorJustification, fillSpace);
        }
    }
}

int ConsoleManager::promptNumber (const Window & win, const std::string & prompt, int minimum, int maximum, int foreColor, int backColor, int errorForeColor, int errorBackColor, Justification::Horizontal justification, Justification::Horizontal errorJustification, bool fillSpace)
{
    WINDOW * cursesWin = win.cursesWindow();
    
    int currentY;
    int currentX;
    getyx(cursesWin, currentY, currentX);
    
    int width = win.clientWidth() - currentX;
    
    int errorY = currentY + 1;
    int errorX = currentX;
    
    return promptNumber(win, currentY, currentX, width, errorY, errorX, width, prompt, minimum, maximum, foreColor, backColor, errorForeColor, errorBackColor, justification, errorJustification, fillSpace);
}

int ConsoleManager::promptNumber (const Window & win, int y, int x, int width, int errorY, int errorX, int errorWidth, const std::string & prompt, int minimum, int maximum, int foreColor, int backColor, int errorForeColor, int errorBackColor, Justification::Horizontal justification, Justification::Horizontal errorJustification, bool fillSpace)
{
    WINDOW * cursesWin = win.cursesWindow();
    
    echo();
    nodelay(cursesWin, false);
    
    const int BUFFER_CHAR_COUNT = 10;
    while (true)
    {
        printMessage(win, y, x, width, prompt, foreColor, backColor, justification);
        wrefresh(cursesWin);
        
        char buffer[BUFFER_CHAR_COUNT + 1];
        if (wgetnstr(cursesWin, buffer, BUFFER_CHAR_COUNT) == OK)
        {
            int input = std::stoi(buffer);
            
            if (input >= minimum && input <= maximum)
            {
                noecho();
                nodelay(cursesWin, true);
                
                return input;
            }
        }

        std::stringstream ss;
        ss << "Please enter a number between " << minimum << " and " << maximum << ".";
        printMessage(win, errorY, errorX, errorWidth, ss.str(), errorForeColor, errorBackColor, errorJustification, fillSpace);
    }
}

char ConsoleManager::promptLetter (const Window & win, const std::string & prompt, char minimum, char maximum, int foreColor, int backColor, int errorForeColor, int errorBackColor, Justification::Horizontal justification, Justification::Horizontal errorJustification, bool fillSpace, bool enforceUpperCase)
{
    WINDOW * cursesWin = win.cursesWindow();
    
    int currentY;
    int currentX;
    getyx(cursesWin, currentY, currentX);
    
    int width = win.clientWidth() - currentX;
    
    int errorY = currentY + 1;
    int errorX = currentX;
    
    return promptLetter(win, currentY, currentX, width, errorY, errorX, width, prompt, minimum, maximum, foreColor, backColor, errorForeColor, errorBackColor, justification, errorJustification, fillSpace, enforceUpperCase);
}

char ConsoleManager::promptLetter (const Window & win, int y, int x, int width, int errorY, int errorX, int errorWidth, const std::string & prompt, char minimum, char maximum, int foreColor, int backColor, int errorForeColor, int errorBackColor, Justification::Horizontal justification, Justification::Horizontal errorJustification, bool fillSpace, bool enforceUpperCase)
{
    WINDOW * cursesWin = win.cursesWindow();
    
    char minimumLower;
    char minimumUpper;
    if (minimum >= 'a' && minimum <= 'z')
    {
        minimumLower = minimum;
        minimumUpper = toupper(minimum);
    }
    else if (minimum >= 'A' && minimum <= 'Z')
    {
        minimumLower = tolower(minimum);
        minimumUpper = minimum;
    }
    else
    {
        throw std::logic_error("minimum must be a valid letter between a-z or A-Z.");
    }
    
    char maximumLower;
    char maximumUpper;
    if (maximum >= 'a' && maximum <= 'z')
    {
        maximumLower = maximum;
        maximumUpper = toupper(maximum);
    }
    else if (maximum >= 'A' && maximum <= 'Z')
    {
        maximumLower = tolower(maximum);
        maximumUpper = maximum;
    }
    else
    {
        throw std::logic_error("maximum must be a valid letter between a-z or A-Z.");
    }
    
    echo();
    nodelay(cursesWin, false);
    
    while (true)
    {
        printMessage(win, y, x, width, prompt, foreColor, backColor, justification, fillSpace);
        wrefresh(cursesWin);
        
        char input = static_cast<char>(wgetch(cursesWin));
        clrtoeol();
        
        if ((input >= minimumLower && input <= maximumLower) || (input >= minimumUpper && input <= maximumUpper))
        {
            if (enforceUpperCase && (input >= minimumLower && input <= maximumLower))
            {
                // Convert the lower case input to upper case before returning.
                // xx0x xxxx = 1101 1111 = 0xdf
                char mask = 0xdf;
                input &= mask;
            }
            
            noecho();
            nodelay(cursesWin, true);
            
            return input;
        }
        
        std::stringstream ss;
        ss << "Please enter a letter between " << minimumLower << " and " << maximumLower << ".";
        printMessage(win, errorY, errorX, errorWidth, ss.str(), errorForeColor, errorBackColor, errorJustification, fillSpace);
    }
}

void ConsoleManager::promptPause (const Window & win, const std::string & prompt, int foreColor, int backColor, Justification::Horizontal justification, bool fillSpace)
{
    WINDOW * cursesWin = win.cursesWindow();
    
    int currentY;
    int currentX;
    getyx(cursesWin, currentY, currentX);
    
    int width = win.clientWidth() - currentX;
    
    promptPause(win, currentY, currentX, width, prompt, foreColor, backColor, justification, fillSpace);
}

void ConsoleManager::promptPause (const Window & win, int y, int x, int width, const std::string & prompt, int foreColor, int backColor, Justification::Horizontal justification, bool fillSpace)
{
    WINDOW * cursesWin = win.cursesWindow();
    
    printMessage(win, y, x, width, prompt, foreColor, backColor, justification, fillSpace);
    wrefresh(cursesWin);
    
    wgetch(cursesWin);
}

void ConsoleManager::printMessage (const Window & win, const std::string & msg, int foreColor, int backColor, Justification::Horizontal justification, bool fillSpace, int cursorY, int cursorX)
{
    WINDOW * cursesWin = win.cursesWindow();
    
    int currentY;
    int currentX;
    getyx(cursesWin, currentY, currentX);
    
    int width = win.clientWidth() - currentX;
    
    printMessage(win, currentY, currentX, width, msg, foreColor, backColor, justification, fillSpace, cursorY, cursorX);
}

void ConsoleManager::printMessage (const Window & win, int y, int x, int width, const std::string & msg, int foreColor, int backColor, Justification::Horizontal justification, bool fillSpace, int cursorY, int cursorX)
{
    int maxWinY;
    int maxWinX;
    if (!getMaxWinBounds(win, maxWinY, maxWinX))
    {
        return;
    }
    if (y > maxWinY || x > maxWinX)
    {
        return;
    }
    
    WINDOW * cursesWin = win.cursesWindow();
    
    int margin = 0;
    switch (justification)
    {
    case Justification::Horizontal::left:
        margin = 0;
        break;
        
    case Justification::Horizontal::center:
        margin = (width - static_cast<int>(msg.length())) / 2;
        break;
        
    case Justification::Horizontal::right:
        margin = width - static_cast<int>(msg.length());
        break;
    }
    if (margin < 0)
    {
        margin = 0;
    }
    int messageX = x + margin;
    
    int i = Colors::colorPairIndex(foreColor, backColor);
    wattrset(cursesWin, COLOR_PAIR(i));
    
    if (fillSpace)
    {
        wmove(cursesWin, y, x);
        for (int i = x; i < messageX; ++i)
        {
            if (i > maxWinX)
            {
                return;
            }
            if (cursorY == y && cursorX == i)
            {
                waddch(cursesWin, ' ' | A_REVERSE);
            }
            else
            {
                waddch(cursesWin, ' ' | A_NORMAL);
            }
        }
    }
    
    printMessage(win, y, messageX, msg, cursorY, cursorX);
    
    if (fillSpace)
    {
        if (y == maxWinY)
        {
            y = maxWinY;
        }
        int currentY = getcury(cursesWin);
        if (currentY != y)
        {
            // This method only prints a single line of text.
            return;
        }
        // We can't rely on the cursor moving automatically when it's already
        // in the bottom right corner.
        int currentX = messageX + static_cast<int>(msg.length());
        for (int i = currentX; i < x + width; ++i)
        {
            if (i > maxWinX)
            {
                return;
            }
            if (cursorY == y && cursorX == i)
            {
                
                waddch(cursesWin, ' ' | A_REVERSE);
            }
            else
            {
                waddch(cursesWin, ' ' | A_NORMAL);
            }
        }
    }
}

void ConsoleManager::printMessage (const Window & win, int y, int x, const std::string & msg, int cursorY, int cursorX)
{
    int maxWinY;
    int maxWinX;
    if (!getMaxWinBounds(win, maxWinY, maxWinX))
    {
        return;
    }
    if (y > maxWinY || x > maxWinX)
    {
        return;
    }
    
    WINDOW * cursesWin = win.cursesWindow();
    
    if (wmove(cursesWin, y, x) == ERR)
    {
        return;
    }
    
    PrintState state = PrintState::normal;
    
    bool skipColorCheck = false;
    int foreColor = 0;
    int backColor = 0;
    
    int lastIndex = static_cast<int>(msg.length()) - 1;
    for (int index = 0; index <= lastIndex; ++index)
    {
        char c = msg[index];
        
        if (c == '\t')
        {
            c = ' ';
        }
        else if (c == '\n')
        {
            // This method prints at most a single line.
            break;
        }
        
        switch (state)
        {
        case PrintState::normal:
            if (index != lastIndex && !skipColorCheck && c == '&')
            {
                state = PrintState::needForeColor;
            }
            else
            {
                if (x > maxWinX)
                {
                    return;
                }
                if (cursorY == y && cursorX == x)
                {
                    
                    mvwaddch(cursesWin, y, x, c | A_REVERSE);
                }
                else
                {
                    mvwaddch(cursesWin, y, x, c | A_NORMAL);
                }
                ++x;
            }
            skipColorCheck = false;
            break;
            
        case PrintState::needForeColor:
            if (index != lastIndex && charToColor(c, foreColor))
            {
                state = PrintState::needBackColor;
            }
            else
            {
                index -= 2;
                skipColorCheck = true;
                state = PrintState::normal;
            }
            break;
            
        case PrintState::needBackColor:
            if (index != lastIndex && charToColor(c, backColor))
            {
                state = PrintState::needEndOfColor;
            }
            else
            {
                index -= 3;
                skipColorCheck = true;
                state = PrintState::normal;
            }
            break;
            
        case PrintState::needEndOfColor:
            if (c == ';')
            {
                int i = Colors::colorPairIndex(foreColor, backColor);
                wattrset(cursesWin, COLOR_PAIR(i));
            }
            else
            {
                index -= 4;
                skipColorCheck = true;
                state = PrintState::normal;
            }
            state = PrintState::normal;
            break;
        }
    }
}

void ConsoleManager::drawBox (const Window & win, int y, int x, int height, int width, int foreColor, int backColor)
{
    int maxWinY;
    int maxWinX;
    if (!getMaxWinBounds(win, maxWinY, maxWinX))
    {
        return;
    }
    if (y > maxWinY || x > maxWinX)
    {
        return;
    }
    
    WINDOW * cursesWin = win.cursesWindow();
    
    int i = Colors::colorPairIndex(foreColor, backColor);
    wattrset(cursesWin, COLOR_PAIR(i));
    
    mvwaddch(cursesWin, y, x, ACS_ULCORNER);
    mvwaddch(cursesWin, y, x + width - 1, ACS_URCORNER);
    mvwaddch(cursesWin, y + height - 1, x, ACS_LLCORNER);
    mvwaddch(cursesWin, y + height - 1, x + width - 1, ACS_LRCORNER);
    mvwhline(cursesWin, y, x + 1, ACS_HLINE, width - 2);
    mvwhline(cursesWin, y + height - 1, x + 1, ACS_HLINE, width - 2);
    mvwvline(cursesWin, y + 1, x, ACS_VLINE, height - 2);
    mvwvline(cursesWin, y + 1, x + width - 1, ACS_VLINE, height - 2);
}

void ConsoleManager::fillRect (const Window & win, int y, int x, int height, int width, int foreColor, int backColor)
{
    int maxWinY;
    int maxWinX;
    if (!getMaxWinBounds(win, maxWinY, maxWinX))
    {
        return;
    }
    if (y > maxWinY || x > maxWinX)
    {
        return;
    }
    
    WINDOW * cursesWin = win.cursesWindow();
    
    int i = Colors::colorPairIndex(foreColor, backColor);
    wattrset(cursesWin, COLOR_PAIR(i));
    
    for (int i = 0; i < height; ++i)
    {
        if (y + i > maxWinY)
        {
            return;
        }
        mvwhline(cursesWin, y + i, x, ' ', width);
    }
}

void ConsoleManager::LineBreakpoint::setDefaultValues ()
{
    beginIndex = 0;
    endIndex = 0;
}

std::vector<ConsoleManager::LineBreakpoint> ConsoleManager::calculateLineBreakpoints (const std::string & text, int width)
{
    std::vector<ConsoleManager::LineBreakpoint> result;

    PrintState state = PrintState::normal;
    
    int x = 0;
    const int maxX = width - 1;
    
    int lastNonSpaceIndex = 0;
    bool foundNonSpaceChar = false;
    
    LineBreakpoint lineBreakpoint;
    lineBreakpoint.setDefaultValues();
    
    bool skipColorCheck = false;
    int foreColor = 0;
    int backColor = 0;
    
    auto setLineBreakpoint = [&lineBreakpoint, &result, &lastNonSpaceIndex, &foundNonSpaceChar, &x] (int index)
    {
        lineBreakpoint.endIndex = index;
        
        result.push_back(lineBreakpoint);
        
        lineBreakpoint.setDefaultValues();
        
        lastNonSpaceIndex = 0;
        
        foundNonSpaceChar = false;
        
        x = 0;
    };
    
    int lastIndex = static_cast<int>(text.length()) - 1;
    for (int index = 0; index <= lastIndex; ++index)
    {
        char c = text[index];
        bool thisCharIsWhitespace = Text::TextUtil::isWhitespace(c);
        
        switch (state)
        {
        case PrintState::normal:
            if (index != lastIndex && !skipColorCheck && c == '&')
            {
                state = PrintState::needForeColor;
            }
            else if (c == '\n')
            {
                setLineBreakpoint(lastNonSpaceIndex);
            }
            else
            {
                if (foundNonSpaceChar || !thisCharIsWhitespace)
                {
                    if (x > maxX)
                    {
                        lineBreakpoint.endIndex = index - 1;
                        
                        if (lastNonSpaceIndex > lineBreakpoint.beginIndex)
                        {
                            // If we found a space after a non space since beginning this
                            // line, then go back to the previous non space.
                            index = lastNonSpaceIndex;
                        }
                        else
                        {
                            // Go back one position.
                            --index;
                        }
                        setLineBreakpoint(index);
                    }
                    else if (index == lastIndex)
                    {
                        // See below why we need to check for the last char at this point.
                        setLineBreakpoint(index);
                    }
                    else
                    {
                        // We already know that this is not the last char.
                        bool nextCharIsWhitespace = Text::TextUtil::isWhitespace(text[index + 1]);
                        
                        // For breaking purposes, the first char is treated as if it was preceded by whitespace.
                        bool prevCharIsWhitespace = (index == 0) ? true : Text::TextUtil::isWhitespace(text[index - 1]);

                        if ((!thisCharIsWhitespace && nextCharIsWhitespace) ||
                            (c == '-' && !nextCharIsWhitespace && !prevCharIsWhitespace))
                        {
                            lastNonSpaceIndex = index;
                        }
                        if (!foundNonSpaceChar)
                        {
                            lineBreakpoint.beginIndex = index;
                            
                            foundNonSpaceChar = true;
                        }
                        ++x;
                    }
                }
            }
            skipColorCheck = false;
            break;
            
        case PrintState::needForeColor:
            if (index != lastIndex && charToColor(c, foreColor))
            {
                state = PrintState::needBackColor;
            }
            else
            {
                index -= 2;
                skipColorCheck = true;
                state = PrintState::normal;
            }
            break;
            
        case PrintState::needBackColor:
            if (index != lastIndex && charToColor(c, backColor))
            {
                state = PrintState::needEndOfColor;
            }
            else
            {
                index -= 3;
                skipColorCheck = true;
                state = PrintState::normal;
            }
            break;
            
        case PrintState::needEndOfColor:
            if (c != ';')
            {
                index -= 4;
                skipColorCheck = true;
            }
            state = PrintState::normal;
            break;
        }
    }
    
    return result;
}

bool ConsoleManager::charToColor (char c, int & color)
{
    switch (c)
    {
    case 'k':
        color = COLOR_BLACK;
        break;
    case 'r':
        color = COLOR_RED;
        break;
    case 'g':
        color = COLOR_GREEN;
        break;
    case 'y':
        color = COLOR_YELLOW;
        break;
    case 'b':
        color = COLOR_BLUE;
        break;
    case 'm':
        color = COLOR_MAGENTA;
        break;
    case 'c':
        color = COLOR_CYAN;
        break;
    case 'w':
        color = COLOR_WHITE;
        break;
    default:
        if (!Colors::useBrightColors)
        {
            return false;
        }
            
        switch (c)
        {
        case 'K':
            color = COLOR_BLACK + Colors::basicColorCount;
            break;
        case 'R':
            color = COLOR_RED + Colors::basicColorCount;
            break;
        case 'G':
            color = COLOR_GREEN + Colors::basicColorCount;
            break;
        case 'Y':
            color = COLOR_YELLOW + Colors::basicColorCount;
            break;
        case 'B':
            color = COLOR_BLUE + Colors::basicColorCount;
            break;
        case 'M':
            color = COLOR_MAGENTA + Colors::basicColorCount;
            break;
        case 'C':
            color = COLOR_CYAN + Colors::basicColorCount;
            break;
        case 'W':
            color = COLOR_WHITE + Colors::basicColorCount;
            break;
        default:
            return false;
        }
    }

    return true;
}

} // namespace Curses
} // namespace TUCUT
