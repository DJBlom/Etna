#include "SystemPeripheralsMock.h"
#include "CppUTestExt/MockSupport.h"

void Test::SystemPeripheralsMock::InitializePeripherals()
{
    mock().actualCall("InitializationPeripherals");
}

void Test::SystemPeripheralsMock::ConfigureSystemPeripheralBusses()
{
    mock().actualCall("ConfigureSystemPeripheralBusses");
}

