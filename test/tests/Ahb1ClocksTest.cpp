/********************************************************************************
 * Contents: Test Fixture of the Ahb1ClockReset.
 *
 * Author: Dawid Blom.
 *
 * Date: December 8, 2022.
 *
 * Note: 
 *******************************************************************************/
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include <cstdint>

#include "Ahb1Clocks.h"
#include "Ahb1ClocksMock.h"

extern "C" 
{

}

using genericType = std::uint32_t;

/**
 * AHB1 CLOCKS TEST LIST
 *
 * Reset the clock control for gpioA
 * Reset the clock control for gpioB
 * Reset the clock control for gpioC
 * Reset the clock control for gpioD
 * Reset the clock control for gpioE
 **/
TEST_GROUP(Ahb1ClocksTest)
{
    Rcc::Ahb1Clocks* gpioClocks = new Ahb1ClocksMock();
    void setup()
    {

    }

    void teardown()
    {
        mock().clear();
        delete gpioClocks;
    }
};

TEST(Ahb1ClocksTest, ResetTheClockControlForGpioA)
{
    genericType gpioA{0};
    mock().expectOneCall("ResetClockControlFor").withParameter("gpioA", gpioA);
    mock().expectOneCall("GpioAResetClockControl");
    gpioClocks->GpioAResetClockControl();

    mock().checkExpectations();
}

TEST(Ahb1ClocksTest, ResetTheClockControlForGpioB)
{
    genericType gpioB{0};
    mock().expectOneCall("ResetClockControlFor").withParameter("gpioB", gpioB);
    mock().expectOneCall("GpioBResetClockControl");
    gpioClocks->GpioBResetClockControl();

    mock().checkExpectations();
}

TEST(Ahb1ClocksTest, ResetTheClockControlForGpioC)
{
    genericType gpioC{0};
    mock().expectOneCall("ResetClockControlFor").withParameter("gpioC", gpioC);
    mock().expectOneCall("GpioCResetClockControl");
    gpioClocks->GpioCResetClockControl();

    mock().checkExpectations();
}

TEST(Ahb1ClocksTest, ResetTheClockControlForGpioD)
{
    genericType gpioD{0};
    mock().expectOneCall("ResetClockControlFor").withParameter("gpioD", gpioD);
    mock().expectOneCall("GpioDResetClockControl");
    gpioClocks->GpioDResetClockControl();

    mock().checkExpectations();
}

TEST(Ahb1ClocksTest, ResetTheClockControlForGpioE)
{
    genericType gpioE{0};
    mock().expectOneCall("ResetClockControlFor").withParameter("gpioE", gpioE);
    mock().expectOneCall("GpioEResetClockControl");
    gpioClocks->GpioEResetClockControl();

    mock().checkExpectations();
}

