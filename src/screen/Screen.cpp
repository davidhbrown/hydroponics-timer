#include "Screen.h"

Setting *Screen::getCurrentSetting(){
    if(nullptr == _settings) return nullptr;
    return _settings->get_item();
};
void Screen::gotoFirstSetting(){
    if (nullptr == _settings) return;
    _settings->rewind();
};
void Screen::gotoNextSetting(){
    if (nullptr == _settings) return;
    if(_settings->has_next()) {
        _settings->iter_next();
    }
};
void Screen::gotoPreviousSetting(){
    _settings->iter_previous();
};
/*
void Screen::update()
{
    Serial.print('^');
    if (nullptr == _settings) return;
    _settings->rewind();
    while(true) {
        Setting *setting = _settings->get_item();
        if(nullptr != setting) {
            setting->displayValue();
        }
        if(!_settings->has_next()) {
            break;
        }
        _settings->iter_next();
    }
}
    */
