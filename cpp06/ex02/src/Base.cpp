#include "Base.hpp"
#include <random>
#include <iostream>

Base::~Base(void) {
}

Base*	Base::generate(void) {
	std::random_device					rd;
	std::mt19937						gen(rd());
	std::uniform_int_distribution<int>	dist(0, 2);

	int	randValue = dist(gen);
	if (randValue == 0){
		// std::cout << "Created A" << std::endl;
		return new A();
	}
	else if (randValue == 1){
		// std::cout << "Created B" << std::endl;
		return new B();
	}
	else{
		// std::cout << "Created C" << std::endl;
		return new C();
	}
}

void	Base::identify(Base* ptr) {
	if (!ptr)
		std::cout << "Null pointer" << std::endl;
	if (dynamic_cast<A*>(ptr))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(ptr))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(ptr))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	Base::identify(Base& ref) {
	identify(&ref);
}
