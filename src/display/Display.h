#pragma once
#include "value/Value.h"

class Display{
    public:
    virtual void display(Value *value) = 0;
    virtual void active() = 0;
    virtual void inactive() = 0;
};