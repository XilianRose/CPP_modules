#pragma once
#include <stack>
#include <string>
#include <exception>

class RPN {
	public:
		RPN();
		~RPN();

		void	parse(std::string &str);
		int		calculate(std::string &str);

		class InvalidExpressionException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
	
	private:
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);

		bool	isOperand(const std::string &token);
		void	operate(const std::string &token);

		std::stack<int> _stack;
};
