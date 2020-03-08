#pragma once
#include "DisplayLCD.h"

/**
 * @brief Displays a value as two decimal digits on a LCD display, e.g., 00-99
 * 
 */
class DisplayLCD2 : public DisplayLCD
{
public:
    DisplayLCD2(LiquidCrystal *lcd, uint8_t row, uint8_t col) : DisplayLCD{lcd, row, col}{};
    void display(Value *value);
};