#include "WrongAAnimal.hpp"
#include "colours.hpp"

WrongAAnimal::WrongAAnimal(void) : _type("default"){
	std::cout << RED << "A WrongAAnimal was born" << std::endl;
	return;
}

WrongAAnimal::WrongAAnimal(std::string const & type) : _type(type){
	std::cout << "A specific type of WrongAAnimal was born" << std::endl;
}

WrongAAnimal::WrongAAnimal(WrongAAnimal const & src){
	std::cout << "Another WrongAAnimal was born" << std::endl;
	*this = src;
	return;
}

WrongAAnimal::~WrongAAnimal(void){
	std::cout << "A WrongAAnimal passed away" << std::endl;
	return;
}

WrongAAnimal &	WrongAAnimal::operator=(WrongAAnimal const & src){
	this->_type = src._type;
	return *this;
}

void WrongAAnimal::makeSound(void) const {
	std::cout << "*WrongAAnimal sounds*" << std::endl;
	return;
}

std::string	WrongAAnimal::getType(void) const {
	return this->_type;
}
