#include "Buttons.h"

Buttons::Buttons(int pin) {
    adc_pin = pin;
    state = State::RELEASED;
    lastButton = Button::NONE;
    lastButtonMS = millis();
    pendingButton = Button::NONE;
    pendingMS = millis();
}
int Buttons::rawRead() {
    return analogRead(adc_pin);
}
int Buttons::getState() {
    return (int) state;
}
int Buttons::getButton() {
    return (int) lastButton;
}

UIEventId Buttons::getEvent() {
    UIEventId theEvent = UIEventId::NONE;

    int currentReading = analogRead(adc_pin);
    Button currentButton = which(currentReading);

    unsigned long now = millis();

    switch (state) {
        case State::RELEASED :
            if(currentButton != Button::NONE) {
                pendingButton = currentButton;
                pendingMS = now;
                state = State::PENDING;
            }
            break;
        case State::PENDING :
            if(currentButton == pendingButton) {
                if(now - pendingMS > BUTTON_DEBOUNCE) {
                    lastButton = currentButton;
                    lastButtonMS = now;
                    state = State::PRESSED;
                }
            } else {
                state = State::RELEASED;
            }
            break;
        case State::PRESSED :
            if(currentButton == lastButton) {
                if(now - lastButtonMS > BUTTON_HELD_DELAY) {
                    theEvent = heldEvent(currentButton);
                    state = State::HELD;
                    lastButtonMS = now;
                }
            }
            else {
                theEvent = releasedEvent(lastButton);
                lastButton = currentButton;
                lastButtonMS = now;
                state = State::RELEASED;
            }
            break;
        case State::HELD :
            if(currentButton == lastButton) {
                if(now - lastButtonMS > BUTTON_HELD_REPEAT) {
                    theEvent = heldEvent(currentButton);
                    lastButtonMS = now;
                }
            } else {
                // don't send an extra event when releasing 
                // an already held button
                lastButton = currentButton;
                lastButtonMS = now;
                state = State::RELEASED;
            }
            break;
        default:
        ;
    }
    return theEvent;
}

Buttons::Button Buttons::which(int reading) {
    // order is essential! Must be from smallest to largest MAX
    if(reading < BUTTON_RIGHT_MAX) return Button::RIGHT;
    if(reading < BUTTON_UP_MAX) return Button::UP;
    if(reading < BUTTON_DOWN_MAX) return Button::DOWN;
    if(reading < BUTTON_LEFT_MAX) return Button::LEFT;
    if(reading < BUTTON_SELECT_MAX) return Button::SELECT;
    return Button::NONE;
}

UIEventId Buttons::releasedEvent(Button theButton) {
    UIEventId theEvent;
    switch (theButton) {
        case Button::RIGHT :
            theEvent = UIEventId::BUTTON_RELEASE_RIGHT;
        break;
        case Button::UP :
            theEvent = UIEventId::BUTTON_RELEASE_UP;
        break;
        case Button::DOWN :
            theEvent = UIEventId::BUTTON_RELEASE_DOWN;
        break;
        case Button::LEFT :
            theEvent = UIEventId::BUTTON_RELEASE_LEFT;
        break;
        case Button::SELECT :
            theEvent = UIEventId::BUTTON_RELEASE_SELECT;
        break;
        default:
        theEvent =  UIEventId::NONE;
    }
    return theEvent;
}
UIEventId Buttons::heldEvent(Button theButton) {
    UIEventId theEvent;
    switch (theButton) {
        case Button::RIGHT :
            theEvent = UIEventId::BUTTON_HELD_RIGHT;
        break;
        case Button::UP :
            theEvent = UIEventId::BUTTON_HELD_UP;
        break;
        case Button::DOWN :
            theEvent = UIEventId::BUTTON_HELD_DOWN;
        break;
        case Button::LEFT :
            theEvent = UIEventId::BUTTON_HELD_LEFT;
        break;
        case Button::SELECT :
            theEvent = UIEventId::BUTTON_HELD_SELECT;
        break;
        default :
            theEvent = UIEventId::NONE;
    }
    return theEvent;
}