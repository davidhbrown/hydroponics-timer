#pragma once
#include "SettingStorage.h"
#include "value/Value.h"
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
    Value<uint8_t> *_val;
    uRTCLib *_rtc;
    SettingStorageURTCLibFields _field;

    public:
    SettingStorageURTCLib(
        Value<uint8_t> *value,
        const SettingStorageURTCLibFields whichField,
        uRTCLib *rtc
    );
    void save();
    void load();
};
