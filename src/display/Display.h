#pragma once
#include "value/Value.h"

/**
 * @brief Defines a mechanism to represent a value on a screen
 * 
 */
class Display{
    public:
    Display();
    /**
     * @brief Display a value on a display
     * 
     * @param value 
     */
    virtual void display(Value *value) = 0;
    /**
     * @brief Mark on the display that this display is active, e.g., a setting as it is being changed
     * 
     */
    virtual void active() = 0;
    /**
     * @brief Undo or reset any display modification associated with active()
     * 
     */
    virtual void inactive() = 0;
};