#pragma once
#include <iostream>
#include "colours.hpp"

class ClapTrap{
	public:
		ClapTrap(void);
		ClapTrap(std::string const & name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);

		ClapTrap &		operator=(ClapTrap const & src);

		void			attack(std::string const & target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		std::string		getName(void) const;
		void			printStatus(void) const;

	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};
