/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/07 15:00:04 by mstegema      #+#    #+#                 */
/*   Updated: 2024/05/07 15:07:09 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanA {
	private:
	std::string	_name;
	Weapon		_weapon;

	public:
	HumanA(void);
	HumanA(std::string name, Weapon weapon);
	~HumanA(void);

	void	attack(void);
};