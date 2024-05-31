#include "Fixed.hpp"

Fixed::Fixed(void){
	std::cout << "Constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const &src){
	std::cout << "Copy constructor called" << std::endl;
	return;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
	return;
}

