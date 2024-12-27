#pragma once
#include <exception>
#include <map>

class BitcoinExchange{
	public:
		static void	execute(std::string filename);
		class InvalidFileException : public std::exception{
			public:
				virtual const char * what() const throw();
		};
		class BadInputException : public std::exception{
			public:
				virtual const char * what() const throw();
		};
		class NegativeValueException : public std::exception{
			public:
				virtual const char * what() const throw();
		};
		class ValueTooLargeException : public std::exception{
			public:
				virtual const char * what() const throw();
		};

	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		static std::map<std::string, double> _data;
};
