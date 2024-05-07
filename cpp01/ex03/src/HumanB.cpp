/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/07 15:07:12 by mstegema      #+#    #+#                 */
/*   Updated: 2024/05/07 15:22:45 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(void){
	std::cout << "Constructor called" << std::endl;
	return;
}

HumanB::HumanB(std::string name){
	this->_name = name;
	return;
}

HumanB::~HumanB(void){
	std::cout << "Destructor called" << std::endl;
	return;
}

void	HumanB::attack(void){
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	return;
}

void	HumanB::setWeapon(Weapon weapon){
	this->_weapon = weapon;
	return;
}
