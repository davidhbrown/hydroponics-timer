#pragma once
#include "ScreenLCD.h"

class ScreenMillis : public ScreenLCD
{
public:
    ScreenMillis(LiquidCrystal *lcd) : ScreenLCD{lcd} {};
    void init();
    void update();
};