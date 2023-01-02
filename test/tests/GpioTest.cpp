/********************************************************************************
 * Contents: Test Fixture of the GpioMode.
 * Author: Dawid Blom.
 * Date: December 8, 2022.
 *
 * Note: 
 *******************************************************************************/
#include "MCURegisters.h"
#include "GpioMode.h"
#include "GpioAF.h"

#include <cstdint>

#include "CppUTest/TestHarness.h"

extern "C" 
{

}

using genericType = std::uint32_t;
static volatile genericType virtualAddress{0};
static genericType expected{0};

/**
 * GPIO MODE TEST LIST
 *
 * 1) Enable input mode for gpio pins (Done)
 * 2) Enable output mode for gpio pins (Done)
 * 3) Enable Alterternative mode for gpio pins (Done)
 * 4) Enable Analog mode for gpio pins (Done)
 **/
TEST_GROUP(GpioModeTest)
{
    Hardware::MCURegisters gpioRegister;
    Gpio::GpioMode mode;
    void setup()
    {
        virtualAddress = 0;
        expected = 0;
        gpioRegister = Hardware::MCURegisters{&virtualAddress};
    }

    void teardown()
    {
    }
};

TEST(GpioModeTest, EnableInputModeForGpioPins)
{
    expected = 0;
    mode.InputModeEnable(gpioRegister, 5);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(GpioModeTest, EnableOutputModeForGpioPins)
{
    expected = 1;
    mode.OutputModeEnable(gpioRegister, 0);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(GpioModeTest, EnableAlternativeFunctionModeForGpioPins)
{
    expected = 2;
    mode.AlternateFunctionModeEnable(gpioRegister, 0);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(GpioModeTest, EnableAnalogModeForGpioPins)
{
    expected = 3;
    mode.AnalogModeEnable(gpioRegister, 0);

    CHECK_EQUAL(expected, virtualAddress);
}




/**
 * GPIO ALTERNATE FUNCTION TEST LIST
 * 
 * 1) Enable AF zero (Done)
 * 2) Enable AF one (Done)
 * 3) Enable AF two (Done)
 * 4) Enable AF three (Done)
 * 5) Enable AF four (Done)
 * 6) Enable AF five (Done)
 * 7) Enable AF six (Done)
 * 8) Enable AF seven (Done)
 * 9) Enable AF eight (Done)
 * 10) Enable AF nine (Done)
 * 11) Enable AF ten (Done)
 * 12) Enable AF twelve (Done)
 * 13) Enable AF fifteen (Done)
 **/
TEST_GROUP(GpioAFTest)
{
    Hardware::MCURegisters gpioRegister;
    Gpio::GpioAF gpioAf;
    void setup()
    {
        virtualAddress = 0;
        expected = 0;
        gpioRegister = Hardware::MCURegisters{&virtualAddress};
    }

    void teardown()
    {
    }
};

TEST(GpioAFTest, EnableAlternateFunctionZero)
{
    expected = 0;
    gpioAf.ZeroEnable(gpioRegister, 0);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(GpioAFTest, EnableAlternateFunctionOne)
{
    expected = 1;
    gpioAf.OneEnable(gpioRegister, 0);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(GpioAFTest, EnableAlternateFunctionTwo)
{
    expected = 2;
    gpioAf.TwoEnable(gpioRegister, 0);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(GpioAFTest, EnableAlternateFunctionThree)
{
    expected = 3;
    gpioAf.ThreeEnable(gpioRegister, 0);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(GpioAFTest, EnableAlternateFunctionFour)
{
    expected = 4;
    gpioAf.FourEnable(gpioRegister, 0);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(GpioAFTest, EnableAlternateFunctionFive)
{
    expected = 5;
    gpioAf.FiveEnable(gpioRegister, 0);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(GpioAFTest, EnableAlternateFunctionSix)
{
    expected = 6;
    gpioAf.SixEnable(gpioRegister, 0);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(GpioAFTest, EnableAlternateFunctionSeven)
{
    expected = 7;
    gpioAf.SevenEnable(gpioRegister, 0);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(GpioAFTest, EnableAlternateFunctionEight)
{
    expected = 8;
    gpioAf.EightEnable(gpioRegister, 0);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(GpioAFTest, EnableAlternateFunctionNine)
{
    expected = 9;
    gpioAf.NineEnable(gpioRegister, 0);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(GpioAFTest, EnableAlternateFunctionTen)
{
    expected = 10;
    gpioAf.TenEnable(gpioRegister, 0);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(GpioAFTest, EnableAlternateFunctionTwelve)
{
    expected = 12;
    gpioAf.TwelveEnable(gpioRegister, 0);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(GpioAFTest, EnableAlternateFunctionFifteen)
{
    expected = 15;
    gpioAf.FifteenEnable(gpioRegister, 0);

    CHECK_EQUAL(expected, virtualAddress);
}
