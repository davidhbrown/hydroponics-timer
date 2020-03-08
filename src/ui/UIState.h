#pragma once

#include "UIEventId.h"
#include "UIStateId.h"

class UIState
{
protected:
  const UIStateId _SELF_STATE_ID;
  bool _didEnter;
  unsigned long _stateStartedMS;

public:
  UIState(UIStateId stateID) : _SELF_STATE_ID{stateID}, _didEnter{false}, _stateStartedMS{0L} {}
  UIStateId getUIStateId();
  virtual UIStateId handleEvent(UIEventId theEventId);
};
