#include "Ahb1Peripheral.h"


bool Rcc::Ahb1Peripheral::GpioAResetClockControl(Hardware::Registers& ahb1Register)
{
    if (ahb1Register.BitEnable(Clock::enable << Reset::gpioa) == false)
        return false;
    else
        return true;
}

bool Rcc::Ahb1Peripheral::GpioBResetClockControl(Hardware::Registers& ahb1Register)
{
    if (ahb1Register.BitEnable(Clock::enable << Reset::gpiob) == false)
        return false;
    else
        return true;
}

bool Rcc::Ahb1Peripheral::GpioCResetClockControl(Hardware::Registers& ahb1Register)
{
    if (ahb1Register.BitEnable(Clock::enable << Reset::gpioc) == false)
        return false;
    else
        return true;
}

bool Rcc::Ahb1Peripheral::GpioDResetClockControl(Hardware::Registers& ahb1Register)
{
    if (ahb1Register.BitEnable(Clock::enable << Reset::gpiod) == false)
        return false;
    else
        return true;
}

bool Rcc::Ahb1Peripheral::GpioEResetClockControl(Hardware::Registers& ahb1Register)
{
    if (ahb1Register.BitEnable(Clock::enable << Reset::gpioe) == false)
        return false;
    else
        return true;
}

bool Rcc::Ahb1Peripheral::GpioHResetClockControl(Hardware::Registers& ahb1Register)
{
    if (ahb1Register.BitEnable(Clock::enable << Reset::gpioh) == false)
        return false;
    else
        return true;
}

bool Rcc::Ahb1Peripheral::CrcResetClockControl(Hardware::Registers& ahb1Register)
{
    if (ahb1Register.BitEnable(Clock::enable << Reset::crc) == false)
        return false;
    else
        return true;
}

bool Rcc::Ahb1Peripheral::Dma1ResetClockControl(Hardware::Registers& ahb1Register)
{
    if (ahb1Register.BitEnable(Clock::enable << Reset::dma1) == false)
        return false;
    else
        return true;
}

bool Rcc::Ahb1Peripheral::Dma2ResetClockControl(Hardware::Registers& ahb1Register)
{
    if (ahb1Register.BitEnable(Clock::enable << Reset::dma2) == false)
        return false;
    else
        return true;
}





