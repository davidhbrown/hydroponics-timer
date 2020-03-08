#pragma once

#include "UIState.h"
#include "UIEventId.h"

class UIStateSetting : public UIState
{
    public:
    UIStateSetting();
    UIStateId handleEvent(UIEventId theEventId);
};

