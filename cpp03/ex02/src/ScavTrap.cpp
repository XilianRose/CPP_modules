#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void){
	std::cout << "ScavTrap Default constructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string const & name) {
	std::cout << LILAC "A wild ScavTrap called " << name << " appeared" NC << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_maxHitPoints = 100;
	return;
}

ScavTrap::ScavTrap(ScavTrap const & src){
	*this = src;
	std::cout << LILAC "Another ScavTrap called " << this->_name << " appeared" NC << std::endl;
	return;
}

ScavTrap::~ScavTrap(void){
	std::cout << LILAC "ScavTrap Default destructor called" NC << std::endl;
	return;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const & src){
	this->_name = src.getName();
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_maxHitPoints = 100;
	return *this;
}

void	ScavTrap::attack(std::string const & target){
	if (this->_energyPoints > 0){
		std::cout << GREEN << "ScavTrap " << this->_name << " attacks " << target ;
		std::cout << " and " << target << " lost " << this->_attackDamage << " hit points!" NC << std::endl;
		this->_energyPoints--;
	}
	else {
		std::cout << YELLOW "Oh no! ScavTrap " << this->_name << " tried to attack but doesn't have any energy points left" NC << std::endl;
	}
	return;
}

void	ScavTrap::guardGate(void){
	std::cout << MAGENTA "ScavTrap " << this->_name << " is now in Gatekeeper mode" NC << std::endl;
	return;
}