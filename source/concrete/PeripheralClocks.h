
#ifndef _PERIPHERAL_CLOCKS_H_ 
#define _PERIPHERAL_CLOCKS_H_ 
#include "RccClocks.h"
#include "RegisterAddresses.h"
#include <iostream>

namespace Rcc {
    class PeripheralClocks : public RccClocks{
        public:
            PeripheralClocks();
            PeripheralClocks(const PeripheralClocks&) = delete;
            PeripheralClocks(PeripheralClocks&&) = delete;
            PeripheralClocks& operator= (const PeripheralClocks&) = delete;
            PeripheralClocks& operator= (PeripheralClocks&&) = delete;
            ~PeripheralClocks() = default;

            
            virtual void ConfigurePeripheralClocks();
    };
}
#endif
