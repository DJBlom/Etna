
#ifndef _MCU_REGISTERS_H_ 
#define _MCU_REGISTERS_H_ 
#include "Registers.h"
#include <iostream>
namespace Hardware {
    class MCURegisters: public Registers {
        public:
            MCURegisters() = delete;
            explicit MCURegisters(volatile registerType* address);
            MCURegisters(const MCURegisters&) = delete;
            MCURegisters(MCURegisters&&) = delete;
            MCURegisters& operator= (const MCURegisters&) = delete;
            MCURegisters& operator= (MCURegisters&&) = delete;
            ~MCURegisters() = default;

            virtual void EnableRegisterBit(registerType&& bits);
            virtual void EnableRegister(registerType&& bits);
            virtual void DisableRegister(registerType&& bits);

        protected:
            virtual void UpdateHardware();

        private:
            registerType registerMask{0};
            volatile registerType* registerAddress{nullptr};
    };
}
#endif
