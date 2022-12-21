
#ifndef _RCC_CLOCKS_H_ 
#define _RCC_CLOCKS_H_ 
#include <cstdint>
using clockType = std::uint32_t;
namespace Rcc {
    class RccClocks {
        public:
            virtual ~RccClocks() = default;
            virtual void ConfigurePeripheralClocks() = 0;
    };
}
#endif
