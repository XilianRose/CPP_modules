/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/05 12:33:49 by mstegema      #+#    #+#                 */
/*   Updated: 2024/05/06 15:15:56 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"


int	main(void){
	PhoneBook	phoneBook;
	std::string	input;

	while(1){
		input = "";
		std::cout << std::endl << "What would you like to do?" << std::endl;
		std::cout << "ADD	: save a new contact" << std::endl;
		std::cout << "SEARCH	: display a specific contact" << std::endl;
		std::cout << "EXIT	: exit ByteBook" << std::endl;
		while(1){
			std::cout << "> ";
			std::getline(std::cin, input);
			if (input == "ADD"){
				phoneBook.add();
				break;
			}
			else if (input == "SEARCH"){
				phoneBook.search();
				break;
			}
			else if (input == "EXIT")
				return 0;
			else{
				std::cout << std::endl << "Please enter a valid option." << std::endl;
				continue;
			}
		}
	}
	return 0;
}
