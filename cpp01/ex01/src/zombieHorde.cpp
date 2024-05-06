/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 17:20:25 by mstegema      #+#    #+#                 */
/*   Updated: 2024/05/06 17:37:56 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name){
	Zombie	*horde = new Zombie[N];

	for (int i = 0; i < N; i++){
		horde[i].setName(name);
	}
	return horde;
}