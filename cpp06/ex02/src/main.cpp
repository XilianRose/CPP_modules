#include "Base.hpp"
#include <iostream>
#include "colours.hpp"

int main(void) {
	Base*	base = new Base();
	Base*	generated = base->generate();
	Base*	generated2 = base->generate();

	std::cout << UNDERLINE "Generated 1" NC << std::endl;
	std::cout << "Identify by pointer:	";
	base->identify(generated);
	std::cout << "Identify by reference:	";
	base->identify(*generated);
	std::cout << UNDERLINE "\nGenerated 2" NC << std::endl;
	std::cout << "Identify by pointer:	";
	base->identify(generated2);
	std::cout << "Identify by reference:	";
	base->identify(*generated2);

	delete generated;
	delete generated2;
	delete base;

	return 0;
}
