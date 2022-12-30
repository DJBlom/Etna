#include "Apb1Peripheral.h"

bool Rcc::Apb1Peripheral::Tim2ResetClockControl()
{
    if (apb1.EnableRegisterBit(Clock::enable << Bit::tim2))
        return true;
    else
        return false;
}

bool Rcc::Apb1Peripheral::Tim3ResetClockControl()
{
    if (apb1.EnableRegisterBit(Clock::enable << Bit::tim3))
        return true;
    else
        return false;
}

bool Rcc::Apb1Peripheral::Tim4ResetClockControl()
{
    if (apb1.EnableRegisterBit(Clock::enable << Bit::tim4))
        return true;
    else
        return false;
}

bool Rcc::Apb1Peripheral::Tim5ResetClockControl()
{
    if (apb1.EnableRegisterBit(Clock::enable << Bit::tim5))
        return true;
    else
        return false;
}

bool Rcc::Apb1Peripheral::WwdgResetClockControl()
{
    if (apb1.EnableRegisterBit(Clock::enable << Bit::wwdg))
        return true;
    else
        return false;
}

bool Rcc::Apb1Peripheral::Spi2ResetClockControl()
{
    if (apb1.EnableRegisterBit(Clock::enable << Bit::spi2))
        return true;
    else
        return false;
}

bool Rcc::Apb1Peripheral::Spi3ResetClockControl()
{
    if (apb1.EnableRegisterBit(Clock::enable << Bit::spi3))
        return true;
    else
        return false;
}

bool Rcc::Apb1Peripheral::Usart2ResetClockControl()
{
    if (apb1.EnableRegisterBit(Clock::enable << Bit::usart2))
        return true;
    else
        return false;
}

bool Rcc::Apb1Peripheral::I2c1ResetClockControl()
{
    if (apb1.EnableRegisterBit(Clock::enable << Bit::i2c1))
        return true;
    else
        return false;
}

bool Rcc::Apb1Peripheral::I2c2ResetClockControl()
{
    if (apb1.EnableRegisterBit(Clock::enable << Bit::i2c2))
        return true;
    else
        return false;
}

bool Rcc::Apb1Peripheral::I2c3ResetClockControl()
{
    if (apb1.EnableRegisterBit(Clock::enable << Bit::i2c3))
        return true;
    else
        return false;
}

bool Rcc::Apb1Peripheral::PwrResetClockControl()
{
    if (apb1.EnableRegisterBit(Clock::enable << Bit::pwr))
        return true;
    else
        return false;
}
