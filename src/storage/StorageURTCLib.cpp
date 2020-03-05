#include "StorageURTCLib.h"

StorageURTCLib::StorageURTCLib(
    StorageURTCLibFields whichField,
    uRTCLib *rtc)
{
    _field = whichField;
    _rtc = rtc;
}

void StorageURTCLib::save(Value *value)
{
    uint8_t v8 = (uint8_t)value->get();
    switch (_field)
    {
    case SECONDS:
        _rtc->set(v8, _rtc->minute(), _rtc->hour(),
                  _rtc->dayOfWeek(), _rtc->day(), _rtc->month(), _rtc->year());
        break;
    case MINUTES:
        _rtc->set(_rtc->second(), v8, _rtc->hour(),
                  _rtc->dayOfWeek(), _rtc->day(), _rtc->month(), _rtc->year());
        break;
    case HOURS:
        _rtc->set(_rtc->second(), _rtc->minute(), v8,
                  _rtc->dayOfWeek(), _rtc->day(), _rtc->month(), _rtc->year());
        break;
    }
}

void StorageURTCLib::load(Value *value)
{
    _rtc->refresh();
    switch (_field)
    {
    case SECONDS:
        value->set(_rtc->second());
        break;
    case MINUTES:
        value->set(_rtc->minute());
        break;
    case HOURS:
        value->set(_rtc->hour());
        break;
    }
}