#pragma once
#include <LiquidCrystal.h>

class Screen {
    private:
    // a default, starting screen
    static Screen *home;
    // the screen currently displayed
    static Screen *current;
    Screen *next;
    Screen *previous;
    public:
    Screen();
    virtual void initLCD(LiquidCrystal *lcd);
    virtual void updateLCD(LiquidCrystal *lcd);
    static Screen *getHome();
    static Screen *getCurrent();
    void static setHome(Screen *theHomeScreen);
    void static setCurrent(Screen *theCurrent);
    void setNext(Screen *theNextScreen);
    void setPrevious(Screen *thePreviousScreen);
    Screen *getNext();
    Screen *getPrevious();
};
