/********************************************************************************
 * Contents: Class Apb1Peripheral.
 * Author: Dawid Blom.
 * Date: January 2, 2023.
 *
 * Note: This class is used to gain clock control to the peripherals on the APB1
 * bus.
 *******************************************************************************/
#ifndef _APB1_PERIPHERAL_H_ 
#define _APB1_PERIPHERAL_H_ 
#include "Registers.h"
namespace Rcc {
    class Apb1Peripheral {
        public:
            Apb1Peripheral() = default;
            Apb1Peripheral(const Apb1Peripheral&) = default;
            Apb1Peripheral(Apb1Peripheral&&) = default;
            Apb1Peripheral& operator= (const Apb1Peripheral&) = default;
            Apb1Peripheral& operator= (Apb1Peripheral&&) = default;
            virtual ~Apb1Peripheral() = default;

            virtual bool Tim2ResetClockControl(Hardware::Registers&);
            virtual bool Tim3ResetClockControl(Hardware::Registers&);
            virtual bool Tim4ResetClockControl(Hardware::Registers&);
            virtual bool Tim5ResetClockControl(Hardware::Registers&);
            virtual bool WwdgResetClockControl(Hardware::Registers&);
            virtual bool Spi2ResetClockControl(Hardware::Registers&);
            virtual bool Spi3ResetClockControl(Hardware::Registers&);
            virtual bool Usart2ResetClockControl(Hardware::Registers&);
            virtual bool I2c1ResetClockControl(Hardware::Registers&);
            virtual bool I2c2ResetClockControl(Hardware::Registers&);
            virtual bool I2c3ResetClockControl(Hardware::Registers&);
            virtual bool PwrResetClockControl(Hardware::Registers&);

        private:
            enum class Clock {
                enable = 1
            };

            enum class Bit {
                tim2 = 0, tim3 = 1, tim4 = 2,
                tim5 = 3, wwdg = 11, spi2 = 14,
                spi3 = 15, usart2 = 17, i2c1 = 21,
                i2c2 = 22, i2c3 = 23, pwr = 28
            };

            friend registerType operator<< (const Clock& clock, const Bit& bit)
            {
                return static_cast<registerType> (clock) << static_cast<registerType> (bit);
            }
    };
}
#endif
