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
#include <cstdint>

#include "MCURegisters.h"

extern "C" 
{

}

using genericType = std::uint32_t;


/**
 * REGISTERS TEST LIST
 *
 * 1) Enable a register bit (Done).
 * 2) Disable a register bit (Done). 
 * 3) Enable a whole register with a value (Done).
 * 4) Disable a whole register with a value (Done).
 **/
TEST_GROUP(RegisterTest)
{
    volatile genericType virtualAddress{0x0};
    genericType expected{0};
    Hardware::MCURegisters reg{&virtualAddress};
    void setup()
    {

    }

    void teardown()
    {

    }
};

TEST(RegisterTest, EnableASpecificRegisterBit)
{
    expected = 4;
    reg.EnableRegisterBit(1U << 2);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(RegisterTest, DisableASpecificRegisterBit)
{
    reg.EnableRegisterBit(1U << 3);
    reg.DisableRegister(1U << 3);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(RegisterTest, EnableAWholeRegisterWithAValue)
{
    expected = 1;
    reg.EnableRegister(0b0001);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(RegisterTest, DisableAWholeRegister)
{
    expected = 0;
    reg.EnableRegister(0b10101);
    reg.DisableRegister(0b10101);

    CHECK_EQUAL(expected, virtualAddress);
}
