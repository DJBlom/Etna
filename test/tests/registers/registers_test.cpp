#include "CppUTest/TestHarness.h"

#include "CppUTestExt/MockSupport.h"

#include "../header_test/registers.h"

#include <cstdint>

#include <iostream>




static std::uint32_t virtual_register {0x00000000};

firmware::Registers<std::uint32_t, std::uint32_t> registers(virtual_register, 0x0);

TEST_GROUP(firmware_registers)
{
	void setup()
	{
		registers.set(virtual_register, 0xffff);
	}


	void teardown()
	{
	}
};


TEST(firmware_registers, get_the_value_of_the_whole_register)
{
	CHECK_EQUAL(registers.get(virtual_register), virtual_register);
}


TEST(firmware_registers, set_multiple_register_bits)
{
	registers.set(virtual_register, 0xff);
	CHECK_EQUAL(0xff, virtual_register);
}


TEST(firmware_registers, enable_multiple_register_bits)
{
	registers.enable(virtual_register, 0xff);
	CHECK_EQUAL(0xffff, virtual_register);
}


TEST(firmware_registers, check_multiple_register_bits)
{
	registers.check(virtual_register, 0xffffffff);
	CHECK_EQUAL(0xffff, virtual_register);
}


TEST(firmware_registers, disable_multiple_register_bits)
{
	registers.disable(virtual_register, 0xffff);
	CHECK_EQUAL(0x0, virtual_register);
}


TEST(firmware_registers, enable_a_single_register_bit)
{
	registers.set(virtual_register, 0x0);
	registers.enable_bit(virtual_register, 0);
	CHECK_EQUAL(0x1, virtual_register);
}


TEST(firmware_registers, disable_a_single_register_bit)
{
	registers.set(virtual_register, 0x0);
	registers.enable_bit(virtual_register, 0);
	registers.disable_bit(virtual_register, 0);
	CHECK_EQUAL(0x0, virtual_register);
}


TEST(firmware_registers, toggle_a_single_register_bit)
{
	registers.set(virtual_register, 0x0);
	registers.toggle_bit(virtual_register, 0);
	CHECK_EQUAL(0x1, virtual_register);
}


TEST(firmware_registers, get_a_single_register_bit_value)
{
	registers.set(virtual_register, 0x0);
	registers.enable_bit(virtual_register, 0);
	CHECK_EQUAL(0x1, registers.get_bit(virtual_register, 0));
}


TEST(firmware_registers, toggle_multiple_register_bits)
{
	registers.set(virtual_register, 0xffff);
	registers.toggle(virtual_register, 0xffffffff);
	CHECK_EQUAL(0xffff0000, virtual_register);
}



















