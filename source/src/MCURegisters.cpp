#include "MCURegisters.h"

void Hardware::MCURegisters::EnableRegisterBit(volatile registerType* address, registerType& bits)
{
    *address = *address | bits;
}

void Hardware::MCURegisters::EnableRegister(volatile registerType* address, registerType& bits)
{
    *address = bits;
}

void Hardware::MCURegisters::DisableRegister(volatile registerType* address, registerType& bits)
{
    *address = *address & ~bits;
}
