#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void){
	std::cout << "Default constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string const & name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << LILAC "A wild ClapTrap called "  << this->_name << " appeared" NC << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const & src) : _hitPoints(10), _energyPoints(10), _attackDamage(0){
	*this = src;
	std::cout << LILAC "Another ClapTrap called " << this->_name << " appeared" NC << std::endl;
	return;
}

ClapTrap::~ClapTrap(void){
	std::cout << LILAC "Default destructor called" << std::endl;
	return;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & src){
	this->_name = src.getName();
	return *this;
}

void	ClapTrap::attack(std::string const & target){
	if (this->_energyPoints > 0){
		std::cout << GREEN << this->_name << " attacks " << target << NC << std::endl;
		std::cout << GREEN << target << " lost " << this->_attackDamage << " hit points!" NC << std::endl;
		this->_energyPoints--;
	}
	else {
		std::cout << YELLOW "Oh no!" << this->_name << " tried to attack but doesn't have any energy points left" NC << std::endl;
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
	if (this->_hitPoints == 10)
		std::cout << YELLOW << this->_name << " already has max hit points!" NC << std::endl;
	else if (this->_energyPoints > 0){
		this->_energyPoints--;
		if (this->_hitPoints + amount <= 10){
			std::cout << CYAN << this->_name << " repairs itself with " << amount << " hit points!" NC << std::endl;
			this->_hitPoints += amount;
		}
		else{
			std::cout << CYAN << this->_name << " repairs itself with " << 10 - this->_hitPoints << " hit points!" NC << std::endl;
			this->_hitPoints = 10;
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
