#ifndef _GREEN_USER_LED_ADDRESSES_MOCK_H_ 
#define _GREEN_USER_LED_ADDRESSES_MOCK_H_ 
#include "Addresses.h"
#include <cstdint>
#include <iostream>

using addressType = std::uint32_t;
struct GreenUserLEDAddressesMock : public Addresses {
    GreenUserLEDAddressesMock() = default;
    GreenUserLEDAddressesMock(const GreenUserLEDAddressesMock&) = delete;
    GreenUserLEDAddressesMock(GreenUserLEDAddressesMock&&) = delete;
    GreenUserLEDAddressesMock& operator= (const GreenUserLEDAddressesMock&) = delete;
    GreenUserLEDAddressesMock& operator= (GreenUserLEDAddressesMock&&) = delete;
    ~GreenUserLEDAddressesMock() = default;

    addressType clockAddress{0x0};
    addressType modeAddress{0x0};
    addressType odrAddress{0x0};
    void Hello()
    {
        std::cout << "Hello from Green User LED Addresses Mock.\n";
        std::cout << "Value of clockAddress is: " << clockAddress << "\n";
    }
};   

#endif
