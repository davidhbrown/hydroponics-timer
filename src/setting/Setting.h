#pragma once
#include "value/Value.h"
#include "display/Display.h"
#include "SettingStorage.h"

template <class T>
class Setting {
    protected:
    Value<T> *value;
    Display *display;
    public:
    Setting(Value<T> *v, Display *d, SettingStorage *s);
};