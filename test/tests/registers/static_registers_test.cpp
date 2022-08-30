#include "CppUTest/TestHarness.h"

#include "CppUTestExt/MockSupport.h"

#include "../header_test/registers.cpp"

#include <cstdint>

#include <iostream>




static std::uint32_t virtual_register {0x00000000};


TEST_GROUP(driver_registers)
{
	void setup()
	{
		driver::registers::set(virtual_register, 0xffff);
	}


	void teardown()
	{
	}
};


TEST(driver_registers, get_the_value_of_the_whole_register)
{
	CHECK_EQUAL(driver::registers::get(virtual_register), virtual_register);
}


TEST(driver_registers, set_multiple_register_bits)
{
	driver::registers::set(virtual_register, 0xff);
	CHECK_EQUAL(0xff, virtual_register);
}


TEST(driver_registers, enable_multiple_register_bits)
{
	driver::registers::enable(virtual_register, 0xff);
	CHECK_EQUAL(0xffff, virtual_register);
}


TEST(driver_registers, check_multiple_register_bits)
{
	driver::registers::check(virtual_register, 0xffffffff);
	CHECK_EQUAL(0xffff, virtual_register);
}


TEST(driver_registers, disable_multiple_register_bits)
{
	driver::registers::disable(virtual_register, 0xffff);
	CHECK_EQUAL(0x0, virtual_register);
}


TEST(driver_registers, enable_a_single_register_bit)
{
	driver::registers::set(virtual_register, 0x0);
	driver::registers::enable_bit(virtual_register, 0);
	CHECK_EQUAL(0x1, virtual_register);
}


TEST(driver_registers, disable_a_single_register_bit)
{
	driver::registers::set(virtual_register, 0x0);
	driver::registers::enable_bit(virtual_register, 0);
	driver::registers::disable_bit(virtual_register, 0);
	CHECK_EQUAL(0x0, virtual_register);
}


TEST(driver_registers, toggle_a_single_register_bit)
{
	driver::registers::set(virtual_register, 0x0);
	driver::registers::toggle_bit(virtual_register, 0);
	CHECK_EQUAL(0x1, virtual_register);
}


TEST(driver_registers, get_a_single_register_bit_value)
{
	driver::registers::set(virtual_register, 0x0);
	driver::registers::enable_bit(virtual_register, 0);
	CHECK_EQUAL(0x1, driver::registers::get_bit(virtual_register, 0));
}


TEST(driver_registers, toggle_multiple_register_bits)
{
	driver::registers::set(virtual_register, 0xffff);
	driver::registers::toggle(virtual_register, 0xffffffff);
	CHECK_EQUAL(0xffff0000, virtual_register);
}



















