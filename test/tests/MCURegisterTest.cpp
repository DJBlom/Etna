/********************************************************************************
 * Contents: Test Fixture of the MCURegister.
 * Author: Dawid Blom.
 * Date: December 8, 2022.
 *
 * Note: 
 *******************************************************************************/
#include "MCURegisters.h"
#include <cstdint>

#include "CppUTest/TestHarness.h"

extern "C" 
{

}

using genericType = std::uint32_t;
static volatile genericType virtualAddress{0};
static genericType expected{0};

/**
 * MCUREGISTER TEST LIST
 *
 * 1) Enable a specified register bit (Done)
 * 2) Set a whole register with a value (Done)
 * 3) Disable a specified register bit (Done)
 * 4) Disable a whole register (Done)
 * 5) Toggle a specified register bit (Done)
 * 6) Toggle a whole register (Done)
 * 7) Check whether or not a bit is set
 **/
TEST_GROUP(MCURegistersTest)
{
    Hardware::MCURegisters reg;
    void setup()
    {
        virtualAddress = 0;
        expected = 0;
        reg = Hardware::MCURegisters(&virtualAddress);
    }

    void teardown()
    {
    }
};

TEST(MCURegistersTest, EnableASpecifiedRegisterBit)
{
    expected = 1;
    reg.EnableBit(1U << 0);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(MCURegistersTest, SetAWholeRegisterWithAValue)
{
    expected = 0b1010;
    reg.SetBits(0b1010);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(MCURegistersTest, DisableASpecifiedRegisterBit)
{
    reg.EnableBit(1U << 0);
    reg.Disable(1U << 0);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(MCURegistersTest, DisableAWholeRegister)
{
    reg.SetBits(0b1010);
    reg.Disable(0b1010);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(MCURegistersTest, ToggleASpecifiedRegisterBit)
{
    expected = 1;
    reg.Toggle(1U << 0);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(MCURegistersTest, ToggleAWholeRegister)
{
    expected = 0;
    reg.Toggle(0b10101);
    reg.Toggle(0b10101);

    CHECK_EQUAL(expected, virtualAddress);
}

TEST(MCURegistersTest, IsTheSpecifiedBitEnabled)
{
    expected = 0;
    reg.EnableBit(1U << 6);
    reg.CheckBit(1U << 6);

    CHECK_EQUAL(expected, reg.CheckBit(1U << 6));
}
