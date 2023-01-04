/********************************************************************************
 * Contents: Class SystemPeripherals.
 * Author: Dawid Blom.
 * Date: January 2, 2023.
 *
 * Note: This class is used to configure the various peripherals required by the 
 * system.
 *******************************************************************************/
#ifndef _SYSTEM_PERIPHERALS_H_ 
#define _SYSTEM_PERIPHERALS_H_ 
#include "MCURegisters.h"
#include "Ahb1Peripheral.h"
#include "Apb1Peripheral.h"
namespace Hal {
    class SystemPeripherals {
        public:
            SystemPeripherals() = default;
            SystemPeripherals(const SystemPeripherals&) = delete;
            SystemPeripherals(SystemPeripherals&&) = delete;
            SystemPeripherals& operator= (const SystemPeripherals&) = delete;
            SystemPeripherals& operator= (SystemPeripherals&&) = delete;
            virtual ~SystemPeripherals() = default;

            virtual void InitializePeripherals();
            virtual void ConfigureSystemPeripheralBusses();
            
        private:
            Hardware::MCURegisters ahb1Register;
            Hardware::MCURegisters apb1Register;
            Rcc::Ahb1Peripheral ahb1Bus;
            Rcc::Apb1Peripheral apb1Bus;
    };
}
#endif
