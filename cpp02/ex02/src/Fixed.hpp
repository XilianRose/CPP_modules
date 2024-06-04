#pragma once
#include <iostream>

class Fixed {
	public:
	Fixed(void);
	Fixed(Fixed const & src);
	Fixed(int const param);
	Fixed(float const param);
	~Fixed(void);

	bool					operator>(Fixed const & src) const;
	bool					operator<(Fixed const & src) const;
	bool					operator>=(Fixed const & src) const;
	bool					operator<=(Fixed const & src) const;
	bool					operator==(Fixed const & src) const;
	bool					operator!=(Fixed const & src) const;

	Fixed					operator+(Fixed const & src) const;
	Fixed					operator-(Fixed const & src) const;
	Fixed					operator*(Fixed const & src) const;
	Fixed					operator/(Fixed const & src) const;

	Fixed &					operator++(void);
	Fixed &					operator--(void);
	Fixed					operator++(int param);
	Fixed					operator--(int param);

	Fixed &					operator=(Fixed const & src);
	friend std::ostream &	operator<<(std::ostream & out, Fixed const & src);

	static Fixed &			min(Fixed & a, Fixed & b);
	static Fixed &			min(Fixed const & a, Fixed const & b);
	static Fixed &			max(Fixed & a, Fixed & b);
	static Fixed &			max(Fixed const & a, Fixed const & b);

	int						getRawBits(void) const;
	void					setRawBits(int const raw);
	float					toFloat(void) const;
	int						toInt(void) const;

	private:
	int						_rawBits;
	static const int		_fractionalBits = 8;
};


