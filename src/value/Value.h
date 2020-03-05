#pragma once
#include <Arduino.h>

/**
 * @brief Increment and decrement a value within bounds, optionally wrapping
 * 
 * I had thought I would template this, but it got too messy several classes in.
 * 
 */
class Value {
    private:
        uint16_t _value, _min, _max;
        bool _wrap;
    public:
        Value(uint16_t min, uint16_t max, bool wrap);
        uint16_t get();
        void set(uint16_t value);
        void increment();
        void incrementBy(uint8_t amount);
        void decrement();
        void decrementBy(uint8_t amount);
};