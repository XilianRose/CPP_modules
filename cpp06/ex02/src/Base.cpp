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
	if (randValue == 0)
		return new A();
	else if (randValue == 1)
		return new B();
	else
		return new C();
}

void	Base::identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	Base::identify(Base& p) {
	identify(&p);
}
