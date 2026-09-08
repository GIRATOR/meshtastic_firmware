#pragma once
#include "AnalogKeyboard.h"
#include "main.h"

/**
 * @brief The idea behind this class to have static methods for the event handlers.
 *      Check attachInterrupt() at RotaryEncoderInteruptBase.cpp
 *      Technically you can have as many rotary encoders hardver attached
 *      to your device as you wish, but you always need to have separate event
 *      handlers, thus you need to have a RotaryEncoderInterrupt implementation.
 */
class AnalogKeyboardImpl : public AnalogKeyboard
{
  public:
    AnalogKeyboardImpl();
    void init();
};

extern AnalogKeyboardImpl *aAnalogKeyboardImpl;