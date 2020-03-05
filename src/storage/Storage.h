#pragma once
#include "value/Value.h"

class Storage
{
public:
    virtual void save(Value *value);
    virtual void load(Value *value);
};