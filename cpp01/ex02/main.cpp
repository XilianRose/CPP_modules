/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 17:48:05 by mstegema      #+#    #+#                 */
/*   Updated: 2024/05/06 18:02:08 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void){
	std::string string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;
	std::string	stringCPY = string;

	std::cout << "Address of string:	" << &string << std::endl;
	std::cout << "Address of stringPTR:	" << stringPTR << std::endl;
	std::cout << "Address of stringREF:	" << &stringREF << std::endl;
	std::cout << "Address of stringCPY:	" << &stringCPY << std::endl;
	std::cout << "Value of string:	" << string << std::endl;
	std::cout << "Value of stringPTR:	" << *stringPTR << std::endl;
	std::cout << "Value of stringREF:	" << stringREF << std::endl;
	std::cout << "Value of stringCPY:	" << stringCPY << std::endl;
}
