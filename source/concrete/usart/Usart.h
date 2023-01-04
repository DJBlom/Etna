
#ifndef _USART_H_ 
#define _USART_H_ 
#include "Registers.h"
namespace Communication {
    class Usart {
        public:
            Usart() = default;
            Usart(const Usart&) = default;
            Usart(Usart&&) = default;
            Usart& operator= (const Usart&) = default;
            Usart& operator= (Usart&&) = default;
            virtual ~Usart() = default;

            virtual bool UsartEnable(Hardware::Registers&);
            virtual bool EightBitWordLengthUsed(Hardware::Registers&);
            virtual bool OneStopBitUsed(Hardware::Registers&);
            virtual bool HighBaudRateUsed(Hardware::Registers&);
            virtual bool TransmitterEnable(Hardware::Registers&);
            virtual bool WriteData(Hardware::Registers&, const registerType&&);
            virtual bool DataBufferIsEmpty(Hardware::Registers&);
            
        private:
            enum class Set {
                low = 0U,
                high = 1U
            };
            enum class Bits {
                transmitter = 3,
                wordLength = 12,
                enabler = 13
            };

            friend registerType operator << (const Set& set, const Bits& bit)
            {
                return static_cast<registerType> (set) << static_cast<registerType> (bit);
            }
    };
}
#endif
