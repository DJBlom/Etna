

#ifndef _UART2_DMA_CONTROLLER_H_ 
#define _UART2_DMA_CONTROLLER_H_ 
#include "Registers.h"
namespace Dma {
    class Uart2DmaController {
        public:
            Uart2DmaController() = default;
            Uart2DmaController(const Uart2DmaController&) = default;
            Uart2DmaController(Uart2DmaController&&) = default;
            Uart2DmaController& operator= (const Uart2DmaController&) = default;
            Uart2DmaController& operator= (Uart2DmaController&&) = default;
            virtual ~Uart2DmaController() = default;

            virtual bool EnableChannelFour(Hardware::Registers&);
            virtual bool Use32BitMemorySize(Hardware::Registers&);
            virtual bool LetMemoryIncrement(Hardware::Registers&);
            virtual bool StreamFromMemoryToPeripheral(Hardware::Registers&);
            virtual bool TransferData(Hardware::Registers&);

        private:
            enum class Position {
                chSel = 25, memSize = 13,
                memInc = 10, direction = 6, enable = 0,
            };

            enum class Bits {
                four = 0b100, word = 0b10, increment = 0b1,
                memToPeriph = 0b01, send = 0b1,
            };

            friend registerType operator<< (const Bits& bits, const Position& position)
            {
                return static_cast<registerType> (bits) << static_cast<registerType> (position);
            }
    };
}
#endif

