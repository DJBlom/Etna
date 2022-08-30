#ifndef _REGISTERS_H
#define _REGISTERS_H


namespace driver
{
	namespace registers
	{
		template<typename address_t, typename position_t>
		static inline void 		set(address_t &, position_t			);

		template<typename address_t, typename position_t>
 		static inline void 		enable(address_t &, position_t		);
 
		template<typename address_t, typename position_t>
 		static inline void 		check(address_t &, position_t		);
 
		template<typename address_t, typename position_t>
 		static inline void			disable(address_t &, position_t		);

		template<typename address_t, typename position_t>
		static inline void 		toggle(address_t &, position_t		);

		template<typename address_t>
		static inline address_t 	get(address_t &						);

			// Single register bit operations.
		template<typename address_t, typename position_t>
		static inline void 		enable_bit(address_t &, position_t	);	

		template<typename address_t, typename position_t>
		static inline void 		disable_bit(address_t &, position_t	);

		template<typename address_t, typename position_t>
		static inline void 		toggle_bit(address_t &, position_t	);

		template<typename address_t, typename position_t>
		static inline address_t	get_bit(address_t &, position_t		);
	}
}

#include "src/registers.cpp"

#endif




