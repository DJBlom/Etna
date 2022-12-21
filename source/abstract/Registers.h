
#ifndef _REGISTERS_H_ 
#define _REGISTERS_H_ 
#include <cstdint>

using registerType = std::uint32_t;
namespace Hardware {
    class Registers {
        public:
            virtual ~Registers() = default;
            virtual void EnableRegisterBit(registerType&& bits) = 0;
            virtual void EnableRegister(registerType&& bits) = 0;
            virtual void DisableRegister(registerType&& bits) = 0;
            
        protected:
            virtual void UpdateHardware() = 0;
    };
}
#endif
