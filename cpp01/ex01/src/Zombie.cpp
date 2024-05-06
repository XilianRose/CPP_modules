/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 15:52:52 by mstegema      #+#    #+#                 */
/*   Updated: 2024/05/06 17:39:43 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void){
	std::cout << "Constructor called" << std::endl;
	return;
}

Zombie::~Zombie(void){
	std::cout << this->_name << "'s destructor called" << std::endl;
	return;
}

void	Zombie::setName(std::string name){
	this->_name = name;
	return;
}

void	Zombie::announce(void){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}
