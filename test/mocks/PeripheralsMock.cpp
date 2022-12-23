#include "PeripheralsMock.h"

void PeripheralsMock::ConfigurePeripheralClocks()
{
    mock().actualCall("GpioAResetClockControl");
}
