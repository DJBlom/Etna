

#ifndef _AHB1_CLOCKS_H_ 
#define _AHB1_CLOCKS_H_ 
#include "HardwareRegisters.h"
#include <cstdint>
using gpioType = std::uint32_t;
namespace Rcc {
    class Ahb1Clocks : public Hardware::Registers {
        public:
            Ahb1Clocks() = default;
            Ahb1Clocks(const Ahb1Clocks&) = delete;
            Ahb1Clocks(Ahb1Clocks&&) = delete;
            Ahb1Clocks& operator= (const Ahb1Clocks&) = delete;
            Ahb1Clocks& operator= (Ahb1Clocks&&) = delete;
            ~Ahb1Clocks() = default;

            virtual void EnableClockForGpioA(volatile gpioType* registerAddress);
            virtual void EnableClockForGpioB(volatile gpioType* registerAddress);
            virtual void EnableClockForGpioC(volatile gpioType* registerAddress);
            virtual void EnableClockForGpioE(volatile gpioType* registerAddress);
            virtual void EnableClockForGpioD(volatile gpioType* registerAddress);

        protected:
            virtual void UpdateHardware(volatile gpioType* registerAddress, gpioType&& pin) override;

        private:
            gpioType pinPosition{0};
            enum class Bits {
                on = 0b1
            };

            enum class Pins {
                gpioA, 
                gpioB, 
                gpioC, 
                gpioD, 
                gpioE 
            };

            friend gpioType operator<< (const Bits& bit, const Pins& pin)
            {
                return (static_cast<gpioType> (bit) << static_cast<gpioType> (pin));
            }
    };
}
#endif
