/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/07 15:07:12 by mstegema      #+#    #+#                 */
/*   Updated: 2024/05/07 15:15:50 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(void){
	std::cout << "Constructor called" << std::endl;
	return;
}

HumanA::HumanA(std::string name, Weapon weapon){
	this->_name = name;
	this->_weapon = weapon;
	return;
}

HumanA::~HumanA(void){
	std::cout << "Destructor called" << std::endl;
	return;
}

void	HumanA::attack(void){
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	return;
}
