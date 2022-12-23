
#ifndef _REGISTERS_H_ 
#define _REGISTERS_H_ 
#include <cstdint>

using registerType = std::uint32_t;
namespace Hardware {
    class Registers {
        public:
            virtual ~Registers() = default;
            virtual void EnableRegisterBit(volatile registerType* address, registerType& bits) = 0;
            virtual void EnableRegister(volatile registerType* address, registerType& bits) = 0;
            virtual void DisableRegister(volatile registerType* address, registerType& bits) = 0;

    };
}
#endif
