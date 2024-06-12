#include "ScavTrap.hpp"

int	main(void){
	{
	ClapTrap clapTrap = ClapTrap("Gamja");
	ScavTrap scavTrap = ScavTrap("Potato");
	ScavTrap scavTrapCpy = ScavTrap(scavTrap);

	std::cout << std::endl << BOLD "~	Testing classes		~" NC << std::endl;
	clapTrap.attack("you");
	clapTrap.printStatus();
	scavTrap.attack("you");
	scavTrap.printStatus();
	scavTrapCpy.attack("you");
	scavTrapCpy.printStatus();
	clapTrap.takeDamage(5);
	clapTrap.printStatus();
	clapTrap.takeDamage(5);
	clapTrap.printStatus();
	clapTrap.takeDamage(5);
	clapTrap.printStatus();
	scavTrap.takeDamage(20);
	scavTrap.printStatus();
	clapTrap.beRepaired(1);
	clapTrap.printStatus();
	scavTrap.beRepaired(30);
	scavTrap.printStatus();
	scavTrap.beRepaired(20);
	scavTrap.printStatus();
	scavTrap.guardGate();
	std::cout << std::endl;
	}
	std::cout << std::endl << BOLD "~	Testing default constructor	~" NC << std::endl;
	{
	ClapTrap noName;
	noName.attack("you");
	noName.takeDamage(1);
	noName.beRepaired(1);
	noName.printStatus();
	}
	return 0;
}