//  Button.h
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-05.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_TUI_Button_h
#define TUCUT_TUI_Button_h

#include "../Notify/EventPublisher.h"
#include "Control.h"
#include "Event.h"

#include <memory>

namespace TUCUT::TUI
{
  class Button : public Control
  {
  public:
    static int const ClickedEventId = 1;

    using ClickedEvent = Notify::EventPublisher<
      WindowSystem *, Button *>;

    static std::shared_ptr<Button> createSharedButton (
      std::string const & name,
      std::string const & text,
      int x,
      int y,
      int width,
      int height,
      Color const & foreColor,
      Color const & backColor,
      Color const & focusForeColor,
      Color const & focusBackColor);

    std::shared_ptr<Button> getSharedButton ();

    bool onKeyPress (WindowSystem * ws,
      CharacterEvent const & event) override;

    bool onNonPrintingKeyPress (WindowSystem * ws,
      NonPrintingCharacterEvent const & event) override;

    void onMouseEvent (WindowSystem * ws,
      MouseEvent const & event) override;

    void onDrawClient (WindowSystem * ws) const override;

    ClickedEvent * clicked ();

  protected:
    Button (std::string const & name,
      std::string const & text,
      int x,
      int y,
      int width,
      int height,
      Color const & foreColor,
      Color const & backColor,
      Color const & focusForeColor,
      Color const & focusBackColor);

    void initialize () override;

  private:
    void handleClick (WindowSystem * ws);

    std::string mText;
    std::unique_ptr<ClickedEvent> mClicked;
  };
} // namespace TUCUT::TUI

#endif // TUCUT_TUI_Button_h
