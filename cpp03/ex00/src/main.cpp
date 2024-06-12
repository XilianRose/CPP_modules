#include "ClapTrap.hpp"

int	main(void){
	ClapTrap one = ClapTrap("Gamja");
	ClapTrap two = ClapTrap("Potato");
	ClapTrap cpy = ClapTrap(one);

	one.attack("you");
	one.printStatus();
	two.attack("you");
	two.printStatus();
	cpy.attack("you");
	one.takeDamage(5);
	one.printStatus();
	one.takeDamage(5);
	one.printStatus();
	one.takeDamage(5);
	one.printStatus();
	two.takeDamage(20);
	one.printStatus();
	for (int i = 0; i < 10; i++){
		one.beRepaired(1);
		one.printStatus();
	}
	two.beRepaired(20);
	two.printStatus();
	two.beRepaired(20);
	two.printStatus();
	return 1;
}