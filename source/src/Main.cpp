
#include <cstdint>
#include "RegisterAddresses.h"
#include "GreenUserLED.h"


using generic_t = std::uint32_t;

volatile generic_t* busClock = GetAddress(registers::rcc::AHB1_ENABLE);
volatile generic_t* mode = GetAddress(registers::gpio::gpioa::GPIOA_MODER);
volatile generic_t* odr = GetAddress(registers::gpio::gpioa::GPIOA_ODR);

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
