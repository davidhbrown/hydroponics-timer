#include "UIStateRepository.h"

UIState *UIStateRepository::registeredStates[UISTATEID_COUNT];
UIState *UIStateRepository::getState(UIStateId theStateId){
    int index = (int) theStateId;
    return UIStateRepository::registeredStates[index];
};
void UIStateRepository::registerState(UIState *theState){
    int index = (int) theState->getUIStateId();
    UIStateRepository::registeredStates[index] = theState;
}