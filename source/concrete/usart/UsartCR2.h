
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

        private:
            enum class NumStopBits {
                one = 0b00
            };

            enum class RegisterBit {
                twelve = 12
            };

            friend registerType operator<< (const NumStopBits& stopBit, const RegisterBit& bit)
            {
                return static_cast<registerType> (stopBit) << static_cast<registerType> (bit);
            }
    };
}
#endif 
