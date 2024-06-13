#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAAnimal("WrongCat"){
	std::cout << "It's a Wrongcat" << std::endl;
	return;
}

WrongCat::WrongCat(WrongCat const & src){
	std::cout << "It's another Wrongcat" << std::endl;
	*this = src;
	return;
}

WrongCat::~WrongCat(void){
	std::cout << "The Wrongcat went to heaven" << std::endl;
	return;
}

WrongCat &	WrongCat::operator=(WrongCat const & src){
	this->_type = src._type;
	return *this;
}

void WrongCat::makeSound(void) const {
	std::cout << "Miaaaauw~" << std::endl;
	return;
}
