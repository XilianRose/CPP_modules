#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat"){
	std::cout << "It's a cat" << std::endl;
	return;
}

Cat::Cat(Cat const & src){
	std::cout << "It's another cat" << std::endl;
	*this = src;
	return;
}

Cat::~Cat(void){
	std::cout << "The cat went to heaven" << std::endl;
	return;
}

Cat &	Cat::operator=(Cat const & src){
	this->_type = src._type;
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "Miaaaauw~" << std::endl;
	return;
}
