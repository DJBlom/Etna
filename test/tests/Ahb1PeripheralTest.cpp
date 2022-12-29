/********************************************************************************
 * Contents: Test Fixture of the Ahb1Peripheral.
 * Author: Dawid Blom.
 * Date: December 8, 2022.
 *
 * Note: 
 *******************************************************************************/
#include "Ahb1Peripheral.h"
#include <cstdint>

#include "CppUTest/TestHarness.h"

extern "C" 
{

}

using genericType = std::uint32_t;
static volatile genericType virtualAddress{0};
static genericType expected{0};

/**
 * ABH1 PERIPHERAL TEST LIST
 * 
 * 1) Reset clock control for DMA2 (Done)
 * 2) Reset clock control for DMA1 (Done)
 * 3) Reset clock control for CRC (Done)
 * 4) Reset clock control for GPIOH (Done) 
 * 5) Reset clock control for GPIOE (Done) 
 * 6) Reset clock control for GPIOD (Done) 
 * 7) Reset clock control for GPIOC (Done) 
 * 8) Reset clock control for GPIOB (Done) 
 * 9) Reset clock control for GPIOA (Done) 
 **/
TEST_GROUP(Ahb1PeripheralTest)
{
    Rcc::Ahb1Peripheral ahb1;
    void setup()
    {
        virtualAddress = 0;
        expected = 0;
        ahb1 = Rcc::Ahb1Peripheral(&virtualAddress);
    }

    void teardown()
    {
    }
};


TEST(Ahb1PeripheralTest, ResetClockControlForDMA2)
{
    expected = 4194304;
    ahb1.DMA2ResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForDMA1)
{
    expected = 2097152;
    ahb1.DMA1ResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForCRC)
{
    expected = 4096;
    ahb1.CRCResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForGPIOH)
{
    expected = 128;
    ahb1.GPIOHResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForGPIOE)
{
    expected = 16;
    ahb1.GPIOEResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForGPIOD)
{
    expected = 8;
    ahb1.GPIODResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForGPIOC)
{
    expected = 4;
    ahb1.GPIOCResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForGPIOB)
{
    expected = 2;
    ahb1.GPIOBResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForGPIOA)
{
    expected = 1;
    ahb1.GPIOAResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}
