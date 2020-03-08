#pragma once

#include "UIState.h"
#include "UIEventId.h"

class UIStateIdle : public UIState
{
    private:
        bool didEnter;
        unsigned long stateStarted;
    public:
    UIStateIdle();
    UIStateId handleEvent(UIEventId theEventId);
};


