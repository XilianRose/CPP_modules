#include "BitcoinExchange.hpp"
#include <string>
#include <fstream>
#include <regex>

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
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);
	if (std::stoi(year) < 2010 || std::stoi(year) > 2021)
		return false;
	if (std::stoi(month) < 1 || std::stoi(month) > 12)
		return false;
	if (std::stoi(day) < 1 || std::stoi(day) > 31)
		return false;
	return true;
}

std::map<std::string, double>	parseDB(std::string filename){
	std::map<std::string, double> data;
	std::ifstream file(filename);
	std::string line;
	std::string date;
	double value;

	if (!file.is_open())
		throw BitcoinExchange::InvalidFileException();
	std::getline(file, line); //skip header
	while (std::getline(file, line)){
		if (line.empty())
			continue;
		size_t pos = line.find('|');
		if (pos == std::string::npos)
			throw BitcoinExchange::BadInputException();
		date = line.substr(0, pos);
		trimWhitespace(date);
		if (!validateDate(date))
			throw BitcoinExchange::BadInputException();
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
		data[date] = value;
	}
	file.close();
	return data;
}

void	BitcoinExchange::execute(std::string filename){
	_data = parseDB(filename);

	return ;
}

const char *BitcoinExchange::InvalidFileException::what() const throw(){
	return "Error: could not open file.";
}

const char *BitcoinExchange::BadInputException::what() const throw(){
		return "Error: bad input.";
}

const char *BitcoinExchange::NegativeValueException::what() const throw(){
		return "Error: not a positive number.";
}

const char *BitcoinExchange::ValueTooLargeException::what() const throw(){
		return "Error: too large a number.";
}
