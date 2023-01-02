#include "SystemPeripherals.h"

namespace Registers {
    static registerType* GetAddress(registerType address)
    {
        return reinterpret_cast<registerType*> (address);
    }

    constexpr registerType rccAhb1Enable{0x40023830U};
    constexpr registerType rccApb1Enable{0x40023840U};
}

namespace Address {
    volatile registerType* ahb1Enable = Registers::GetAddress(Registers::rccAhb1Enable);
    volatile registerType* apb1Enable = Registers::GetAddress(Registers::rccApb1Enable);
}

void Hal::SystemPeripherals::InitializePeripherals()
{
    ahb1Register = Hardware::MCURegisters{Address::ahb1Enable};
    apb1Register = Hardware::MCURegisters{Address::apb1Enable};
}

void Hal::SystemPeripherals::ConfigureSystemPeripheralBusses()
{
    ahb1Bus.GpioAResetClockControl(ahb1Register);
    apb1Bus.Usart2ResetClockControl(apb1Register);
}

