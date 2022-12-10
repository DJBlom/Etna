

#ifndef _BOARD_BUS_H_ 
#define _BOARD_BUS_H_ 
#include "PeripheralBusses.h"
namespace Hal {
    class BoardBus : public PeripheralBusses {
        public:
            BoardBus() = default;
            //explicit BoardBus(boardBusType busAddr): busAddress{busAddr} {}
            BoardBus(const BoardBus&) = delete;
            BoardBus(BoardBus&&) = delete;
            BoardBus& operator= (const BoardBus&) = delete;
            BoardBus& operator= (BoardBus&&) = delete;
            ~BoardBus() = default;

            bool EnablePeripheralBusFor(boardBusType busAddress, boardBusType&&); 

        private:
            //boardBusType busAddress{0};
    };
}
#endif
