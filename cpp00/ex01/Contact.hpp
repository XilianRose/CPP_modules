/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/05 12:29:16 by mstegema      #+#    #+#                 */
/*   Updated: 2024/04/25 15:17:53 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Contact {
public:
	Contact(void);
	~Contact(void);
	
	std::string	_FirstName;
	std::string	_LastName;
	std::string	_NickName;
	std::string	_PhoneNumber;
	std::string	_DarkestSecret;

	static int	GetId(void);

private:
	static int			_Id;
};
