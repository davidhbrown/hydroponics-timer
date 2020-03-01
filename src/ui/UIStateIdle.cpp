#include "UIStateIdle.h"
#include "config.h"
#include "DLL.h"
#include "screen/ScreenLCD.h"

extern DLL<ScreenLCD> *screens;

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
        screens = screens->next();
        idleStart = millis();
        break;
    case UIEventId::BUTTON_RELEASE_LEFT:
    case UIEventId::BUTTON_HELD_LEFT:
        screens = screens->previous();
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