#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void){
	std::cout << "Default constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string const & name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "A wild "  << this->_name << " appeared" << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const & src){
	*this = src;
	std::cout << "Another " << this->_name << " appeared" << std::endl;
	return;
}

ClapTrap::~ClapTrap(void){
	std::cout << "Default destructor called" << std::endl;
	return;
}

std::string	ClapTrap::getName(void){
	return this->_name;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & src){
	this->_name = src._name; //why not src.getName()???
}
