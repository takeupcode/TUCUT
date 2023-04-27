//  Control.h
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-24.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_TUI_Control_h
#define TUCUT_TUI_Control_h

#include "Window.h"

namespace TUCUT::TUI
{
  class Control : public Window
  {
  public:
    void onDrawNonClient (WindowSystem * ws) const override;

  protected:
    Control (std::string const & name,
      int x,
      int y,
      int width,
      int height,
      Color const & clientForeColor,
      Color const & clientBackColor,
      Color const & borderForeColor,
      Color const & borderBackColor,
      Color const & focusForeColor,
      Color const & focusBackColor,
      bool border);
  };
} // namespace TUCUT::TUI

#endif // TUCUT_TUI_Control_h
