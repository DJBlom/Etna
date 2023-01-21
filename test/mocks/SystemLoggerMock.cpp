#include "SystemLoggerMock.h"
#include "CppUTestExt/MockSupport.h"

bool Test::SystemLoggerMock::InitializeSystemLogger()
{
   return mock().actualCall("InitializeSystemLogger").returnBoolValue();
}

bool Test::SystemLoggerMock::LogMessage(const char* msg)
{
    return mock().actualCall("LogMessage").withParameter("msg", msg).returnBoolValue();
}

registerType Test::SystemLoggerMock::MessageToRegisterType(const char* msg)
{
    mock().actualCall("MessageToInt").withParameter("msg", msg).returnUnsignedIntValue();
    return 10U;
}
