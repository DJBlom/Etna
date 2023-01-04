#include "GpioAF.h"

bool Gpio::GpioAF::ZeroEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.BitEnable(AF::zero << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::OneEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.BitEnable(AF::one << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::TwoEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.BitEnable(AF::two << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::ThreeEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.BitEnable(AF::three << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::FourEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.BitEnable(AF::four << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::FiveEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.BitEnable(AF::five << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::SixEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.BitEnable(AF::six << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::SevenEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.BitEnable(AF::seven << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::EightEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.BitEnable(AF::eight << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::NineEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.BitEnable(AF::nine << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::TenEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.BitEnable(AF::ten << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::TwelveEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.BitEnable(AF::twelve << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::FifteenEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.BitEnable(AF::fifteen << bit) == false)
        return false;
    else
        return true;
}
