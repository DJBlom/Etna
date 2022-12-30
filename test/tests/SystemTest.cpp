/********************************************************************************
 * Contents: Test Fixture of the SystemTest.
 * Author: Dawid Blom.
 * Date: December 29, 2022.
 *
 * Note: 
 *******************************************************************************/
#include "System.h"
#include "SystemMock.h"

extern "C" 
{

}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"



/**
 * SYSTEM PERIPHERAL TEST LIST
 *
 * 1) Initialize objects with desired addresses
 * 2) Configure Rcc peripheral buss
 * 3) Configure the gpio modes
 **/
TEST_GROUP(SystemTest)
{
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
