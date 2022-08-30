/**
 * Contents	: Static helper functions to access MCU registers.
 *
 * Author	: Dawid Blom	
 *
 * Date		: 08/30/2022
 *
 * NOTE		:
 **/



namespace driver
{
	namespace registers
	{
		/*************************************
		 * MULTIPLE BIT MANIPULATION FUNCTIONS
		 *************************************/


		/**
		 * By calling this method, it should
		 * allow the programmer to set and re-
		 * set the whole register with a new 
		 * or old bit_positions.
		 **/
		template<typename address_t, typename position_t>
		static inline void set(address_t &address, position_t bit_positions)
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
		static inline void enable(address_t &address, position_t bit_positions)
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
		static inline void check(address_t &address, position_t bit_positions)
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
		static inline void disable(address_t &address, position_t bit_positions)
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
		static inline void toggle(address_t &address, position_t bit_positions)
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
		template<typename address_t>
		static inline address_t get(address_t &address)
		{
				return (*(reinterpret_cast<volatile address_t *> (&address)));
		}

















		/***********************************
		 * SINGLE BIT MANIPULATION FUNCTIONS	
		 ***********************************/


		/**
		 * By calling this method, it should 
		 * set a specific bit of a register 
		 * to high. Thereby enabling a single
		 * bit of the register.
		 **/
		template<typename address_t, typename position_t>
		static inline void enable_bit(address_t &address, position_t bit_position)
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
		static inline void disable_bit(address_t &address, position_t bit_position)
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
		static inline void toggle_bit(address_t &address, position_t bit_position)
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
		static inline address_t get_bit(address_t &address, position_t bit_position)
		{
				return ((get(address) & static_cast<position_t> (1U << bit_position)) != static_cast<position_t> (0U));
		}
	}
}
