/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randomChump.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 16:28:55 by mstegema      #+#    #+#                 */
/*   Updated: 2024/05/06 17:16:19 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump(std::string name){
	Zombie	newZombie = Zombie(name);
	newZombie.announce();
	return;
}
