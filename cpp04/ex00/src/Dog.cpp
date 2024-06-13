#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"){
	std::cout << "It's a dog" << std::endl;
	return;
}

Dog::Dog(Dog const & src){
	std::cout << "It's another dog" << std::endl;
	*this = src;
	return;
}

Dog::~Dog(void){
	std::cout << "The dog went to heaven" << std::endl;
	return;
}

Dog &	Dog::operator=(Dog const & src){
	this->_type = src._type;
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "Wooof!" << std::endl;
	return;
}
