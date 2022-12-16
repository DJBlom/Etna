/**********************************************************************************
 * Contents: Main function.
 *
 * Author: Dawid Blom.
 *
 * Data: December 8, 2022.
 *
 * NOTE: This file contains the main function of the Etna application.
 *********************************************************************************/
#include "PeripheralClocks.h"
#include "RegisterAddresses.h"
#include <cstdint>

namespace SystemInit {
    Rcc::PeripheralClocks clocks;
}

using genericType = std::uint32_t;

volatile genericType* rcc = reinterpret_cast<genericType*> (registers::rcc::AHB1_ENABLE);
volatile genericType* mode = reinterpret_cast<genericType*> (registers::gpio::gpioa::GPIOA_MODER);
volatile genericType* odr = reinterpret_cast<genericType*> (registers::gpio::gpioa::GPIOA_ODR);

class LED {
    public:
        LED(volatile genericType* rcc, volatile genericType* mode, volatile genericType* odr)
        {
            this->odr = odr;
            *rcc = *rcc | (Bits::odrOn << Pos::clock);
            *mode = *mode | (Bits::modeOn << Pos::outputMode);
        }

        void EnableLED()
        {
            *this->odr = *this->odr | (Bits::odrOn << Pos::odr); 
        }

        void DisableLED()
        {
            *this->odr = *this->odr & ~(Bits::odrOn << Pos::odr); 
        }

    private:
        volatile genericType* odr{nullptr};

        enum class Pos {
            clock = 0,
            odr = 5,
            outputMode = 10
        };

        enum class Bits {
            odrOn = 0b1,
            modeOn = 0b01
        };

        friend genericType operator<< (const Bits& bit, const Pos& pos)
        {
            return static_cast<genericType> (bit) << static_cast<genericType> (pos);
        }

};



int main()
{
//    SystemInit::clocks.ConfigurePeripheralClocks();
    LED led{rcc, mode, odr};

    while (true)
    {
        led.EnableLED();
        for (int i = 0; i < 500000; i++)
        {

        }

        led.DisableLED();
        for (int i = 0; i < 500000; i++)
        {

        }
    }





}
