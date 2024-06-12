#pragma once
#include <iostream>
#include "colours.hpp"

class ClapTrap{
	public:
		ClapTrap(void);
		ClapTrap(std::string const & name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);

		ClapTrap &			operator=(ClapTrap const & src);

		void				attack(std::string const & target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);

		std::string			getName(void) const;
		void				printStatus(void) const;
		// void				setName(std::string const & name);
		// unsigned int		getHitPoints(void) const;
		// void				setHitPoints(unsigned int amount);
		// unsigned int		getEnergyPoints(void) const;
		// void				setEnergyPoints(unsigned int amount);
		// unsigned int		getAttackDamage(void) const;
		// void				setAttackDamage(unsigned int amount);

	protected:
		std::string			_name = "Default";
		unsigned int		_hitPoints = 10;
		unsigned int		_energyPoints = 10;
		unsigned int		_attackDamage = 0;
		unsigned int		_maxHitPoints = 10;
};
