#include "Fixed.hpp"

#define PURPLE "\33[0;95m"
#define NC "\33[0m"

int	main(void){
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << PURPLE "tests from subject" NC << std::endl;
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
	}
	// {
	// 	Fixed a(2);
	// 	Fixed b(3);

	// 	std::cout << std::endl << PURPLE "comparison operator tests (0: false 1: true)" NC << std::endl;
	// 	std::cout << a << " > " << b << " = " << (a > b) << std::endl;
	// 	std::cout << a << " < " << b << " = " << (a < b) << std::endl;
	// 	std::cout << a << " >= " << b << " = " << (a >= b) << std::endl;
	// 	std::cout << a << " <= " << b << " = " << (a <= b) << std::endl;
	// 	std::cout << a << " == " << b << " = " << (a == b) << std::endl;
	// 	std::cout << a << " != " << b << " = " << (a != b) << std::endl;

	// 	std::cout << std::endl << PURPLE "arithmetic operator tests" NC << std::endl;
	// 	std::cout << a << " + " << b << " = " << (a + b) << std::endl;
	// 	std::cout << a << " - " << b << " = " << (a - b) << std::endl;
	// 	std::cout << a << " * " << b << " = " << (a * b) << std::endl;
	// 	std::cout << a << " / " << b << " = " << (a / b) << std::endl;

	// 	std::cout << std::endl << PURPLE "in-/decrement operator tests" NC << std::endl;
	// 	std::cout << "before a++ " << a << "		during a++ " << a++ << "		after a++ " << a << std::endl;
	// 	std::cout << "before a-- " << a << "	during a-- " << a-- << "	after a-- " << a << std::endl;
	// 	std::cout << "before ++a " << a << "		during ++a " << ++a << "	after ++a " << a << std::endl;
	// 	std::cout << "before --a " << a << "	during --a " << --a << "		after --a " << a << std::endl;

	// 	std::cout << std::endl << PURPLE "min/max static member functions" NC << std::endl;
	// 	std::cout << "Fixed::min( a, b ) = " << Fixed::min( a, b ) << std::endl;
	// 	std::cout << "Fixed::max( a, b ) = " << Fixed::max( a, b ) << std::endl;
	// }
	return 0;
}
