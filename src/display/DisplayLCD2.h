#pragma once
#include "Display.h"
#include "value/Value.h"
#include <LiquidCrystal.h>
/** 
 * Allocates only 2 characters for its display...
 * adequate for 00-99, time segments, ...?
 */
class DisplayLCD2 : public Display
{
private:
    LiquidCrystal *_lcd;
    Value *_val;
    uint8_t _row, _col;

public:
    DisplayLCD2(LiquidCrystal *lcd, uint8_t row, uint8_t col);
    void display(Value *value);
    void active();
    void inactive();
};