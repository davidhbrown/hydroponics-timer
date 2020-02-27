#pragma once
#include "config.h"
#include "ui/UIEventId.h"

class Buttons {
    private:
        int adc_pin;
        enum Button {
            NONE, RIGHT, UP, DOWN, LEFT, SELECT
        };
        enum State {
            RELEASED, PENDING, PRESSED, HELD
        };
        Button lastButton;
        unsigned long lastButtonMS;
        State state;
        Button pendingButton;
        unsigned long pendingMS;
        static Button which(int reading);
        static UIEventId releasedEvent(Button theButton);
        static UIEventId heldEvent(Button theButton);
    public:
        Buttons(int pin);
        UIEventId getEvent();
        int rawRead();
        int getState();
        int getButton();
};

