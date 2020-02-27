#pragma once
#include <Arduino.h>

template <class T> class Value {
    private:
        T value;
        T min, max;
    protected:
        bool wrap_inc_dec;
    public:
        Value(T min, T max, bool wrap);
        T get();
        void set(T value);
        void increment();
        void incrementBy(uint8_t amount);
        void decrement();
        void decrementBy(uint8_t amount);
};