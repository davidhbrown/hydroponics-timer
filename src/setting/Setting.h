#pragma once

#include "value/Value.h"
#include "display/Display.h"
#include "storage/Storage.h"

/*
// forward declare instead of #include (http://www.cplusplus.com/forum/articles/10627/) ?
class Value;
class Display;
class Storage;
*/

class Setting {
    private:
    Value *_value;
    Display *_display;
    Storage *_storage;
    public:
    Setting(Value *v=nullptr, Display *d=nullptr, Storage *s=nullptr) : _value{v}, _display{d}, _storage{s}{};
    Value *getValue();
    Display *getDisplay();
    Storage *getStorage();
    void displayValue();
    void loadValue();
    void saveValue();
};
