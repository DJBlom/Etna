#include "MCURegisters.h"

Hardware::MCURegisters::MCURegisters(volatile registerType* address)
{
    this->registerMask = *address;
    this->registerAddress = address;
}

void Hardware::MCURegisters::EnableRegisterBit(registerType&& bits)
{
    this->registerMask = this->registerMask | bits;
    UpdateHardware();
}

void Hardware::MCURegisters::EnableRegister(registerType&& bits)
{
    this->registerMask = bits;
    UpdateHardware();
}

void Hardware::MCURegisters::DisableRegister(registerType&& bits)
{
    this->registerMask = this->registerMask & ~bits;
    UpdateHardware();
}
            
void Hardware::MCURegisters::UpdateHardware()
{
    *this->registerAddress = this->registerMask;
    this->registerMask = *this->registerAddress;
}
