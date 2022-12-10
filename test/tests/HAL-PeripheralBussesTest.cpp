/********************************************************************************
 * Contents: Test Fixture of the HAL-PeripheralBusses.
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

#include "BoardBus.h"
#include "BoardBusses.h"

extern "C" 
{

}

using generic_t = std::uint32_t;

static generic_t virtualRegister{0x0};

/**
 * ENABLE BUS TEST LIST
 *
 * 1) Enable a peripheral bus for gpio.
 * 2) Confirming register manipulation took place.
 **/
TEST_GROUP(EnableBusTest)
{
//    generic_t virtualRegister{0x0};
    //Hal::BoardBus bus{virtualRegister};
    Hal::BoardBus bus;


    void setup()
    {

    }

    void teardown()
    {

    }
};

TEST(EnableBusTest, EnableAPeripheralBusForGpio)
{
    bus.EnablePeripheralBusFor(virtualRegister, 1U << 0);

    CHECK_EQUAL(1, virtualRegister);
}

TEST(EnableBusTest, ConfirmingRegisterManipulationTookPlace)
{
    bool result = bus.EnablePeripheralBusFor(virtualRegister, 1U << 0);

    CHECK_EQUAL(true, result);
}


/**
 * PERIPHERAL BUS TEST LIST
 *
 * 1) Enable all desired bus peripherals.
 **/
TEST_GROUP(PeripheralBusTest)
{
    void setup()
    {

    }

    void teardown()
    {
        mock().clear();
    }
};

TEST(PeripheralBusTest, Failed)
{
    Init::BoardBusses board;

//    mock().expectOneCall("EnablePeripheralBusFor");
//    board.InitializeBoardBusses();
//    mock().checkExpectations();
 
    CHECK(board.InitializeBoardBusses());
}
