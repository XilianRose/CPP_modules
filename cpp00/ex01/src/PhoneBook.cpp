/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/05 12:35:53 by mstegema      #+#    #+#                 */
/*   Updated: 2024/05/06 15:21:09 by mstegema      ########   odam.nl         */
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

void PhoneBook::_gatherInfo(std::string& field, const std::string& prompt){
	while (1) {
		std::cout << prompt;
		if (std::getline(std::cin, field) && field != "") {
			break;
		}
		std::cout << std::endl << "Field can't be left empty." << std::endl << std::endl;
	}
}

void PhoneBook::add(){
	Contact newContact;

	if (this->_index > 7){
		std::cout << std::endl << "Warning! Contact #" << this->_index % 8 + 1 << " will be overwritten." << std::endl;
	}
	std::cout << std::endl;
	_gatherInfo(newContact.firstName, "First name	: ");
	_gatherInfo(newContact.lastName, "Last name	: ");
	_gatherInfo(newContact.nickname, "Nickname	: ");
	_gatherInfo(newContact.phoneNumber, "Phone number	: ");
	_gatherInfo(newContact.darkestSecret, "Darkest secret	: ");
	this->_contacts[this->_index % 8] = newContact;
	this->_index++;
}

std::string	PhoneBook::_resizeToTen(const std::string &str){
	std::string	res = str;
	int			len = res.length();
	
	if (len > 10) {
		res.resize(10);
		res[9] = '.';
	}
	else if (len < 10) {
		res.insert(0, 10 - len, ' ');
	}
	return res;
}

void	PhoneBook::_printPB(void){
	std::string	line = "_";

	line.resize(10 * 4 + 3, '_');
	std::cout << std::endl;
	std::cout << _resizeToTen("Index") << "|";
	std::cout << _resizeToTen("First Name") << "|";
	std::cout << _resizeToTen("Last Name") << "|";
	std::cout << _resizeToTen("Nickname") << std::endl;
	std::cout << line << std::endl;
	for(int i = 0; i < 8; i++){
		std::cout << _resizeToTen(std::to_string(i + 1)) << "|";
		std::cout << _resizeToTen(this->_contacts[i].firstName) << "|";
		std::cout << _resizeToTen(this->_contacts[i].lastName) << "|";
		std::cout << _resizeToTen(this->_contacts[i].nickname) << std::endl;
	}
	return;
}

void	PhoneBook::_printContact(int index){
	Contact	contact = this->_contacts[index - 1];

	std::cout << std::endl;
	std::cout << "First name	: " << contact.firstName << std::endl;
	std::cout << "Last name	: " << contact.lastName << std::endl;
	std::cout << "Nickname	: " << contact.nickname << std::endl;
	std::cout << "Phone number	: " << contact.phoneNumber << std::endl;
	std::cout << "Darkest secret	: " << contact.darkestSecret << std::endl;
	return;
}

void	PhoneBook::search(void){
	std::string	input;
	int			index;

	_printPB();
	if (this->_index == 0){
		std::cout << std::endl << "ByteBook is empty!" << std::endl;
		return;
	}
	while(1){
		input = "";
		std::cout << std::endl << "Enter the index of the contact you would like to display" << std::endl << "> ";
		if (std::getline(std::cin, input) && input != ""){
			if (input.length() == 1 && input[0] > '0' && input[0] < '9'){
				index = std::stoi(input);
				if (index <= this->_index)
					break;
			}
			std::cout << std::endl << "Invalid option." << std::endl;
		}
		if (input == ""){
		std::cout << std::endl << "Field can't be left empty." << std::endl << std::endl;
		}
	}
	_printContact(index);
	return;
}
