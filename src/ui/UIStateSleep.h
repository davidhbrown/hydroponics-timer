#pragma once
#include "UIState.h"
#include "UIEventId.h"

class UIStateSleep : public UIState
{
public:
  UIStateSleep(UIStateId id) : UIState{id} {};
  UIStateId handleEvent(UIEventId theEvent);
};
