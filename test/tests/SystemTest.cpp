/********************************************************************************
 * Contents: Test Fixture of the SystemTest.
 * Author: Dawid Blom.
 * Date: December 29, 2022.
 *
 * Note: 
 *******************************************************************************/
#include <cstdint>
#include "System.h"
#include "SystemMock.h"

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
 * 3) Configure the gpio modes (Done)
 **/
TEST_GROUP(SystemTest)
{
    genericType pin{0};
    Hal::System* system;
    void setup()
    {
        system = new Test::SystemMock();
    }

    void teardown()
    {
        mock().clear();
        delete system;
    }
};

TEST(SystemTest, InitializeObjectsWithDesiredAddresses)
{
    mock().expectOneCall("Initialization");
    system->Initialize();

    mock().checkExpectations();
}

TEST(SystemTest, ConfigureAHB1PeripheralBus)
{
    mock().expectOneCall("RccConfiguration");
    system->RccConfiguration();

    mock().checkExpectations();
}

TEST(SystemTest, ConfigureTheGpioModes)
{
    mock().expectOneCall("ModeConfiguration");
    system->ModeConfiguration();

    mock().checkExpectations();
}
