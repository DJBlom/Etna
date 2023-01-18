#include "SystemLogger.h"

namespace Addresses {
    static registerType* GetAddress(registerType address)
    {
        return reinterpret_cast<registerType*> (address);
    }

    constexpr registerType dmaStreamCtrl{0x40026000U + 0x10U + (0x18U * 6)};
    constexpr registerType dmaStreamMar{0x40026000U + 0x1CU + (0x18U * 6)};
    constexpr registerType dmaStreamPar{0x40026000U + 0x18U + (0x18U * 6)};
    constexpr registerType dmaStreamNdtr{0x40026000U + 0x14U + (0x18U * 6)};

    constexpr registerType uart2Ctrl1{0x4000440CU};
    constexpr registerType uart2Ctrl2{0x40004410U};
    constexpr registerType uart2Ctrl3{0x40004414U};
    constexpr registerType uart2Brr{0x40004408U};
    constexpr registerType uart2Dr{0x40004404U};
    constexpr registerType uart2Sr{0x40004400U};
}

namespace Registers {
    volatile registerType* dmaStreamControlR = Addresses::GetAddress(Addresses::dmaStreamCtrl); 
    volatile registerType* dmaStreamMarR = Addresses::GetAddress(Addresses::dmaStreamMar); 
    volatile registerType* dmaStreamParR = Addresses::GetAddress(Addresses::dmaStreamPar); 
    volatile registerType* dmaStreamNdtrR = Addresses::GetAddress(Addresses::dmaStreamNdtr); 

    volatile registerType* uart2ControlR1 = Addresses::GetAddress(Addresses::uart2Ctrl1); 
    volatile registerType* uart2ControlR2 = Addresses::GetAddress(Addresses::uart2Ctrl2); 
    volatile registerType* uart2ControlR3 = Addresses::GetAddress(Addresses::uart2Ctrl3); 
    volatile registerType* uart2BaudR = Addresses::GetAddress(Addresses::uart2Brr); 
    volatile registerType* uart2DataR = Addresses::GetAddress(Addresses::uart2Dr); 
    volatile registerType* uart2StatusR = Addresses::GetAddress(Addresses::uart2Sr); 
}


void Hal::SystemLogger::InitializeSystemLogger()
{
    uart2Control1 = Hardware::MCURegisters{Registers::uart2ControlR1};
    uart2Control2 = Hardware::MCURegisters{Registers::uart2ControlR2};
    uart2Control3 = Hardware::MCURegisters{Registers::uart2ControlR3};
    uart2BaudRate = Hardware::MCURegisters{Registers::uart2BaudR};
    uart2Status = Hardware::MCURegisters{Registers::uart2StatusR};
    uart2Data = Hardware::MCURegisters{Registers::uart2DataR};

    uart2DmaControl = Hardware::MCURegisters{Registers::dmaStreamControlR};
    uart2DmaNdtr = Hardware::MCURegisters{Registers::dmaStreamNdtrR};
    uart2DmaPar = Hardware::MCURegisters{Registers::dmaStreamParR};
    uart2DmaMar = Hardware::MCURegisters{Registers::dmaStreamMarR};
}

bool Hal::SystemLogger::ConfigureSystemLogger()
{
    if (uart2.OversamplingBySixteen(uart2Control1) == false)
        return false;

    if (uart2.UseEightBitWordLength(uart2Control1) == false)
        return false;

    if (uart2.SetBaudRateHigh(uart2BaudRate) == false)
        return false;

    if (uart2.UseOneStopBit(uart2Control2) == false)
        return false;

    if (uart2.EnableDmaTransmission(uart2Control3) == false)
        return false;

    if (uart2.EnableTransmitter(uart2Control1) == false)
        return false;

    if (uart2.UsartEnable(uart2Control1) == false)
        return false;

    if (uart2Dma.EnableChannelFour(uart2DmaControl) == false)
        return false;

    if (uart2Dma.Use32BitMemorySize(uart2DmaControl) == false)
        return false;

    if (uart2Dma.LetMemoryIncrement(uart2DmaControl) == false)
        return false;

    if (uart2Dma.StreamFromMemoryToPeripheral(uart2DmaControl) == false)
        return false;

    return true;
}

bool Hal::SystemLogger::LogMessage(const char* msg)
{
    if (uart2DmaPar.AssignAnotherRegister(Addresses::uart2Dr) == false)
        return false;

    if (uart2DmaMar.AssignAnotherRegister(MessageToRegisterType(msg)) == false)
        return false;
    
    registerType length{0};
    while (msg[length++]);
    if (uart2DmaNdtr.SetBits(length & Bit::mask) == false)
        return false;

    if (uart2Dma.TransferData(uart2DmaControl) == false)
        return false;

    return true;
}

registerType Hal::SystemLogger::MessageToRegisterType(const char* msg)
{
    return reinterpret_cast<registerType&> (msg);
}


