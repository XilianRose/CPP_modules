#include "FragTrap.hpp"

FragTrap::FragTrap(void){
	std::cout << "FragTrap Default constructor called" << std::endl;
	return;
}

FragTrap::FragTrap(std::string const & name) : ClapTrap(name){
	std::cout << LILAC "A wild FragTrap called " << name << " appeared" NC << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_maxHitPoints = 100;
	return;
}

FragTrap::FragTrap(FragTrap const & src){
	*this = src;
	std::cout << LILAC "Another FragTrap called " << this->_name << " appeared" NC << std::endl;
	return;
}

FragTrap::~FragTrap(void){
	std::cout << LILAC "FragTrap Default destructor called" NC << std::endl;
	return;
}

FragTrap &	FragTrap::operator=(FragTrap const & src){
	this->_name = src._name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_maxHitPoints = 100;
	return *this;
}

void	FragTrap::highFivesGuys(void){
	std::cout << MAGENTA << this->_name << " says: \"WHOOOHOOO!!! Can I get some high fives?!\"" NC << std::endl;
}