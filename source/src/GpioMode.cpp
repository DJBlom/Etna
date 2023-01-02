#include "GpioMode.h"

bool Gpio::GpioMode::InputModeEnable(Hardware::Registers& gpio, registerType&& pin)
{
    if (gpio.BitEnable(Mode::input << pin) == false)
        return false;
    else 
        return true;
}

bool Gpio::GpioMode::OutputModeEnable(Hardware::Registers& gpio, registerType&& pin)
{
    if (gpio.BitEnable(Mode::output << pin) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioMode::AlternateFunctionModeEnable(Hardware::Registers& gpio, registerType&& pin)
{
    if (gpio.BitEnable(Mode::alternateFunction << pin) == false)
        return false;
    else 
        return true;
}

bool Gpio::GpioMode::AnalogModeEnable(Hardware::Registers& gpio, registerType&& pin)
{
    if (gpio.BitEnable(Mode::analog << pin) == false)
        return false;
    else
        return true;
}

