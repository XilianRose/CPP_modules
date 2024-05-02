/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/04 14:50:45 by mstegema      #+#    #+#                 */
/*   Updated: 2024/05/02 18:05:05 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char** argv)
{
	std::string	input;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; argv[i] != nullptr; i++)
		{
			input.append(argv[i]);
		}
		for (int i = 0; input[i] != '\0'; i++)
		{
			input[i] = std::toupper(input[i]);
		}
		std::cout << input << std::endl;
	}
	return 0;
}
