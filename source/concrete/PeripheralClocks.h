
#ifndef _PERIPHERAL_CLOCKS_H_ 
#define _PERIPHERAL_CLOCKS_H_ 
#include "Ahb1Clocks.h"
#include "RccClocks.h"
#include <cstdint>

using peripheralType = std::uint32_t;



namespace Rcc {
    class PeripheralClocks : public RccClocks{
        public:
            PeripheralClocks() = default;
            PeripheralClocks(const PeripheralClocks&) = delete;
            PeripheralClocks(PeripheralClocks&&) = delete;
            PeripheralClocks& operator= (const PeripheralClocks&) = delete;
            PeripheralClocks& operator= (PeripheralClocks&&) = delete;
            ~PeripheralClocks() = default;

            
            virtual void ConfigurePeripheralClocks();

        private:
            Ahb1Clocks clocks;
    };
}
#endif
