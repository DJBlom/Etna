#include "SystemMock.h"
#include "CppUTestExt/MockSupport.h"

void Test::SystemMock::Initialize()
{
    mock().actualCall("Initialization");
}

void Test::SystemMock::RccConfiguration()
{
    mock().actualCall("GpioAResetClockControl");
    mock().actualCall("Usart2ResetClockControl");
}

void Test::SystemMock::ModeConfiguration()
{
    mock().actualCall("EnableOutputMode").withParameter("Pin", 1);
}
