#include "Dog.hpp"
#include "colours.hpp"

Dog::Dog(void) : Animal("Dog"){
	std::cout << CYAN "It's a dog" NC << std::endl;
	_brain = new Brain("Obedient thought");
	return;
}

Dog::Dog(Dog const & src) : Animal("Dog"){
	std::cout << CYAN "It's another dog" NC << std::endl;
	*this = src;
	return;
}

Dog::~Dog(void){
	delete this->_brain;
	std::cout << CYAN "The dog passed away" NC << std::endl;
	return;
}

Dog &	Dog::operator=(Dog const & src){
	this->_type = src._type;
	this->_brain = new Brain(*src._brain);
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << CYAN "Wooof!" NC << std::endl;
	return;
}

Brain &	Dog::getBrain(void) const {
	return *this->_brain;
}
