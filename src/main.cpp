/*
Digital Timer for Hydroponics Pump
David H. Brown
2020-02-21
*/

#include "config.h"

#include <LiquidCrystal.h>
LiquidCrystal lcd(PIN_RS, PIN_EN, PIN_D4, PIN_D5, PIN_D6, PIN_D7);

#include "ui/UIStateId.h"
UIStateId currentStateId;

#include "ui/UIStateRepository.h"
#include "ui/UIStateIdle.h"
UIStateIdle uis_idle = UIStateIdle();
#include "ui/UIStateSleep.h"
UIStateSleep uis_sleep = UIStateSleep();
#include "Buttons.h"
Buttons lcdButtons(PIN_BUTTONS);

#define EVENTS 5
UIEventId events[EVENTS];
int eventsIndex = 0;

#include "DLL.h"
#include "screen/ScreenCurrentTime.h"
#include "screen/ScreenTimer.h"
#include "screen/ScreenLight.h"
DLL<ScreenLCD> *screens, *previousScreens;
ScreenLCD *sl_currentTime = new ScreenCurrentTime(),
          *sl_timer = new ScreenTimer(),
          *sl_light = new ScreenLight();

void setup()
{
  for (int i = 0; i < EVENTS; i++)
  {
    events[i] = UIEventId::NONE;
  }
  // set up the LCD's number of columns and rows:
  pinMode(PIN_BACKLIGHT, OUTPUT);
  digitalWrite(PIN_BACKLIGHT, HIGH); // turn backlight on
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print(" Digital Timer  ");
  lcd.setCursor(0, 1);
  lcd.print("Hydroponics Pump");
  delay(2000);
  UIStateRepository::registerState(UIStateId::IDLE, &uis_idle);
  UIStateRepository::registerState(UIStateId::SLEEP, &uis_sleep);
  currentStateId = UIStateId::IDLE;

  screens = new DLL<ScreenLCD>(sl_currentTime);
  screens->append(sl_timer);
  screens->append(sl_light);
  previousScreens = nullptr;
}

void loop()
{
  // initialize current event
  UIEventId currentEventId = lcdButtons.getEvent();

  UIState *state = UIStateRepository::getState(currentStateId);
  currentStateId = state->handleEvent(currentEventId);

  if (previousScreens != screens)
  {
    previousScreens = screens;
    screens->item()->initLCD(&lcd);
  }
  screens->item()->updateLCD(&lcd);
}