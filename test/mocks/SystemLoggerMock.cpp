#include "SystemLogger.h"
#include "CppUTestExt/MockSupport.h"

bool Hal::SystemLogger::InitializeSystemLogger()
{
   return mock().actualCall("InitializeSystemLogger").returnBoolValue();
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
