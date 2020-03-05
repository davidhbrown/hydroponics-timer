#pragma once
#include <LiquidCrystal.h>
#include "DLL.h"
#include "setting/Setting.h"

class ScreenLCD
{
protected:
    LiquidCrystal *_lcd;
    DLL<Setting> *_settings;

public:
    ScreenLCD(LiquidCrystal *lcd) : _lcd{ lcd }, _settings{ nullptr }{};
    DLL<Setting> *getSettings();
    virtual void initLCD();
    virtual void updateLCD();
};
