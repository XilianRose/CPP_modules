/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/25 10:41:05 by mstegema      #+#    #+#                 */
/*   Updated: 2024/04/25 15:22:18 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void){
	std::cout << "Constructor called" << std::endl;
	Contact::_Id += 1;
	return;
}

Contact::~Contact(void){
	std::cout << "Destructor called" << std::endl;
	return;
}

int	Contact::GetId(void){
	return Contact::_Id;
}

int	Contact::_Id = 0;
