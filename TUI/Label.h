//  Label.h
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-11.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_TUI_Label_h
#define TUCUT_TUI_Label_h

#include "Justification.h"
#include "Control.h"

namespace TUCUT::TUI
{
  class Label : public Control
  {
  public:
    static std::shared_ptr<Label> createSharedLabel (
      std::string const & name,
      std::string const & text,
      int x,
      int y,
      int width,
      int height,
      Color const & foreColor,
      Color const & backColor,
      Justification::Horizontal horizontalJustification =
        Justification::Horizontal::left,
      Justification::Vertical verticalJustification =
        Justification::Vertical::center,
      bool multiline = false);

    std::shared_ptr<Label> getSharedLabel ();

    void onDrawClient () const override;

    void onDrawNonClient () const override;

    bool isMultiline () const;

    void setMultiline (bool multiline);

    std::string text () const;

    void setText (std::string const & text);

  protected:
    Label (std::string const & name,
      std::string const & text,
      int x,
      int y,
      int width,
      int height,
      Color const & foreColor,
      Color const & backColor,
      Justification::Horizontal horizontalJustification,
      Justification::Vertical verticalJustification,
      bool multiline);

    void initialize () override;

  private:
    std::string mText;
    Justification::Horizontal mHorizontalJustification;
    Justification::Vertical mVerticalJustification;
    bool mMultiline;
  };
} // namespace TUCUT::TUI

#endif // TUCUT_TUI_Label_h
