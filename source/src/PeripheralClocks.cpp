#include "PeripheralClocks.h"
#include "RegisterAddresses.h"

namespace Addresses {
    volatile peripheralType* ahb1Enable = reinterpret_cast<peripheralType*> (registers::rcc::AHB1_ENABLE);
}


void Rcc::PeripheralClocks::ConfigurePeripheralClocks()
{
    clocks.EnableClockForGpioA(Addresses::ahb1Enable);
}
