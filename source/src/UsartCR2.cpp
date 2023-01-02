#include "UsartCR2.h"

bool Usart::UsartCR2::UseOneStopBit(Hardware::Registers& usartRegister)
{
    if (usartRegister.BitEnable(0b00 << 12) == false)
        return false;
    else
        return true;
}
