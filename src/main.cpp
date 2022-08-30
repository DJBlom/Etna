
#include <cstdint>

#include "../header/registers.h"



using address_t = std::uint32_t;
using position_t = std::uint32_t;
address_t address{0x00000000};
position_t position{0xff};

int main()
{
	driver::registers::set<address_t, position_t>(address, position);


	return 0;
}
