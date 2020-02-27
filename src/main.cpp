/*
Digital Timer for Hydroponics Pump
David H. Brown
2020-02-21
*/

#include "config.h"

#include <LiquidCrystal.h>
LiquidCrystal lcd( PIN_RS,  PIN_EN,  PIN_D4,  PIN_D5,  PIN_D6,  PIN_D7);

#include "ui/UIStateId.h"
UIStateId currentStateId;

#include "ui/UIStateRepository.h"
#include "ui/UIStateIdle.h"
#include "ui/UIStateSleep.h"
#include "Buttons.h"
Buttons lcdButtons(PIN_BUTTONS);

#define EVENTS 5
UIEventId events[EVENTS];
int eventsIndex = 0;

#include "screen/ScreenCurrentTime.h"
#include "screen/ScreenTimer.h"
#include "screen/ScreenLight.h"
#include "screen/Screen.h"
ScreenCurrentTime screenCurrentTime = ScreenCurrentTime();
ScreenTimer screenTimer = ScreenTimer();
ScreenLight screenLight = ScreenLight();
Screen *previousScreen = nullptr;

void setup() {
  for(int i=0; i < EVENTS;i++) {
    events[i]=UIEventId::NONE;
  }
  // set up the LCD's number of columns and rows:
  pinMode( PIN_BACKLIGHT, OUTPUT); 
  digitalWrite(PIN_BACKLIGHT, HIGH); // turn backlight on
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print(" Digital Timer  ");
  lcd.setCursor(0,1);
  lcd.print("Hydroponics Pump");
  delay(2000);
  UIStateRepository::registerState(UIStateId::IDLE, new UIStateIdle());
  UIStateRepository::registerState(UIStateId::SLEEP, new UIStateSleep());
  currentStateId = UIStateId::IDLE;
  screenCurrentTime.setNext(& screenTimer);
  screenTimer.setNext(& screenLight);
  Screen::setHome(& screenCurrentTime);
}

void loop() {
  // initialize current event
  UIEventId currentEventId = lcdButtons.getEvent();

  UIState *state = UIStateRepository::getState(currentStateId);
  currentStateId = state->handleEvent(currentEventId);

// tried to make this behavior Screen's responsibility, but setCurrent
// doesn't have a parameter for the LCD and it seems like it should
// stay independent of that. Maybe need an ScreenManager ABC
  if(previousScreen != Screen::getCurrent()) {
    previousScreen = Screen::getCurrent();
    Screen::getCurrent()->initLCD(&lcd);
  }
  Screen::getCurrent()->updateLCD(&lcd);

}