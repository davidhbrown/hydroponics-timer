#include "SettingStorageURTCLib.h"

SettingStorageURTCLib::SettingStorageURTCLib(
    Value<uint8_t> *value,
    const SettingStorageURTCLibFields whichField,
    uRTCLib *rtc)
{
    _field = whichField;
    _rtc = rtc;
    _val = value;
};
void SettingStorageURTCLib::save()
{
    switch (_field)
    {
    case SECONDS:
        _rtc->set(_val->get(), _rtc->minute(), _rtc->hour(),
                  _rtc->dayOfWeek(), _rtc->day(), _rtc->month(), _rtc->year());
        break;
    case MINUTES:
        _rtc->set(_rtc->second(), _val->get(), _rtc->hour(),
                  _rtc->dayOfWeek(), _rtc->day(), _rtc->month(), _rtc->year());
        break;
    case HOURS:
        _rtc->set(_rtc->second(), _rtc->minute(), _val->get(),
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
        _val->set(_rtc->second());
        break;
    case MINUTES:
        _val->set(_rtc->minute());
        break;
    case HOURS:
        _val->set(_rtc->hour());
        break;
    }
};