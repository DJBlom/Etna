#include "Uart2DmaController.h"

bool Dma::Uart2DmaController::EnableChannelFour(Hardware::Registers& dmaSCRegister)
{
    if (dmaSCRegister.EnableBit(Bits::four << Position::chSel) == false)
        return false;
    else
        return true;
}

bool Dma::Uart2DmaController::Use32BitMemorySize(Hardware::Registers& dmaSCRegister)
{
    if (dmaSCRegister.EnableBit(Bits::word << Position::memSize) == false)
        return false;
    else
        return true;
}

bool Dma::Uart2DmaController::LetMemoryIncrement(Hardware::Registers& dmaSCRegister)
{
    if (dmaSCRegister.EnableBit(Bits::increment << Position::memInc) == false)
        return false;
    else
        return true;
}

bool Dma::Uart2DmaController::StreamFromMemoryToPeripheral(Hardware::Registers& dmaSCRegister)
{
    if (dmaSCRegister.EnableBit(Bits::memToPeriph << Position::direction) == false)
        return false;
    else
        return true;
}

bool Dma::Uart2DmaController::TransferData(Hardware::Registers& dmaSCRegister)
{
    if (dmaSCRegister.EnableBit(Bits::send << Position::enable) == false)
        return false;
    else
        return true;
}
