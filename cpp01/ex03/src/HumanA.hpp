/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/07 15:00:04 by mstegema      #+#    #+#                 */
/*   Updated: 2024/05/14 14:29:33 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanA {
	private:
	std::string	_name;
	Weapon&		_weapon;

	public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA(void);

	void	attack(void);
};
