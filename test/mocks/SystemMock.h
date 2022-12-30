
#ifndef _SYSTEM_MOCK_H_ 
#define _SYSTEM_MOCK_H_ 
#include "System.h"
#include "Ahb1Peripheral.h"
#include "GpioMode.h"
namespace Test {
    class SystemMock : public Hal::System {
        public:
            SystemMock() = default;
            SystemMock(const SystemMock&) = delete;
            SystemMock(SystemMock&&) = delete;
            SystemMock& operator= (const SystemMock&) = delete;
            SystemMock& operator= (SystemMock&&) = delete;
            virtual ~SystemMock() = default;

            virtual void Initialize();
            virtual void RccConfiguration();
            virtual void ModeConfiguration();
        private:
            Rcc::Ahb1Peripheral ahb1;
            Gpio::GpioMode gpioMode;
    };
}
#endif
