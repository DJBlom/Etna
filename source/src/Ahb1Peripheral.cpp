#include "Ahb1Peripheral.h"


bool Rcc::Ahb1Peripheral::GPIOAResetClockControl()
{
    if (ahb1.EnableRegisterBit(Clock::enable << Reset::gpioa))
        return true;
    else
        return false;
}

bool Rcc::Ahb1Peripheral::GPIOBResetClockControl()
{
    if (ahb1.EnableRegisterBit(Clock::enable << Reset::gpiob))
        return true;
    else
        return false;
}

bool Rcc::Ahb1Peripheral::GPIOCResetClockControl()
{
    if (ahb1.EnableRegisterBit(Clock::enable << Reset::gpioc))
        return true;
    else
        return false;
}

bool Rcc::Ahb1Peripheral::GPIODResetClockControl()
{
    if (ahb1.EnableRegisterBit(Clock::enable << Reset::gpiod))
        return true;
    else
        return false;
}

bool Rcc::Ahb1Peripheral::GPIOEResetClockControl()
{
    if (ahb1.EnableRegisterBit(Clock::enable << Reset::gpioe))
        return true;
    else
        return false;
}

bool Rcc::Ahb1Peripheral::GPIOHResetClockControl()
{
    if (ahb1.EnableRegisterBit(Clock::enable << Reset::gpioh))
        return true;
    else
        return false;
}

bool Rcc::Ahb1Peripheral::CRCResetClockControl()
{
    if (ahb1.EnableRegisterBit(Clock::enable << Reset::crc))
        return true;
    else
        return false;
}

bool Rcc::Ahb1Peripheral::DMA1ResetClockControl()
{
    if (ahb1.EnableRegisterBit(Clock::enable << Reset::dma1))
        return false;
    else
        return true;
}

bool Rcc::Ahb1Peripheral::DMA2ResetClockControl()
{
    if (ahb1.EnableRegisterBit(Clock::enable << Reset::dma2))
        return false;
    else
        return true;
}
