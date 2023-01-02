#include "SystemGpios.h"

namespace Registers {
    static registerType* GetAddress(registerType address)
    {
        return reinterpret_cast<registerType*> (address);
    }

    constexpr registerType gpioaMode{0x40020000U};
    constexpr registerType gpioaAF{0x40020020U};
}

namespace Address {
    volatile registerType* gpioaModeAddress = Registers::GetAddress(Registers::gpioaMode);
    volatile registerType* lowAFAddress = Registers::GetAddress(Registers::gpioaAF);
}

void Hal::SystemGpios::InitializeGpios()
{
    gpioaModeRegister = Hardware::MCURegisters{Address::gpioaModeAddress};
    gpioaAFRegister = Hardware::MCURegisters{Address::lowAFAddress};
}

void Hal::SystemGpios::ConfigureSystemGpios()
{
    modeA.OutputModeEnable(gpioaModeRegister, ConvertModeBitToSystemType(ModeBit::five));
    modeA.AlternateFunctionModeEnable(gpioaModeRegister, ConvertModeBitToSystemType(ModeBit::two));
    lowAFA.SevenEnable(gpioaAFRegister, ConvertAFBitToSystemType(AFBit::two));
}

registerType Hal::SystemGpios::ConvertModeBitToSystemType(const ModeBit& bit)
{
    return static_cast<registerType> (bit);
}

registerType Hal::SystemGpios::ConvertAFBitToSystemType(const AFBit& bit)
{
    return static_cast<registerType> (bit);
}
