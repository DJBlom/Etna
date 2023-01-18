#include "SystemLogger.h"
#include "CppUTestExt/MockSupport.h"

void Hal::SystemLogger::InitializeSystemLogger()
{
    mock().actualCall("InitializeSystemLogger");
}

bool Hal::SystemLogger::ConfigureSystemLogger()
{
    return mock().actualCall("ConfigureSystemLogger").returnBoolValue();
}

bool Hal::SystemLogger::LogMessage(const char msg[])
{
    return mock().actualCall("LogMessage").withParameter("msg", msg).returnBoolValue();
}

registerType Hal::SystemLogger::MessageToRegisterType(const char msg[])
{
    mock().actualCall("MessageToInt").withParameter("msg", msg).returnUnsignedIntValue();
    return 10U;
}
