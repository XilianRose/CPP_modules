#pragma once
#include <iostream>

class ClapTrap{
	public:
		ClapTrap(void);
		ClapTrap(std::string const & name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);

		ClapTrap &	operator=(ClapTrap const & src);

		std::string	getName(ClapTrap const & src);
		void		attack(std::string const & target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};
