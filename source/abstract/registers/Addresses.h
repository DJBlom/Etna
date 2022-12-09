#ifndef _ADDRESSES_H_
#define _ADDRESSES_H_ 
#include <cstdint>
using addressType = std::uint32_t;
struct Addresses {
    virtual ~Addresses() = default;
    virtual void Hello() = 0;
    addressType clockAddress{0x0};
    addressType modeAddress{0x0};
    addressType odrAddress{0x0};
};
#endif
