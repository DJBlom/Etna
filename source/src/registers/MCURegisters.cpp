#include "MCURegisters.h"


Hardware::MCURegisters::MCURegisters(volatile registerType* address)
{
    this->registerMask = *address;
    this->registerAddress = address;
}

bool Hardware::MCURegisters::BitEnable(registerType&& pin)
{
    this->registerMask = this->registerMask | pin;
    if (HardwareIsUpdated() == false)
        return false;
    else
        return true;
}

bool Hardware::MCURegisters::BitsEnable(registerType&& pin)
{
    this->registerMask = pin;
    if (HardwareIsUpdated() == false)
        return false;
    else
        return true;
}

bool Hardware::MCURegisters::Disable(registerType&& pin)
{
    this->registerMask = this->registerMask & ~(pin);
    if (HardwareIsUpdated() == false)
        return false;
    else 
        return true;
}

bool Hardware::MCURegisters::Toggle(registerType&& pin)
{
    this->registerMask = this->registerMask ^ pin;
    if (HardwareIsUpdated() == false)
        return false;
    else
        return true;
}

bool Hardware::MCURegisters::HardwareIsUpdated()
{
    *this->registerAddress = this->registerMask;
    this->registerMask = *this->registerAddress;
    if (this->registerMask != *this->registerAddress)
        return false;
    else
        return true;
}
