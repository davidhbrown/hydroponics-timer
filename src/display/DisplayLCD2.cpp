#include "DisplayLCD2.h"

DisplayLCD2::DisplayLCD2(
    LiquidCrystal *lcd, uint8_t row, uint8_t col) : Display()
{
    _lcd = lcd;
    _row = row;
    _col = col;
};
void DisplayLCD2::display(Value *val)
{
    _lcd->setCursor(_col, _row);
    uint8_t v = (uint8_t)val->get();
    if (v > 99)
    {
        _lcd->print(F("++"));
    }
    else if (v < 10)
    {
        _lcd->print(F(" "));
        _lcd->print(v);
    }
    else
    {
        _lcd->print(v);
    }
    _lcd->setCursor(_col, _row);
}

void DisplayLCD2::active()
{
    _lcd->setCursor(_col, _row);
    _lcd->cursor();
}

void DisplayLCD2::inactive()
{
    _lcd->noCursor();
}