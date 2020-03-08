#include "UIStateSetting.h"
#include "config.h"
#include "List.h"
#include "screen/Screen.h"

UIStateId UIStateSetting::handleEvent(UIEventId theEventId)
{
    UIStateId nextState = _SELF_STATE_ID; 
    if (!_didEnter)
    {
        // enter:
        _stateStartedMS = millis();
        /** @todo activate current setting */
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
        /** @todo save setting */
        /** @todo deactivate current setting */
//        screens->item()->gotoNextSetting();
        _stateStartedMS = millis();
    }
    break;
    case UIEventId::BUTTON_RELEASE_LEFT:
    case UIEventId::BUTTON_HELD_LEFT:
    {
        /** @todo save setting */
        /** @todo deactivate current setting */
//        screens->item()->gotoPreviousSetting();
        _stateStartedMS = millis();
    }
    break;

    default:
        //other events just restart the idle timer
//        _stateStartedMS = millis();
        break;
    } // switch

    if (millis() - _stateStartedMS > SETTING_TIMEOUT_MS)
    {
        /** @todo save setting */
        nextState = UIStateId::IDLE;
    }

    if (nextState != _SELF_STATE_ID)
    {
        // exit:
        _didEnter = false;
    }
    return nextState;
}