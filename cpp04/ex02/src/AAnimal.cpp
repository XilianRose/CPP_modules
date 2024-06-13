#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("default") {
	std::cout << "An AAnimal was born" << std::endl;
	return;
}

AAnimal::AAnimal(std::string const & type) : _type(type) {
	std::cout << "A specific type of AAnimal was born" << std::endl;
}

AAnimal::AAnimal(AAnimal const & src){
	std::cout << "Another AAnimal was born" << std::endl;
	*this = src;
	return;
}

AAnimal::~AAnimal(void){
	std::cout << "An AAnimal went to heaven" << std::endl;
	return;
}

AAnimal &	AAnimal::operator=(AAnimal const & src){
	this->_type = src._type;
	return *this;
}

void AAnimal::makeSound(void) const {
	std::cout << "*AAnimal sounds*" << std::endl;
	return;
}

std::string	AAnimal::getType(void) const {
	return this->_type;
}

void	AAnimal::setType(std::string const & type){
	this->_type = type;
	return;
}
