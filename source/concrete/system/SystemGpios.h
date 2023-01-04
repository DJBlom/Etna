/********************************************************************************
 * Contents: Class SystemGpios.
 * Author: Dawid Blom.
 * Date: January 2, 2023.
 *
 * Note: This class is used to configure the various gpios required by the 
 * system.
 *******************************************************************************/
#ifndef _SYSTEM_GPIOS_H_ 
#define _SYSTEM_GPIOS_H_ 
#include "MCURegisters.h"
#include "GpioMode.h"
#include "GpioAF.h"
namespace Hal {
    class SystemGpios {
        public:
            SystemGpios() = default;
            SystemGpios(const SystemGpios&) = delete;
            SystemGpios(SystemGpios&&) = delete;
            SystemGpios& operator= (const SystemGpios&) = delete;
            SystemGpios& operator= (SystemGpios&&) = delete;
            virtual ~SystemGpios() = default;

            virtual void InitializeGpios();
            virtual void ConfigureSystemGpios();
            
        private:
            enum class ModeBit {
                two = 4,
                five = 10
            };

            enum class AFBit {
                zero, one, two,
                three, four, five,
                six, seven, eight,
                nine, ten, twelve,
                fifteen
            };

            virtual registerType ConvertModeBitToSystemType(const ModeBit&);
            virtual registerType ConvertAFBitToSystemType(const AFBit&);

        private:
            Hardware::MCURegisters gpioaModeRegister;
            Hardware::MCURegisters gpioaAFRegister;
            Gpio::GpioMode modeA;
            Gpio::GpioAF lowAFA;
    };
}
#endif
