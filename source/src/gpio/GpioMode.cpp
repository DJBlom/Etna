#include "GpioMode.h"

bool Gpio::GpioMode::InputModeEnable(Hardware::Registers& gpioModeRegister, registerType&& bit)
{
    if (gpioModeRegister.BitEnable(Mode::input << bit) == false)
        return false;
    else 
        return true;
}

bool Gpio::GpioMode::OutputModeEnable(Hardware::Registers& gpioModeRegister, registerType&& bit)
{
    if (gpioModeRegister.BitEnable(Mode::output << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioMode::AlternateFunctionModeEnable(Hardware::Registers& gpioModeRegister, registerType&& bit)
{
    if (gpioModeRegister.BitEnable(Mode::alternateFunction << bit) == false)
        return false;
    else 
        return true;
}

bool Gpio::GpioMode::AnalogModeEnable(Hardware::Registers& gpioModeRegister, registerType&& bit)
{
    if (gpioModeRegister.BitEnable(Mode::analog << bit) == false)
        return false;
    else
        return true;
}

