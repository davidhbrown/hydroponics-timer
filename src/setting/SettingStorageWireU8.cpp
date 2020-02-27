#include "SettingStorageWireU8.h"

SettingStorageWireU8::SettingStorageWireU8(
    Value<uint8_t> *value,
    uint8_t device_address,
    uint8_t register_address)
{
    val = value;
    dev_addr = device_address;
    reg_addr = register_address;
};
void SettingStorageWireU8::save() {

};
void SettingStorageWireU8::load() {

};