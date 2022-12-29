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
#include "MCURegisters.h"
namespace Rcc {
    class Ahb1Peripheral {
        public:
            Ahb1Peripheral() = default;
            explicit Ahb1Peripheral(volatile registerType* address): ahb1{address} {}
            Ahb1Peripheral(const Ahb1Peripheral&) = default;
            Ahb1Peripheral(Ahb1Peripheral&&) = default;
            Ahb1Peripheral& operator= (const Ahb1Peripheral&) = default;
            Ahb1Peripheral& operator= (Ahb1Peripheral&&) = default;
            virtual ~Ahb1Peripheral() = default;

            virtual bool GPIOAResetClockControl();
            virtual bool GPIOBResetClockControl();
            virtual bool GPIOHResetClockControl();
            virtual bool GPIOEResetClockControl();
            virtual bool GPIODResetClockControl();
            virtual bool GPIOCResetClockControl();
            virtual bool CRCResetClockControl();
            virtual bool DMA2ResetClockControl();
            virtual bool DMA1ResetClockControl();

        private:
            Hardware::MCURegisters ahb1;

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
