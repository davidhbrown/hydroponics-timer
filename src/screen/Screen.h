#pragma once
#include "List.h"
#include "setting/Setting.h"

/**
 * @brief A screen displays some information with zero or more settings available
 * 
 * The first subclass of Screen will usually also be abstract, describing a type of 
 * display such as LCD (16x2 LCD). The concrete classes, then, will usually
 * establish the settings specific to a screen in their constructor.
 * 
 */
class Screen
{
protected:
    List<Setting> *_settings;

public:
    Screen(List<Setting> *settings) : _settings{settings}{};
    Setting * getCurrentSetting();
    void gotoFirstSetting();
    /**
     * @brief select the next setting if there is one; if not, stay with the current setting
     * 
     */
    void gotoNextSetting();
    /**
     * @brief select the previous setting if there is one; if not, stay with the current setting
     * 
     */
    void gotoPreviousSetting();
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
