/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/05 12:22:44 by mstegema      #+#    #+#                 */
/*   Updated: 2024/05/06 15:24:28 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook(void);
	~PhoneBook(void);

	void		add(void);
	void		search(void);

private:
	Contact		_contacts[8];
	int			_index;

	void		_gatherInfo(std::string& field, const std::string& prompt);
	std::string	_resizeToTen(const std::string &str);
	void		_printPB(void);
	void		_printContact(int index);

};
 