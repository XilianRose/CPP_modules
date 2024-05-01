/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/05 12:35:53 by mstegema      #+#    #+#                 */
/*   Updated: 2024/05/01 16:49:34 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	std::cout << "Welcome to ByteBook!" << std::endl;
	this->_index = 0;
	return;
}

PhoneBook::~PhoneBook(void){
	std::cout << "GoodByte!" << std::endl;
	return;
}

void	PhoneBook::add(void){
	std::string	input;

	while(1)
	{
		input = "";
		std::cout << "First name	: ";
		if (std::getline(std::cin, input) && input !=)
			this->_contacts[this->_index % 8].FirstName = input;
	}
	return;
}

