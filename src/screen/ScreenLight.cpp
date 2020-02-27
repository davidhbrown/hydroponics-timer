#include "ScreenLight.h"
#include "config.h"

void ScreenLight::initLCD(LiquidCrystal *lcd) {
    lcd->setCursor(0,0);
    lcd->print("Light Lvl: 1023 ");
    lcd->setCursor(0,1);
    lcd->print("Off below:    0 ");
}

void ScreenLight::updateLCD(LiquidCrystal *lcd) {

}
