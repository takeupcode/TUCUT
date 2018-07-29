//
//  Label.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/11/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#include "Label.h"

#include "ConsoleManager.h"

namespace TUCUT {
namespace Curses {

Label::Label (const std::string & name, const std::string & text, int y, int x, int height, int width, int foreColor, int backColor, Justification::Horizontal horizontalJustification, Justification::Vertical verticalJustification, bool multiline)
: Control(name, y, x, height, width, foreColor, backColor, foreColor, backColor),
  mText(text), mHorizontalJustification(horizontalJustification), mVerticalJustification(verticalJustification),
  mMultiline(multiline)
{
    setIsDirectFocusPossible(false);
    
    setFillClientArea(false);
}

void Label::onDrawClient () const
{
    if (visibleState() != Window::VisibleState::shown)
    {
        return;
    }
    
    if (isMultiline())
    {
        std::vector<ConsoleManager::LineBreakpoint> lineBreakPoints = ConsoleManager::calculateLineBreakpoints (mText, clientWidth());
        int margin = 0;
        switch (mVerticalJustification)
        {
            case Justification::Vertical::top:
                margin = 0;
                break;
                
            case Justification::Vertical::center:
                margin = (clientHeight() - static_cast<int>(lineBreakPoints.size())) / 2;
                break;
                
            case Justification::Vertical::bottom:
                margin = clientHeight() - static_cast<int>(lineBreakPoints.size());
                break;
        }
        if (margin < 0)
        {
            margin = 0;
        }
        
        int i = 0;
        for (; i < margin; ++i)
        {
            ConsoleManager::printMessage(*this, i, 0, clientWidth(), " ", clientForeColor(), clientBackColor(), Justification::Horizontal::left, true);
        }
        for (auto & breakpoint: lineBreakPoints)
        {
            std::string lineText = mText.substr(breakpoint.beginIndex, breakpoint.endIndex - breakpoint.beginIndex + 1);
            ConsoleManager::printMessage(*this, i, 0, clientWidth(), lineText, clientForeColor(), clientBackColor(), mHorizontalJustification, true);
            ++i;
        }
        for (; i < clientHeight(); ++i)
        {
            ConsoleManager::printMessage(*this, i, 0, clientWidth(), " ", clientForeColor(), clientBackColor(), Justification::Horizontal::left, true);
        }
    }
    else
    {
        int vertCenter = clientHeight() / 2;
        ConsoleManager::printMessage(*this, vertCenter, 0, clientWidth(), mText, clientForeColor(), clientBackColor(), mHorizontalJustification, true);
    }
}

std::shared_ptr<Label> Label::createSharedLabel (const std::string & name, const std::string & text, int y, int x, int height, int width, int foreColor, int backColor, Justification::Horizontal horizontalJustification, Justification::Vertical verticalJustification, bool multiline)
{
    return std::shared_ptr<Label>(new Label(name, text, y, x, height, width, foreColor, backColor, horizontalJustification, verticalJustification, multiline));
}

std::shared_ptr<Label> Label::getSharedLabel ()
{
    return std::static_pointer_cast<Label>(shared_from_this());
}
    
void Label::onDrawNonClient () const
{ }

bool Label::isMultiline () const
{
    return mMultiline;
}

void Label::setMultiline (bool multiline)
{
    mMultiline = multiline;
}

} // namespace Curses
} // namespace TUCUT