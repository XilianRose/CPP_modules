#include "Animal.hpp"

Animal::Animal(void) : _type("default") {
	std::cout << "An animal was born" << std::endl;
	return;
}

Animal::Animal(std::string const & type) : _type(type) {
	std::cout << "A specific type of animal was born" << std::endl;
}

Animal::Animal(Animal const & src){
	std::cout << "Another animal was born" << std::endl;
	*this = src;
	return;
}

Animal::~Animal(void){
	std::cout << "An animal passed away" << std::endl;
	return;
}

Animal &	Animal::operator=(Animal const & src){
	this->_type = src._type;
	return *this;
}

void Animal::makeSound(void) const {
	std::cout << "*Animal sounds*" << std::endl;
	return;
}

std::string	Animal::getType(void) const {
	return this->_type;
}
