/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/05 12:35:53 by mstegema      #+#    #+#                 */
/*   Updated: 2024/05/02 19:01:46 by mstegema      ########   odam.nl         */
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

void PhoneBook::_gatherInfo(std::string& field, const std::string& prompt) {
	while (1) {
		std::cout << prompt;
		if (std::getline(std::cin, field) && field != "") {
			break;
		}
		std::cout << "Field can't be left empty." << std::endl;
	}
}

void PhoneBook::add() {
	Contact new_contact;

	new_contact = this->_contacts[this->_index % 8];
	if (this->_index > 7){
		std::cout << "Warning! Contact " << new_contact.firstName << " " << new_contact.lastName << " will be overwritten." << std::endl;
	}
	_gatherInfo(new_contact.firstName, "First name	: ");
	_gatherInfo(new_contact.lastName, "Last name	: ");
	_gatherInfo(new_contact.nickname, "Nickname	: ");
	_gatherInfo(new_contact.phoneNumber, "Phone number	: ");
	_gatherInfo(new_contact.darkestSecret, "Darkest secret	: ");

	// this->_contacts[this->_index % 8] = new_contact;
	this->_index++;
}

void	PhoneBook::search(void){
	std::string	input;

	while(1){
		input = "";
		std::cout << "Enter the index: ";
		if (std::getline(std::cin, input) && input != ""){
			break;
		}
		std::cout << "Field can't be left empty." << std::endl;
	}
	return;
}
