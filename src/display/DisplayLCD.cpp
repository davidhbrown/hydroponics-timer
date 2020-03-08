#include "DisplayLCD.h"

DisplayLCD::DisplayLCD(
    LiquidCrystal *lcd, uint8_t row, uint8_t col) : Display(), _lcd{lcd}, _row{row}, _col{col} {};

void DisplayLCD::active()
{
    _lcd->setCursor(_col, _row);
    _lcd->cursor();
}

void DisplayLCD::inactive()
{
    _lcd->noCursor();
}