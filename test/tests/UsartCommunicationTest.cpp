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
 * 6) Enable DMA mode for uart transmission
 * 7) Enable DMA mode for uart receiver
 * 8) Send data via the uart (Done)
 * 9) Make sure the stransmission was completed (Done)
 * 10) Make sure transmission is configured for DMA by setting the TC bit to 0 (Done)
 **/
TEST_GROUP(UsartTest)
{
    bool functionWorked{false};
    genericType expected{0};
    Hardware::MCURegisters uartRegister;
    Communication::Usart uart; 
    void setup()
    {
        functionWorked = false;
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
    functionWorked = uart.UsartEnable(uartRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(UsartTest, SetTheWordLengthToBeUsed)
{
    expected = 0;
    functionWorked = uart.EightBitWordLengthUsed(uartRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(UsartTest, SetTheNumberOfStopBitsToBeUsed)
{
    expected = 0;
    functionWorked = uart.OneStopBitUsed(uartRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(UsartTest, SetTheBaudRateToBeUsed)
{
    expected = 0x8b;
    functionWorked = uart.HighBaudRateUsed(uartRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(UsartTest, EnableTheTransmitterBitToTransmitData)
{
    expected = 8;
    functionWorked = uart.TransmitterEnable(uartRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(UsartTest, EnableDmaModeForTransmission)
{
    expected = 128;
    functionWorked = uart.EnableDmaTransmission(uartRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(UsartTest, EnableDmaModeForReceiver)
{
    expected = 64;
    functionWorked = uart.EnableDmaReceiver(uartRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(UsartTest, InputTheDataToBeSent)
{
    expected = 'C';
    functionWorked = uart.WriteData(uartRegister, 'C');

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(UsartTest, MakeSureTheTransmissionWasCompleted)
{
    functionWorked = uart.WriteData(uartRegister, 'V');

    CHECK(functionWorked);
    CHECK_EQUAL(true, uart.TransmissionIsCompleted(uartRegister));
}

TEST(UsartTest, ConfigureTheTransmissionForDmaTransfers)
{
    expected = 22;
    uart.WriteData(uartRegister, 'V');
    functionWorked = uart.DMATransmissionIsCompleted(uartRegister);
        
    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(UsartTest, ConfigureOversamplingMode)
{
    expected = 0;
    functionWorked = uart.OversamplingBySixteen(uartRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}
