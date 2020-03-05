#include "ScreenTimer.h"

void ScreenTimer::initLCD() {
    _lcd->setCursor(0,0);
    _lcd->print("   Pump Timer   ");
    _lcd->setCursor(0,1);
    _lcd->print("0123456789ABCDEF");
}

void ScreenTimer::updateLCD() {

}
