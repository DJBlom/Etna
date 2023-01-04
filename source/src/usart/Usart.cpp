#include "Usart.h"

bool Communication::Usart::UsartEnable(Hardware::Registers& uartRegister)
{
    if (uartRegister.BitEnable(1U << 13) == false)
        return false;
    else
        return true;
}

bool Communication::Usart::EightBitWordLengthUsed(Hardware::Registers& uartRegister)
{
    if (uartRegister.BitEnable(0U << 12) == false)
        return false;
    else
        return true;
}

bool Communication::Usart::OneStopBitUsed(Hardware::Registers& uartRegister)
{
    if (uartRegister.BitEnable(0b00 << 12) == false)
        return false;
    else
        return true;
}

bool Communication::Usart::HighBaudRateUsed(Hardware::Registers& uartRegister)
{
    if (uartRegister.BitsEnable(0x8b) == false)
        return false;
    else
        return true;
}

bool Communication::Usart::TransmitterEnable(Hardware::Registers& uartRegister)
{
    if (uartRegister.BitEnable(1U << 3) == false)
        return false;
    else
        return true;
}

bool Communication::Usart::WriteData(Hardware::Registers& uartRegister, const registerType&& character)
{
    if (uartRegister.BitsEnable(character & 0xff) == false)
        return false;
    else
        return true;
}

bool Communication::Usart::DataBufferIsEmpty(Hardware::Registers& statusRegister)
{
    if (statusRegister.BitsEnable(0x40) == false)
        return false;
    else
        return true;
}
