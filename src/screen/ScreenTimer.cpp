#include "ScreenTimer.h"
#include "config.h"

void ScreenTimer::initLCD(LiquidCrystal *lcd) {
    lcd->setCursor(0,0);
    lcd->print("   Pump Timer   ");
    lcd->setCursor(0,1);
    lcd->print("0123456789ABCDEF");
}

void ScreenTimer::updateLCD(LiquidCrystal *lcd) {

}
