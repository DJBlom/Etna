
#ifndef _SYSTEM_PERIPHERALS_MOCK_H_ 
#define _SYSTEM_PERIPHERALS_MOCK_H_ 
#include "SystemPeripherals.h"
#include "Ahb1Peripheral.h"
#include "Apb1Peripheral.h"
namespace Test {
    class SystemPeripheralsMock : public Hal::SystemPeripherals {
        public:
            SystemPeripheralsMock() = default;
            SystemPeripheralsMock(const SystemPeripheralsMock&) = delete;
            SystemPeripheralsMock(SystemPeripheralsMock&&) = delete;
            SystemPeripheralsMock& operator= (const SystemPeripheralsMock&) = delete;
            SystemPeripheralsMock& operator= (SystemPeripheralsMock&&) = delete;
            virtual ~SystemPeripheralsMock() = default;

            virtual void InitializePeripherals();
            virtual void ConfigureSystemPeripheralBusses();
        private:
            Rcc::Ahb1Peripheral ahb1;
            Rcc::Apb1Peripheral apb1;
    };
}
#endif
