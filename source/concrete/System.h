
#ifndef _SYSTEM_H_ 
#define _SYSTEM_H_ 
#include <cstdint>
#include "Ahb1Peripheral.h"
#include "Apb1Peripheral.h"
#include "GpioMode.h"
using systemType = std::uint32_t;
namespace Hal {
    class System {
        public:
            System() = default;
            System(const System&) = delete;
            System(System&&) = delete;
            System& operator= (const System&) = delete;
            System& operator= (System&&) = delete;
            virtual ~System() = default;

            virtual void Initialize();
            virtual void RccConfiguration();
            virtual void ModeConfiguration();
            
        private:
            enum class Pin: uint32_t {
                five = 5 * 2
            };

            virtual systemType ConvertPinToSystemType(const Pin&);

        private:
            Rcc::Ahb1Peripheral ahb1;
//            Rcc::Apb1Peripheral apb1;
            Gpio::GpioMode modeA;
    };
}
#endif
