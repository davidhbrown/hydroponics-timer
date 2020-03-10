#pragma once
#include <Arduino.h>

/**
 * @brief Increment and decrement a value within bounds, optionally wrapping
 * 
 * I had thought I would template this, but it got too messy several classes in.
 * 
 */
class Value
{
private:
    uint16_t _value, _min, _max;
    bool _wrap;

public:
    Value(uint16_t min=0, uint16_t max=65535, bool wrap=true) : _value{min}, _min{min}, _max{max}, _wrap{wrap} {};
    uint16_t get();
    void set(uint16_t value);
    void increment();
    void incrementBy(uint8_t amount);
    void decrement();
    void decrementBy(uint8_t amount);
};