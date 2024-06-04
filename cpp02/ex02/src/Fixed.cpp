#include "Fixed.hpp"
#include <cmath>

/*		Constructors & destructors		*/
/*--------------------------------------*/
Fixed::Fixed(void) : _rawBits(0){
	// std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(int const param) : _rawBits(param << _fractionalBits){
	// std::cout << "Int parametric constructor called" << std::endl;
	return;
}

Fixed::Fixed(float const param) : _rawBits(std::roundf((1 << _fractionalBits) * param)){
	// std::cout << "Float parametric constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const & src){
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed(void){
	// std::cout << "Destructor called" << std::endl;
	return;
}


/*		Comparison operator overloads		*/
/*------------------------------------------*/
bool	Fixed::operator>(Fixed const & src) const{
	return this->_rawBits > src.getRawBits();
}

bool	Fixed::operator<(Fixed const & src) const{
	return this->_rawBits < src.getRawBits();
}

bool	Fixed::operator>=(Fixed const & src) const{
	return this->_rawBits >= src.getRawBits();
}

bool	Fixed::operator<=(Fixed const & src) const{
	return this->_rawBits <= src.getRawBits();
}

bool	Fixed::operator==(Fixed const & src) const{
	return this->_rawBits == src.getRawBits();
}

bool	Fixed::operator!=(Fixed const & src) const{
	return this->_rawBits != src.getRawBits();
}


/*		Arithmetic operator overloads		*/
/*------------------------------------------*/
Fixed	Fixed::operator+(Fixed const & src) const{
	Fixed	result;

	result.setRawBits(this->_rawBits + src.getRawBits());
	return result;
}

Fixed	Fixed::operator-(Fixed const & src) const{
	Fixed	result;

	result.setRawBits(this->_rawBits - src.getRawBits());
	return result;
}

Fixed	Fixed::operator*(Fixed const & src) const{
	Fixed	result;

	result.setRawBits((this->_rawBits * src.getRawBits()) / ( 1 << _fractionalBits));
	return result;
}

Fixed	Fixed::operator/(Fixed const & src) const{
	Fixed	result;

	result.setRawBits((this->_rawBits * ( 1 << _fractionalBits)) / src.getRawBits());
	return result;
}


/*		In-/decrement operator overloads		*/
/*----------------------------------------------*/
Fixed &	Fixed::operator++(void){
	this->_rawBits++;
	return *this;
}

Fixed &	Fixed::operator--(void){
	this->_rawBits--;
	return *this;
}

Fixed	Fixed::operator++(int){
	Fixed	temp(*this);
	this->_rawBits++;
	return temp;
}

Fixed	Fixed::operator--(int){
	Fixed	temp(*this);
	this->_rawBits--;
	return temp;
}


/*		Other operator overloads		*/
/*--------------------------------------*/
Fixed &	Fixed::operator=(Fixed const & src){
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = src.getRawBits();
	return *this;
}

std::ostream &	operator<<(std::ostream & out, Fixed const & src){
	return (out << src.toFloat());
}


/*		Member functions		*/
/*------------------------------*/
Fixed &	Fixed::min(Fixed & a, Fixed & b){
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed &	Fixed::min(Fixed const & a, Fixed const & b){
	if (a.getRawBits() < b.getRawBits())
		return (Fixed &) a;
	return (Fixed &) b;
}

Fixed &	Fixed::max(Fixed & a, Fixed & b){
	if (a.getRawBits() < b.getRawBits())
		return b;
	return a;
}

Fixed &	Fixed::max(Fixed const & a, Fixed const & b){
	if (a.getRawBits() < b.getRawBits())
		return (Fixed &) b;
	return (Fixed &) a;
}

int	Fixed::getRawBits(void) const{
	return this->_rawBits;
}

void	Fixed::setRawBits(int const raw){
	this->_rawBits = raw;
	return;
}

float	Fixed::toFloat(void) const {
	return this->_rawBits / (float)(1 << _fractionalBits);
}

int	Fixed::toInt(void) const {
	// return this->_rawBits >> _fractionalBits;
	return this->_rawBits / (1 << _fractionalBits);
}
