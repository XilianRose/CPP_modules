#pragma once
#include <iostream>

class Fixed {
	public:
	Fixed(void);
	Fixed(Fixed const & src);
	Fixed(int const param);
	Fixed(float const param);
	~Fixed(void);

	Fixed &				operator=(Fixed const & src);
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;

	private:
	int					_rawBits;
	static const int	_fractionalBits = 8;
};
