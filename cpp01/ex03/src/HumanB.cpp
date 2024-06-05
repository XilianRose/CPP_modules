/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/07 15:07:12 by mstegema      #+#    #+#                 */
/*   Updated: 2024/06/05 12:06:30 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(void){
	std::cout << "Default constructor called" << std::endl;
	return;
}

HumanB::HumanB(std::string name) :_name(name), _weapon(nullptr){
	std::cout << this->_name << "'s constructor called" << std::endl;
	return;
}

HumanB::~HumanB(void){
	std::cout << this->_name << "'s destructor called" << std::endl;
	return;
}

void	HumanB::attack(void){
	if (this->_weapon == nullptr)
		std::cout << PURPLE "The attack failed, " << this->_name << " has no weapon equipped" NC << std::endl;
	else
		std::cout << PURPLE << this->_name << " attacks with their " << this->_weapon->getType() << NC << std::endl;
	return;
}

void	HumanB::setWeapon(Weapon& weapon){
	this->_weapon = &weapon;
	return;
}
