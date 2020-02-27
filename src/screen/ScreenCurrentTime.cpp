#include "ScreenCurrentTime.h"
#include "config.h"

void ScreenCurrentTime::initLCD(LiquidCrystal *lcd) {
    lcd->setCursor(0,0);
    lcd->print("  Current Time  ");
    lcd->setCursor(0,1);
    lcd->print("01:00 AM   (OFF)");
}

void ScreenCurrentTime::updateLCD(LiquidCrystal *lcd) {

}
