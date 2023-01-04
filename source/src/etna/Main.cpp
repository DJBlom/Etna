/**********************************************************************************
 * Contents: Main function.
 * Author: Dawid Blom.
 * Data: December 8, 2022.
 *
 * NOTE: This file contains the main function of the Etna application.
 *********************************************************************************/
#include "SystemPeripherals.h"
#include "SystemGpios.h"
#include "RegisterAddresses.h"
#include "Usart.h"
#include "MCURegisters.h"
#include <cstdint>
 

using genericType = std::uint32_t;

volatile genericType* mode = GetAddress(registers::gpio::gpioa::GPIOA_MODER);
volatile genericType* lowAF = GetAddress(registers::gpio::gpioa::GPIOA_AFRL);
volatile genericType* odr = GetAddress(registers::gpio::gpioa::GPIOA_ODR);
volatile genericType* ctl1 = GetAddress(registers::uart::uart2::USART2_CR1);
volatile genericType* ctl2 = GetAddress(registers::uart::uart2::USART2_CR2);
volatile genericType* ctl3 = GetAddress(registers::uart::uart2::USART2_CR3);
volatile genericType* dr = GetAddress(registers::uart::uart2::USART2_DR);
volatile genericType* baud = GetAddress(registers::uart::uart2::USART2_BRR);
volatile genericType* st = GetAddress(registers::uart::uart2::USART2_DR);

Hardware::MCURegisters control1{ctl1};
Hardware::MCURegisters control2{ctl2};
Hardware::MCURegisters baudRate{baud};
Hardware::MCURegisters status{st};
Hardware::MCURegisters data{dr};

//void WriteData(int ch);

int main()
{

    Hal::SystemPeripherals systemPeripheral;
    systemPeripheral.InitializePeripherals();
    systemPeripheral.ConfigureSystemPeripheralBusses();

    Hal::SystemGpios systemGpios;
    systemGpios.InitializeGpios();
    systemGpios.ConfigureSystemGpios();

//    Communication::Usart debug;
//    debug.UsartEnable(control1);
//    debug.EightBitWordLengthUsed(control1);
//    debug.OneStopBitUsed(control2);
//    debug.HighBaudRateUsed(baudRate);
//    debug.TransmitterEnable(control1);


   
    *lowAF = *lowAF | (7 << 12);
    *lowAF = *lowAF | (7 << 8);
    *mode = *mode | (1 << 7);
    *mode = *mode | (1 << 5);
    *baud = 0x8b;
    *ctl1 = *ctl1 | (1 << 2);
    *ctl1 = *ctl1 | (1 << 3);
    *ctl1 = *ctl1 | (1 << 13);


    while (true)
    {
        if (!(*st & (1 << 7)))
            *dr = ('D' & 0xff);
//        if (debug.DataBufferIsEmpty(status))
//            debug.WriteData(data, 'D');
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

//void WriteData(int ch)
//{
//    std::uint32_t _ch = ch & 0xff;
//    while (!(*st & 0x80))
//    {
//        *dr = _ch;
//    }
//}

