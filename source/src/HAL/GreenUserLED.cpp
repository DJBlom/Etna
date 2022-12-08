#include "GreenUserLED.h"

HAL::GreenUserLED::GreenUserLED(volatile ledType* clockAddr, volatile ledType* modeAddr, volatile ledType* odrAddr): odrAddress{odrAddr}
{ 
    *clockAddr = *clockAddr | (bits::gpioaClockOn << position::gpioaClock);
    *modeAddr = *modeAddr | (bits::setModeOn << position::outputMode);
}

void HAL::GreenUserLED::EnableLED(ledType& bitPosition)
{
    *this->odrAddress = *this->odrAddress | bitPosition;
}

void HAL::GreenUserLED::DisableLED(ledType& bitPosition)
{
    *this->odrAddress = *this->odrAddress & ~bitPosition;
}
