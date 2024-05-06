/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 16:21:50 by mstegema      #+#    #+#                 */
/*   Updated: 2024/05/06 16:52:46 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name){
	return new Zombie(name);
}
