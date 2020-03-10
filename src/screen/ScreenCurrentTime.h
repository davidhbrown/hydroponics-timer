#pragma once
#include "ScreenLCD.h"
#include "uRTCLib.h"
#include "List.h"
#include "setting/Setting.h"
#include "storage/StorageURTCLib.h"
#include "value/Value.h"
#include "display/DisplayLCD2.h"


class ScreenCurrentTime : public ScreenLCD {
    private:
    StorageURTCLib _hs, _ms, _ss;
    Value _hv, _mv, _sv;
    DisplayLCD2 _hd, _md, _sd;
    Setting _hset, _mset, _sset;
    protected:
    List<Setting> *_settings;
    public:
    ScreenCurrentTime(LiquidCrystal *lcd, uRTCLib *rtc) ;
    void init();
    void update();
};