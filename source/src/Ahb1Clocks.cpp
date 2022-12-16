#include "Ahb1Clocks.h"

void Rcc::Ahb1Clocks::EnableClockForGpioA(volatile gpioType* registerAddress)
{
    UpdateHardware(registerAddress, Bits::on << Pins::gpioA);
}

void Rcc::Ahb1Clocks::EnableClockForGpioB(volatile gpioType* registerAddress)
{
    UpdateHardware(registerAddress, Bits::on << Pins::gpioB);
}

void Rcc::Ahb1Clocks::EnableClockForGpioC(volatile gpioType* registerAddress)
{
    UpdateHardware(registerAddress, Bits::on << Pins::gpioC);
}

void Rcc::Ahb1Clocks::EnableClockForGpioD(volatile gpioType* registerAddress)
{
    UpdateHardware(registerAddress, Bits::on << Pins::gpioD);
}

void Rcc::Ahb1Clocks::EnableClockForGpioE(volatile gpioType* registerAddress)
{
    UpdateHardware(registerAddress, Bits::on << Pins::gpioE);
}

void Rcc::Ahb1Clocks::UpdateHardware(volatile gpioType* registerAddress, gpioType&& pin)
{
     *registerAddress = *registerAddress | pin;
} 
