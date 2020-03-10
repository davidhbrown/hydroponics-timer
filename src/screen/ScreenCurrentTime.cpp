#include "ScreenCurrentTime.h"

ScreenCurrentTime::ScreenCurrentTime(LiquidCrystal *lcd, uRTCLib *rtc) : ScreenLCD{lcd}
{
    Value _hv(0, 23, true), _mv(0, 59, true), _sv(0, 59, true);
    StorageURTCLib _hs(StorageURTCLibFields::HOURS, rtc),
        _ms(StorageURTCLibFields::MINUTES, rtc),
        _ss(StorageURTCLibFields::SECONDS, rtc);
    DisplayLCD2 _hd(lcd, 0, 1), _md(lcd, 3, 1), _sd(lcd, 6, 1);
    Setting _hset(&_hv, &_hd, &_hs), _mset(&_mv, &_md, &_ms), sset(&_sv, &_sd, &_ss);

    _settings = new List<Setting>();
    _settings->insert(&_hset);
    _settings->insert(&_mset);
    _settings->insert(&_sset);
    _settings->rewind();
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
    _lcd->setCursor(0, 1);
    _lcd->print(millis() / 1000);

    Serial.print('t');
    if (nullptr == _settings->get_item())
    {
        Serial.print('!');
    }
    else
    {
        _settings->get_item()->loadValue();
    }
    //*
    while (true)
    {
        Setting *setting = _settings->get_item();

        setting->loadValue();
        setting->displayValue();
        if (_settings->has_next())
        {
            _settings->iter_next();
        }
        else
        {
            break;
        }
    }
    //*/
}
