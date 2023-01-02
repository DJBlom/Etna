
#ifndef _USART_CR1_H_ 
#define _USART_CR1_H_ 
#include "Registers.h"
namespace Usart {
    class UsartCR1 {
        public:
            UsartCR1() = default;
            UsartCR1(const UsartCR1&) = default;
            UsartCR1(UsartCR1&&) = default;
            UsartCR1& operator= (const UsartCR1&) = default;
            UsartCR1& operator= (UsartCR1&&) = default;
            virtual ~UsartCR1() = default;

            virtual bool UsartEnable(Hardware::Registers&);
            virtual bool EightBitWordEnable(Hardware::Registers&);
            virtual bool TransmitterEnable(Hardware::Registers&);
            
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
