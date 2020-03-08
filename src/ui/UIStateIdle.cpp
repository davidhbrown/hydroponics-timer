#include "UIStateIdle.h"
#include "config.h"
#include "List.h"
#include "screen/Screen.h"

extern List<Screen> screens_list;

UIStateId UIStateIdle::handleEvent(UIEventId theEventId)
{
    UIStateId nextState = UIStateId::IDLE; //that's me!
    if (!_didEnter)
    {
        // enter:
        _stateStartedMS = millis();
        digitalWrite(PIN_BACKLIGHT, HIGH);
        _didEnter = true;
    }
    switch (theEventId)
    {
    case UIEventId::NONE:
        // do nothing
        break;

    case UIEventId::BUTTON_RELEASE_RIGHT:
    case UIEventId::BUTTON_HELD_RIGHT:
    {
        screens_list.iter_next();
        _stateStartedMS = millis();
    }
    break;
    case UIEventId::BUTTON_RELEASE_LEFT:
    case UIEventId::BUTTON_HELD_LEFT:
    {
        screens_list.iter_previous();
        _stateStartedMS = millis();
    }
    break;
    case UIEventId::BUTTON_HELD_SELECT:
    {
        nextState = UIStateId::SETTING;
    }

    default:
        //other events just restart the idle timer
        _stateStartedMS = millis();
        break;
    } // switch

    if (millis() - _stateStartedMS > IDLE_TIMEOUT_MS)
    {
        nextState = UIStateId::SLEEP;
    }

    if (nextState != UIStateId::IDLE)
    {
        // exit:
        _didEnter = false;
    }
    return nextState;
}