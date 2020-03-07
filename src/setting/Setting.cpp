#include "Setting.h"


Setting::Setting(Value *v, Display *d, Storage *s)
{
    _value = v;
    _display = d;
    _storage = s;
};

Value *Setting::getValue() { return _value; };
Display *Setting::getDisplay() { return _display; }
Storage *Setting::getStorage() { return _storage; }
void Setting::displayValue() {
    _display->display(_value);
}