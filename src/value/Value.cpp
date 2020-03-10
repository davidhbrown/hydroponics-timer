#include "Value.h"

uint16_t Value::get() {
    return _value;
}
void Value::set(uint16_t value) {
    if (value > _max) value = _max;
    if (value < _min) value = _min;
    _value = value;
}
void Value::increment() {
    incrementBy(1);
}
void Value::decrement() {
    decrementBy(1);
}
void Value::incrementBy(uint8_t amount) {
    if (_max - _value > amount) {
        _value = _wrap ? _min : _max;
    } else {
        _value += amount;
    }
}
void Value::decrementBy(uint8_t amount) {
    if (_value - _min > amount) {
        _value = _wrap ? _max : _min;
    } else {
        _value -= amount;
    }
}
