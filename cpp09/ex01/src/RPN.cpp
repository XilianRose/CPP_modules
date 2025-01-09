#include "RPN.hpp"
#include <regex>

/*	Constructor & destructor	*/
RPN::RPN() {
}

RPN::~RPN() {
}

/*	Member functions	*/
void	RPN::parse(std::string &str) {
	for (auto it = str.begin(); it != str.end(); it++){
		if (isdigit(*it) || *it == '+' || *it == '-' || *it == '*' || *it == '/' || *it == ' ')
			continue ;
		else
			throw InvalidExpressionException();
	}
	return ;
}

int	RPN::calculate(std::string &str) {
	std::regex pattern("([0-9]+|\\+|\\-|\\*|\\/)");
	std::smatch match;

	std::string::const_iterator start(str.cbegin());
	std::string::const_iterator end(str.cend());
	while (std::regex_search(start, end, match, pattern)) {
		if (isOperand(match[0]))
			_stack.push(std::stoi(match[0]));
		else
			operate(match[0]);
		start = match.suffix().first;
	}
	if (_stack.size() != 1)
		throw InvalidExpressionException();
	return _stack.top();
}

bool	RPN::isOperand(const std::string &token) {
	return std::isdigit(token[0]);
}

void	RPN::operate(const std::string &token) {
	if (_stack.size() < 2)
		throw InvalidExpressionException();

	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();

	if (token == "+")
		_stack.push(b + a);
	else if (token == "-")
		_stack.push(b - a);
	else if (token == "*")
		_stack.push(b * a);
	else if (token == "/")
		_stack.push(b / a);
	else
		throw InvalidExpressionException();
	return ;
}

/*	Exeptions	*/
const char *RPN::InvalidExpressionException::what() const throw() {
	return "Invalid expression";
}
