
#ifndef _USART_CR2_H_ 
#define _USART_CR2_H_ 
#include "Registers.h"
namespace Usart {
    class UsartCR2 {
        public:
            UsartCR2() = default;
            UsartCR2(const UsartCR2&) = default;
            UsartCR2(UsartCR2&&) = default;
            UsartCR2& operator= (const UsartCR2&) = default;
            UsartCR2& operator= (UsartCR2&&) = default;
            virtual ~UsartCR2() = default;

            virtual bool UseOneStopBit(Hardware::Registers&);
    };
}
#endif 
