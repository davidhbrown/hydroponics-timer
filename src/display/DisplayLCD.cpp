#include "DisplayLCD.h"


void DisplayLCD::active()
{
    _lcd->setCursor(_col, _row);
    _lcd->cursor();
}

void DisplayLCD::inactive()
{
    _lcd->noCursor();
}