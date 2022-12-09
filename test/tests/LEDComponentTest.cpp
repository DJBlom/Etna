/********************************************************************************
 * Contents: Test Fixture GreenUserLEDComponentTest.
 *
 * Author: Dawid Blom.
 *
 * Date: Testing the register manipulation of GPIOA and RCC pins.
 *******************************************************************************/
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include <cstdint>

#include "GreenUserLED.h"

extern "C" 
{

}

using generic_t = std::uint32_t;

/**************************
 * LED COMPONENT TEST LIST
 * 
 * 1) Enable the LED Green User LED.
 * 2) Disable the LED Green User LED.
 * 3) Clock access is enabled for GPIOA.
 * 4) GPIOA mode is set to output.
 **/
TEST_GROUP(GreenUserLEDComponentTest)
{
    generic_t mode{0};
    generic_t rcc{0};
    generic_t odr{0};
    generic_t expected{1};
    generic_t bitPosition{1U << 5};
    HAL::GreenUserLED led{&rcc, &mode, &odr};
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(GreenUserLEDComponentTest, EnableClockAccessToGpioa)
{
    CHECK_EQUAL(expected, rcc);
}

TEST(GreenUserLEDComponentTest, EnableOutPutModeOnGpioA)
{
    expected = 1024;

    CHECK_EQUAL(expected, mode);
}

TEST(GreenUserLEDComponentTest, EnableTheLEDOnTheBoard)
{
    expected = 32;
    led.EnableLED(bitPosition);

    CHECK_EQUAL(expected, odr);
}

TEST(GreenUserLEDComponentTest, DisableTheLEDOnTheBoard)
{
    expected = 0;
    led.EnableLED(bitPosition);
    led.DisableLED(bitPosition);

    CHECK_EQUAL(expected, odr);
}
