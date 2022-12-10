

#ifndef _BOARD_BUSSES_H_ 
#define _BOARD_BUSSES_H_ 
#include "BoardBus.h"
//#include "RegisterAddresses.h"
//volatile boardBusType* ahb1Bus = GetAddress(registers::rcc::AHB1_ENABLE);
//Hal::BoardBus ahb1{ahb1Bus};
//ahb1.EnablePeripheralBusFor(1U << 0);
namespace Init {
    class BoardBusses {
        public:
            BoardBusses() = default;
            BoardBusses(const BoardBusses&) = delete;
            BoardBusses(BoardBusses&&) = delete;
            BoardBusses& operator= (const BoardBusses&) = delete;
            BoardBusses& operator= (BoardBusses&&) = delete;
            ~BoardBusses() = default;

            bool InitializeBoardBusses();

        private:
//            Hal::BoardBus ahb1{nullptr};

            enum class ports {
                gpioa
            };

            enum class bits {
                off,
                on
            };

            friend boardBusType operator<< (const bits& bit, const ports& port)
            {
                return static_cast<boardBusType> (bit) << static_cast<boardBusType> (port);
            }
    };
}
#endif
