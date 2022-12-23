#include "Ahb1ClocksMock.h"

volatile clockType virtualAddress{0};

void Ahb1ClocksMock::GpioAResetClockControl()
{
    clockType gpioA{0};
    mock().actualCall("ResetClockControlFor").withParameter("gpioA", gpioA);
    mock().actualCall("GpioAResetClockControl");
}

void Ahb1ClocksMock::GpioBResetClockControl()
{
    clockType gpioB{0};
    mock().actualCall("ResetClockControlFor").withParameter("gpioB", gpioB);
    mock().actualCall("GpioBResetClockControl");
}

void Ahb1ClocksMock::GpioCResetClockControl()
{
    clockType gpioC{0};
    mock().actualCall("ResetClockControlFor").withParameter("gpioC", gpioC);
    mock().actualCall("GpioCResetClockControl");
}

void Ahb1ClocksMock::GpioDResetClockControl()
{
    clockType gpioD{0};
    mock().actualCall("ResetClockControlFor").withParameter("gpioD", gpioD);
    mock().actualCall("GpioDResetClockControl");
}

void Ahb1ClocksMock::GpioEResetClockControl()
{
    clockType gpioE{0};
    mock().actualCall("ResetClockControlFor").withParameter("gpioE", gpioE);
    mock().actualCall("GpioEResetClockControl");
}

void Ahb1ClocksMock::ResetClockControlFor(clockType&& gpio)
{
    mock().actualCall("ResetClockControlFor").withParameter("gpio", gpio << 0);
}
