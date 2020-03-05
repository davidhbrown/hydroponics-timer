#pragma once
#include "ScreenLCD.h"
#include "uRTCLib.h"
#include "DLL.h"
#include "setting/Setting.h"
#include "storage/StorageURTCLib.h"
#include "value/Value.h"
#include "display/DisplayLCD2.h"


class ScreenCurrentTime : public ScreenLCD {
    private:
    Setting *_hours, *_minutes, *_seconds;
    DisplayLCD2 *_hours_d, *_minutes_d, *_seconds_d;
    StorageURTCLib *_hours_ss, *_minutes_ss, *_seconds_ss;
    Value *_hours_v, *_minutes_v, *_seconds_v;
    protected:
    DLL<Setting> *_settings;
    public:
    ScreenCurrentTime(LiquidCrystal *lcd, uRTCLib *rtc);
    void initLCD();
    void updateLCD();
};