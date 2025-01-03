#include "BitcoinExchange.hpp"
#include <string>
#include <fstream>
#include <regex>
#include <iostream>

void	trimWhitespace(std::string str){
	str.erase(0, str.find_first_not_of(' '));
	str.erase(str.find_last_not_of(' ') + 1);
	return ;
}

bool	validateDate(std::string date){
	if (date.length() != 10)
		return false;
	std::regex pattern("^[0-9]{4}-[0-9]{2}-[0-9]{2}$");
	if (!std::regex_match(date, pattern))
		return false;
	int year = std::stoi(date.substr(0, 4));
	int month = std::stoi(date.substr(5, 2));
	int day = std::stoi(date.substr(8, 2));
	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if (month == 4 || month == 6 || month == 9 || month == 11){
		if (day > 30)
			return false;
	}
	if (month == 2){
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
			if (day > 29)
				return false;
		}
		else{
			if (day > 28)
				return false;
		}
	}
	return true;
}

std::map<std::string, double>	parseDB(void){
	std::map<std::string, double> data;
	std::ifstream db("../src/data.csv");
	std::string line;
	std::string date;
	double value;

	if (!db.is_open())
		throw BitcoinExchange::InvalidFileException();
	std::getline(db, line); //skip header
	while (std::getline(db, line)){
		size_t pos = line.find(',');
		if (pos == std::string::npos)
			throw BitcoinExchange::InvalidDBException();		
		date = line.substr(0, pos);
		if (!validateDate(date))
			throw BitcoinExchange::InvalidDBException();
		try{
			value = std::stod(line.substr(pos + 1));
		}
		catch (std::exception &e){
			throw BitcoinExchange::InvalidDBException();
		}
		data[date] = value;
	}
	db.close();
	return data;
}

std::string	convert(std::string line){
	std::string date;
	double value;

		size_t pos = line.find('|');
		if (pos == std::string::npos)
			throw BitcoinExchange::BadInputException();
		date = line.substr(0, pos);
		trimWhitespace(date);
		if (!validateDate(date))
			throw BitcoinExchange::InvalidDateException(date);
		try{
			value = std::stod(line.substr(pos + 1));
		}
		catch (std::exception &e){
			throw BitcoinExchange::BadInputException();
		}
		if (value < 0)
			throw BitcoinExchange::NegativeValueException();
		if (value > 1000)
			throw BitcoinExchange::ValueTooLargeException();
		
}

void	BitcoinExchange::execute(std::string filename){
	std::ifstream file(filename);
	std::string line;

	_data = parseDB();
	if (_data.empty())
		throw BitcoinExchange::InvalidDBException();
	if (!file.is_open())
		throw BitcoinExchange::InvalidFileException();
	std::getline(file, line); //skip header
	while (std::getline(file, line)){
		try{
			convert(line);
		}
		catch (std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}
	file.close();
	return ;
}

const char *BitcoinExchange::InvalidFileException::what() const throw(){
	return "Error: could not open file.";
}

const char *BitcoinExchange::InvalidDBException::what() const throw(){
	return "Error: database invalid.";
}

const char *BitcoinExchange::BadInputException::what() const throw(){
	return "Error: bad input.";
}

BitcoinExchange::InvalidDateException::InvalidDateException(const std::string& date) : _date(date) {
	return ;
}

const char *BitcoinExchange::InvalidDateException::what() const throw(){
	std::string res = "Error: date invalid => " + _date;
	return res.c_str();
}

const char *BitcoinExchange::NegativeValueException::what() const throw(){
	return "Error: not a positive number.";
}

const char *BitcoinExchange::ValueTooLargeException::what() const throw(){
	return "Error: too large a number.";
}
