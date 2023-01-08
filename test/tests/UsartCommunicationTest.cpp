/********************************************************************************
 * Contents: Test Fixture of the UsartCommunication.
 * Author: Dawid Blom.
 * Date: January 2, 2023.
 *
 * Note: 
 *******************************************************************************/
#include "MCURegisters.h"
#include "Usart.h"
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
 * 1) Enable the uart for transmission (Done)
 * 2) Define a 8-bit word length to be transmitted (Done)
 * 3) Set a single stop bit when transmitting (Done)
 * 4) Set the baud rate to 115200 (Done)
 * 5) Enable the transmitter by sending a idle frame as first transmission (Done)
 * 6) Send data via the uart (Done)
 * 7) Make sure the stransmission was completed (Done)
 * 8) Make sure transmission is configured for DMA by setting the TC bit to 0
**/
TEST_GROUP(UsartTest)
{
    genericType expected{0};
    Hardware::MCURegisters uartRegister;
    Communication::Usart uart; 
    void setup()
    {
        virtualAddress = 0;
        uartRegister = Hardware::MCURegisters{&virtualAddress};
    }

    void teardown()
    {
    }
};

TEST(UsartTest, EnableTheUsart)
{
    expected = 8192;
    uart.UsartEnable(uartRegister);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(UsartTest, SetTheWordLengthToBeUsed)
{
    expected = 0;
    uart.EightBitWordLengthUsed(uartRegister);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(UsartTest, SetTheNumberOfStopBitsToBeUsed)
{
    expected = 0;
    uart.OneStopBitUsed(uartRegister);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(UsartTest, SetTheBaudRateToBeUsed)
{
    expected = 0x8b;
    uart.HighBaudRateUsed(uartRegister);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(UsartTest, EnableTheTransmitterBitToTransmitData)
{
    expected = 8;
    uart.TransmitterEnable(uartRegister);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(UsartTest, InputTheDataToBeSent)
{
    expected = 'C';
    uart.WriteData(uartRegister, 'C');

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(UsartTest, MakeSureTheTransmissionWasCompleted)
{
    expected = 99;
    uart.WriteData(uartRegister, 'V');

    CHECK_EQUAL(false, uart.TransmissionIsCompleted(uartRegister));
}

TEST(UsartTest, ConfigureTheTransmissionForDmaTransfers)
{
    expected = 22;
    uart.WriteData(uartRegister, 'V');

    uart.DMATransmissionIsCompleted(uartRegister);
        
    CHECK_EQUAL(expected, virtualAddress);
}