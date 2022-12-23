/********************************************************************************
 * Contents: Test Fixture of the RCCPeripheralClock.
 *
 * Author: Dawid Blom.
 *
 * Date: December 8, 2022.
 *
 * Note: TDD of the enablement of the periphiral busses used.
 *******************************************************************************/
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include <cstdint>

#include "PeripheralsMock.h"
#include "Peripherals.h"

extern "C" 
{

}

using genericType = std::uint32_t;

TEST_GROUP(PeripheralsTest)
{
    void setup()
    {

    }

    void teardown()
    {
        mock().clear();
    }
};

TEST(PeripheralsTest, EnablePeripheralAhb1ForGpioA)
{
    Hal::Peripherals* clocks = new PeripheralsMock();

    mock().expectOneCall("GpioAResetClockControl");
    clocks->ConfigurePeripheralClocks();

    mock().checkExpectations();
    delete clocks;
}
