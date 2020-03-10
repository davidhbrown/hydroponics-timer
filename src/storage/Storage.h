#pragma once
#include "value/Value.h"

class Storage
{
public:
    Storage(){};
    virtual void save(Value *value);
    virtual void load(Value *value);
};