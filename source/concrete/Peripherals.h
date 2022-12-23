
#ifndef _PERIPHERALS_H_ 
#define _PERIPHERALS_H_ 
#include "Ahb1Clocks.h"
namespace Hal {
    class Peripherals {
        public:
            Peripherals() = default;
            Peripherals(const Peripherals&) = delete;
            Peripherals(Peripherals&&) = delete;
            Peripherals& operator= (const Peripherals&) = delete;
            Peripherals& operator= (Peripherals&&) = delete;
            virtual ~Peripherals() = default;

            virtual void ConfigurePeripheralClocks();

        private:
            Rcc::Ahb1Clocks ahb1Clock;
    };
}
#endif
