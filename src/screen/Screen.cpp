#include "Screen.h"
#include "config.h"

Screen::Screen()
{
    next = nullptr;
    previous = nullptr;
}

Screen *Screen::home = nullptr;
void Screen::setHome(Screen *theHomeScreen)
{
    Screen::home = theHomeScreen;
};
Screen *Screen::getHome()
{
    return home;
}

Screen *Screen::current = nullptr;
void Screen::setCurrent(Screen *theCurrentScreen)
{
    current = theCurrentScreen;
};
Screen *Screen::getCurrent()
{
    if(! current) {
        current = home;
    }
    return current;
}

void Screen::setNext(Screen *theNextScreen) {
    next = theNextScreen;
    if (! (theNextScreen->previous)) {
        theNextScreen->setPrevious(this);
    }
}

void Screen::setPrevious(Screen *thePreviousScreen) {
    previous = thePreviousScreen;
}
Screen *Screen::getNext()
{
    if (next)
    {
        return next;
    }
    else
    {
        return home;
    }
}
Screen *Screen::getPrevious()
{
    if (previous)
    {
        return previous;
    }
    else
    {
        return home;
    }
}