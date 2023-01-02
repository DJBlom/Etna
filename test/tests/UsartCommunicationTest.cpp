/********************************************************************************
 * Contents: Test Fixture of the UsartCommunication.
 * Author: Dawid Blom.
 * Date: January 2, 2023.
 *
 * Note: 
 *******************************************************************************/
#include "MCURegisters.h"
#include "UsartCR1.h"
#include <cstdint>


extern "C" 
{

}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using genericType = std::uint32_t;
static genericType virtualAddress{0};
/**
 * USART COMMUNICATION TEST LIST
 *
 * 1) Enable the USART by writing the UE bit in USART_CR1 register to 1
 * 2) Program the M bit in USART_CR1 to define the word length.
 * 3) Program the number of stop bits in USART_CR2.
 * 4) Select the desired baud rate using the USART_BRR register.
 * 5) Set the TE bit in USART_CR1 to send an idle frame as first transmission.
 * 6) Write the data to send in the USART_DR register (this clears the TXE bit). Repeat this
 * for each data to be transmitted in case of single buffer.
 * 7) After writing the last data into the USART_DR register, wait until TC=1. This indicates
 * that the transmission of the last frame is complete. This is required for instance when
 * the USART is disabled or enters the Halt mode to avoid corrupting the last
 * transmission.
**/



/**
 * USART CR1 TEST LIST
 *
 * 1) Enable usart for transmission (Done)
 * 2) Set the word length to eight bits (Done)
 * 3) Set the transmitter bit to send a idle frame (Done)
 **/
TEST_GROUP(UsartCR1Test)
{
    genericType expected{0};
    Hardware::MCURegisters uartRegister;
    Communication::UsartCR1 uart2; 
    void setup()
    {
        virtualAddress = 0;
        uartRegister = Hardware::MCURegisters{&virtualAddress};
    }

    void teardown()
    {
    }
};

TEST(UsartCR1Test, EnableTheUsartTransmitter)
{
    expected = 8;
    uart2.TransmitterEnable(uartRegister);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(UsartCR1Test, DefineTheWordLengthOfTheData)
{
    expected = 0;
    uart2.EightBitWordEnable(uartRegister);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(UsartCR1Test, EnableTheUsart)
{
    expected = 8192;
    uart2.UsartEnable(uartRegister);

    CHECK_EQUAL(expected, virtualAddress);
}

