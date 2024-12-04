#include "Base.hpp"

int main(void) {
	Base*	base = new Base();
	Base*	generated = base->generate();
	Base*	generated2 = base->generate();

	base->identify(generated);
	base->identify(*generated);
	base->identify(generated2);
	base->identify(*generated2);

	delete generated;
	delete generated2;
	delete base;

	return 0;
}
