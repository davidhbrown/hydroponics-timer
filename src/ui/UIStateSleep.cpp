#include "config.h"
#include "UIStateSleep.h"

UIStateSleep::UIStateSleep() {
    didEnter = false;
}
UIStateId UIStateSleep::handleEvent(UIEventId theEventId){
    UIStateId nextState = UIStateId::SLEEP; //that's me!
    if(!didEnter) {
        // enter:
        digitalWrite(PIN_BACKLIGHT, LOW);
        didEnter=true;
    }
    switch (theEventId)
    {
        case UIEventId::NONE:
            /* code */
        break;

        default:
            nextState = UIStateId::IDLE;
        break;
    }

    if(nextState != UIStateId::SLEEP) {
        // exit:
        didEnter = false;
        digitalWrite(PIN_BACKLIGHT, HIGH);
    }
    return nextState;
};
