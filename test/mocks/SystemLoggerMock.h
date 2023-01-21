#ifndef _SYSTEM_LOGGER_MOCK_H_ 
#define _SYSTEM_LOGGER_MOCK_H_ 
#include "SystemLogger.h"
namespace Test {
    class SystemLoggerMock : public Hal::SystemLogger{
        public:
            SystemLoggerMock() = default;
            SystemLoggerMock(const SystemLoggerMock&) = default;
            SystemLoggerMock(SystemLoggerMock&&) = default;
            SystemLoggerMock& operator= (const SystemLoggerMock&) = default;
            SystemLoggerMock& operator= (SystemLoggerMock&&) = default;
            virtual ~SystemLoggerMock() = default;

            virtual bool InitializeSystemLogger();
            virtual bool LogMessage(const char*);

        protected:
            virtual registerType MessageToRegisterType(const char*);
    };
}
#endif
