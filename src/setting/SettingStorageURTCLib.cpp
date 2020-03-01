#include "SettingStorageURTCLib.h"

SettingStorageURTCLib::SettingStorageURTCLib(
    Setting *setting,
    const SettingStorageURTCLibFields whichField,
    uRTCLib *rtc)
{
    _field = whichField;
    _rtc = rtc;
    _setting = setting;
};
void SettingStorageURTCLib::save()
{
    uint8_t value = (uint8_t) _setting->value->get();
    switch (_field)
    {
    case SECONDS:
        _rtc->set(value, _rtc->minute(), _rtc->hour(),
                  _rtc->dayOfWeek(), _rtc->day(), _rtc->month(), _rtc->year());
        break;
    case MINUTES:
        _rtc->set(_rtc->second(), value, _rtc->hour(),
                  _rtc->dayOfWeek(), _rtc->day(), _rtc->month(), _rtc->year());
        break;
    case HOURS:
        _rtc->set(_rtc->second(), _rtc->minute(), value,
                  _rtc->dayOfWeek(), _rtc->day(), _rtc->month(), _rtc->year());
        break;    
    }
};
void SettingStorageURTCLib::load()
{
    _rtc->refresh();
    switch (_field)
    {
    case SECONDS:
        _setting->value->set(_rtc->second());
        break;
    case MINUTES:
        _setting->value->set(_rtc->minute());
        break;
    case HOURS:
        _setting->value->set(_rtc->hour());
        break;
    }
};