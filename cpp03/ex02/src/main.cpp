#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void){
	{
	ClapTrap clapTrap = ClapTrap("Gamja");
	ScavTrap scavTrap = ScavTrap("Potato");
	FragTrap fragTrap = FragTrap("Kriel");
	FragTrap fragTrapCpy = FragTrap(fragTrap);

	std::cout << std::endl << BOLD "~	Testing classes		~" NC << std::endl;
	clapTrap.attack("you");
	clapTrap.printStatus();
	clapTrap.takeDamage(5);
	clapTrap.printStatus();
	clapTrap.takeDamage(5);
	clapTrap.printStatus();
	clapTrap.takeDamage(5);
	clapTrap.printStatus();
	clapTrap.beRepaired(1);
	clapTrap.printStatus();
	std::cout << std::endl;
	scavTrap.attack("you");
	scavTrap.printStatus();
	scavTrap.takeDamage(20);
	scavTrap.printStatus();
	scavTrap.beRepaired(30);
	scavTrap.printStatus();
	scavTrap.beRepaired(20);
	scavTrap.printStatus();
	scavTrap.guardGate();
	std::cout << std::endl;
	fragTrap.attack("you");
	fragTrap.printStatus();
	fragTrapCpy.attack("you");
	fragTrapCpy.printStatus();
	fragTrap.takeDamage(20);
	fragTrap.printStatus();
	fragTrap.beRepaired(30);
	fragTrap.printStatus();
	fragTrap.highFivesGuys();
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