#pragma once
#include "Display.h"
#include "value/Value.h"
#include <LiquidCrystal.h>

/** 
 * Accepts a ValueU16 but allocates only 4 characters for its display...
 * adequate for a 13-bit A/D if there were such a thing
 */
class DisplayLCD4 : public Display {
    private:
    LiquidCrystal *_lcd;
    Value<uint16_t> *_val;
    uint8_t _row, _col;
    public:
    DisplayLCD4(LiquidCrystal *lcd, Value<uint16_t> *value, uint8_t row, uint8_t col);
};