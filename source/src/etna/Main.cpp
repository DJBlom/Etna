/**********************************************************************************
 * Contents: Main function.
 *
 * Author: Dawid Blom.
 *
 * Data: December 8, 2022.
 *
 * NOTE: This file contains the main function of the Etna application.
 *********************************************************************************/
#include "MCURegisters.h"
#include "RegisterAddresses.h"
#include <cstdint>
 

using genericType = std::uint32_t;

genericType* Address(addressType address)
{
    return reinterpret_cast<addressType*> (address);
}

volatile genericType* rcc = Address(registers::rcc::AHB1_ENABLE);
////reinterpret_cast<volatile genericType*> (registers::rcc::AHB1_ENABLE);
volatile genericType* mode = Address(registers::gpio::gpioa::GPIOA_MODER);
volatile genericType* odr = Address(registers::gpio::gpioa::GPIOA_ODR);

int main()
{
    Hardware::MCURegisters gpioRcc{rcc};
    gpioRcc.EnableRegisterBit(1U << 0);

    Hardware::MCURegisters gpioMode{mode};
    gpioMode.EnableRegisterBit(0b01 << 10);

    Hardware::MCURegisters led{odr};
    while (true)
    {
        led.EnableRegisterBit(1U << 5);
        for (int i = 0; i < 500000; i++)
        {

        }

        led.DisableRegister(1U << 5);
        for (int i = 0; i < 500000; i++)
        {

        }
    }
}
