#pragma once

#include "UIState.h"
#include "UIEventId.h"

class UIStateIdle : public UIState
{
public:
    UIStateIdle(UIStateId id) : UIState{id} {};
    UIStateId handleEvent(UIEventId theEventId);
};
