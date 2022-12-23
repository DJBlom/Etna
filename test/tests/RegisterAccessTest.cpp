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
    genericType bits{0};
    volatile genericType virtualAddress{0x0};
    genericType expected{0};
    Hardware::MCURegisters reg;
    void setup()
    {

    }

    void teardown()
    {

    }
};

TEST(RegisterTest, EnableASpecificRegisterBit)
{
    bits = 1U << 2;
    expected = 4;
    reg.EnableRegisterBit(&virtualAddress, bits);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(RegisterTest, DisableASpecificRegisterBit)
{
    bits = 1U << 3;
    reg.EnableRegisterBit(&virtualAddress, bits);
    reg.DisableRegister(&virtualAddress, bits);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(RegisterTest, EnableAWholeRegisterWithAValue)
{
    bits = 0b0001;
    expected = 1;
    reg.EnableRegister(&virtualAddress, bits);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(RegisterTest, DisableAWholeRegister)
{
    bits = 0b10101;
    expected = 0;
    reg.EnableRegister(&virtualAddress, bits);
    reg.DisableRegister(&virtualAddress, bits);

    CHECK_EQUAL(expected, virtualAddress);
}
