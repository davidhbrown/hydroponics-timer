#include "ScreenLight.h"

void ScreenLight::init() {
    _lcd->setCursor(0,0);
    _lcd->print("Light Lvl: 1023 ");
    _lcd->setCursor(0,1);
    _lcd->print("Off below:    0 ");
}

void ScreenLight::update() {

}
