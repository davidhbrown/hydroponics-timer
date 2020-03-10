#include "StorageURTCLib.h"

void StorageURTCLib::save(Value *value)
{
    uint8_t v8 = (uint8_t)value->get();
    switch (_field)
    {
    case StorageURTCLibFields::SECONDS:
        _rtc->set(v8, _rtc->minute(), _rtc->hour(),
                  _rtc->dayOfWeek(), _rtc->day(), _rtc->month(), _rtc->year());
        break;
    case StorageURTCLibFields::MINUTES:
        _rtc->set(_rtc->second(), v8, _rtc->hour(),
                  _rtc->dayOfWeek(), _rtc->day(), _rtc->month(), _rtc->year());
        break;
    case StorageURTCLibFields::HOURS:
        _rtc->set(_rtc->second(), _rtc->minute(), v8,
                  _rtc->dayOfWeek(), _rtc->day(), _rtc->month(), _rtc->year());
        break;
    default:; //oops?
    }
}

void StorageURTCLib::load(Value *value)
{
    Serial.println(F("StorageURTCLib is loading"));
    delay(100);
    if (nullptr == _rtc)
    {
        Serial.println(F("Failed to initialie rtc"));
    }
    delay(100);
    _rtc->refresh();
    switch (_field)
    {
    case StorageURTCLibFields::SECONDS:
        value->set(_rtc->second());
        break;
    case StorageURTCLibFields::MINUTES:
        value->set(_rtc->minute());
        break;
    case StorageURTCLibFields::HOURS:
        value->set(_rtc->hour());
        break;
    default:; //oops?
    }
}