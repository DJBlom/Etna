#include "Apb1Peripheral.h"

bool Rcc::Apb1Peripheral::Tim2ResetClockControl(Hardware::Registers& apb1Register)
{
    if (apb1Register.BitEnable(Clock::enable << Bit::tim2) == false)
        return false;
    else
        return true;
}

bool Rcc::Apb1Peripheral::Tim3ResetClockControl(Hardware::Registers& apb1Register)
{
    if (apb1Register.BitEnable(Clock::enable << Bit::tim3) == false)
        return false;
    else
        return true;
}

bool Rcc::Apb1Peripheral::Tim4ResetClockControl(Hardware::Registers& apb1Register)
{
    if (apb1Register.BitEnable(Clock::enable << Bit::tim4) == false)
        return false;
    else
        return true;
}

bool Rcc::Apb1Peripheral::Tim5ResetClockControl(Hardware::Registers& apb1Register)
{
    if (apb1Register.BitEnable(Clock::enable << Bit::tim5) == false)
        return false;
    else
        return true;
}

bool Rcc::Apb1Peripheral::WwdgResetClockControl(Hardware::Registers& apb1Register)
{
    if (apb1Register.BitEnable(Clock::enable << Bit::wwdg) == false)
        return false;
    else
        return true;
}

bool Rcc::Apb1Peripheral::Spi2ResetClockControl(Hardware::Registers& apb1Register)
{
    if (apb1Register.BitEnable(Clock::enable << Bit::spi2) == false)
        return false;
    else
        return true;
}

bool Rcc::Apb1Peripheral::Spi3ResetClockControl(Hardware::Registers& apb1Register)
{
    if (apb1Register.BitEnable(Clock::enable << Bit::spi3) == false)
        return false;
    else
        return true;
}

bool Rcc::Apb1Peripheral::Usart2ResetClockControl(Hardware::Registers& apb1Register)
{
    if (apb1Register.BitEnable(Clock::enable << Bit::usart2) == false)
        return false;
    else
        return true;
}

bool Rcc::Apb1Peripheral::I2c1ResetClockControl(Hardware::Registers& apb1Register)
{
    if (apb1Register.BitEnable(Clock::enable << Bit::i2c1) == false)
        return false;
    else 
        return true;
}

bool Rcc::Apb1Peripheral::I2c2ResetClockControl(Hardware::Registers& apb1Register)
{
    if (apb1Register.BitEnable(Clock::enable << Bit::i2c2) == false)
        return false;
    else 
        return true;
}

bool Rcc::Apb1Peripheral::I2c3ResetClockControl(Hardware::Registers& apb1Register)
{
    if (apb1Register.BitEnable(Clock::enable << Bit::i2c3) == false)
        return false;
    else
        return true;
}

bool Rcc::Apb1Peripheral::PwrResetClockControl(Hardware::Registers& apb1Register)
{
    if (apb1Register.BitEnable(Clock::enable << Bit::pwr) == false)
        return false;
    else 
        return true;
}
