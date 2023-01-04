/********************************************************************************
 * Contents: Class MCURegisters.
 * Author: Dawid Blom.
 * Date: December 29, 2022.
 *
 * Note: This class is used to Enable, Disable, or Toggle a register bit or a
 * whole register.
 *******************************************************************************/
#ifndef _MCU_REGISTERS_H_ 
#define _MCU_REGISTERS_H_ 
#include "Registers.h"
namespace Hardware {
    class MCURegisters : public Registers {
        public:
            MCURegisters() = default;
            explicit MCURegisters(volatile registerType*);
            MCURegisters(const MCURegisters&) = default;
            MCURegisters(MCURegisters&&) = default;
            MCURegisters& operator= (const MCURegisters&) = default;
            MCURegisters& operator= (MCURegisters&&) = default;
            virtual ~MCURegisters() = default;

            virtual bool BitEnable(registerType&&);
            virtual bool BitsEnable(registerType&&);
            virtual bool Disable(registerType&&);
            virtual bool Toggle(registerType&&);
            
        protected:
            virtual bool HardwareIsUpdated();
            
        private:
            registerType registerMask{0};
            volatile registerType* registerAddress{nullptr};
    };
}
#endif
