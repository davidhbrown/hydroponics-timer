#pragma once
#include "SettingDisplay.h"
#include "value/ValueU16.h"
/** 
 * Accepts a ValueU16 but allocates only 4 characters for its display...
 * adequate for a 13-bit A/D if there were such a thing
 */
class SettingDisplayLCD4 : public SettingDisplay {
    private:
    ValueU16 *value;
    uint8_t row, col;
    public:
    SettingDisplayLCD4(ValueU16 value, uint8_t row, uint8_t col);
};