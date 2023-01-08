#include "GpioMode.h"

bool Gpio::GpioMode::InputModeEnable(Hardware::Registers& gpioModeRegister, registerType&& bit)
{
    if (gpioModeRegister.EnableBit(Mode::input << bit) == false)
        return false;
    else 
        return true;
}

bool Gpio::GpioMode::OutputModeEnable(Hardware::Registers& gpioModeRegister, registerType&& bit)
{
    if (gpioModeRegister.EnableBit(Mode::output << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioMode::AlternateFunctionModeEnable(Hardware::Registers& gpioModeRegister, registerType&& bit)
{
    if (gpioModeRegister.EnableBit(Mode::alternateFunction << bit) == false)
        return false;
    else 
        return true;
}

bool Gpio::GpioMode::AnalogModeEnable(Hardware::Registers& gpioModeRegister, registerType&& bit)
{
    if (gpioModeRegister.EnableBit(Mode::analog << bit) == false)
        return false;
    else
        return true;
}

