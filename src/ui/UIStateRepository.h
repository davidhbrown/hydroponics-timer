#ifndef UISTATEREPOSITORY_H
#define UISTATEREPOSITORY_H

#include "UIState.h"

class UIStateRepository {
private:
    static UIState *registeredStates[];
public:
    static void registerState(UIState *theState);
    static UIState* getState(UIStateId theStateId);
};

#endif // UISTATEREPOSITORY_H