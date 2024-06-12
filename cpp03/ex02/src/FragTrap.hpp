#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
	public:
		FragTrap(void);
		FragTrap(std::string const & name);
		FragTrap(FragTrap const & src);
		~FragTrap(void);

		FragTrap &	operator=(FragTrap const & src);

		void		highFivesGuys(void);
};
