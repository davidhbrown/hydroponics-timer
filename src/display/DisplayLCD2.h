#pragma once
#include "DisplayLCD.h"

/**
 * @brief Displays a value as two decimal digits on a LCD display, e.g., 00-99
 * 
 */
class DisplayLCD2 : public DisplayLCD
{
private:
    char _pad;

public:
    DisplayLCD2(LiquidCrystal *lcd=nullptr, uint8_t col=16, uint8_t row=2, char pad = ' ') : DisplayLCD{lcd, col, row}, _pad{pad} {};
    void display(Value *value);
};