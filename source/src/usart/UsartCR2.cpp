#include "UsartCR2.h"

bool Usart::UsartCR2::UseOneStopBit(Hardware::Registers& usartRegister)
{
    if (usartRegister.BitEnable(NumStopBits::one << RegisterBit::twelve) == false)
        return false;
    else
        return true;
}
