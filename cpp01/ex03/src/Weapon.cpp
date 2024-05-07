/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/07 14:49:14 by mstegema      #+#    #+#                 */
/*   Updated: 2024/05/07 15:00:00 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void){
	std::cout << "Constructor called" << std::endl;
	return;
}

Weapon::Weapon(std::string type){
	this->_type = type;
	return;
}

Weapon::~Weapon(void){
	std::cout << "Destructor called" << std::endl;
	return;
}

const std::string	&Weapon::getType(void){
	return this->_type;
}

void	Weapon::setType(std::string type){
	this->_type = type;
	return;
}
