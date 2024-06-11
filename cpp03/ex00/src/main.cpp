#include "ClapTrap.hpp"

int	main(void){
	ClapTrap one = ClapTrap("Puffy");
	ClapTrap two = ClapTrap("Potato");
	ClapTrap cpy = ClapTrap(one);

	one.attack("Ringo");
	one.printStatus();
	two.attack("Ringo");
	two.printStatus();
	cpy.attack("Ringo");
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