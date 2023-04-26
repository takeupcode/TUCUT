//  Justification.h
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-16.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_TUI_Justification_h
#define TUCUT_TUI_Justification_h

namespace TUCUT::TUI
{
  struct Justification
  {
    enum class Horizontal
    {
      Left,
      Center,
      Right
    };

    enum class Vertical
    {
      Top,
      Center,
      Bottom
    };
  };
} // namespace TUCUT::TUI

#endif // TUCUT_TUI_Justification_h
