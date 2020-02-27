#include "UIStateIdle.h"
#include "../screen/Screen.h"
#include "config.h"

UIStateIdle::UIStateIdle()
{
    didEnter = false;
}
UIStateId UIStateIdle::handleEvent(UIEventId theEventId)
{
    UIStateId nextState = UIStateId::IDLE; //that's me!
    if (!didEnter)
    {
        // enter:
        idleStart = millis();
        digitalWrite(PIN_BACKLIGHT, HIGH);
        didEnter = true;
    }
    switch (theEventId)
    {
    case UIEventId::NONE:
        // do nothing
        break;

    case UIEventId::BUTTON_RELEASE_RIGHT:
    case UIEventId::BUTTON_HELD_RIGHT:
        Screen::setCurrent(Screen::getCurrent()->getNext());
        idleStart = millis();
        break;
    case UIEventId::BUTTON_RELEASE_LEFT:
    case UIEventId::BUTTON_HELD_LEFT:
        Screen::setCurrent(Screen::getCurrent()->getPrevious());
        idleStart = millis();
        break;
    default:
        //other events just restart the idle timer
        idleStart = millis();
        break;
    } // switch

    if (millis() - idleStart > IDLE_TIMEOUT)
    {
        nextState = UIStateId::SLEEP;
    }

    if (nextState != UIStateId::IDLE)
    {
        // exit:
        didEnter = false;
    }
    return nextState;
}