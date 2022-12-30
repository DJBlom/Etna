/********************************************************************************
 * Contents: Test Fixture of the Ahb1Peripheral.
 * Author: Dawid Blom.
 * Date: December 8, 2022.
 *
 * Note: 
 *******************************************************************************/
#include "Ahb1Peripheral.h"
#include "Apb1Peripheral.h"
#include <cstdint>

#include "CppUTest/TestHarness.h"

extern "C" 
{

}

using genericType = std::uint32_t;
static volatile genericType virtualAddress{0};
static genericType expected{0};

/**
 * AHB1 PERIPHERAL TEST LIST
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
    ahb1.Dma2ResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForDMA1)
{
    expected = 2097152;
    ahb1.Dma1ResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForCRC)
{
    expected = 4096;
    ahb1.CrcResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForGPIOH)
{
    expected = 128;
    ahb1.GpioHResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForGPIOE)
{
    expected = 16;
    ahb1.GpioEResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForGPIOD)
{
    expected = 8;
    ahb1.GpioDResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForGPIOC)
{
    expected = 4;
    ahb1.GpioCResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForGPIOB)
{
    expected = 2;
    ahb1.GpioBResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForGPIOA)
{
    expected = 1;
    ahb1.GpioAResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}



/**
 * APB1 PERIPHERAL TEST LIST
 * 
 * 1) Reset clock control for TIM2 (Done) 
 * 2) Reset clock control for TIM3 (Done) 
 * 3) Reset clock control for TIM4 (Done) 
 * 4) Reset clock control for TIM5 (Done) 
 * 5) Reset clock control for WWDG (Done) 
 * 6) Reset clock control for SPI2 (Done) 
 * 7) Reset clock control for SPI3 (Done) 
 * 8) Reset clock control for USART2 (Done)
 * 9) Reset clock control I2C1 (Done)
 * 10) Reset clock control I2C2 (Done)
 * 11) Reset clock control I2C3 (Done)
 * 12) Reset clock control PWR (Done)
 **/
TEST_GROUP(Apb1PeripheralTest)
{
    Rcc::Apb1Peripheral apb1;
    void setup()
    {
        virtualAddress = 0;
        expected = 0;
        apb1 = Rcc::Apb1Peripheral(&virtualAddress);
    }

    void teardown()
    {
    }
};

TEST(Apb1PeripheralTest, ResetClockControlForTIM2)
{
    expected = 1;
    apb1.Tim2ResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Apb1PeripheralTest, ResetClockControlForTIM3)
{
    expected = 2;
    apb1.Tim3ResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Apb1PeripheralTest, ResetClockControlForTIM4)
{
    expected = 4;
    apb1.Tim4ResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Apb1PeripheralTest, ResetClockControlForTIM5)
{
    expected = 8;
    apb1.Tim5ResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Apb1PeripheralTest, ResetClockControlForWWDG)
{
    expected = 2048;
    apb1.WwdgResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Apb1PeripheralTest, ResetClockControlForSpi2)
{
    expected = 16384;
    apb1.Spi2ResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Apb1PeripheralTest, ResetClockControlForSpi3)
{
    expected = 32768;
    apb1.Spi3ResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Apb1PeripheralTest, ResetClockControlForUSART2)
{
    expected = 131072;
    apb1.Usart2ResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Apb1PeripheralTest, ResetClockControlForI2C1)
{
    expected = 2097152;
    apb1.I2c1ResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Apb1PeripheralTest, ResetClockControlForI2C2)
{
    expected = 4194304;
    apb1.I2c2ResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Apb1PeripheralTest, ResetClockControlForI2C3)
{
    expected = 8388608;
    apb1.I2c3ResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Apb1PeripheralTest, ResetClockControlForPWR)
{
    expected = 268435456;
    apb1.PwrResetClockControl();

    CHECK_EQUAL(expected, virtualAddress);
}