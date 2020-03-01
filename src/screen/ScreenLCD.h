#pragma once
#include <LiquidCrystal.h>
#include "DLL.h"
#include "setting/Setting.h"

class ScreenLCD
{
private:
    DLL<Setting> *_settings;

public:
    virtual void initLCD(LiquidCrystal *lcd);
    virtual void updateLCD(LiquidCrystal *lcd);
    DLL<Setting> *getSettings();
    void setSettings(DLL<Setting> *settings);
};
