#pragma once
#include "ScreenLCD.h"

class ScreenLight : public ScreenLCD {
    public:
    void initLCD(LiquidCrystal *lcd);
    void updateLCD(LiquidCrystal *lcd);
};