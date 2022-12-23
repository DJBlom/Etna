#include "Ahb1Clocks.h"

namespace Registers {
    static clockType* GetAddress(clockType address)
    {
        return reinterpret_cast<clockType*> (address);
    }

    constexpr clockType ahb1Enable{0x40023830U};
}

namespace Addresses {
    volatile clockType* gpioAhb1Enable = Registers::GetAddress(Registers::ahb1Enable);
}

void Rcc::Ahb1Clocks::GpioAResetClockControl()
{
    ResetClockControlFor(Bits::enable << Pins::gpioA);
}

void Rcc::Ahb1Clocks::GpioBResetClockControl()
{
    ResetClockControlFor(Bits::enable << Pins::gpioB);
}

void Rcc::Ahb1Clocks::GpioCResetClockControl()
{
    ResetClockControlFor(Bits::enable << Pins::gpioC);
}

void Rcc::Ahb1Clocks::GpioDResetClockControl()
{
    ResetClockControlFor(Bits::enable << Pins::gpioD);
}

void Rcc::Ahb1Clocks::GpioEResetClockControl()
{
    ResetClockControlFor(Bits::enable << Pins::gpioE);
}

void Rcc::Ahb1Clocks::ResetClockControlFor(clockType&& gpio)
{
    clock.EnableRegisterBit(Addresses::gpioAhb1Enable, gpio);
}
