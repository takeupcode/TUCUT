//
//  CheckBox.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/24/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Curses_CheckBox_h
#define TUCUT_Curses_CheckBox_h

#include <memory>

#include "../Event/EventPublisher.h"
#include "Control.h"

namespace TUCUT {
namespace Curses {

class CheckBox : public Control
{
public:
    const static int ClickedEventId = 1;
    
    using ClickedEvent = Event::EventPublisher<GameManager *, CheckBox *>;
    
    static std::shared_ptr<CheckBox> createSharedCheckBox (const std::string & name, const std::string & text, int y, int x, int height, int width, int foreColor, int backColor, int focusForeColor, int focusBackColor);
    
    std::shared_ptr<CheckBox> getSharedCheckBox ();
    
    bool onKeyPress (GameManager * gm, int key) override;
    
    void onMouseEvent (GameManager * gm, short id, int y, int x, mmask_t buttonState) override;
    
    void onDrawClient () const override;
    
    virtual bool isChecked () const;
    
    virtual void setIsChecked (bool value);
    
    ClickedEvent * clicked ();

protected:
    CheckBox (const std::string & name, const std::string & text, int y, int x, int height, int width, int foreColor, int backColor, int focusForeColor, int focusBackColor);
    
    void initialize () override;

private:
    void handleClick (GameManager * gm);
    
    std::string mText;
    std::unique_ptr<ClickedEvent> mClicked;
    bool mIsChecked;
};
    
} // namespace Curses
} // namespace TUCUT

#endif // TUCUT_Curses_CheckBox_h
