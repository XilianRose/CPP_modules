#include "WrongAnimal.hpp"
#include "colours.hpp"

WrongAnimal::WrongAnimal(void) : _type("default"){
	std::cout << RED << "A WrongAnimal was born" << std::endl;
	return;
}

WrongAnimal::WrongAnimal(std::string const & type) : _type(type){
	std::cout << "A specific type of WrongAnimal was born" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src){
	std::cout << "Another WrongAnimal was born" << std::endl;
	*this = src;
	return;
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "A WrongAnimal passed away" << std::endl;
	return;
}

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const & src){
	this->_type = src._type;
	return *this;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "*WrongAnimal sounds*" << std::endl;
	return;
}

std::string	WrongAnimal::getType(void) const {
	return this->_type;
}
