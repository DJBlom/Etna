
#ifndef _PERIPHERALS_MOCK_H_ 
#define _PERIPHERALS_MOCK_H_ 
#include "CppUTestExt/MockSupport.h"
#include "Peripherals.h"
class PeripheralsMock : public Hal::Peripherals {
    public:
        PeripheralsMock() = default;
        virtual void ConfigurePeripheralClocks();

    private:

};
#endif
