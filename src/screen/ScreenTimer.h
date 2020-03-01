#pragma once
#include "ScreenLCD.h"

class ScreenTimer : public ScreenLCD {
    public:
    void initLCD(LiquidCrystal *lcd);
    void updateLCD(LiquidCrystal *lcd);
};