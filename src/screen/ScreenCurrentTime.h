#pragma once
#include "Screen.h"

class ScreenCurrentTime : public Screen {
    public:
    void initLCD(LiquidCrystal *lcd);
    void updateLCD(LiquidCrystal *lcd);
};