#pragma once
#include "Screen.h"

class ScreenLight : public Screen {
    public:
    void initLCD(LiquidCrystal *lcd);
    void updateLCD(LiquidCrystal *lcd);
};