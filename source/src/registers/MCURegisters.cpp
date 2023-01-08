#include "MCURegisters.h"


Hardware::MCURegisters::MCURegisters(volatile registerType* address)
{
    this->registerMask = *address;
    this->registerAddress = address;
}

bool Hardware::MCURegisters::EnableBit(registerType&& bit)
{
    this->registerMask = this->registerMask | bit;
    if (HardwareIsUpdated() == false)
        return false;
    else
        return true;
}

bool Hardware::MCURegisters::SetBits(registerType&& bits)
{
    this->registerMask = bits;
    if (HardwareIsUpdated() == false)
        return false;
    else
        return true;
}

bool Hardware::MCURegisters::Disable(registerType&& bit)
{
    this->registerMask = this->registerMask & ~(bit);
    if (HardwareIsUpdated() == false)
        return false;
    else 
        return true;
}

bool Hardware::MCURegisters::Toggle(registerType&& bit)
{
    this->registerMask = this->registerMask ^ bit;
    if (HardwareIsUpdated() == false)
        return false;
    else
        return true;
}

bool Hardware::MCURegisters::CheckBit(registerType&& bit)
{
    if (((this->registerMask >> bit) & 1U) == false)
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
