/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/07 13:25:27 by mstegema      #+#    #+#                 */
/*   Updated: 2024/05/07 14:52:21 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Weapon {
	private:
	std::string	_type;

	public:
	Weapon(void);
	Weapon(std::string type);
	~Weapon(void);
	
	const std::string	&getType(void);
	void				setType(std::string type);
};
