#pragma once
#include "Display.h"
#include <LiquidCrystal.h>

/**
 * @brief Displays a value on a LiquidCrystal LCD, using the cursor to indicate active/inactive
 * 
 */
class DisplayLCD : public Display
{
protected:
    LiquidCrystal *_lcd;
    uint8_t _row, _col;

public:
    DisplayLCD(LiquidCrystal *lcd, uint8_t row, uint8_t col);
    void active();
    void inactive();
};