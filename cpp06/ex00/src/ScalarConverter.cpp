#include "ScalarConverter.hpp"
#include "colours.hpp"
#include <string>
#include <exception>
#include <iomanip>
#include <math.h>

ScalarConverter::ScalarConverter(void) {
	std::cout << GRAY "Default constructor called" NC << std::endl;
	return;
}

ScalarConverter::ScalarConverter(ScalarConverter const & src) {
	std::cout << GRAY "Copy constructor called" << std::endl;
	*this = src;
	return;
}

ScalarConverter::~ScalarConverter(void) {
	std::cout << GRAY "Default destructor called" NC << std::endl;
	return;
}

ScalarConverter &	ScalarConverter::operator=(ScalarConverter const & src) {
	std::cout << "Copy assignment operator called" << std::endl;
	(void)src;
	return *this;
}

void ScalarConverter::convert(const std::string & input) {
	// Char check
	if (input.length() == 1 && !isdigit(input[0])) {
		char c = input[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
		return;
	}

	// Double check
	try {
		double d = std::stod(input);
		if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
			std::cout << "char: impossible" << std::endl;
		else if (d < 32 || d > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		if (std::isnan(d) || std::isinf(d))
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
		return;
	} catch (std::exception & e) {
		// Not a double
	}

	// Float check
	try {
		float f = std::stof(input);
		if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
			std::cout << "char: impossible" << std::endl;
		else if (f < 32 || f > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
		if (std::isnan(f) || std::isinf(f))
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(f) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
		return;
	} catch (std::exception & e) {
		// Not a float
	}

	// Int check
	try {
		int i = std::stoi(input);
		if (std::isnan(i) || std::isinf(i) || i < 0 || i > 127)
			std::cout << "char: impossible" << std::endl;
		else
		if (i < 32 || i > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
		return;
	} catch (std::exception & e) {
		// Not an integer
	}

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
	return;
}
