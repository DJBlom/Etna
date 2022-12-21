
#ifndef _PERIPHERAL_CLOCKS_MOCKS_H_ 
#define _PERIPHERAL_CLOCKS_MOCKS_H_ 
class PeripheralClocksMocks : public Rcc::PeripheralClocks {
    public:
        PeripheralClocksMocks()
        {
        }

        virtual void ConfigurePeripheralClocks()
        {
            peripheralType bit{0};
            mock().actualCall("EnableRegisterBit").withParameter("bit", bit);
        }

    private:
        Hardware::Registers clocks;
};
#endif
