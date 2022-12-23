
#ifndef _MCU_REGISTERS_H_ 
#define _MCU_REGISTERS_H_ 
#include "Registers.h"
namespace Hardware {
    class MCURegisters: public Registers {
        public:
            MCURegisters() = default;
            MCURegisters(const MCURegisters&) = delete;
            MCURegisters(MCURegisters&&) = delete;
            MCURegisters& operator= (const MCURegisters&) = delete;
            MCURegisters& operator= (MCURegisters&&) = delete;
            ~MCURegisters() = default;

            virtual void EnableRegisterBit(volatile registerType* address, registerType& bits);
            virtual void EnableRegister(volatile registerType* address, registerType& bits);
            virtual void DisableRegister(volatile registerType* address, registerType& bits);
    };
}
#endif
