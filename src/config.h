#pragma once
/*
Configuration settings for this application
*/

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


#define PIN_RS 8
#define PIN_EN 9
#define PIN_D4 4
#define PIN_D5 5
#define PIN_D6 6
#define PIN_D7 7
#define PIN_BACKLIGHT 10
#define PIN_BUTTONS 0
#define IDLE_TIMEOUT_MS 30000L
#define SETTING_TIMEOUT_MS 8000L

/*
 for Buttons
 Experimental readings of each button are (USB power):
 Select: 741; Left: 505; Down: 330; Up: 142; Right: 0. (None: 1023)
 Low values win. If the reading is below these thresholds, that's our button
 */
// The right button reads at 0
#define BUTTON_RIGHT_MAX 75
// The up button reads at 142
#define BUTTON_UP_MAX 200
// The down button reads at 330
#define BUTTON_DOWN_MAX 400
// the left button reads at 505
#define BUTTON_LEFT_MAX 675
// the select button reads at 741
#define BUTTON_SELECT_MAX 800
// How many ms a button must be held to generate an event
#define BUTTON_HELD_DELAY 1500
// How many ms between held button repeats
#define BUTTON_HELD_REPEAT 500
// How many ms to accept a value
#define BUTTON_DEBOUNCE 30