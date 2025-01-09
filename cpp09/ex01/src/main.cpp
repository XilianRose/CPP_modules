#include "RPN.hpp"
#include <iostream>
#include "colours.hpp"

int	main(int argc, char **argv) {
	RPN rpn;

	if (argc != 2) {
		std::cerr << "Usage: ./ RPN \"expression\"" << std::endl;
		return 1;
	}
	std::string input = argv[1];
	try {
		rpn.parse(input);
		std::cout << rpn.calculate(input) << std::endl;
	}
	catch (RPN::InvalidExpressionException &e) {
		std::cerr << RED << e.what() << NC << std::endl;
		return 1;
	}
	return 0;
}
