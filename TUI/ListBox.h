//  ListBox.h
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-24.
//  Copyright © Take Up Code, Inc.
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

class ListBox : public Control, public Event::EventSubscriber<WindowSystem *, Button *>
{
public:
    static int const SelectionChangedEventId = 1;

    using SelectionChangedEvent = Event::EventPublisher<WindowSystem *, ListBox *>;

    static std::shared_ptr<ListBox> createSharedListBox (std::string const & name, std::vector<std::string> const & items, int y, int x, int height, int width, int foreColor, int backColor, int selectionForeColor, int selectionBackColor);

    std::shared_ptr<ListBox> getSharedListBox ();

    bool onKeyPress (WindowSystem * ws, int key) override;

    void onMouseEvent (WindowSystem * ws, short id, int y, int x, mmask_t buttonState) override;

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

    void setText (int index, std::string const & text);

    void appendItems (std::vector<std::string> const & items);

    void insertItems (int index, std::vector<std::string> const & items);

    SelectionChangedEvent * selectionChanged ();

protected:
    ListBox (std::string const & name, std::vector<std::string> const & items, int y, int x, int height, int width, int foreColor, int backColor, int selectionForeColor, int selectionBackColor);

    void initialize () override;

private:
    void notify (int id, WindowSystem * ws, Button * button) override;

    void handleSelectionChange (WindowSystem * ws);

    void moveSelectionUp ();
    void moveSelectionDown ();

    void ensureSelectionIsVisible ();

    static std::string const windowName;
    static std::string const moveSelectionUpButtonName;
    static std::string const moveSelectionDownButtonName;

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
