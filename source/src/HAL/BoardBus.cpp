#include "BoardBus.h"

bool Hal::BoardBus::EnablePeripheralBusFor(boardBusType busAddress, boardBusType&& gpioPort)
{
    *(reinterpret_cast<volatile boardBusType*> (busAddress))
    = (*reinterpret_cast<volatile boardBusType*> (busAddress)  
    | static_cast<boardBusType> (gpioPort));

    return true;
}

