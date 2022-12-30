#include "Ahb1Peripheral.h"


bool Rcc::Ahb1Peripheral::GpioAResetClockControl()
{
    if (ahb1.EnableRegisterBit(Clock::enable << Reset::gpioa))
        return true;
    else
        return false;
}

bool Rcc::Ahb1Peripheral::GpioBResetClockControl()
{
    if (ahb1.EnableRegisterBit(Clock::enable << Reset::gpiob))
        return true;
    else
        return false;
}

bool Rcc::Ahb1Peripheral::GpioCResetClockControl()
{
    if (ahb1.EnableRegisterBit(Clock::enable << Reset::gpioc))
        return true;
    else
        return false;
}

bool Rcc::Ahb1Peripheral::GpioDResetClockControl()
{
    if (ahb1.EnableRegisterBit(Clock::enable << Reset::gpiod))
        return true;
    else
        return false;
}

bool Rcc::Ahb1Peripheral::GpioEResetClockControl()
{
    if (ahb1.EnableRegisterBit(Clock::enable << Reset::gpioe))
        return true;
    else
        return false;
}

bool Rcc::Ahb1Peripheral::GpioHResetClockControl()
{
    if (ahb1.EnableRegisterBit(Clock::enable << Reset::gpioh))
        return true;
    else
        return false;
}

bool Rcc::Ahb1Peripheral::CrcResetClockControl()
{
    if (ahb1.EnableRegisterBit(Clock::enable << Reset::crc))
        return true;
    else
        return false;
}

bool Rcc::Ahb1Peripheral::Dma1ResetClockControl()
{
    if (ahb1.EnableRegisterBit(Clock::enable << Reset::dma1))
        return false;
    else
        return true;
}

bool Rcc::Ahb1Peripheral::Dma2ResetClockControl()
{
    if (ahb1.EnableRegisterBit(Clock::enable << Reset::dma2))
        return false;
    else
        return true;
}





