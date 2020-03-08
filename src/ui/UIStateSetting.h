#pragma once

#include "UIState.h"

class UIStateSetting : public UIState
{
public:
    UIStateSetting(UIStateId id) : UIState{id} {};
    UIStateId handleEvent(UIEventId theEventId);
};
