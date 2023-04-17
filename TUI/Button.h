//  Button.h
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-05.
//  Copyright © Take Up Code, Inc.
//
#ifndef TUCUT_Curses_Button_h
#define TUCUT_Curses_Button_h

#include <memory>

#include "../Event/EventPublisher.h"
#include "Control.h"

namespace TUCUT {
namespace Curses {

class Button : public Control
{
public:
    const static int ClickedEventId = 1;

    using ClickedEvent = Event::EventPublisher<WindowSystem *, Button *>;

    static std::shared_ptr<Button> createSharedButton (const std::string & name, const std::string & text, int y, int x, int height, int width, int foreColor, int backColor, int focusForeColor, int focusBackColor);

    std::shared_ptr<Button> getSharedButton ();

    bool onKeyPress (WindowSystem * ws, int key) override;

    void onMouseEvent (WindowSystem * ws, short id, int y, int x, mmask_t buttonState) override;

    void onDrawClient () const override;

    ClickedEvent * clicked ();

protected:
    Button (const std::string & name, const std::string & text, int y, int x, int height, int width, int foreColor, int backColor, int focusForeColor, int focusBackColor);

    void initialize () override;

private:
    void handleClick (WindowSystem * ws);

    std::string mText;
    std::unique_ptr<ClickedEvent> mClicked;
};

} // namespace Curses
} // namespace TUCUT

#endif // TUCUT_Curses_Button_h
