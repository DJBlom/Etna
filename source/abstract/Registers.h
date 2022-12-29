
#ifndef _REGISTERS_H_ 
#define _REGISTERS_H_ 
#include <cstdint>
using registerType = std::uint32_t;
namespace Hardware {
    class Registers {
        public:
            virtual ~Registers() = default;
            virtual bool HardwareIsUpdated() = 0;
    };
}
#endif
