/********************************************************************************
 * Contents: Class Ahb1Peripheral.
 * Author: Dawid Blom.
 * Date: December 29, 2022.
 *
 * Note: This class is used to reset the clock control for the AHB1 peripheral 
 * bus.
 *******************************************************************************/
#ifndef _AHB1_PERIPHERAL_H_ 
#define _AHB1_PERIPHERAL_H_ 
#include "Registers.h"
namespace Rcc {
    class Ahb1Peripheral {
        public:
            Ahb1Peripheral() = default;
            Ahb1Peripheral(const Ahb1Peripheral&) = default;
            Ahb1Peripheral(Ahb1Peripheral&&) = default;
            Ahb1Peripheral& operator= (const Ahb1Peripheral&) = default;
            Ahb1Peripheral& operator= (Ahb1Peripheral&&) = default;
            virtual ~Ahb1Peripheral() = default;

            virtual bool GpioAResetClockControl(Hardware::Registers& rccRegister);
            virtual bool GpioBResetClockControl(Hardware::Registers& rccRegister);
            virtual bool GpioHResetClockControl(Hardware::Registers& rccRegister);
            virtual bool GpioEResetClockControl(Hardware::Registers& rccRegister);
            virtual bool GpioDResetClockControl(Hardware::Registers& rccRegister);
            virtual bool GpioCResetClockControl(Hardware::Registers& rccRegister);
            virtual bool CrcResetClockControl(Hardware::Registers& rccRegister);
            virtual bool Dma2ResetClockControl(Hardware::Registers& rccRegister);
            virtual bool Dma1ResetClockControl(Hardware::Registers& rccRegister);

        private:
            enum class Clock {
                enable = 1
            };

            enum class Reset {
                gpioa = 0,
                gpiob = 1,
                gpioc = 2,
                gpiod = 3,
                gpioe = 4,
                gpioh = 7,
                crc = 12,
                dma1 = 21, 
                dma2 = 22
            };

            friend registerType operator<< (const Clock& clock, const Reset& reset)
            {
                return static_cast<registerType> (clock) << static_cast<registerType> (reset);
            }
    };
}
#endif
