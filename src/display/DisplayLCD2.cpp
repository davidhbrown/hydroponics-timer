#include "DisplayLCD2.h"

void DisplayLCD2::display(Value *val)
{
    _lcd->setCursor(_col, _row);
    uint8_t v = (uint8_t)val->get();
    if (v > 99)
    {
        _lcd->print(F(">>"));
    }
    else if (v < 10)
    {
        _lcd->print(_pad);
        _lcd->print(v);
    }
    else
    {
        _lcd->print(v);
    }
    _lcd->setCursor(_col, _row);
}
