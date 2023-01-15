#include "Usart.h"

bool Communication::Usart::OversamplingBySixteen(Hardware::Registers& cr1Register)
{
    if (cr1Register.EnableBit(Set::low << Bit::over) == false)
        return false;
    else
        return true;
}

bool Communication::Usart::UsartEnable(Hardware::Registers& cr1Register)
{
    if (cr1Register.EnableBit(Set::high << Bit::eu) == false)
        return false;
    else
        return true;
}

bool Communication::Usart::EightBitWordLengthUsed(Hardware::Registers& cr1Register)
{
    if (cr1Register.EnableBit(Set::low << Bit::m) == false)
        return false;
    else
        return true;
}

bool Communication::Usart::OneStopBitUsed(Hardware::Registers& cr2Register)
{
    if (cr2Register.EnableBit(Set::stop << Bit::st) == false)
        return false;
    else
        return true;
}

bool Communication::Usart::HighBaudRateUsed(Hardware::Registers& brrRegister)
{
    if (brrRegister.SetBits(Mask::write & Set::baud) == false)
        return false;
    else
        return true;
}

bool Communication::Usart::TransmitterEnable(Hardware::Registers& cr1Register)
{
    if (cr1Register.EnableBit(Set::high << Bit::te) == false)
        return false;
    else
        return true;
}

bool Communication::Usart::EnableDmaTransmission(Hardware::Registers& cr3Register)
{
    if (cr3Register.EnableBit(Set::high << Bit::dmat) == false)
        return false;
    else
        return true;
}

bool Communication::Usart::EnableDmaReceiver(Hardware::Registers& cr3Register)
{
    if (cr3Register.EnableBit(Set::high << Bit::dmar) == false)
        return false;
    else
        return true;
}

bool Communication::Usart::WriteData(Hardware::Registers& drRegister, const char& character)
{
    if (drRegister.SetBits(character & Mask::write) == false)
        return false;
    else
        return true;
}

bool Communication::Usart::TransmissionIsCompleted(Hardware::Registers& stRegister)
{
    if (stRegister.CheckBit(Set::high << Bit::tc) != 0)
        return false;
    else
        return true;
}

bool Communication::Usart::DMATransmissionIsCompleted(Hardware::Registers& stRegister)
{
    stRegister.Disable(Set::high << Bit::tc);
    if (stRegister.CheckBit(Set::high << Bit::tc) != 0)
        return false;
    else
        return true;
}
