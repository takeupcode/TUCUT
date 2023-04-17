//  NumberBox.cpp
//  TUCUT/TUI (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 2017-11-24.
//  Copyright © Take Up Code, Inc.
//
#include "NumberBox.h"

#include <sstream>
#include <stdexcept>

#include "Button.h"
#include "Colors.h"
#include "ConsoleManager.h"
#include "Justification.h"

namespace TUCUT {
namespace Curses {

const std::string NumberBox::windowName = "parent";
const std::string NumberBox::incrementButtonName = "incrementButton";
const std::string NumberBox::decrementButtonName = "decrementButton";

NumberBox::NumberBox (const std::string & name, int number, int y, int x, int width, int foreColor, int backColor)
: Control(name, y, x, 1, width, foreColor, backColor, foreColor, backColor),
  mText("0"), mNumberChanged(new NumberChangedEvent(NumberChangedEventId))
{
    if (width < 5)
    {
        throw std::out_of_range("width cannot be less than 5.");
    }

    mMinHeight = 1;
    mMinWidth = 5;

    setFillClientArea(false);

    setNumber(number);
}

void NumberBox::initialize ()
{
    Control::initialize();

    mIncrementButton = Button::createSharedButton(incrementButtonName, "+", 0, 0, 1, 1, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE);
    mIncrementButton->clicked()->connect(windowName, getSharedNumberBox());
    mIncrementButton->setIsDirectFocusPossible(false);

    mDecrementButton = Button::createSharedButton(decrementButtonName, "-", 0, 0, 1, 1, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE, Colors::COLOR_DIM_BLACK, Colors::COLOR_DIM_WHITE);
    mDecrementButton->clicked()->connect(windowName, getSharedNumberBox());
    mDecrementButton->setIsDirectFocusPossible(false);

    mIncrementButton->setAnchorTop(0);
    mIncrementButton->setAnchorRight(2);

    mDecrementButton->setAnchorTop(0);
    mDecrementButton->setAnchorRight(1);

    addControl(mIncrementButton);
    addControl(mDecrementButton);
}

std::shared_ptr<NumberBox> NumberBox::createSharedNumberBox (const std::string & name, int number, int y, int x, int width, int foreColor, int backColor)
{
    auto result = std::shared_ptr<NumberBox>(new NumberBox(name, number, y, x, width, foreColor, backColor));

    result->initialize();

    return result;
}

std::shared_ptr<NumberBox> NumberBox::getSharedNumberBox ()
{
    return std::static_pointer_cast<NumberBox>(shared_from_this());
}

bool NumberBox::onKeyPress (WindowSystem * ws, int key)
{
    if (enableState() != Window::EnableState::enabled)
    {
        return false;
    }

    switch (key)
    {
    case 127: // Delete
    case 8: // Backspace
    case KEY_DC:
    case KEY_BACKSPACE:
        if (removeChar())
        {
            handleNumberChange(ws);
        }
        break;

    case KEY_UP:
    case KEY_RIGHT:
    {
        int oldValue = number();

        increment();

        int newValue = number();

        if (newValue != oldValue)
        {
            handleNumberChange(ws);
        }
        break;
    }

    case KEY_DOWN:
    case KEY_LEFT:
    {
        int oldValue = number();

        decrement();

        int newValue = number();

        if (newValue != oldValue)
        {
            handleNumberChange(ws);
        }
        break;
    }

    default:
        if (addChar(key))
        {
            handleNumberChange(ws);
        }
        else if (parent())
        {
            return parent()->onKeyPress(ws, key);
        }
        break;
    }

    return true;
}

void NumberBox::onDrawClient () const
{
    if (visibleState() != Window::VisibleState::shown)
    {
        return;
    }

    ConsoleManager::printMessage(*this, 0, 1, textClientWidth(), mText, clientForeColor(), clientBackColor(), Justification::Horizontal::right, true);
}

int NumberBox::textClientWidth () const
{
    // This method accounts for the area used by the increment/decrement buttons and focus markers.
    return clientWidth() - 4;
}

void NumberBox::setMinWidth (int width)
{
    if (width < 5)
    {
        throw std::out_of_range("width cannot be less than 5.");
    }

    mMinWidth = width;
}

int NumberBox::number () const
{
    return std::stoi(mText);
}

void NumberBox::setNumber (int value)
{
    if (value < 0)
    {
        value = 0;
    }

    int currentValue = number();
    if (currentValue == value)
    {
        return;
    }

    std::ostringstream ss;
    ss << value;

    mText = ss.str();
}

void NumberBox::increment ()
{
    int value = number() + 1;

    setNumber(value);
}

void NumberBox::decrement ()
{
    int value = number() - 1;

    setNumber(value);
}

NumberBox::NumberChangedEvent * NumberBox::numberChanged ()
{
    return mNumberChanged.get();
}

void NumberBox::notify (int id, WindowSystem * ws, Button * button)
{
    if (id != Button::ClickedEventId)
    {
        return;
    }

    int oldValue = number();

    if (button->name() == incrementButtonName)
    {
        increment();
    }
    else if (button->name() == decrementButtonName)
    {
        decrement();
    }

    int newValue = number();

    if (newValue != oldValue)
    {
        handleNumberChange(ws);
    }
}

void NumberBox::handleNumberChange (WindowSystem * ws)
{
    mNumberChanged->signal(ws, this);
}

bool NumberBox::removeChar ()
{
    if (mText == "0")
    {
        return false;
    }

    mText.pop_back();
    if (mText.empty())
    {
        mText = "0";
    }

    return true;
}

bool NumberBox::addChar (int key)
{
    char c = static_cast<char>(key);
    if (c < '0' || c > '9')
    {
        return false;
    }

    if (mText == "0")
    {
        if (c == '0')
        {
            // We don't allow leading zeros.
            return false;
        }
        mText.clear();
    }

    mText.push_back(c);

    return true;
}

} // namespace Curses
} // namespace TUCUT
