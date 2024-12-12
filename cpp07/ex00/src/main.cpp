#include <iostream>
#include "whatever.hpp"
#include "colours.hpp"

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << LILAC "~	tests from subject	~" NC << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	float e = 42.1f;
	float f = -4.2f;
	std::cout << LILAC "~	more testing	~" NC << std::endl;
	std::cout << "Max of " << e << " and " << f << " is " << max<float>(e, f) << std::endl; // Explicit instanciation 
	std::cout << "Max of " << e << " and " << f << " is " << ::max(e, f) << std::endl; // Implicit instanciation
	return 0;
}
