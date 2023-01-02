#include "SystemMock.h"
#include "CppUTestExt/MockSupport.h"

void Test::SystemMock::Initialize()
{
    mock().actualCall("Initialization");
}

void Test::SystemMock::RccConfiguration()
{
    mock().actualCall("RccConfiguration");
}

void Test::SystemMock::ModeConfiguration()
{
    mock().actualCall("ModeConfiguration");
}
