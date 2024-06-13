#include "Cat.hpp"
#include "colours.hpp"

Cat::Cat(void) : AAnimal("Cat"){
	std::cout << LILAC "It's a cat" NC << std::endl;
	_brain = new Brain("Mischievous thought");
	return;
}

Cat::Cat(Cat const & src) : AAnimal("Cat"){
	std::cout << LILAC "It's another cat" NC << std::endl;
	*this = src;
	return;
}

Cat::~Cat(void){
	delete this-> _brain;
	std::cout << LILAC "The cat passed away" NC << std::endl;
	return;
}

Cat &	Cat::operator=(Cat const & src){
	this->_type = src._type;
	this->_brain = new Brain(*src._brain);
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << LILAC "Miaaaauw~" NC << std::endl;
	return;
}

Brain &	Cat::getBrain(void) const {
	return *this->_brain;
}
