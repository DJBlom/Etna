/********************************************************************************
 * Contents: Test Fixture of the Ahb1Peripheral.
 * Author: Dawid Blom.
 * Date: December 8, 2022.
 *
 * Note: 
 *******************************************************************************/
#include "MCURegisters.h"
#include "Ahb1Peripheral.h"
#include "Apb1Peripheral.h"
#include <cstdint>

#include "CppUTest/TestHarness.h"

extern "C" 
{

}

using genericType = std::uint32_t;
static volatile genericType virtualAddress{0};



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
    bool functionWorked{false};
    genericType expected{0};
    Hardware::MCURegisters rccRegisters;
    Rcc::Ahb1Peripheral ahb1;
    void setup()
    {
        functionWorked = false;
        virtualAddress = 0;
        expected = 0;
        rccRegisters = Hardware::MCURegisters{&virtualAddress};
    }

    void teardown()
    {
    }
};


TEST(Ahb1PeripheralTest, ResetClockControlForDMA2)
{
    expected = 4194304;
    functionWorked = ahb1.Dma2ResetClockControl(rccRegisters);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForDMA1)
{
    expected = 2097152;
    functionWorked = ahb1.Dma1ResetClockControl(rccRegisters);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForCRC)
{
    expected = 4096;
    functionWorked = ahb1.CrcResetClockControl(rccRegisters);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForGPIOH)
{
    expected = 128;
    functionWorked = ahb1.GpioHResetClockControl(rccRegisters);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForGPIOE)
{
    expected = 16;
    functionWorked = ahb1.GpioEResetClockControl(rccRegisters);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForGPIOD)
{
    expected = 8;
    functionWorked = ahb1.GpioDResetClockControl(rccRegisters);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForGPIOC)
{
    expected = 4;
    functionWorked = ahb1.GpioCResetClockControl(rccRegisters);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForGPIOB)
{
    expected = 2;
    functionWorked = ahb1.GpioBResetClockControl(rccRegisters);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Ahb1PeripheralTest, ResetClockControlForGPIOA)
{
    expected = 1;
    functionWorked = ahb1.GpioAResetClockControl(rccRegisters);

    CHECK(functionWorked);
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
    bool functionWorked{false};
    genericType expected{0};
    Hardware::MCURegisters rccRegister;
    Rcc::Apb1Peripheral apb1;
    void setup()
    {
        functionWorked = false;
        virtualAddress = 0;
        expected = 0;
        rccRegister = Hardware::MCURegisters{&virtualAddress};
    }

    void teardown()
    {
    }
};

TEST(Apb1PeripheralTest, ResetClockControlForTIM2)
{
    expected = 1;
    functionWorked = apb1.Tim2ResetClockControl(rccRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Apb1PeripheralTest, ResetClockControlForTIM3)
{
    expected = 2;
    functionWorked = apb1.Tim3ResetClockControl(rccRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Apb1PeripheralTest, ResetClockControlForTIM4)
{
    expected = 4;
    functionWorked = apb1.Tim4ResetClockControl(rccRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Apb1PeripheralTest, ResetClockControlForTIM5)
{
    expected = 8;
    functionWorked = apb1.Tim5ResetClockControl(rccRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Apb1PeripheralTest, ResetClockControlForWWDG)
{
    expected = 2048;
    functionWorked = apb1.WwdgResetClockControl(rccRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Apb1PeripheralTest, ResetClockControlForSpi2)
{
    expected = 16384;
    functionWorked = apb1.Spi2ResetClockControl(rccRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Apb1PeripheralTest, ResetClockControlForSpi3)
{
    expected = 32768;
    functionWorked = apb1.Spi3ResetClockControl(rccRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Apb1PeripheralTest, ResetClockControlForUSART2)
{
    expected = 131072;
    functionWorked = apb1.Usart2ResetClockControl(rccRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Apb1PeripheralTest, ResetClockControlForI2C1)
{
    expected = 2097152;
    functionWorked = apb1.I2c1ResetClockControl(rccRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Apb1PeripheralTest, ResetClockControlForI2C2)
{
    expected = 4194304;
    functionWorked = apb1.I2c2ResetClockControl(rccRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Apb1PeripheralTest, ResetClockControlForI2C3)
{
    expected = 8388608;
    functionWorked = apb1.I2c3ResetClockControl(rccRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}

TEST(Apb1PeripheralTest, ResetClockControlForPWR)
{
    expected = 268435456;
    functionWorked = apb1.PwrResetClockControl(rccRegister);

    CHECK(functionWorked);
    CHECK_EQUAL(expected, virtualAddress);
}
