//
//  ListBox.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 11/24/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Curses_ListBox_h
#define TUCUT_Curses_ListBox_h

#include <string>
#include <vector>

#include "../Event/EventPublisher.h"
#include "../Event/EventSubscriber.h"
#include "Control.h"

namespace TUCUT {
namespace Curses {

class Button;

class ListBox : public Control, public Event::EventSubscriber<GameManager *, Button *>
{
public:
    const static int SelectionChangedEventId = 1;
    
    using SelectionChangedEvent = Event::EventPublisher<GameManager *, ListBox *>;
    
    static std::shared_ptr<ListBox> createSharedListBox (const std::string & name, const std::vector<std::string> & items, int y, int x, int height, int width, int foreColor, int backColor, int selectionForeColor, int selectionBackColor);
    
    std::shared_ptr<ListBox> getSharedListBox ();
    
    bool onKeyPress (GameManager * gm, int key) override;
    
    void onMouseEvent (GameManager * gm, short id, int y, int x, mmask_t buttonState) override;
    
    void onDrawClient () const override;
    
    void onResize () override;
    
    int textClientWidth () const;
    
    void setMinHeight (int height) override;
    
    void setMinWidth (int width) override;
    
    int selectionForeColor () const;
    
    void setSelectionForeColor (int color);
    
    int selectionBackColor () const;
    
    void setSelectionBackColor (int color);
    
    int size () const;
    
    int selection () const;
    
    std::string text (int index) const;
    
    void setText (int index, const std::string & text);
    
    void appendItems (const std::vector<std::string> & items);
    
    void insertItems (int index, const std::vector<std::string> & items);
    
    SelectionChangedEvent * selectionChanged ();

protected:
    ListBox (const std::string & name, const std::vector<std::string> & items, int y, int x, int height, int width, int foreColor, int backColor, int selectionForeColor, int selectionBackColor);
    
    void initialize () override;

private:
    void notify (int id, GameManager * gm, Button * button) override;
    
    void handleSelectionChange (GameManager * gm);
    
    void moveSelectionUp ();
    void moveSelectionDown ();
    
    void ensureSelectionIsVisible ();
    
    static const std::string windowName;
    static const std::string moveSelectionUpButtonName;
    static const std::string moveSelectionDownButtonName;
    
    std::vector<std::string> mItems;
    std::unique_ptr<SelectionChangedEvent> mSelectionChanged;
    std::shared_ptr<Button> mMoveSelectionUpButton;
    std::shared_ptr<Button> mMoveSelectionDownButton;
    int mSelectionForeColor;
    int mSelectionBackColor;
    int mScrollItem;
    int mSelectionItem;
};
    
} // namespace Curses
} // namespace TUCUT

#endif // TUCUT_Curses_ListBox_h
