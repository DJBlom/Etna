#include "registers.h"





/**********************************************
 * CONSTRUCTOR IMPLEMENTATION
 *
 * NOTE:By calling this constructor, it should
 *              set the address specified with a given 
 *              bit_positions.
 **********************************************/
template<typename address_t, typename position_t>
firmware::Registers<address_t, position_t>::Registers(address_t &address, position_t bit_positions)
{
        *(reinterpret_cast<volatile address_t *> (&address)) = static_cast<position_t> (bit_positions);
}










/***********************************
 * MULTIPLE BIT MANIPULATION METHODS
 ***********************************/


/**
 * By calling this method, it should
 * allow the programmer to set and re-
 * set the whole register with a new 
 * or old bit_positions.
 **/
template<typename address_t, typename position_t>
inline void firmware::Registers<address_t, position_t>::set(address_t &address, position_t bit_positions)
{
        *(reinterpret_cast<volatile address_t *> (&address))
        = (static_cast<position_t> (bit_positions));
}





/**
 * By calling this method, it should 
 * set all the pins in the register
 * to high. Thus performing an OR
 * operation.
 **/
template<typename address_t, typename position_t>
inline void firmware::Registers<address_t, position_t>::enable(address_t &address, position_t bit_positions)
{
        *(reinterpret_cast<volatile address_t *> (&address)) 
        = (*(reinterpret_cast<volatile address_t *> (&address)) 
        | (static_cast<position_t> (bit_positions)));
}






/**
 * By calling this method, it should 
 * keep the pins high that are that 
 * match the bit_positions passed. Thus peroforming
 * an and operation.
 **/
template<typename address_t, typename position_t>
inline void firmware::Registers<address_t, position_t>::check(address_t &address, position_t bit_positions)
{
        *(reinterpret_cast<volatile address_t *> (&address)) 
        = (*(reinterpret_cast<volatile address_t *> (&address))
        & (static_cast<position_t> (bit_positions)));
}






/**
 * By calling this method, it should
 * set all high pins low. Thereby,
 * disabling the register.
 **/
template<typename address_t, typename position_t>
inline void firmware::Registers<address_t, position_t>::disable(address_t &address, position_t bit_positions)
{
        *(reinterpret_cast<volatile address_t *> (&address))
        = (*(reinterpret_cast<volatile address_t *> (&address))
        & (static_cast<address_t> (~bit_positions)));
}





/**
 * By calling this method, it should
 * set all high pins low and all low
 * pins high. Thereby toggling the 
 * register.
 **/
template<typename address_t, typename position_t>
inline void firmware::Registers<address_t, position_t>::toggle(address_t &address, position_t bit_positions)
{
        *(reinterpret_cast<volatile address_t *> (&address))
        = (*(reinterpret_cast<volatile address_t *> (&address))
        ^ (static_cast<position_t> (bit_positions)));
}






/**
 * By calling this method, it should 
 * return the bit_positions of the register in
 * use.
 **/
template<typename address_t, typename position_t>
inline address_t firmware::Registers<address_t, position_t>::get(address_t &address)
{
        return (*(reinterpret_cast<volatile address_t *> (&address)));
}

















/*********************************
 * SINGLE BIT MANIPULATION METHODS
 *********************************/


/**
 * By calling this method, it should 
 * set a specific bit of a register 
 * to high. Thereby enabling a single
 * bit of the register.
 **/
template<typename address_t, typename position_t>
inline void firmware::Registers<address_t, position_t>::enable_bit(address_t &address, position_t bit_position)
{
         *(reinterpret_cast<volatile address_t *> (&address)) 
         = (*(reinterpret_cast<volatile address_t *> (&address)) 
         | (static_cast<position_t> (1U << bit_position)));
}





/**
 * By calling this method, it should
 * set a specific bit of a register
 * to low. Thereby disabling a single 
 * bit of the register.
 **/
template<typename address_t, typename position_t>
inline void firmware::Registers<address_t, position_t>::disable_bit(address_t &address, position_t bit_position)
{
        *(reinterpret_cast<volatile address_t *> (&address))
        = (*(reinterpret_cast<volatile address_t *> (&address))
        & (static_cast<volatile position_t> (~(1U << bit_position))));
}





/**
 * By calling this method, it should
 * set the bit that's currently high
 * to low or wisa versa. Thereby, 
 * toggling the bit on/off.
 **/
template<typename address_t, typename position_t>
inline void firmware::Registers<address_t, position_t>::toggle_bit(address_t &address, position_t bit_position)
{
        *(reinterpret_cast<volatile address_t *> (&address))
        = (*(reinterpret_cast<volatile address_t *> (&address))
        ^ (static_cast<position_t> (1U << bit_position)));
}






/**
 * By calling this method, it should
 * return the bit data of a specified
 * bit position of the register.
 **/
template<typename address_t, typename position_t>
inline address_t firmware::Registers<address_t, position_t>::get_bit(address_t &address, position_t bit_position)
{
        return ((get(address) & static_cast<position_t> (1U << bit_position)) != static_cast<position_t> (0U));
}

