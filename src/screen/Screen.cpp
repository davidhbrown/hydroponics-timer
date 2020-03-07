#include "Screen.h"

Screen::Screen(DLL<Setting> *settings) : _settings{settings}{};
Setting *Screen::getCurrentSetting(){
    if(nullptr == _settings) return nullptr;
    return _settings->item();
};
void Screen::gotoFirstSetting(){
    if (nullptr == _settings) return;
    _settings=_settings->first();
};
void Screen::gotoNextSetting(){
    if (nullptr == _settings) return;
    DLL<Setting> *next = _settings->next();
    if(nullptr == next) return;
    _settings=next;
};
void Screen::gotoPreviousSetting(){
    if (nullptr == _settings) return;
    DLL<Setting> *prev = _settings->previous();
    if(nullptr == prev) return;
    _settings=prev;
};
void Screen::update()
{
    DLL<Setting > *settings = _settings->first();
    while(nullptr != settings) {
        Setting *setting = settings->item();
        setting->displayValue();
        settings = settings->next();
    }
}