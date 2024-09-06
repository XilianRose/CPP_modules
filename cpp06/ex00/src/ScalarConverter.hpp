#pragma once
#include <iostream>

class ScalarConverter {
	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & src);
		virtual	~ScalarConverter(void);

		virtual ScalarConverter &	operator=(ScalarConverter const & src) = 0;

		static void		convert(const std::string & input);
};
