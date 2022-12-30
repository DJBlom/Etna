#include "System.h"

namespace Registers {
    static systemType* GetAddress(systemType address)
    {
        return reinterpret_cast<systemType*> (address);
    }

    constexpr systemType rccAhb1Enable{0x40023830U};
    constexpr systemType rccApb1Enable{0x40023840U};
    constexpr systemType gpioaMode{0x40020000U};
}

namespace Address {
    volatile systemType* ahb1Enable = Registers::GetAddress(Registers::rccAhb1Enable);
    volatile systemType* apb1Enable = Registers::GetAddress(Registers::rccApb1Enable);
    volatile systemType* modeA = Registers::GetAddress(Registers::gpioaMode);
}

void Hal::System::Initialize()
{
    ahb1 = Rcc::Ahb1Peripheral{Address::ahb1Enable};
    apb1 = Rcc::Apb1Peripheral{Address::apb1Enable};
    modeA = Gpio::GpioMode{Address::modeA};
}

void Hal::System::RccConfiguration()
{
    ahb1.GpioAResetClockControl();
    apb1.Usart2ResetClockControl();
}

void Hal::System::ModeConfiguration()
{
    modeA.EnableOutputMode(ConvertPinToSystemType(Pin::five));
}

systemType Hal::System::ConvertPinToSystemType(const Pin& pin)
{
    return static_cast<systemType> (pin);
}
