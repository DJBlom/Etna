/********************************************************************************
 * Contents: Test Fixture for DMAController.
 * Author: Dawid Blom.
 * Date: January 8, 2023.
 *
 * Note: 
 *******************************************************************************/
#include "MCURegisters.h"
#include "Uart2DmaController.h"

#include "CppUTest/TestHarness.h"

extern "C" 
{

}

using genericType = std::uint32_t;
static volatile genericType virtualAddress{0};

/**
 * UART2 DMA CONTROLLER TEST LIST
 *
 * 1) Enable channel four for uart transmission (Done)
 * 2) Set the priority level of the dma stream (Done)
 * 3) Specify the memory size (Done)
 * 4) Enable memory increment mode (Done)
 * 5) Specify the direction of the stream
 * 6) Ensure the dma is the flow controller
 * 7) Enable the dma stream
 **/
TEST_GROUP(Uart2DmaControllerTest)
{
    bool functionWorked{false};
    genericType expected{0};
    Hardware::MCURegisters dmaRegister;
    Dma::Uart2DmaController uart2Dma;
    void setup()
    {
        functionWorked = false;
        expected = 0;
        virtualAddress = 0;
        dmaRegister = Hardware::MCURegisters{&virtualAddress};
    }

    void teardown()
    {
    }
};

TEST(Uart2DmaControllerTest, SetChannelFourAsTheChannelToBeUsedForUartTwo)
{
    expected = 134217728;
    functionWorked = uart2Dma.EnableChannelFour(dmaRegister);
    
    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Uart2DmaControllerTest, SpecifyTheMemorySize)
{
    expected = 16384;
    functionWorked = uart2Dma.Use32BitMemorySize(dmaRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Uart2DmaControllerTest, EnableMemoryIncrementMode)
{
    expected = 1024;
    functionWorked = uart2Dma.LetMemoryIncrement(dmaRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Uart2DmaControllerTest, SpecifyDirectionOfTheDmaStream)
{
    expected = 64;
    functionWorked = uart2Dma.StreamFromMemoryToPeripheral(dmaRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Uart2DmaControllerTest, EnableTheDma)
{
    expected = 1;
    functionWorked = uart2Dma.TransferData(dmaRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

