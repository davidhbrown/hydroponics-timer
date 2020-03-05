#pragma once
#include "ScreenLCD.h"

class ScreenLight : public ScreenLCD
{
public:
    ScreenLight(LiquidCrystal *lcd) : ScreenLCD{lcd} {};
    void initLCD();
    void updateLCD();
};