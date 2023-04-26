//  NumberBox.h
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-24.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_TUI_NumberBox_h
#define TUCUT_TUI_NumberBox_h

#include <string>

#include "../Event/EventPublisher.h"
#include "../Event/EventSubscriber.h"
#include "Control.h"

namespace TUCUT::TUI
{
  class Button;

  class NumberBox : public Control, public Event::EventSubscriber<WindowSystem *, Button *>
  {
  public:
    static int const NumberChangedEventId = 1;

    using NumberChangedEvent = Event::EventPublisher<WindowSystem *, NumberBox *>;

    static std::shared_ptr<NumberBox> createSharedNumberBox (
      std::string const & name,
      int number,
      int x,
      int y,
      int width,
      Color const & foreColor,
      Color const & backColor);

    std::shared_ptr<NumberBox> getSharedNumberBox ();

    bool onKeyPress (WindowSystem * ws, int key) override;

    void onDrawClient () const override;

    int textClientWidth () const;

    void setMinWidth (int width) override;

    int number () const;

    void setNumber (int value);

    void increment ();

    void decrement ();

    NumberChangedEvent * numberChanged ();

  protected:
    NumberBox (std::string const & name,
      int number,
      int x,
      int y,
      int width,
      Color const & foreColor,
      Color const & backColor);

    void initialize () override;

  private:
    void notify (int id, WindowSystem * ws, Button * button) override;

    void handleNumberChange (WindowSystem * ws);

    bool removeChar ();
    bool addChar (int key);

    static std::string const windowName;
    static std::string const incrementButtonName;
    static std::string const decrementButtonName;

    std::string mText;
    std::unique_ptr<NumberChangedEvent> mNumberChanged;
    std::shared_ptr<Button> mIncrementButton;
    std::shared_ptr<Button> mDecrementButton;
  };
} // namespace TUCUT::TUI

#endif // TUCUT_TUI_NumberBox_h
