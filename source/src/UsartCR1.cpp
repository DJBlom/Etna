#include "UsartCR1.h"

bool Usart::UsartCR1::UsartEnable(Hardware::Registers& usartRegister)
{
    if (usartRegister.BitEnable(Set::high << Bits::enabler) == false)
        return false;
    else
        return true;
}

bool Usart::UsartCR1::EightBitWordEnable(Hardware::Registers& usartRegister)
{
    if (usartRegister.BitEnable(Set::low << Bits::wordLength) == false)
        return false;
    else
        return true;
}

bool Usart::UsartCR1::TransmitterEnable(Hardware::Registers& usartRegister)
{
    if (usartRegister.BitEnable(Set::high << Bits::transmitter) == false)
        return false;
    else
        return true;
}
