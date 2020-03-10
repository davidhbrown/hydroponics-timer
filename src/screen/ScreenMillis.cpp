#include "ScreenMillis.h"

void ScreenMillis::init() {
    _lcd->setCursor(0,0);
    _lcd->print("Milliseconds up ");
    _lcd->setCursor(0,1);
    _lcd->print("                ");
}

void ScreenMillis::update() {
    _lcd->setCursor(0,1);
    _lcd->print(millis());
}
