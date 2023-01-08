#include "GpioAF.h"

bool Gpio::GpioAF::ZeroEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.EnableBit(AF::zero << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::OneEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.EnableBit(AF::one << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::TwoEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.EnableBit(AF::two << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::ThreeEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.EnableBit(AF::three << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::FourEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.EnableBit(AF::four << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::FiveEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.EnableBit(AF::five << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::SixEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.EnableBit(AF::six << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::SevenEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.EnableBit(AF::seven << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::EightEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.EnableBit(AF::eight << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::NineEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.EnableBit(AF::nine << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::TenEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.EnableBit(AF::ten << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::TwelveEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.EnableBit(AF::twelve << bit) == false)
        return false;
    else
        return true;
}

bool Gpio::GpioAF::FifteenEnable(Hardware::Registers& afRegister, registerType&& bit)
{
    if (afRegister.EnableBit(AF::fifteen << bit) == false)
        return false;
    else
        return true;
}
