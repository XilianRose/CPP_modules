/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/07 15:07:12 by mstegema      #+#    #+#                 */
/*   Updated: 2024/06/05 12:06:09 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon){
	std::cout << this->_name << "'s constructor called" << std::endl;
	return;
}

HumanA::~HumanA(void){
	std::cout << this->_name << "'s destructor called" << std::endl;
	return;
}

void	HumanA::attack(void){
	std::cout << PURPLE << this->_name << " attacks with their " << this->_weapon.getType() << NC << std::endl;
	return;
}
