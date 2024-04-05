/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/04 14:50:45 by mstegema      #+#    #+#                 */
/*   Updated: 2024/04/05 11:08:16 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char** argv)
{
	int j = 0;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			while (argv[i][j] != '\0')
			{
				argv[i][j] = std::toupper(argv[i][j]);
				std::cout << argv[i][j];
				j++;
			}
			j = 0;
		}
		std::cout << std::endl;
	}
	return 0;
}