#pragma once
#include <exception>
#include <map>
#include <string>

class BitcoinExchange{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		
		void	execute(std::string filename);
		class InvalidFileException : public std::exception{
			public:
				virtual const char * what() const throw();
		};
		class InvalidDBException : public std::exception{
			public:
				virtual const char * what() const throw();
		};
		class BadInputException : public std::exception{
			public:
				virtual const char * what() const throw();
		};
		class InvalidDateException : public std::exception{
			public:
				InvalidDateException(const std::string& date);
				virtual const char * what() const throw();
			private:
				std::string _date;
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
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		std::map<std::string, double> _data;
};
