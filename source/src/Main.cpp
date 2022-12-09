/********************************************************************************
 * Contents: Main function of Etna.
 *
 * Author: Dawid Blom.
 *
 * Date: December 8, 2022.
 *
 * Note: Starts the whole application.
 *******************************************************************************/
#include <cstdint>
#include "RegisterAddresses.h"
#include "GreenUserLED.h"

int main()
{
    HAL::GreenUserLED led{busClock, mode, odr};


    generic_t bitPosition = (1U << 5);
    while (true)
    {
        led.EnableLED(bitPosition);
        for (int i = 0; i < 500000; i++)
        {

        }

        led.DisableLED(bitPosition);
        for (int i = 0; i < 500000; i++)
        {

        }
    }
}
