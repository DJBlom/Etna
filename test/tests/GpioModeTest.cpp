/********************************************************************************
 * Contents: Test Fixture of the GpioMode.
 * Author: Dawid Blom.
 * Date: December 8, 2022.
 *
 * Note: 
 *******************************************************************************/
#include "GpioMode.h"
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
    Gpio::GpioMode mode;
    void setup()
    {
        virtualAddress = 0;
        expected = 0;
        mode = Gpio::GpioMode(&virtualAddress);
    }

    void teardown()
    {
    }
};

TEST(GpioModeTest, EnableInputModeForGpioPins)
{
    expected = 0;
    mode.EnableInputMode(5);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(GpioModeTest, EnableOutputModeForGpioPins)
{
    expected = 1;
    mode.EnableOutputMode(0);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(GpioModeTest, EnableAlternativeFunctionModeForGpioPins)
{
    expected = 2;
    mode.EnableAlternativeFunctionMode(0);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(GpioModeTest, EnableAnalogModeForGpioPins)
{
    expected = 3;
    mode.EnableAnalogMode(0);

    CHECK_EQUAL(expected, virtualAddress);
}
