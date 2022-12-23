#ifndef _AHB1_CLOCKS_H_ 
#define _AHB1_CLOCKS_H_ 
#include "RccClocks.h"
#include "MCURegisters.h"
using clockType = std::uint32_t;
namespace Rcc {
    class Ahb1Clocks : public RccClocks {
        public:
            Ahb1Clocks() = default;
            Ahb1Clocks(const Ahb1Clocks&) = delete;
            Ahb1Clocks(Ahb1Clocks&&) = delete;
            Ahb1Clocks& operator= (const Ahb1Clocks&) = delete;
            Ahb1Clocks& operator= (Ahb1Clocks&&) = delete;
            ~Ahb1Clocks() = default;

            virtual void GpioAResetClockControl();
            virtual void GpioBResetClockControl();
            virtual void GpioCResetClockControl();
            virtual void GpioDResetClockControl();
            virtual void GpioEResetClockControl();

        protected:
            virtual void ResetClockControlFor(clockType&&);

        private:
            Hardware::MCURegisters clock;
            enum class Pins {
                gpioA = 0,
                gpioB = 1,
                gpioC = 2,
                gpioD = 3, 
                gpioE = 4
            };
            
            enum class Bits {
                enable = 1U
            };

            friend clockType operator<< (const Bits& bit, const Pins& pin)
            {
                return static_cast<clockType> (bit) << static_cast<clockType> (pin);
            }
    };
}
#endif
