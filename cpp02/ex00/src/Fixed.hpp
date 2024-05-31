#pragma once
#include <iostream>

class Fixed {
	public:
	Fixed(void);
	Fixed(Fixed const &src);
	~Fixed(void);

	Fixed	&operator=(Fixed const &src);
};
