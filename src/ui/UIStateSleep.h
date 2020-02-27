#pragma once
#include "UIState.h"
#include "UIEventId.h"


class UIStateSleep : public UIState
{
private:
        bool didEnter;
public:
  UIStateSleep();
  UIStateId handleEvent(UIEventId theEvent);
};

