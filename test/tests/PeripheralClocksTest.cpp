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

#include "MCURegisters.h"
#include "RegisterAddresses.h"

extern "C" 
{

}

using genericType = std::uint32_t;


TEST_GROUP(PeripheralClocksTest)
{
    void setup()
    {

    }

    void teardown()
    {
        mock().clear();
    }
};

//TEST(PeripheralClocksTest, EnablePeripheralAhb1ForGpioA)
//{
//    genericType bit{0};
//    mock().expectOneCall("EnableRegisterBit").withParameter("bit", bit);
//    PeripheralClocksMocks clocks;
//    clocks.ConfigurePeripheralClocks();
//
//    mock().checkExpectations();
//}
