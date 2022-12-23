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
#include "Peripherals.h"
#include "RegisterAddresses.h"
#include <cstdint>
 

using genericType = std::uint32_t;

volatile genericType* mode = GetAddress(registers::gpio::gpioa::GPIOA_MODER);
volatile genericType* odr = GetAddress(registers::gpio::gpioa::GPIOA_ODR);

int main()
{
    Hal::Peripherals board;
    board.ConfigurePeripheralClocks();

    Hardware::MCURegisters gpios;
    genericType bits{0b01 << 10};
    gpios.EnableRegisterBit(mode, bits);

    bits = 1U << 5;
    while (true)
    {
        gpios.EnableRegisterBit(odr, bits);
        for (int i = 0; i < 500000; i++)
        {

        }

        gpios.DisableRegister(odr, bits);
        for (int i = 0; i < 500000; i++)
        {

        }
    }
}
