#include "config.h"
#include "UIStateSleep.h"
#include "List.h"
#include "screen/Screen.h"

extern List<Screen> screens_list;

UIStateId UIStateSleep::handleEvent(UIEventId theEventId)
{
    UIStateId nextState = UIStateId::SLEEP; //that's me!
    if (!_didEnter)
    {
        // enter:
        digitalWrite(PIN_BACKLIGHT, LOW);
        _didEnter = true;
    }
    switch (theEventId)
    {
    case UIEventId::NONE:
        screens_list.get_item()->update();
        break;

    default:
        nextState = UIStateId::IDLE;
        break;
    }

    if (nextState != UIStateId::SLEEP)
    {
        // exit:
        _didEnter = false;
        digitalWrite(PIN_BACKLIGHT, HIGH);
    }
    return nextState;
};
