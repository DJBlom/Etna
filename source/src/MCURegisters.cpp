#include "MCURegisters.h"


Hardware::MCURegisters::MCURegisters(volatile registerType* address)
{
    this->registerMask = *address;
    this->registerAddress = address;
}

bool Hardware::MCURegisters::EnableRegisterBit(registerType&& pin)
{
    this->registerMask = this->registerMask | pin;
    if (HardwareIsUpdated())
        return true;
    else
        return false;
}

bool Hardware::MCURegisters::EnableRegister(registerType&& pin)
{
    this->registerMask = pin;
    if (HardwareIsUpdated())
        return true;
    else
        return false;
}

bool Hardware::MCURegisters::DisableRegister(registerType&& pin)
{
    this->registerMask = this->registerMask & ~(pin);
    if (HardwareIsUpdated())
        return true;
    else
        return false;
}

bool Hardware::MCURegisters::ToggleRegister(registerType&& pin)
{
    this->registerMask = this->registerMask ^ pin;
    if (HardwareIsUpdated())
        return true;
    else
        return false;
}

bool Hardware::MCURegisters::HardwareIsUpdated()
{
    *this->registerAddress = this->registerMask;
    this->registerMask = *this->registerAddress;
    if (this->registerMask == *this->registerAddress)
        return true;
    else
        return false;
}
