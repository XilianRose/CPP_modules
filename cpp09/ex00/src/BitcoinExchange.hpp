#pragma once
#include <exception>

class BitcoinExchange{
	public:
		class InvalidFileException : public std::exception{
			public:
				virtual const char * what() const throw(){
					return "Error: could not open file.";
				}
		};
		class BadInputException : public std::exception{
			public:
				virtual const char * what() const throw(){
					return "Error: bad input.";
				}
		};
		class NegativeValueException : public std::exception{
			public:
				virtual const char * what() const throw(){
					return "Error: not a positive number.";
				}
		};
		class ValueTooLargeException : public std::exception{
			public:
				virtual const char * what() const throw(){
					return "Error: too large a number.";
				}
		};

	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();
};
