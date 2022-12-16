#ifndef _GPIO_REGISTERS_MOCK_H_ 
#define _GPIO_REGISTERS_MOCK_H_ 
#include <cstdint>
using registerType = std::uint32_t;
namespace Registers {
    struct GpioRegistersMock {
        registerType someAddress;
    };
}
#endif
