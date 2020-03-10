/*
Digital Timer for Hydroponics Pump
David H. Brown
2020-02-21
*/

#include "config.h"

#include <LiquidCrystal.h>
LiquidCrystal lcd(PIN_RS, PIN_EN, PIN_D4, PIN_D5, PIN_D6, PIN_D7);

#include "uRTCLib.h"
uRTCLib rtc = uRTCLib();

#include "ui/UIStateId.h"
UIStateId currentUIStateId;

#include "ui/UIStateRepository.h"
#include "ui/UIStateIdle.h"
UIStateIdle uis_idle = UIStateIdle(UIStateId::IDLE);
#include "ui/UIStateSleep.h"
UIStateSleep uis_sleep = UIStateSleep(UIStateId::SLEEP);
#include "ui/UIStateSetting.h"
UIStateSetting uis_setting = UIStateSetting(UIStateId::SETTING);
#include "Buttons.h"
Buttons lcdButtons(PIN_BUTTONS);

#define EVENTS 5
UIEventId events[EVENTS];
int eventsIndex = 0;

#include "List.h"
#include "screen/ScreenCurrentTime.h"
#include "screen/ScreenTimer.h"
#include "screen/ScreenLight.h"
#include "screen/ScreenMillis.h"

List<Screen> screens_list = List<Screen>();

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < EVENTS; i++)
  {
    events[i] = UIEventId::NONE;
  }
  // set up the LCD's number of columns and rows:
  pinMode(PIN_BACKLIGHT, OUTPUT);
  digitalWrite(PIN_BACKLIGHT, HIGH); // turn backlight on
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print(F(" Digital Timer  "));
  lcd.setCursor(0, 1);
  lcd.print(F("Hydroponics Pump"));
  for (int t = 2000; t > 0; t -= 500)
  {
    Serial.print(F("Starting in "));
    Serial.println(t);
    delay(500);
  }
  UIStateRepository::registerState(&uis_setting);
  UIStateRepository::registerState(&uis_idle);
  UIStateRepository::registerState(&uis_sleep);
  currentUIStateId = UIStateId::IDLE;
  Serial.println("UI setup complete");
  delay(100);

  Serial.println("Registering Screens");

  screens_list.insert(new ScreenLight(&lcd));
  screens_list.insert(new ScreenTimer(&lcd));
  screens_list.insert(new ScreenCurrentTime(&lcd, &rtc));
  screens_list.insert(new ScreenMillis(&lcd));
  Serial.println(F("Setup complete"));
  screens_list.get_item()->init();
  screens_list.get_item()->update();
}

void loop()
{
  // initialize current event
  UIEventId currentUIEventId = lcdButtons.getEvent();

  currentUIStateId = UIStateRepository::getState(currentUIStateId)->handleEvent(currentUIEventId);
}