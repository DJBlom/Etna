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


void DMA1_Stream6_IRQHandler()
{
    if ((*streamHisr >> 27) & 1U)
    {
        *streamHifcr = *streamHifcr | (1U << 27);
        *streamCtrl = *streamCtrl & ~(1U << 0);
    }
} 


int main()
{
    Hal::SystemPeripherals systemPeripheral;
    systemPeripheral.InitializePeripherals();
    systemPeripheral.ConfigureSystemPeripheralBusses();

    Hal::SystemGpios systemGpios;
    systemGpios.InitializeGpios();
    systemGpios.ConfigureSystemGpios();

    Communication::Usart debug;
    debug.OversamplingBySixteen(control1);
    debug.UsartEnable(control1);
    debug.EightBitWordLengthUsed(control1);
    debug.OneStopBitUsed(control2);
    debug.HighBaudRateUsed(baudRate);
    debug.TransmitterEnable(control1);
    debug.EnableDmaTransmission(control3);

    //const char* str = "\n\n\r Hello from my uart";
    char str[256] = "\n\n\r Hello from my uart!";



    // DMA configuration
    *streamCtrl = *streamCtrl | (0b100 << 25);
    *streamCtrl = *streamCtrl | (0b00 << 23);
    *streamCtrl = *streamCtrl | (0b00 << 21);
    *streamCtrl = *streamCtrl | (0b00 << 16);
    *streamCtrl = *streamCtrl | (0b00 << 13);
    *streamCtrl = *streamCtrl | (0b1 << 10);
    *streamCtrl = *streamCtrl | (0b0 << 8);
    *streamCtrl = *streamCtrl | (0b01 << 6);
    *streamCtrl = *streamCtrl | (0b0 << 4);
    


    *streamPar = registers::uart::uart2::USART2_DR;
    *streamMar = (std::uint32_t)str;
    *streamNdtr = sizeof(str);

    
//    *streamCtrl = *streamCtrl | (0b1 << 0);
//    *streamCtrl = *streamCtrl | (0b0 << 0);
    while (true)
    {

//        if(debug.TransmissionIsCompleted(status) == true)
//            debug.WriteData(data, str[0]);



        *streamCtrl = *streamCtrl | (0b1 << 0);
//        *streamCtrl = *streamCtrl | (0b0 << 0);

        //while (((*streamHisr >> 27) & 1U) == 0);

        //*streamHifcr = *streamHifcr | (1U << 27);
//        *streamCtrl = *streamCtrl & ~(1U << 0);

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


