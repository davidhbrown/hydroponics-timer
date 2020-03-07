#pragma once
#include "ScreenLCD.h"

class ScreenTimer : public ScreenLCD
{
public:
    ScreenTimer(LiquidCrystal *lcd) : ScreenLCD{lcd} {};
    void init();
    void update();
};