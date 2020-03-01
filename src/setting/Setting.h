#pragma once
#include "value/Value.h"
#include "display/Display.h"
#include "SettingStorage.h"

/* didn't work as a tempalte; need polymorphism
// or maybe to decide that a uint16_t can handle all cases?
*/
struct Setting{
    Value<uint16_t> *value;
    Display *display;
    SettingStorage *storage;
};
//*/
/*
class Setting {
    private:
    Value<uint16_t> *_value;
    Display *_display;
    SettingStorage *_storage;
    public:
    Setting(Value<uint16_t> *v, Display *d, SettingStorage *s);
    Value<uint16_t> *getValue();
    Display *getDisplay();
    SettingStorage *getStorage();
};
*/