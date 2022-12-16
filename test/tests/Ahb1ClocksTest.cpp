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

#include "Ahb1Clocks.h"
#include "PeripheralClocks.h"

extern "C" 
{

}

using genericType = std::uint32_t;

/**
 * ENABLE SYSTEM PERIPHERAL CLOCKS TEST LIST
 *
 * 1) Enable peripheral clock AHB1 for gpioa. (Done)
 * 2) Enable peripheral clock AHB1 for gpiob. (Done) 
 * 3) Enable peripheral clock AHB1 for gpioc. (Done) 
 * 4) Enable peripheral clock AHB1 for gpiod. (Done) 
 * 5) Enable peripheral clock AHB1 for gpioe. (Done) 
 **/
TEST_GROUP(Ahb1ClocksTest)
{
    genericType expected{1};
    volatile genericType gpioRegister{0};
    Rcc::Ahb1Clocks clocks;

    void setup()
    {

    }

    void teardown()
    {

    }
};

TEST(Ahb1ClocksTest, EnablePeripheralClockAHB1ForGpioA)
{
    clocks.EnableClockForGpioA(&gpioRegister);

    CHECK_EQUAL(expected, gpioRegister);
}

TEST(Ahb1ClocksTest, EnablePeripheralClockAHB1ForGpioB)
{
    expected = 2;
    clocks.EnableClockForGpioB(&gpioRegister);

    CHECK_EQUAL(expected, gpioRegister);
}

TEST(Ahb1ClocksTest, EnablePeripheralClockAHB1ForGpioC)
{
    expected = 4;
    clocks.EnableClockForGpioC(&gpioRegister);

    CHECK_EQUAL(expected, gpioRegister);
}

TEST(Ahb1ClocksTest, EnablePeripheralClockAHB1ForGpioD)
{
    expected = 8;
    clocks.EnableClockForGpioD(&gpioRegister);

    CHECK_EQUAL(expected, gpioRegister);
}

TEST(Ahb1ClocksTest, EnablePeripheralClockAHB1ForGpioE)
{
    expected = 16;
    clocks.EnableClockForGpioE(&gpioRegister);

    CHECK_EQUAL(expected, gpioRegister);
}



class PeripheralClocksMocks : public Rcc::PeripheralClocks {
    public:
        virtual void ConfigurePeripheralClocks()
        {
            volatile peripheralType address{0};
            mock().actualCall("EnableClockForGpioA").withParameter("address", address);
        }

    private:
        Rcc::Ahb1Clocks clocks;
};


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

TEST(PeripheralClocksTest, EnablePeripheralAhb1ForGpioA)
{
    volatile genericType address{0};
    mock().expectOneCall("EnableClockForGpioA").withParameter("address", address);
    PeripheralClocksMocks clocks;
    clocks.ConfigurePeripheralClocks();

    mock().checkExpectations();
}
