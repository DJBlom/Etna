/**********************************************************************************
 * Contents: Main function.
 * Author: Dawid Blom.
 * Data: December 8, 2022.
 *
 * NOTE: This file contains the main function of the Etna application.
 *********************************************************************************/
#include "SystemPeripherals.h"
#include "SystemGpios.h"
#include "SystemLogger.h"
#include "RegisterAddresses.h"
#include "Usart.h"
#include "Uart2DmaController.h"
#include "MCURegisters.h"
#include <cstdint>
#include <string.h>
 

using genericType = std::uint32_t;

volatile genericType* streamHisr = GetAddress(registers::dma::dma1::STREAM6_DMA_HISR);
volatile genericType* streamHifcr = GetAddress(registers::dma::dma1::STREAM6_DMA_HIFCR);
volatile genericType* streamCtrl = GetAddress(registers::dma::dma1::STREAM6_DMA_CR);
volatile genericType* streamNdtr = GetAddress(registers::dma::dma1::STREAM6_DMA_NDTR);
volatile genericType* streamPar = GetAddress(registers::dma::dma1::STREAM6_DMA_PAR);
volatile genericType* streamMar = GetAddress(registers::dma::dma1::STREAM6_DMA_M0AR);

volatile genericType* ahb1Rcc = GetAddress(registers::rcc::AHB1_ENABLE);
volatile genericType* apb1Rcc = GetAddress(registers::rcc::APB1_ENABLE);

volatile genericType* mode = GetAddress(registers::gpio::gpioa::GPIOA_MODER);

volatile genericType* lowAF = GetAddress(registers::gpio::gpioa::GPIOA_AFRL);

volatile genericType* odr = GetAddress(registers::gpio::gpioa::GPIOA_ODR);

volatile genericType* ctl1 = GetAddress(registers::uart::uart2::USART2_CR1);
volatile genericType* ctl2 = GetAddress(registers::uart::uart2::USART2_CR2);
volatile genericType* ctl3 = GetAddress(registers::uart::uart2::USART2_CR3);
volatile genericType* dr = GetAddress(registers::uart::uart2::USART2_DR);
volatile genericType* baud = GetAddress(registers::uart::uart2::USART2_BRR);
volatile genericType* st = GetAddress(registers::uart::uart2::USART2_SR);

Hardware::MCURegisters control1{ctl1};
Hardware::MCURegisters control2{ctl2};
Hardware::MCURegisters control3{ctl3};
Hardware::MCURegisters baudRate{baud};
Hardware::MCURegisters status{st};
Hardware::MCURegisters data{dr};
Hardware::MCURegisters controlRegister{streamCtrl};



int main()
{
    Hal::SystemPeripherals systemPeripheral;
    systemPeripheral.InitializePeripherals();
    systemPeripheral.ConfigureSystemPeripheralBusses();

    Hal::SystemGpios systemGpios;
    systemGpios.InitializeGpios();
    systemGpios.ConfigureSystemGpios();

    Hal::SystemLogger debug;
    debug.InitializeSystemLogger();

    while (true)
    {
        //*odr = *odr | (1U << 5);
        debug.LogMessage("Blink\n\r");
        for (int i = 0; i < 500000; i++)
        {

        }

        //*odr = *odr & ~(1U << 5);
        for (int i = 0; i < 500000; i++)
        {

        }
    }
}


