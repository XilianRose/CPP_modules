#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0){
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(int const param){
	std::cout << "Int parametric constructor called" << std::endl;
	this->_rawBits = param << _fractionalBits;
	return;
}

Fixed::Fixed(float const param){
	std::cout << "Float parametric constructor called" << std::endl;
	this->_rawBits = (int)((1 << this->_fractionalBits) * param);
	// int	intPart = (int) param;
	// int	fractionalPart = param - intPart;
	// this->_rawBits = intPart << _fractionalBits;
	// this->_rawBits += (int)((1 << _fractionalBits)*(fractionalPart));
	return; 
}

Fixed::Fixed(Fixed const & src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed &	Fixed::operator=(Fixed const & src){
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = src.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

void	Fixed::setRawBits(int const raw){
std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
	return;
}

float	Fixed::toFloat(void) const {
	return this->_rawBits / (float)(1 << this->_fractionalBits);
}