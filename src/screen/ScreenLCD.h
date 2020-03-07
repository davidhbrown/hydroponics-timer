#pragma once
#include "Screen.h"
#include <LiquidCrystal.h>

class ScreenLCD : public Screen
{
protected:
    LiquidCrystal *_lcd;

public:
    ScreenLCD(LiquidCrystal *lcd);
};
