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
    uint8_t _col, _row;

public:
    DisplayLCD(LiquidCrystal *lcd, uint8_t col, uint8_t row) : Display(), _lcd{lcd}, _col{col}, _row{row} {};
    void active();
    void inactive();
};