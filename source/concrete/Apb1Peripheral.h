
#ifndef _APB1_PERIPHERAL_H_ 
#define _APB1_PERIPHERAL_H_ 
#include "MCURegisters.h"
namespace Rcc {
    class Apb1Peripheral {
        public:
            Apb1Peripheral() = default;
            explicit Apb1Peripheral(volatile registerType* address): apb1{address} {}
            Apb1Peripheral(const Apb1Peripheral&) = default;
            Apb1Peripheral(Apb1Peripheral&&) = default;
            Apb1Peripheral& operator= (const Apb1Peripheral&) = default;
            Apb1Peripheral& operator= (Apb1Peripheral&&) = default;
            virtual ~Apb1Peripheral() = default;

            virtual bool Tim2ResetClockControl();
            virtual bool Tim3ResetClockControl();
            virtual bool Tim4ResetClockControl();
            virtual bool Tim5ResetClockControl();
            virtual bool WwdgResetClockControl();
            virtual bool Spi2ResetClockControl();
            virtual bool Spi3ResetClockControl();
            virtual bool Usart2ResetClockControl();
            virtual bool I2c1ResetClockControl();
            virtual bool I2c2ResetClockControl();
            virtual bool I2c3ResetClockControl();
            virtual bool PwrResetClockControl();

        private:
            enum class Clock {
                enable = 1
            };

            enum class Bit {
                tim2 = 0,
                tim3 = 1,
                tim4 = 2,
                tim5 = 3,
                wwdg = 11,
                spi2 = 14,
                spi3 = 15,
                usart2 = 17,
                i2c1 = 21,
                i2c2 = 22,
                i2c3 = 23,
                pwr = 28
            };

            friend registerType operator<< (const Clock& clock, const Bit& bit)
            {
                return static_cast<registerType> (clock) << static_cast<registerType> (bit);
            }

        private:
            Hardware::MCURegisters apb1;
    };
}
#endif
