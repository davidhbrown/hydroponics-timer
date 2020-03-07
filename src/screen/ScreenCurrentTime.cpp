#include "ScreenCurrentTime.h"

ScreenCurrentTime::ScreenCurrentTime(LiquidCrystal *lcd, uRTCLib *rtc) : ScreenLCD{lcd}
{
    _hours_v = new Value(0, 23, true);
    _minutes_v = new Value(0, 59, true);
    _seconds_v = new Value(0, 59, true);
    _hours_ss = new StorageURTCLib(HOURS, rtc);
    _minutes_ss = new StorageURTCLib(MINUTES, rtc);
    _seconds_ss = new StorageURTCLib(SECONDS, rtc);
    _hours_d = new DisplayLCD2(lcd, 1, 0);
    _minutes_d = new DisplayLCD2(lcd, 1, 3);
    _seconds_d = new DisplayLCD2(lcd, 1, 6);
    _hours = new Setting(_hours_v, _hours_d, _hours_ss);
    _minutes = new Setting(_minutes_v, _minutes_d, _minutes_ss);
    _seconds = new Setting(_seconds_v, _seconds_d, _seconds_ss);
    _settings = new DLL<Setting>(_hours);
    _settings->append(_minutes);
    _settings->append(_seconds);
}

void ScreenCurrentTime::init()
{
    _lcd->setCursor(0, 0);
    _lcd->print("  Current Time  ");
    _lcd->setCursor(0, 1);
    _lcd->print("01:00:00        ");
}

void ScreenCurrentTime::update()
{
    DLL<Setting> *settings = _settings->first();
    while(nullptr != settings) {
        settings->item()->getDisplay()->display(
            settings->item()->getValue()
        );
        settings = settings->next();
    }
}

