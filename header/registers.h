#ifndef _REGISTERS_H
#define _REGISTERS_H

namespace firmware
{
	template<typename address_t, typename position_t>
	class Registers
	{
		public:
			Registers(address_t &, position_t);

			~Registers(){}

			Registers()									= delete; // Explicitly removed

			Registers(const Registers &) 				= delete; // Explicitly removed

			Registers(Registers &&) 					= delete; // Explicitly removed

			Registers& operator = (const Registers &) 	= delete; // Explicitly removed

			Registers& operator = (Registers &&) 		= delete; // Explicitly removed
			

			
			// All register bits operations.
			inline void 		set(address_t &, position_t			);

 			inline void 		enable(address_t &, position_t		);
 
 			inline void 		check(address_t &, position_t		);
 
 			inline void			disable(address_t &, position_t		);

			inline void 		toggle(address_t &, position_t		);

			inline address_t 	get(address_t &						);


			// Single register bit operations.
			inline void 		enable_bit(address_t &, position_t	);	

			inline void 		disable_bit(address_t &, position_t	);

			inline void 		toggle_bit(address_t &, position_t	);

			inline address_t	get_bit(address_t &, position_t		);
	};
}


#endif




