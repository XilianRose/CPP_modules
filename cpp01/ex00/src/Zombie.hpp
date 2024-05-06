/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 15:48:45 by mstegema      #+#    #+#                 */
/*   Updated: 2024/05/06 17:15:58 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Zombie{
public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);

	void		announce(void);
	
private:
	std::string	_name;
};

Zombie		*newZombie(std::string name);
void		randomChump(std::string name);
