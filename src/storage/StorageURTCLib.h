#pragma once
#include "Storage.h"
#include "value/Value.h"
#include <Arduino.h>
#include "uRTClib.h"

/*
 * Currently handles only hours, minutes, seconds
 */
enum StorageURTCLibFields
{
    SECONDS,
    MINUTES,
    HOURS
};

class StorageURTCLib : public Storage
{
private:
    StorageURTCLibFields _field;
    uRTCLib *_rtc;
public:
    StorageURTCLib(
        StorageURTCLibFields whichField,
        uRTCLib *rtc);
    void save(Value *value);
    void load(Value *value);
};
