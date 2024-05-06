/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 15:48:45 by mstegema      #+#    #+#                 */
/*   Updated: 2024/05/06 17:36:03 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Zombie{
public:
	Zombie(void);
	~Zombie(void);

	void	setName(std::string name);
	void	announce(void);
	
private:
	std::string	_name;
};

Zombie		*zombieHorde(int N, std::string name);
