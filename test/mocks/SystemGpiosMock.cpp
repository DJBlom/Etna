#include "SystemGpiosMock.h"
#include "CppUTestExt/MockSupport.h"

void Test::SystemGpiosMock::InitializeGpios()
{
    mock().actualCall("InitializeGpios");
}

void Test::SystemGpiosMock::ConfigureSystemGpios()
{
    mock().actualCall("ConfigureSystemGpios");
}
