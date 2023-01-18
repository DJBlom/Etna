#include "MCURegisters.h"


Hardware::MCURegisters::MCURegisters(volatile registerType* address)
{
    this->registerMask = *address;
    this->registerAddress = address;
}

bool Hardware::MCURegisters::EnableBit(registerType&& bit)
{
    this->registerMask = this->registerMask | bit;
    if (HardwareIsUpdated() == true)
        return true;
    else
        return false;
}

bool Hardware::MCURegisters::SetBits(registerType&& bits)
{
    this->registerMask = bits;
    if (HardwareIsUpdated() == true)
        return true;
    else
        return false;
}

bool Hardware::MCURegisters::Disable(registerType&& bit)
{
    this->registerMask = this->registerMask & ~(bit);
    if (HardwareIsUpdated() == true)
        return true;
    else
        return false;
}

bool Hardware::MCURegisters::Toggle(registerType&& bit)
{
    this->registerMask = this->registerMask ^ bit;
    if (HardwareIsUpdated() == true)
        return true;
    else
        return false;
}

registerType Hardware::MCURegisters::CheckBit(registerType&& bit)
{
    registerType registerBit{0};
    if (((this->registerMask >> bit) & 1U) == true)
        registerBit = (this->registerMask >> bit) & 1U;
        
    return registerBit;
}

bool Hardware::MCURegisters::AssignAnotherRegister(const registerType& newRegister)
{
    this->registerMask = newRegister;
    if (HardwareIsUpdated() == true)
        return true;
    else
        return false;
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
