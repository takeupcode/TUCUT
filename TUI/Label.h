//  Label.h
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-11.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_Curses_Label_h
#define TUCUT_Curses_Label_h

#include "Justification.h"
#include "Control.h"

namespace TUCUT {
namespace Curses {

class Label : public Control
{
public:
    static std::shared_ptr<Label> createSharedLabel (std::string const & name, std::string const & text, int y, int x, int height, int width, int foreColor, int backColor, Justification::Horizontal horizontalJustification = Justification::Horizontal::left, Justification::Vertical verticalJustification = Justification::Vertical::center, bool multiline = false);

    std::shared_ptr<Label> getSharedLabel ();

    void onDrawClient () const override;

    void onDrawNonClient () const override;

    bool isMultiline () const;

    void setMultiline (bool multiline);

    std::string text () const;

    void setText (std::string const & text);

protected:
    Label (std::string const & name, std::string const & text, int y, int x, int height, int width, int foreColor, int backColor, Justification::Horizontal horizontalJustification, Justification::Vertical verticalJustification, bool multiline);

    void initialize () override;

private:
    std::string mText;
    Justification::Horizontal mHorizontalJustification;
    Justification::Vertical mVerticalJustification;
    bool mMultiline;
};

} // namespace Curses
} // namespace TUCUT

#endif // TUCUT_Curses_Label_h
