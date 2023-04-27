//  CheckBox.h
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-24.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_TUI_CheckBox_h
#define TUCUT_TUI_CheckBox_h

#include "../Notify/EventPublisher.h"
#include "Control.h"
#include "Event.h"

#include <memory>

namespace TUCUT::TUI
{
  class CheckBox : public Control
  {
  public:
    static int const ClickedEventId = 1;

    using ClickedEvent = Notify::EventPublisher<
      WindowSystem *, CheckBox *>;

    static std::shared_ptr<CheckBox> createSharedCheckBox (
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

    std::shared_ptr<CheckBox> getSharedCheckBox ();

    bool onKeyPress (WindowSystem * ws,
      CharacterEvent const & event) override;

    bool onNonPrintingKeyPress (WindowSystem * ws,
      NonPrintingCharacterEvent const & event) override;

    void onMouseEvent (WindowSystem * ws,
      MouseEvent const & event) override;

    void onDrawClient (WindowSystem * ws) const override;

    virtual bool isChecked () const;

    virtual void setIsChecked (bool value);

    ClickedEvent * clicked ();

  protected:
    CheckBox (std::string const & name,
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
    bool mIsChecked;
  };
} // namespace TUCUT::TUI

#endif // TUCUT_TUI_CheckBox_h
