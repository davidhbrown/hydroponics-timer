#pragma once
#include "Screen.h"

class ScreenTimer : public Screen {
    public:
    void initLCD(LiquidCrystal *lcd);
    void updateLCD(LiquidCrystal *lcd);
};