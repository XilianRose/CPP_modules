/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 16:36:18 by mstegema      #+#    #+#                 */
/*   Updated: 2024/05/06 17:42:24 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void){
	int	N = 20;
	Zombie	*horde = zombieHorde(N, "Zombie");

	for(int	i = 0; i < N; i++){
		horde[i].announce();
	}
	delete [] horde;
	return 0;
}
