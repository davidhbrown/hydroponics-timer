#include "SettingStorage.h"
#include "value/Value.h"
#include <Arduino.h>
#include <Wire.h>

class SettingStorageWireU8 : protected SettingStorage {
    private:
    Value<uint8_t> *val;
    uint8_t dev_addr, reg_addr;
    public:
    SettingStorageWireU8(
        Value<uint8_t> *value,
        uint8_t device_address,
        uint8_t register_address
    );

};