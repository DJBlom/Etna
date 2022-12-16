
#ifndef _HARDWARE_REGISTERS_H_ 
#define _HARDWARE_REGISTERS_H_ 
#include <cstdint>
using registerType = std::uint32_t;
namespace Hardware {
    class Registers {
        public:
            virtual ~Registers() = default;
            virtual void UpdateHardware(volatile registerType*, registerType&&) = 0;
    };
}
#endif
