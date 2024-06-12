#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	std::cout << "ClapTrap Default constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string const & name) : _name(name){
	std::cout << LILAC "A wild ClapTrap called "  << this->_name << " appeared" NC << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	*this = src;
	std::cout << LILAC "Another ClapTrap called " << this->_name << " appeared" NC << std::endl;
	return;
}

ClapTrap::~ClapTrap(void){
	std::cout << "ClapTrap Default destructor called" << std::endl;
	return;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & src){
	this->_name = src.getName();
	return *this;
}

void	ClapTrap::attack(std::string const & target){
	if (this->_energyPoints > 0){
		std::cout << GREEN << "ClapTrap " << this->_name << " attacks " << target;
		std::cout << " and " << target << " lost " << this->_attackDamage << " hit points!" NC << std::endl;
		this->_energyPoints--;
	}
	else {
		std::cout << YELLOW "Oh no! ClapTrap " << this->_name << " tried to attack but doesn't have any energy points left" NC << std::endl;
	}
	return;
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (this->_hitPoints == 0){
		std::cout << RED << this->_name << "'s already dead, YOU BASTARD! *sobbing noises*" NC << std::endl;
	}
	else if (amount >= this->_hitPoints){
		std::cout << RED << this->_name << " took " << this->_hitPoints << " damage and died in battle :(" NC << std::endl;
		this->_hitPoints = 0;
	}
	else if (amount < this->_hitPoints){
		std::cout << YELLOW << this->_name << " was attacked and took " << amount << " damage" NC << std::endl;
		this->_hitPoints -= amount;
	}
	return;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->_hitPoints == this->_maxHitPoints)
		std::cout << YELLOW << this->_name << " already has max hit points!" NC << std::endl;
	else if (this->_energyPoints > 0){
		this->_energyPoints--;
		if (this->_hitPoints + amount <= this->_maxHitPoints){
			std::cout << CYAN << this->_name << " repairs itself with " << amount << " hit points!" NC << std::endl;
			this->_hitPoints += amount;
		}
		else{
			std::cout << CYAN << this->_name << " repairs itself with " << this->_maxHitPoints - this->_hitPoints << " hit points!" NC << std::endl;
			this->_hitPoints = this->_maxHitPoints;
		}
	}
	else {
		std::cout << YELLOW "Oh no! " << this->_name << " tried to repair itself but doesn't have any energy points left" NC << std::endl;
	}
	return;
}

std::string	ClapTrap::getName(void) const{
	return this->_name;
}

void	ClapTrap::printStatus(void) const{
	std::cout << UNDERLINE << this->_name <<"'s status" NC << std::endl;
	std::cout << "Hit points	: " << this->_hitPoints << std::endl;
	std::cout << "Energy points	: " << this->_energyPoints << std::endl;
	return;
}

// void	ClapTrap::setName(std::string const & name){
// 	this->_name = name;
// 	return;
// }

// unsigned int	ClapTrap::getHitPoints(void) const{
// 	return this->_hitPoints;
// }

// void	ClapTrap::setHitPoints(unsigned int amount){
// 	this->_hitPoints = amount;
// 	return;
// }

// unsigned int	ClapTrap::getEnergyPoints(void) const{
// 	return this->_energyPoints;
// }

// void	ClapTrap::setEnergyPoints(unsigned int amount){
// 	this->_energyPoints = amount;
// 	return;
// }

// unsigned int	ClapTrap::getAttackDamage(void) const{
// 	return this->_attackDamage;
// }

// void	ClapTrap::setAttackDamage(unsigned int amount){
// 	this->_attackDamage = amount;
// 	return;
// }
