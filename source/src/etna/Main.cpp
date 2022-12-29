/**********************************************************************************
 * Contents: Main function.
 * Author: Dawid Blom.
 * Data: December 8, 2022.
 *
 * NOTE: This file contains the main function of the Etna application.
 *********************************************************************************/
#include "GpioMode.h"
#include "Ahb1Peripheral.h"
#include "RegisterAddresses.h"
#include <cstdint>
 

using genericType = std::uint32_t;

volatile genericType* rcc = GetAddress(registers::rcc::AHB1_ENABLE);
volatile genericType* mode = GetAddress(registers::gpio::gpioa::GPIOA_MODER);
volatile genericType* odr = GetAddress(registers::gpio::gpioa::GPIOA_ODR);

int main()
{
    Rcc::Ahb1Peripheral ahb1{rcc};
    ahb1.GPIOAResetClockControl();

    Gpio::GpioMode gpioMode{mode};
    gpioMode.EnableOutputMode(10);

    while (true)
    {
        *odr = *odr | (1U << 5);
        for (int i = 0; i < 500000; i++)
        {

        }

        *odr = *odr & ~(1U << 5);
        for (int i = 0; i < 500000; i++)
        {

        }
    }
}
