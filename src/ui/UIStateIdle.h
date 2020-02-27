#ifndef STATEIDLE_H
#define STATEIDLE_H

#include "UIState.h"
#include "UIEventId.h"

class UIStateIdle : public UIState
{
    private:
        bool didEnter;
        unsigned long idleStart;
    public:
    UIStateIdle();
    UIStateId handleEvent(UIEventId theEventId);
};


#endif  //STATEIDLE_H