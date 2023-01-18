
#ifndef _SYSTEM_GPIOS_MOCK_H_ 
#define _SYSTEM_GPIOS_MOCK_H_ 
#include "SystemGpios.h"
#include "GpioMode.h"
namespace Test {
    class SystemGpiosMock : public Hal::SystemGpios {
        public:
            SystemGpiosMock() = default;
            SystemGpiosMock(const SystemGpiosMock&) = delete;
            SystemGpiosMock(SystemGpiosMock&&) = delete;
            SystemGpiosMock& operator= (const SystemGpiosMock&) = delete;
            SystemGpiosMock& operator= (SystemGpiosMock&&) = delete;
            virtual ~SystemGpiosMock() = default;

            virtual void InitializeGpios();
            virtual void ConfigureSystemGpios();
        private:
            Gpio::GpioMode gpioMode;
    };
}
#endif
