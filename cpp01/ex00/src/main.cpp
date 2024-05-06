/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 16:36:18 by mstegema      #+#    #+#                 */
/*   Updated: 2024/05/06 17:16:12 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void){
	Zombie	*billy = newZombie("billy");
	randomChump("zaddy");
	billy->announce();
	delete billy;
	return 0;
}
