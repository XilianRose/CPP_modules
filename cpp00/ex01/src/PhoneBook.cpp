/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/05 12:35:53 by mstegema      #+#    #+#                 */
/*   Updated: 2024/05/02 17:54:04 by mstegema      ########   odam.nl         */
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
		if (std::getline(std::cin, input) && input != "")
		{
			this->_contacts[this->_index % 8].FirstName = input;
			break;
		}
		std::cout << "Field can't be left empty." << std::endl;
	}
	while(1)
	{
		input = "";
		std::cout << "Last name	: ";
		if (std::getline(std::cin, input) && input != "")
		{
			this->_contacts[this->_index % 8].LastName = input;
			break;
		}
		std::cout << "Field can't be left empty." << std::endl;
	}
	std::cout << "FirstName: " << this->_contacts[this->_index % 8].FirstName << std::endl;
	std::cout << "LastName: " << this->_contacts[this->_index % 8].LastName << std::endl;
	this->_index++;
	return;
}

void	PhoneBook::search(void){
	std::string	input;

	while(1)
	{
		input = "";
		std::cout << "Enter the index: ";
		if (std::getline(std::cin, input) && input != "")
		{
			break;
		}
		std::cout << "Field can't be left empty." << std::endl;
	}
	return;
}
