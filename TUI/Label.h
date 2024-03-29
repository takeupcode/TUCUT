//  Label.h
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-11.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_TUI_Label_h
#define TUCUT_TUI_Label_h

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
      Justification::Horizontal horizontal =
        Justification::Horizontal::Left,
      Justification::Vertical vertical =
        Justification::Vertical::Center,
      bool multiline = false);

    std::shared_ptr<Label> getSharedLabel ();

    void onDrawClient (WindowSystem * ws) const override;

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
      Justification::Horizontal horizontal,
      Justification::Vertical vertical,
      bool multiline);

  private:
    std::string mText;
    Justification::Horizontal mHorizontal;
    Justification::Vertical mVertical;
    bool mMultiline;
  };
} // namespace TUCUT::TUI

#endif // TUCUT_TUI_Label_h
