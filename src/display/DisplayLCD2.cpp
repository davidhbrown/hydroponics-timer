#include "DisplayLCD2.h"

DisplayLCD2::DisplayLCD2(
    LiquidCrystal *lcd, Value<uint8_t> *value, uint8_t row, uint8_t col)
{
    _lcd = lcd;
    _val = value;
    _row = row;
    _col = col;
};
void DisplayLCD2::display() {
    _lcd->setCursor(_col, _row);
    uint8_t v = _val->get();
    if(v>99) {
        _lcd->print(F("++"));
    } else if (v<10) {
        _lcd->print(F(" "));
        _lcd->print(v);
    } else {
        _lcd->print(v);
    }
    _lcd->setCursor(_col, _row);
}

void DisplayLCD2::active() {
        _lcd->setCursor(_col, _row);
    _lcd->cursor();
}

void DisplayLCD2::inactive() {
    _lcd->noCursor();
}