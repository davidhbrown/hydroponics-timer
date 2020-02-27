#pragma once
#include "value/Value.h"
#include "SettingDisplay.h"
#include "SettingStorage.h"

class Setting {
    protected:
    Value *value;
    SettingDisplay *display;
    public:
    Setting(Value *v, SettingDisplay *d, SettingStorage *s);
};