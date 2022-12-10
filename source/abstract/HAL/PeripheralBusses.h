

#ifndef _PERIPHERAL_BUSSES_H_ 
#define _PERIPHERAL_BUSSES_H_ 
#include <cstdint>
using boardBusType = std::uint32_t;
namespace Hal {
    class PeripheralBusses {
        public:
            virtual ~PeripheralBusses() = default;
            virtual bool EnablePeripheralBusFor(boardBusType busAddress, boardBusType&&) = 0;
    };
}

#endif
