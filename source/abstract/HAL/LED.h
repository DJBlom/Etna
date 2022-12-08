#ifndef _LED_H_
#define _LED_H_
#include <cstdint>
using ledType = std::uint32_t;
namespace HAL {
    class LED {
        public: 
            virtual ~LED() = default;

            virtual void EnableLED(ledType&) = 0;
            virtual void DisableLED(ledType&) = 0;
    };
}
#endif
