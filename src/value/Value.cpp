#include "Value.h"

template <class T> Value<T>::Value(T mn, T mx, bool wrap) {
    min = mn;
    max = mx;
    wrap_inc_dec = wrap;
    value = min;
};

template <class T> T Value<T>::get() {
    return value;
}
template <class T> void Value<T>::set(T v) {
    if (v > max) v = max;
    if (v < min) v = min;
    value = v;
}
template <class T> void Value<T>::increment() {
    incrementBy(1);
}
template <class T> void Value<T>::decrement() {
    decrementBy(1);
}
template <class T> void Value<T>::incrementBy(uint8_t amount) {
    if (max - value > amount) {
        value = wrap_inc_dec ? min : max;
    } else {
        value += amount;
    }
}
template <class T> void Value<T>::decrementBy(uint8_t amount) {
    if (value - min > amount) {
        value = wrap_inc_dec ? max : min;
    } else {
        value -= amount;
    }
}

//template class Value<uint8_t>;
template class Value<uint16_t>;