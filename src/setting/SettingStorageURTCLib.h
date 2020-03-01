#pragma once
#include "SettingStorage.h"
#include "Setting.h"
#include <Arduino.h>
#include "uRTClib.h"

/*
 * Currently handles only hours, minutes, seconds
 */
enum SettingStorageURTCLibFields {
    SECONDS,
    MINUTES,
    HOURS
};

class SettingStorageURTCLib : public SettingStorage {
    private:
    Setting *_setting;
    uRTCLib *_rtc;
    SettingStorageURTCLibFields _field;

    public:
    SettingStorageURTCLib(
        Setting *setting,
        const SettingStorageURTCLibFields whichField,
        uRTCLib *rtc
    );
    void save();
    void load();
};
