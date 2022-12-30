/********************************************************************************
 * Contents: Class GpioMode.
 * Author: Dawid Blom.
 * Date: December 29, 2022.
 *
 * Note: This class is used to set the GpioMode that will be used.
 *******************************************************************************/
#ifndef _GPIO_MODE_H_ 
#define _GPIO_MODE_H_ 
#include "MCURegisters.h"
namespace Gpio {
    class GpioMode {
        public:
            GpioMode() = default;
            explicit GpioMode(volatile registerType* address): gpio{address} {}
            GpioMode(const GpioMode&) = default;
            GpioMode(GpioMode&&) = default;
            GpioMode& operator= (const GpioMode&) = default;
            GpioMode& operator= (GpioMode&&) = default;
            virtual ~GpioMode() = default;

            virtual bool EnableInputMode(registerType&&);
            virtual bool EnableOutputMode(registerType&&);
            virtual bool EnableAlternativeFunctionMode(registerType&&);
            virtual bool EnableAnalogMode(registerType&&);

        private:
            enum class Mode {
                input = 0b00,
                output = 0b01,
                alternateFunction = 0b10,
                analog = 0b11
            };

            friend registerType operator<< (const Mode& mode, const registerType& pin)
            {
                return static_cast<registerType> (mode) << pin;
            }

        private:
            Hardware::MCURegisters gpio;


    };
}
#endif
