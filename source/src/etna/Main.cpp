/**********************************************************************************
 * Contents: Main function.
 * Author: Dawid Blom.
 * Data: December 8, 2022.
 *
 * NOTE: This file contains the main function of the Etna application.
 *********************************************************************************/
#include "System.h"
#include "RegisterAddresses.h"
#include <cstdint>
 

using genericType = std::uint32_t;

volatile genericType* odr = GetAddress(registers::gpio::gpioa::GPIOA_ODR);

int main()
{

    Hal::System system;
    system.Initialize();
    system.RccConfiguration();
    system.ModeConfiguration();

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