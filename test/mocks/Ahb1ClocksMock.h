
#ifndef _AHB1_CLOCKS_MOCK_H_ 
#define _AHB1_CLOCKS_MOCK_H_ 
#include "CppUTestExt/MockSupport.h"
#include "Ahb1Clocks.h"
class Ahb1ClocksMock : public Rcc::Ahb1Clocks {
    public:
        Ahb1ClocksMock() = default;
        Ahb1ClocksMock(const Ahb1ClocksMock&) = delete;
        Ahb1ClocksMock(Ahb1ClocksMock&&) = delete;
        Ahb1ClocksMock& operator= (const Ahb1ClocksMock&) = delete;
        Ahb1ClocksMock& operator= (Ahb1ClocksMock&&) = delete;
        ~Ahb1ClocksMock() = default;

        virtual void GpioAResetClockControl();
        virtual void GpioBResetClockControl();
        virtual void GpioCResetClockControl();
        virtual void GpioDResetClockControl();
        virtual void GpioEResetClockControl();

    protected:
        virtual void ResetClockControlFor(clockType&&);
};
#endif
