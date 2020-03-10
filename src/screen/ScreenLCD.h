#pragma once
#include "Screen.h"
#include <LiquidCrystal.h>

/**
 * @brief A 2-row, 16-column display using the LiquidCrystal Arduino library
 * 
 */
class ScreenLCD : public Screen
{
protected:
    LiquidCrystal *_lcd;

public:
    /**
 * @brief Construct a new Screen LCD object
 * 
 * @param lcd a pointer to a LiquidCrystal instance
 */
    ScreenLCD(LiquidCrystal *lcd) : Screen{nullptr}, _lcd{lcd} {};
    /**
     * @brief Prepare the screen to display the appropriate information
     * 
     */
    virtual void init();
    /**
     * @brief Update the screen to display current information / setting
     * 
     */
    virtual void update();
    };
