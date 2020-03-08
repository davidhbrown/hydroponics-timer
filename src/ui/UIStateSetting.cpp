#include "UIStateSetting.h"
#include "config.h"
#include "DLL.h"
#include "screen/Screen.h"

extern DLL<Screen> *screens;


UIStateSetting::UIStateSetting()
{
    didEnter = false;
}
UIStateId UIStateSetting::handleEvent(UIEventId theEventId)
{
    UIStateId nextState = UIStateId::IDLE; //that's me!
    if (!didEnter)
    {
        // enter:
        stateStarted = millis();
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
    {
        DLL<Screen> *next = screens->next();
        if (nullptr != next)
        {
            screens = next;
        }
        stateStarted = millis();
    }
    break;
    case UIEventId::BUTTON_RELEASE_LEFT:
    case UIEventId::BUTTON_HELD_LEFT:
    {
        DLL<Screen> *prev = screens->previous();
        if (nullptr != prev)
        {
            screens = prev;
        }
        stateStarted = millis();
    }
    break;
    case UIEventId::BUTTON_HELD_SELECT:
    {
        nextState = UIStateId::SETTING;
    }

    default:
        //other events just restart the idle timer
        stateStarted = millis();
        break;
    } // switch

    if (millis() - stateStarted > IDLE_TIMEOUT)
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