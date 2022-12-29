#include "GpioMode.h"

bool Gpio::GpioMode::EnableInputMode(registerType&& pin)
{
    if (gpio.EnableRegisterBit(Mode::input << pin))
        return true;
    else
        return false;
}

bool Gpio::GpioMode::EnableOutputMode(registerType&& pin)
{
    if (gpio.EnableRegisterBit(Mode::output << pin))
        return true;
    else
        return false;
}

bool Gpio::GpioMode::EnableAlternativeFunctionMode(registerType&& pin)
{
    if (gpio.EnableRegisterBit(Mode::alternateFunction << pin))
        return true;
    else
        return false;
}

bool Gpio::GpioMode::EnableAnalogMode(registerType&& pin)
{
    if (gpio.EnableRegisterBit(Mode::analog << pin))
        return true;
    else
        return false;
}

