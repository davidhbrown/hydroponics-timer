#pragma once
#include "ScreenLCD.h"

class ScreenCurrentTime : public ScreenLCD {
    public:
    void initLCD(LiquidCrystal *lcd);
    void updateLCD(LiquidCrystal *lcd);
};