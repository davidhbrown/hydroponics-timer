#pragma once
#include "Setting.h"
class Settings
{
private:
    Setting *setting;
    Settings *next;

public:
    Settings(Setting *setting);
    void setNext(Settings *next);
    Settings *getNext();
    Setting *setting();
};