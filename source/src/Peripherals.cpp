#include "Peripherals.h"

void Hal::Peripherals::ConfigurePeripheralClocks()
{
    ahb1Clock.GpioAResetClockControl();
}
