/********************************************************************************
 * Contents: Test Fixture of the SystemPeripheralTest.
 * Author: Dawid Blom.
 * Date: December 29, 2022.
 *
 * Note: 
 *******************************************************************************/
#include <cstdint>
#include "SystemPeripherals.h"
#include "SystemPeripheralsMock.h"

#include "SystemGpios.h"
#include "SystemGpiosMock.h"

extern "C" 
{

}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

using genericType = std::uint32_t;

/**
 * SYSTEM PERIPHERAL TEST LIST
 *
 * 1) Initialize objects with desired addresses (Done)
 * 2) Configure Rcc peripheral buss (Done)
 **/
TEST_GROUP(SystemPeripheralTest)
{
    genericType bit{0};
    Hal::SystemPeripherals* system;
    void setup()
    {
        system = new Test::SystemPeripheralsMock();
    }

    void teardown()
    {
        mock().clear();
        delete system;
    }
};

TEST(SystemPeripheralTest, InitializeObjectsWithDesiredAddresses)
{
    mock().expectOneCall("InitializationPeripherals");
    system->InitializePeripherals();

    mock().checkExpectations();
}

TEST(SystemPeripheralTest, ConfigureAHB1PeripheralBus)
{
    mock().expectOneCall("ConfigureSystemPeripheralBusses");
    system->ConfigureSystemPeripheralBusses();

    mock().checkExpectations();
}



/**
 * SYSTEM GPIO TEST LIST
 *
 * 1) Initialize objects with desired addresses (Done)
 * 3) Configure the gpio modes (Done)
 **/
TEST_GROUP(SystemGpioTest)
{
    genericType bit{0};
    Hal::SystemGpios* system;
    void setup()
    {
        system = new Test::SystemGpiosMock();
    }

    void teardown()
    {
        mock().clear();
        delete system;
    }
};

TEST(SystemGpioTest, InitializeObjectsWithDesiredAddresses)
{
    mock().expectOneCall("InitializeGpios");
    system->InitializeGpios();

    mock().checkExpectations();
}

TEST(SystemGpioTest, ConfigureTheGpioModes)
{
    mock().expectOneCall("ConfigureSystemGpios");
    system->ConfigureSystemGpios();

    mock().checkExpectations();
}
