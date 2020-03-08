#pragma once

#include "UIEventId.h"
#include "UIStateId.h"

class UIState
{
protected:
  bool didEnter;
  unsigned long stateStarted;

public:
UIState():didEnter{false}, stateStarted{0L} {}
  virtual UIStateId handleEvent(UIEventId theEventId);
};
