#include "Setting.h"


Value *Setting::getValue() { return _value; };
Display *Setting::getDisplay() { return _display; }
Storage *Setting::getStorage() { return _storage; }
void Setting::displayValue() {
    _display->display(_value);
}
void Setting::loadValue() {
    Serial.println(F("Setting::loadValue..."));
    if(nullptr == _value) {
        Serial.println(F("Setting has no Value"));
    }
    if(nullptr == _storage) {
        Serial.println(F("Setting has no Storage"));
    }
    delay(100);
    _storage->load(_value);
}
void Setting::saveValue() {
    _storage->save(_value);
}